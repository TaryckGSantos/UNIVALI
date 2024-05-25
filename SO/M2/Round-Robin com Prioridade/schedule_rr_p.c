// Funciona apenas o Round Robin
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include "schedule_rr_p.h"

#define MAX_PRIORITY 10 

// Lista de aptos
struct node *lista_aptos[MAX_PRIORITY];
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// Inicializa a lista de aptos
void init_lista_aptos() {
    for (int i = 0; i < MAX_PRIORITY; i++) {
        lista_aptos[i] = NULL;
    }
}

// Adiciona uma tarefa na lista de aptos
void add(char *name, int priority, int burst) {
    pthread_mutex_lock(&mutex);

    Task *new_task = (Task *)malloc(sizeof(Task));
    new_task->name = strdup(name);
    new_task->priority = priority;
    new_task->burst = burst;

    insert(&lista_aptos[priority - 1], new_task);

    pthread_mutex_unlock(&mutex);
}

// Função de escalonamento Round-Robin com prioridade
void schedule() {
    printf("\n------------------------------------\n\n\n");

    for (int i = 0; i < MAX_PRIORITY; i++) {
        while (1) {
            pthread_mutex_lock(&mutex);
            int all_empty = 1; // Supondo que a fila atual está vazia

            if (lista_aptos[i] != NULL) {
                all_empty = 0; // Encontrou pelo menos uma tarefa para executar

                struct node *current = lista_aptos[i];
                struct node *prev = NULL;

                while (current != NULL) {
                    Task *task = current->task;
                    int time_slice = (task->burst > QUANTUM) ? QUANTUM : task->burst;
                    run(task, time_slice);

                    task->burst -= time_slice;
                    sleep(1); // Simular slice de tempo

                    if (task->burst <= 0) {
                        printf("\n%s concluída\n\n", task->name);
                        struct node *to_delete = current;
                        if (prev == NULL) {
                            lista_aptos[i] = current->next;
                        } else {
                            prev->next = current->next;
                        }
                        current = current->next;
                        free(to_delete->task->name);
                        free(to_delete->task);
                        free(to_delete);
                    } else {
                        prev = current;
                        current = current->next;
                    }
                }
            }

            pthread_mutex_unlock(&mutex);

            if (all_empty) {
                break; // Sai do loop se a fila está vazia
            }
        }
    }
    printf("Todas as tarefas foram concluídas.\n");
}