#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <omp.h>

#define QTD_ESTEIRAS 3
#define CONT_PARA_PESAGEM 1500

// Variáveis globais
int cont_total[QTD_ESTEIRAS] = {0};
float peso_total = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// Função para contar os itens nas esteiras
void *att_esteiras(void *id_thread) {
  int id = *(int*)id_thread; // Coleta o valor do inteiro do void id_thread
  float peso[3] = {5.0, 2.0, 0.5}; // Peso por itens (em ordem)
  float velocidade[3] = {1.0, 2.0, 10.0}; // Velocidade em itens por segundo (em ordem)
  
  while (1) { // 
      pthread_mutex_lock(&mutex);
      cont_total[id]++;
      peso_total += peso[id];
      if ((cont_total[0] + cont_total[1] + cont_total[2]) % CONT_PARA_PESAGEM == 0){
        usleep(2000000);
        printf("Total de itens na esteira 1 na pausa: %d\n", cont_total[0]);
        printf("Total de itens na esteira 2 na pausa: %d\n", cont_total[1]);
        printf("Total de itens na esteira 3 na pausa: %d\n\n", cont_total[2]);
        printf("Peso total dos itens na pausa: %.2f kg\n\n\n", peso_total);
      }
      pthread_mutex_unlock(&mutex);
    // Introduce a delay based on the thread's velocity
    usleep(1000000 / velocidade[id]);
  }
}

// Função para exibir o peso total periodicamente
void *display_peso_total() {
  while (1) {
    pthread_mutex_lock(&mutex);
    printf("Total de itens na esteira 1: %d\n", cont_total[0]);
    printf("Total de itens na esteira 2: %d\n", cont_total[1]);
    printf("Total de itens na esteira 3: %d\n\n\n", cont_total[2]);
    pthread_mutex_unlock(&mutex);
    sleep(2);
  }
  
  return NULL;
}

// Função para monitorar o botão de parar a contagem
void *monitorar_botao() {
   // Aguarda entrada do usuário
  if(getchar()){
    system("pause"); // Pausa o programa até o usuário pressionar Enter
    printf("Tecla ENTER pressionada. Programa finalizado.\n");
    exit(0);
  }
  return NULL;
}

int main() {
  pthread_t display_thread, botao_thread;
  pthread_t esteira[QTD_ESTEIRAS];

  int pipe_fd[2];
  
  if (pipe(pipe_fd) < 0) {
      perror("Erro ao criar pipe");
      exit(EXIT_FAILURE);
  }

  pid_t pid = fork();

  if (pid < 0) {
      perror("Erro ao criar processo filho");
      exit(EXIT_FAILURE);
  }

  if (pid == 0)
  {                      
      close(pipe_fd[1]); // close the writer

      while (1)
      {
          sleep(2);
          read(pipe_fd[0], &peso_total, sizeof(float));
          pthread_mutex_lock(&mutex);
          write(pipe_fd[1], &peso_total, sizeof(float));
          pthread_mutex_unlock(&mutex);
      }

      close(pipe_fd[0]); // close the reader
  } else {

      // Launch display thread
      pthread_create(&display_thread, NULL, display_peso_total, NULL);
      pthread_create(&botao_thread, NULL, monitorar_botao, NULL);

      #pragma omp parallel for num_threads(QTD_ESTEIRAS)
      for(int i = 0; i < QTD_ESTEIRAS; i++){
        pthread_create(&esteira[i], NULL, att_esteiras, &i);
        pthread_join(esteira[i], NULL);
      }
    
      // Wait for display thread to finish
      pthread_join(display_thread, NULL);
      pthread_join(botao_thread, NULL);
    }

  return 0;
}