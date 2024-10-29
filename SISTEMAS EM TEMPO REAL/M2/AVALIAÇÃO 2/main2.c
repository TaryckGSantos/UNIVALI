//Bibliotecas utilizadas
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/timer.h"
#include "driver/gpio.h"
#include "driver/touch_pad.h"
#include <time.h>
#include <string.h>
#include "esp_log.h"
#include "esp_intr_alloc.h"

// Definições de GPIOs para sensores e atuadores
#define TOUCH_INJECAO TOUCH_PAD_NUM0 // GPIO4
#define TOUCH_TEMPERATURA TOUCH_PAD_NUM8 // GPIO0
#define TOUCH_ABS TOUCH_PAD_NUM9 // GPIO32
#define TOUCH_AIRBAG TOUCH_PAD_NUM3 // GPIO15
#define TOUCH_CINTO TOUCH_PAD_NUM4 // GPIO13

#define GPIO_ATUADOR_INJECAO GPIO_NUM_18
#define GPIO_ATUADOR_TEMPERATURA GPIO_NUM_19
#define GPIO_ATUADOR_ABS GPIO_NUM_21
#define GPIO_ATUADOR_AIRBAG GPIO_NUM_22
#define GPIO_ATUADOR_CINTO GPIO_NUM_23

// Deadlines em microssegundos
#define DEADLINE_INJECAO 500 // 500 us
#define DEADLINE_TEMPERATURA 20000 // 20 ms
#define DEADLINE_ABS 100000 // 100 ms
#define DEADLINE_AIRBAG 100000 // 100 ms
#define DEADLINE_CINTO 1000000 // 1 segundo

volatile bool sensor_injecao_acionado = false;
volatile bool sensor_temperatura_acionado = false;
volatile bool sensor_abs_acionado = false;
volatile bool sensor_airbag_acionado = false;
volatile bool sensor_cinto_acionado = false;

// Número de amostras e configuração do timer
#define NUM_AMOSTRAS 200
int vetor_velocidade[NUM_AMOSTRAS] = {0};
int vetor_consumo[NUM_AMOSTRAS] = {0};
int indice = 0;

#define TIMER_DIVIDER 80 // Divisor de clock para precisão em microssegundos
#define TIMER_BASE_CLK 80000000 // Clock base do timer
#define TIMER_SCALE (TIMER_BASE_CLK / TIMER_DIVIDER) // Escala do timer para conversão de microssegundos

// Função para atualizar as amostras de velocidade e consumo
void atualizar_amostras() {
    int nova_velocidade = rand() % 150;
    int novo_consumo = rand() % 20;
    vetor_velocidade[indice] = nova_velocidade;
    vetor_consumo[indice] = novo_consumo;
    indice = (indice + 1) % NUM_AMOSTRAS;
}

// Função para calcular a média de amostras
float calcular_media(int* vetor) {
    int soma = 0;
    for (int i = 0; i < NUM_AMOSTRAS; i++) {
        soma += vetor[i];
    }
    return (float)soma / NUM_AMOSTRAS;
}

// Configuração do Timer
void configurar_timer() {
    timer_config_t config = {
        .divider = TIMER_DIVIDER, // Configura o divisor de clock
        .counter_dir = TIMER_COUNT_UP, // Configura o timer para contagem crescente
        .counter_en = TIMER_PAUSE, // Inicia o timer em pausa
        .alarm_en = TIMER_ALARM_DIS, // Desabilita alarmes
        .auto_reload = false, // Desabilita recarga automática
    };
    timer_init(TIMER_GROUP_0, TIMER_0, &config); // Inicializa o timer com a configuração
    timer_set_counter_value(TIMER_GROUP_0, TIMER_0, 0x00000000ULL); // Zera o valor do timer
    timer_start(TIMER_GROUP_0, TIMER_0); // Inicia o timer
}

// Função para obter o tempo em microssegundos usando o driver de timer
uint64_t obter_tempo() {
    uint64_t timer_val; // Variável para armazenar o valor do timer
    timer_get_counter_value(TIMER_GROUP_0, TIMER_0, &timer_val); // Obtém o valor do contador
    return timer_val / (TIMER_BASE_CLK / TIMER_DIVIDER / 1000000); // Converte o valor para microssegundos
}

