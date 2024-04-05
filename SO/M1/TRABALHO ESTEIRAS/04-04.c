#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <omp.h>

#define QTD_ESTEIRAS 3
#define CONT_PARA_PESAGEM 5

// Variáveis globais
int cont_total[QTD_ESTEIRAS] = {0, 0, 0};
float peso_total = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// Função para contar os itens nas esteiras
void *att_esteiras(void *arg) {
  int esteira_id = *((int *)arg);
  float peso[3] = {5.0, 2.0, 0.5}; // Peso por itens (em ordem)
  float velocidade[3] = {1.0, 0.5,
                         0.1}; // Velocidade em itens por segundo (em ordem)

  while (1) {
#pragma omp parallel num_threads(3)
    {
      int id = omp_get_thread_num();
      if (id == esteira_id) {
        pthread_mutex_lock(&mutex);
        cont_total[esteira_id]++;
        peso_total += peso[0] + peso[1] + peso[2];
        pthread_mutex_unlock(&mutex);
      }
    }
    usleep(1000000 / velocidade[esteira_id]);
  }
}

// Função para exibir o peso total periodicamente
void *display_peso_total() {
  while (1) {
    sleep(2);
    pthread_mutex_lock(&mutex);
    printf("Total de itens na esteira 1: %d\n",
           (cont_total[0] + cont_total[1] + cont_total[2]));
    printf("Peso total dos itens processados: %.2f kg\n", peso_total);
    pthread_mutex_unlock(&mutex);
  }
}

int main() {

  pthread_t threads[QTD_ESTEIRAS];
  pthread_t display_thread;

  printf("Peso total dos itens processados: %.2f kg\n", peso_total);

  for (int i = 0; i < QTD_ESTEIRAS; i++) {
    pthread_create(&threads[i], NULL, att_esteiras, (void *)&i);
  }

  pthread_create(&display_thread, NULL, display_peso_total, NULL);

  for (int i = 0; i < QTD_ESTEIRAS; i++) {
    pthread_join(threads[i], NULL);
  }

  pthread_join(display_thread, NULL);

  return 0;
}
