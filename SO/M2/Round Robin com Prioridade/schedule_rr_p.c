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

    for (int i = 0; i < MAX_PRIORITY; i++) { // Iteração sobre todas as filas de prioridade
        while (1) {
            pthread_mutex_lock(&mutex);
            int all_empty = 1; // Supondo que a fila atual está vazia

            if (lista_aptos[i] != NULL) {
                all_empty = 0; // Encontrou pelo menos uma tarefa para executar

                struct node *current = lista_aptos[i]; // Inicializa o ponteiro para o nó atual da lista
                struct node *prev = NULL; // Inicializa o ponteiro para o nó anterior da lista como NULL

                while (current != NULL) { // Loop sobre todas as tarefas na fila de prioridade atual
                    Task *task = current->task; // Obtém a tarefa atual
                    int time_slice = (task->burst > QUANTUM) ? QUANTUM : task->burst; // Determina o tamanho do quantum de tempo
                    run(task, time_slice); // Executa a tarefa por um quantum de tempo

                    task->burst -= time_slice; // Reduz o tempo restante de burst da tarefa
                    sleep(1); // Simular slice de tempo

                    if (task->burst <= 0) { // Verifica se a tarefa foi concluída
                        printf("\n%s concluída\n\n", task->name);
                        struct node *to_delete = current; // Salva o ponteiro para o nó a ser removido
                        if (prev == NULL) { // Se o nó a ser removido é o primeiro da lista
                            lista_aptos[i] = current->next; // Atualiza a head da lista
                        } else {
                            prev->next = current->next; // Remove o nó da lista
                        }
                        current = current->next; // Avança para o próximo nó
                        free(to_delete->task->name);
                        free(to_delete->task);
                        free(to_delete);
                    } else { 
                        prev = current; // Atualiza o ponteiro para o nó anterior
                        current = current->next; // Avança para o próximo nó
                    }
                }
            }

            pthread_mutex_unlock(&mutex);

            if (all_empty) { // Verifica se a fila está vazia
                break; // Sai do loop se a fila está vazia
            }
        }
    }
    printf("Todas as tarefas foram concluídas.\n");
}