// Função para lidar com deadlines ultrapassados
void alta_deadline(char* nome_acao, uint64_t tempo_execucao) {
    if (strcmp(nome_acao, "da injeção eletrônica") == 0){
        printf("Alerta: Tempo de resposta da %s excedeu o deadline (%llu us)\n", nome_acao, tempo_execucao);
    } else if (strcmp(nome_acao, "da temperatura do motor") == 0 || 
               strcmp(nome_acao, "do ABS") == 0 || 
               strcmp(nome_acao, "do airbag") == 0) {
        uint64_t tempo_execucao_micro = (tempo_execucao / 1000);
        printf("Alerta: Tempo de resposta da %s excedeu o deadline (%llu ms)\n", nome_acao, tempo_execucao_micro);
    } else if (strcmp(nome_acao, "do cinto de segurança") == 0){
        uint64_t tempo_execucao_segundos = (tempo_execucao / 1000000);
        printf("Alerta: Tempo de resposta da %s excedeu o deadline (%llu s)\n", nome_acao, tempo_execucao_segundos);
    }
    vTaskDelay(pdMS_TO_TICKS(1000));  // Delay para atualização do display
}

// Função para exibir o tempo de resposta
void mostrar_tempo(char* nome_acao, uint64_t tempo_execucao) {
    if (tempo_execucao < 1000) {
        printf("%s ativada\nTempo de resposta para a ativação da %s: %llu us\n", nome_acao, nome_acao, tempo_execucao);
    } else if (tempo_execucao < 1000000) {
        printf("%s ativado\nTempo de resposta para %s: %.2f ms\n", nome_acao, nome_acao, tempo_execucao / 1000.0);
    } else {
        printf("%s colocado\nTempo de resposta para a verificação do %s: %.2f s\n", nome_acao, nome_acao, tempo_execucao / 1000000.0);
    }
    vTaskDelay(pdMS_TO_TICKS(1000));  // Delay para atualização do display
}

// Função para exibir mensagem de sensor não ativado
void nao_ativado(char* nome_acao) {
    printf("%s\n", nome_acao); // Exibe mensagem do sistema que não está ativado
    vTaskDelay(pdMS_TO_TICKS(1000));  // Delay para atualização
}

// Função de interrupção para os touch pads
void IRAM_ATTR touch_pad_isr_handler(void *arg) {
    printf("Interrupção acionada - touch_pad_isr_handler\n");

    uint32_t pad_intr = touch_pad_get_status();
    touch_pad_clear_status(); // Limpa o status da interrupção

    if ((pad_intr >> TOUCH_INJECAO) & 0x01) {
        printf("Injeção eletrônica acionada\n");
        sensor_injecao_acionado = true;
    }
    if ((pad_intr >> TOUCH_TEMPERATURA) & 0x01) {
        printf("Temperatura do motor acionada\n");
        sensor_temperatura_acionado = true;
    }
    if ((pad_intr >> TOUCH_ABS) & 0x01) {
        printf("ABS acionado\n");
        sensor_abs_acionado = true;
    }
    if ((pad_intr >> TOUCH_AIRBAG) & 0x01) {
        printf("Airbag acionado\n");
        sensor_airbag_acionado = true;
    }
    if ((pad_intr >> TOUCH_CINTO) & 0x01) {
        printf("Cinto de segurança acionado\n");
        sensor_cinto_acionado = true;
    }
}

// Função de controle para injeção eletrônica
void verificar_injecao_eletronica(void *pvParameters) {
    while (1) { // Loop infinito
        uint64_t tempo_inicio, tempo_fim, tempo_execucao; // Variáveis para medir tempo

        if (sensor_injecao_acionado) {
            sensor_injecao_acionado = false; // Reseta a flag 
            tempo_inicio = obter_tempo(); // Captura o tempo em microssegundos
            vTaskDelay(pdMS_TO_TICKS(1) / 1000);  // Simula tempo de aquisição de 1 us

            vTaskDelay(pdMS_TO_TICKS(10) / 1000); // Simula tempo de envio dos dados (10 us) 

            gpio_set_level(GPIO_ATUADOR_INJECAO, 1);  // Ativa o atuador

            vTaskDelay(pdMS_TO_TICKS(5) / 1000);  // Simula tempo de controle do atuador (5 us)

            gpio_set_level(GPIO_ATUADOR_INJECAO, 0); // Desativa o atuador

            vTaskDelay(pdMS_TO_TICKS(10) / 1000); // Simula tempo de envio dos dados (10 us)

            tempo_fim = obter_tempo();   // Captura o tempo após a ação
            tempo_execucao = tempo_fim - tempo_inicio; // Calcula o tempo total de execução

            if (tempo_execucao > DEADLINE_INJECAO) { // Verifica se o tempo excedeu o deadline
                alta_deadline("da injeção eletrônica", tempo_execucao);
            } else {
                mostrar_tempo("Injeção eletrônica", tempo_execucao);
            }
        } else { // Se o sensor não estiver acionado
            nao_ativado("Injeção eletrônica desativada");
        }

        vTaskDelay(pdMS_TO_TICKS(100));   // Delay antes da próxima verificação
    }
}

