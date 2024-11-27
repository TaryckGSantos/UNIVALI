#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <termios.h>
#include <fcntl.h>

// Definições para simulação dos sensores e atuadores
#define SENSOR_ABS 'a'
#define SENSOR_AIRBAG 'b'

// Deadlines em microssegundos
#define DEADLINE_ABS 100000
#define DEADLINE_AIRBAG 100000

// Configurações globais
#define NUM_AMOSTRAS 200
#define JANELA_ATIVACOES 10
#define M_ATIVACOES 10

// Variáveis globais
volatile bool sensor_ativado[2] = {false};
pthread_mutex_t sensor_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t sensor_cond = PTHREAD_COND_INITIALIZER;

// Variáveis para medir tempos
uint64_t WCET[2] = {0};
uint64_t WCRT[2] = {0};
uint64_t HWM[2] = {0};
uint64_t LWM[2] = {UINT64_MAX, UINT64_MAX};

// Função para obter o tempo em microssegundos
uint64_t obter_tempo() {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return ts.tv_sec * 1000000ULL + ts.tv_nsec / 1000;
}

// Função para capturar teclas pressionadas (simulação de sensores)
int capturar_tecla() {
    struct termios oldt, newt;
    int ch;
    int oldf;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    return ch;
}

// Função para lidar com deadlines ultrapassados
void alta_deadline(char* nome_acao, uint64_t tempo_execucao) {
    if (strcmp(nome_acao, "da injeção eletrônica") == 0){
        printf("Alerta: Tempo de resposta da %s excedeu o deadline (%lu us)\n", nome_acao, tempo_execucao);
    } else if (strcmp(nome_acao, "da temperatura do motor") == 0 || 
               strcmp(nome_acao, "do ABS") == 0 || 
               strcmp(nome_acao, "do airbag") == 0) {
        uint64_t tempo_execucao_micro = (tempo_execucao / 1000);
        printf("Alerta: Tempo de resposta da %s excedeu o deadline (%lu ms)\n", nome_acao, tempo_execucao_micro);
    } else if (strcmp(nome_acao, "do cinto de segurança") == 0){
        uint64_t tempo_execucao_segundos = (tempo_execucao / 1000000);
        printf("Alerta: Tempo de resposta da %s excedeu o deadline (%lu s)\n", nome_acao, tempo_execucao_segundos);
    }
    usleep(1000000);
}

// Função para exibir o tempo de resposta
void mostrar_tempo(char* nome_acao, uint64_t tempo_execucao, uint64_t tempo_resposta) {
    if (tempo_execucao < 1000) {
        printf("%s ativado\nTempo de execução para a ativação do %s: %lu us\n", nome_acao, nome_acao, tempo_execucao);
    } else if (tempo_execucao < 1000000) {
        printf("%s ativado\nTempo de execução para %s: %.2f ms\n", nome_acao, nome_acao, tempo_execucao / 1000.0);
    } else {
        printf("%s colocado\nTempo de execução para a verificação do %s: %.2f s\n", nome_acao, nome_acao, tempo_execucao / 1000000.0);
    }

    if (tempo_resposta < 1000) {
        printf("Tempo de resposta para a ativação da %s: %lu us\n", nome_acao, tempo_resposta);
    } else if (tempo_resposta < 1000000) {
        printf("Tempo de resposta para %s: %.2f ms\n", nome_acao, tempo_resposta / 1000.0);
    } else {
        printf("Tempo de resposta para a verificação do %s: %.2f s\n\n", nome_acao, tempo_resposta / 1000000.0);
    }

    usleep(1000000);  // Delay para atualização do display
}

void* tarefa_ABS(void* arg) {
    uint64_t tempo_inicio, tempo_fim_WCET, tempo_fim_HWM, tempo_execucao, tempo_resposta;

    while (1) {
        pthread_mutex_lock(&sensor_mutex);

        // Espera o sinal ou timeout
        while (!sensor_ativado[0]) {
            struct timespec ts;
            clock_gettime(CLOCK_MONOTONIC, &ts);
            ts.tv_sec += 1; // Timeout de 1 segundo
            pthread_cond_timedwait(&sensor_cond, &sensor_mutex, &ts);
        }
        uint64_t tempo_inicio = obter_tempo();

        sensor_ativado[0] = false; // Reseta o estado do sensor
        pthread_mutex_unlock(&sensor_mutex);

        usleep(1); // Simula tempo de aquisição
        usleep(10); // Simula tempo de envio de dados
        usleep(5); // Simula tempo de controle do atuador
        usleep(10); // Simula tempo de envio de dados

        tempo_fim_WCET = obter_tempo(); // Captura o tempo após a execução
        tempo_execucao = tempo_fim_WCET - tempo_inicio; // Calcula o tempo total de execução

        // Atualizar WCET e verificar deadline
        if (tempo_execucao > WCET[0]){ 
            WCET[0] = tempo_execucao;
        }

        tempo_fim_HWM = obter_tempo(); // Captura o tempo após a resposta
        tempo_resposta = tempo_fim_HWM - tempo_inicio; // Calcula o tempo total de resposta

        if (tempo_resposta > HWM[0]) { // Verifica o maior tempo de resposta
            HWM[0] = tempo_resposta;
        }

        if (tempo_resposta < LWM[0]) { // Verifica o menor tempo de resposta
            LWM[0] = tempo_resposta;
        }

        WCRT[0] = HWM[0] + (HWM[0] - LWM[0]); // Calculo do WCRT do ABS

        if (HWM[0] > DEADLINE_ABS) { // Verifica se o tempo excedeu o deadline
            alta_deadline("do ABS", tempo_resposta);
        }

        mostrar_tempo("ABS", tempo_execucao, tempo_resposta);

        usleep(100000);        
    }
    return NULL;
}

