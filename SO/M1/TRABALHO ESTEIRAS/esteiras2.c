#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include "omp.h"

#define NUM_CONVEYORS 3
#define ITEMS_PER_WEIGHING 1500

// Dados compartilhados
int total_contagem;
pthread_mutex_t mutex;

// Pipe para comunicação entre processos
int fd[2];

// Função para contar itens na esteira
void* contagem_esteira(void* arg) {
  int numero_esteira = (int) arg;
  int contagem = 0;
  // Simula o tempo entre os itens passando pela esteira
  for (int i = 0; i < NUM_CONVEYORS; i++) {
    pthread_mutex_lock(&mutex);
    contagem++;
    total_contagem++;
    pthread_mutex_unlock(&mutex);
    if (contagem % ITEMS_PER_WEIGHING == 0) {
      // Calcula o peso total dos itens usando OpenMP
      #pragma omp parallel for
      for (int j = 0; j < ITEMS_PER_WEIGHING; j++) {
        // Calcula o peso do item com base no número da esteira
        double peso = (numero_esteira == 0) ? 5.0 : (numero_esteira == 1) ? 2.0 : 0.5;
        // Atualiza os dados compartilhados
        pthread_mutex_lock(&mutex);
        total_contagem += peso;
        pthread_mutex_unlock(&mutex);
      }
    }
    // Simula o tempo de passagem dos itens pela esteira
    sleep(numero_esteira == 0 ? 1 : (numero_esteira == 1) ? 0.5 : 0.1);
  }
  return NULL;
}

// Função para atualizar o display
void atualizar_display() {
  while (1) {
    sleep(2);
    printf("Total de contagem: %d\n", total_contagem);
  }
}

int main() {
  // Inicializa os dados compartilhados
  total_contagem = 0;
  pthread_mutex_init(&mutex, NULL);

  // Cria pipe para comunicação entre processos
  if (pipe(fd) < 0) {
    perror("Falha ao criar o pipe");
    exit(1);
  }

  // Fork do processo
  pid_t pid = fork();
  if (pid < 0) {
    perror("Fork falhou");
    exit(1);
  }

  if (pid == 0) {
    // Processo filho
    pthread_t threads[NUM_CONVEYORS];
    for (int i = 0; i < NUM_CONVEYORS; i++) {
      pthread_create(&threads[i], NULL, contagem_esteira, (void*) i);
    }
    for (int i = 0; i < NUM_CONVEYORS; i++) {
      pthread_join(threads[i], NULL);
    }

    // Libera os recursos
    pthread_mutex_destroy(&mutex);
    close(fd[0]);
    close(fd[1]);
    
    exit(0);
  } else {
    // Processo pai
    atualizar_display();
    wait(NULL);

    // Libera os recursos
    pthread_mutex_destroy(&mutex);
    close(fd[0]);
    close(fd[1]);
    
    return 0;
  }
}