// Função de controle para temperatura do motor
void verificar_temperatura_motor(void *pvParameters) {
    while (1) {
        uint64_t tempo_inicio, tempo_fim, tempo_execucao;

        if (sensor_temperatura_acionado) {
            sensor_temperatura_acionado = false; // Reseta a flag 
            tempo_inicio = obter_tempo();  
            vTaskDelay(pdMS_TO_TICKS(1) / 1000);  // Tempo de aquisição de 1 us 

            gpio_set_level(GPIO_ATUADOR_TEMPERATURA, 1);

            vTaskDelay(pdMS_TO_TICKS(5) / 1000);  // Simula tempo de controle do atuador (5 us) 

            gpio_set_level(GPIO_ATUADOR_TEMPERATURA, 0);

            vTaskDelay(pdMS_TO_TICKS(10) / 1000); // Simula tempo de envio dos dados (10 us)

            tempo_fim = obter_tempo();  
            tempo_execucao = tempo_fim - tempo_inicio;

            if (tempo_execucao > DEADLINE_TEMPERATURA) {
                alta_deadline("da temperatura do motor", tempo_execucao);
            } else {
                mostrar_tempo("Verificação da temperatura do motor", tempo_execucao);
            }
        } else {
            nao_ativado("Temperatura do motor normal");
        }

        vTaskDelay(pdMS_TO_TICKS(100));  
    }
}

// Função de controle para ABS
void verificar_abs(void *pvParameters) {
    while (1) {
        uint64_t tempo_inicio, tempo_fim, tempo_execucao;

        if (sensor_abs_acionado) {
            sensor_abs_acionado = false; // Reseta a flag 
            tempo_inicio = obter_tempo();  
            vTaskDelay(pdMS_TO_TICKS(1) / 1000);  // Tempo de aquisição de 1 us

            vTaskDelay(pdMS_TO_TICKS(10) / 1000); // Simula tempo de envio dos dados (10 us)

            gpio_set_level(GPIO_ATUADOR_ABS, 1);

            vTaskDelay(pdMS_TO_TICKS(5) / 1000);  // Simula tempo de controle do atuador (5 us)  

            gpio_set_level(GPIO_ATUADOR_ABS, 0);

            vTaskDelay(pdMS_TO_TICKS(10) / 1000); // Simula tempo de envio dos dados (10 us)

            tempo_fim = obter_tempo();  
            tempo_execucao = tempo_fim - tempo_inicio;

            if (tempo_execucao > DEADLINE_ABS) {
                alta_deadline("do ABS", tempo_execucao);
            } else {
                mostrar_tempo("ABS", tempo_execucao);
            }
        }else {
            nao_ativado("ABS desativado");
        }

        vTaskDelay(pdMS_TO_TICKS(100));  
    }
}

// Função de controle para airbag
void verificar_airbag(void *pvParameters) {
    while (1) {
        uint64_t tempo_inicio, tempo_fim, tempo_execucao;

        if (sensor_airbag_acionado) {
            sensor_airbag_acionado = false;
            tempo_inicio = obter_tempo();  
            vTaskDelay(pdMS_TO_TICKS(1) / 1000);  // Tempo de aquisição de 1 us 

            vTaskDelay(pdMS_TO_TICKS(10) / 1000); // Simula tempo de envio dos dados (10 us)

            gpio_set_level(GPIO_ATUADOR_AIRBAG, 1);

            vTaskDelay(pdMS_TO_TICKS(5) / 1000);  // Simula tempo de controle do atuador (5 us)  

            gpio_set_level(GPIO_ATUADOR_AIRBAG, 0);

            vTaskDelay(pdMS_TO_TICKS(10) / 1000); // Simula tempo de envio dos dados (10 us)

            tempo_fim = obter_tempo();  
            tempo_execucao = tempo_fim - tempo_inicio;

            if (tempo_execucao > DEADLINE_AIRBAG) {
                alta_deadline("do airbag", tempo_execucao);
            } else {
                mostrar_tempo("Airbag", tempo_execucao);
            }
        }else {
            nao_ativado("Airbag pronto");
        }

        vTaskDelay(pdMS_TO_TICKS(100));  
    }
}

