#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <omp.h>

#define NUM_CONVEYORS 3
#define ITEMS_PER_WEIGHING 1500

// Shared data
int total_count;
pthread_mutex_t mutex;

// Pipe for interprocess communication
int fd[2];

// Function to count items on conveyor
void* conveyor_count(void* arg) {
  int conveyor_number = (int) arg;
  int count = 0;
  // Simulate time between items passing through the conveyor
  for (int i = 0; i < NUM_CONVEYORS; i++) {
    pthread_mutex_lock(&mutex);
    count++;
    total_count++;
    pthread_mutex_unlock(&mutex);
    if (count % ITEMS_PER_WEIGHING == 0) {
      // Calculate total weight of items using OpenMP
      #pragma omp parallel for
      for (int j = 0; j < ITEMS_PER_WEIGHING; j++) {
        // Calculate weight of item based on conveyor number
        double weight = (conveyor_number == 0) ? 5.0 : (conveyor_number == 1) ? 2.0 : 0.5;
        // Update shared data
        pthread_mutex_lock(&mutex);
        total_count += weight;
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
    printf("Total count: %d\n", total_count);
  }
}

int main() {
  // Initialize shared data
  total_count = 0;
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
    pthread_t threads[NUM_CONVEYORS];
    for (int i = 0; i < NUM_CONVEYORS; i++) {
      pthread_create(&threads[i], NULL, conveyor_count, (void*) i);
    }
    for (int i = 0; i < NUM_CONVEYORS; i++) {
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