void* tarefa_Airbag(void* arg) {
    uint64_t tempo_inicio, tempo_fim_WCET, tempo_fim_HWM, tempo_execucao, tempo_resposta;
    
    while (1) {
        pthread_mutex_lock(&sensor_mutex);

        // Espera o sinal ou timeout
        while (!sensor_ativado[1]) {
            struct timespec ts;
            clock_gettime(CLOCK_MONOTONIC, &ts);
            ts.tv_sec += 1; // Timeout de 1 segundo
            pthread_cond_timedwait(&sensor_cond, &sensor_mutex, &ts);
        }
        uint64_t tempo_inicio = obter_tempo();

        sensor_ativado[1] = false; // Reseta o estado do sensor
        pthread_mutex_unlock(&sensor_mutex);

        usleep(1); // Simula tempo de aquisição
        usleep(10); // Simula tempo de envio de dados
        usleep(5); // Simula tempo de controle do atuador
        usleep(10); // Simula tempo de envio de dados

        tempo_fim_WCET = obter_tempo(); // Captura o tempo após a execução
        tempo_execucao = tempo_fim_WCET - tempo_inicio; // Calcula o tempo total de execução

        // Atualizar WCET e verificar deadline
        if (tempo_execucao > WCET[1]){ 
            WCET[1] = tempo_execucao;
        }

        tempo_fim_HWM = obter_tempo(); // Captura o tempo após a resposta
        tempo_resposta = tempo_fim_HWM - tempo_inicio; // Calcula o tempo total de resposta

        if (tempo_resposta > HWM[1]) { // Verifica o maior tempo de resposta
            HWM[1] = tempo_resposta;
        }

        if (tempo_resposta < LWM[1]) { // Verifica o menor tempo de resposta
            LWM[1] = tempo_resposta;
        }

        WCRT[1] = HWM[1] + (HWM[1] - LWM[1]) + HWM[0] ; // Calculo do WCRT do Airbag

        if (HWM[1] > DEADLINE_ABS) { // Verifica se o tempo excedeu o deadline
            alta_deadline("do Airbag", tempo_resposta);
        }

        mostrar_tempo("Airbag", tempo_execucao, tempo_resposta);

        usleep(100000);        
    }
    return NULL;
}

void *monitorar_sensores(void *arg) {
    while (1) {
        int tecla = capturar_tecla();
        if (tecla != EOF) {
            pthread_mutex_lock(&sensor_mutex);
            switch (tecla) {
                case SENSOR_ABS:
                    sensor_ativado[0] = true;
                    break;
                case SENSOR_AIRBAG:
                    sensor_ativado[1] = true;
                    break;
            }
            pthread_mutex_unlock(&sensor_mutex);
        }
        usleep(10000); // Reduz carga da CPU
    }
    return NULL;
}

// Thread: Atualizar Display
void* atualizar_display(void* arg) {
    while (1) {
        //atualizar_amostras();
        float media_vel = 0, media_con = 0;
        for (int i = 0; i < NUM_AMOSTRAS; i++) {
            //media_vel += velocidade[i];
            //media_con += consumo[i];
        }
        media_vel = 0;
        media_con = 1;

        printf("\nVelocidade média: %.2f km/h\n", media_vel);
        printf("Consumo médio: %.2f L/100km\n", media_con);
        sleep(1); // Atualização a cada 1 segundo
    }
}

// Função principal
int main() {

    pthread_t threads[4];
    pthread_attr_t attr;

    // Inicializar atributos das threads
    pthread_attr_init(&attr);
    pthread_attr_setschedpolicy(&attr, SCHED_FIFO);

    // Configure a prioridade para cada thread
    struct sched_param param;

    // Criar threads
    param.sched_priority = 50;
    pthread_attr_setschedparam(&attr, &param);
    pthread_create(&threads[0], &attr, tarefa_ABS, NULL);

    param.sched_priority = 40;
    pthread_attr_setschedparam(&attr, &param);
    pthread_create(&threads[1], &attr, tarefa_Airbag, NULL);

    param.sched_priority = 5;
    pthread_attr_setschedparam(&attr, &param);
    pthread_create(&threads[2], &attr, atualizar_display, NULL);

    param.sched_priority = 15;
    pthread_attr_setschedparam(&attr, &param);
    pthread_create(&threads[3], &attr, monitorar_sensores, NULL);

    pthread_attr_destroy(&attr); // Destrua os atributos após uso

    pthread_join(threads[0], NULL);
    pthread_join(threads[1], NULL);
    pthread_join(threads[2], NULL);
    pthread_join(threads[3], NULL);

    printf("aqui 6");

    return 0;
}