// Função de controle para cinto de segurança
void verificar_cinto_seguranca(void *pvParameters) {
    while (1) {
        uint64_t tempo_inicio, tempo_fim, tempo_execucao;

        if (sensor_cinto_acionado) {
            sensor_cinto_acionado = false;
            tempo_inicio = obter_tempo();  
            vTaskDelay(pdMS_TO_TICKS(1) / 1000);  // Tempo de aquisição de 1 us

            vTaskDelay(pdMS_TO_TICKS(10) / 1000); // Simula tempo de envio dos dados (10 us)

            gpio_set_level(GPIO_ATUADOR_CINTO, 1);

            vTaskDelay(pdMS_TO_TICKS(5) / 1000);  // Simula tempo de controle do atuador (5 us)  

            gpio_set_level(GPIO_ATUADOR_CINTO, 0);

            vTaskDelay(pdMS_TO_TICKS(10) / 1000); // Simula tempo de envio dos dados (10 us)

            tempo_fim = obter_tempo();  
            tempo_execucao = tempo_fim - tempo_inicio;

            if (tempo_execucao > DEADLINE_CINTO) {
                alta_deadline("do cinto de segurança", tempo_execucao);
            } else {
                mostrar_tempo("Cinto de segurança", tempo_execucao);
            }
        } else {
            nao_ativado("O Cinto de segurança não está colocado");
        }

        vTaskDelay(pdMS_TO_TICKS(100));  
    }
}

// Função para atualizar o display
void atualizar_display(void *pvParameters) {
    while (1) { // Loop infinito
        atualizar_amostras();  // Atualiza as amostras de velocidade e consumo
        float media_velocidade = calcular_media(vetor_velocidade); // Calcula a média de velocidade
        float media_consumo = calcular_media(vetor_consumo); // Calcula a média de consumo
        printf("\nVelocidade média: %.2f km/h\n", media_velocidade); // Exibe a média de velocidade
        printf("Consumo médio: %.2f L/100km\n", media_consumo); // Exibe a média de consumo

        vTaskDelay(pdMS_TO_TICKS(1000));  // Delay de 1 segundo para atualização
    }
}

void configurar_interrupcoes() {
    touch_pad_set_trigger_mode(TOUCH_TRIGGER_BELOW);
    touch_pad_clear_status(); // Limpa status antes de habilitar
    touch_pad_intr_enable(); // Habilita interrupções do touch pad
    
    esp_err_t err = touch_pad_isr_register(touch_pad_isr_handler, NULL); // Registra o handler
    if (err == ESP_OK) {
        printf("Deu boaAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA!!!!!!!!!!!!!!!!!!!!!");
    } else {
        printf("MEU CUUUUUUUUUUUUUUUUUUUUU");
    }
}

// Função principal
void app_main() {
    // Configuram os atuadores
    gpio_set_direction(GPIO_ATUADOR_INJECAO, GPIO_MODE_OUTPUT);
    gpio_set_direction(GPIO_ATUADOR_TEMPERATURA, GPIO_MODE_OUTPUT);
    gpio_set_direction(GPIO_ATUADOR_ABS, GPIO_MODE_OUTPUT);
    gpio_set_direction(GPIO_ATUADOR_AIRBAG, GPIO_MODE_OUTPUT);
    gpio_set_direction(GPIO_ATUADOR_CINTO, GPIO_MODE_OUTPUT);
    
    touch_pad_init(); // Inicializa os sensores touch
    
    touch_pad_config(TOUCH_INJECAO, 40);
    touch_pad_config(TOUCH_TEMPERATURA, 40);
    touch_pad_config(TOUCH_ABS, 40);
    touch_pad_config(TOUCH_AIRBAG, 40);
    touch_pad_config(TOUCH_CINTO, 40);

    touch_pad_set_fsm_mode(TOUCH_FSM_MODE_TIMER);

    touch_pad_filter_start(10);

    configurar_interrupcoes(); 

    // Criar threads para os sensores e atuadores
    xTaskCreate(verificar_injecao_eletronica, "InjecaoEletronicaTask", 2048, NULL, 10, NULL);
    xTaskCreate(verificar_temperatura_motor, "TemperaturaMotorTask", 2048, NULL, 7, NULL);
    xTaskCreate(verificar_abs, "ABSTask", 2048, NULL, 4, NULL);
    xTaskCreate(verificar_airbag, "AirbagTask", 2048, NULL, 3, NULL);
    xTaskCreate(verificar_cinto_seguranca, "CintoSegurancaTask", 2048, NULL, 2, NULL);

    // Criar thread para atualizar o display
    xTaskCreate(atualizar_display, "DisplayTask", 2048, NULL, 1, NULL);
}
