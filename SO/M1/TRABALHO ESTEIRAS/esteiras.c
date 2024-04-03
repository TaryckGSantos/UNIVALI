#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include "omp.h"

#define NUM_ESTEIRAS 3
#define CONT_PARA_PESAGEM 5

// Variáveis globais
int cont_total;
pthread_mutex_t mutex;

// Pipe para comunicação entre processos
int fd[2];

// Função para contar os itens nas esteiras
void* cont_esteiras(void* arg) {
  int conveyor_number = (int) arg;
  int count = 0;
  // Simulate time between items passing through the conveyor
  for (int i = 0; i < NUM_ESTEIRAS; i++) {
    pthread_mutex_lock(&mutex);
    count++;
    cont_total++;
    pthread_mutex_unlock(&mutex);
    if (count % CONT_PARA_PESAGEM == 0) {
      // Calculate total weight of items using OpenMP
      #pragma omp parallel for
      for (int j = 0; j < CONT_PARA_PESAGEM; j++) {
        // Calculate weight of item based on conveyor number
        double weight = (conveyor_number == 0) ? 5.0 : (conveyor_number == 1) ? 2.0 : 0.5;
        // Update shared data
        pthread_mutex_lock(&mutex);
        cont_total += weight;
        pthread_mutex_unlock(&mutex);
      }
    }
    sleep(conveyor_number == 0 ? 1 : (conveyor_number == 1) ? 0.5 : 0.1);
  }
  return NULL;
}

// Function to update display
void update_display() {
  while (1) {
    sleep(2);
    printf("Total count: %d\n", cont_total);
  }
}

int main() {
  // Initialize shared data
  cont_total = 0;
  pthread_mutex_init(&mutex, NULL);

  // Create pipe for interprocess communication
  if (pipe(fd) < 0) {
    perror("Pipe failed");
    exit(1);
  }

  // Fork process
  pid_t pid = fork();
  if (pid < 0) {
    perror("Fork failed");
    exit(1);
  }

  if (pid == 0) {
    // Child process
    pthread_t threads[NUM_ESTEIRAS];
    for (int i = 0; i < NUM_ESTEIRAS; i++) {
      pthread_create(&threads[i], NULL, cont_esteiras, (void*) i);
    }
    for (int i = 0; i < NUM_ESTEIRAS; i++) {
      pthread_join(threads[i], NULL);
    }
    exit(0);
  } else {
    // Parent process
    update_display();
    wait(NULL);
    return 0;
  }
}
