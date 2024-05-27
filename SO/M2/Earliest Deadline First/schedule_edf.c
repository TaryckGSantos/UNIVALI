#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include "schedule_edf.h"

// Define o número máximo de níveis de prioridade
#define MAX_PRIORITY 10 

// Lista de aptos e mutex
struct node *lista_aptos[MAX_PRIORITY];
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// Inicializa a lista de aptos
void init_lista_aptos() {
    for (int i = 0; i < MAX_PRIORITY; i++) {
        lista_aptos[i] = NULL; // Define cada lista de aptos como vazia
    }
}

// Função para imprimir o estado atual da lista de aptos
void print_lista_aptos() {
    for (int i = 0; i < MAX_PRIORITY; i++) { // Percorre cada nível de prioridade
        struct node *current = lista_aptos[i]; // Aponta para o início da lista de tarefas
        printf("Prioridade %d: ", i + 1); // Imprime a prioridade atual
        while (current != NULL) { // Percorre todas as tarefas na lista de aptos na prioridade atual
            // Imprime as informações da tarefa atual
            printf("[%s, Burst: %d, Deadline: %d] -> ", current->task->name, current->task->burst, current->task->deadline);
            current = current->next; // Move para a próxima tarefa
        }
        printf("NULL\n\n");
    }
    printf("\n");
}

// Adiciona uma nova tarefa à lista de aptos
void add(char *name, int priority, int burst, int deadline) {
    pthread_mutex_lock(&mutex);

    Task *new_task = (Task *)malloc(sizeof(Task));
    new_task->name = strdup(name);
    new_task->priority = priority;
    new_task->burst = burst;
    new_task->deadline = deadline;

    insert(&lista_aptos[priority - 1], new_task);

    pthread_mutex_unlock(&mutex);
}

// Função de escalonamento EDF
void schedule() {
    printf("\n------------------------------------\n\n\n");

    // Inicializa a variável de tempo total de execução
    int running= 0;

    while (1) {
        pthread_mutex_lock(&mutex);
        struct node *earliest_node = NULL; // Ponteiro para a tarefa com a menor deadline
        int earliest_priority = -1; // Armazena a prioridade da tarefa com a menor deadline
        struct node *earliest_prev = NULL; // Ponteiro para o nó anterior ao de menor deadline na lista

        // Encontrar a tarefa com a menor deadline
        for (int i = 0; i < MAX_PRIORITY; i++) {
            struct node *current = lista_aptos[i]; // Ponteiro para percorrer a lista de tarefas na prioridade atual
            struct node *prev = NULL; // Ponteiro para o nó anterior na lista de tarefas na prioridade atual

            // Percorre todas as tarefas na lista de aptos na prioridade atual
            while (current != NULL) {
                // Verifica se a tarefa atual tem uma deadline menor que a armazenada ou se não há uma tarefa armazenada ainda
                if (earliest_node == NULL || current->task->deadline < earliest_node->task->deadline) {
                    earliest_node = current;
                    earliest_priority = i;
                    earliest_prev = prev;
                }
                // Atualiza os ponteiros para a próxima iteração
                prev = current;
                current = current->next;
            }
        }

        // Se não há mais tarefas a serem executadas, sai do loop
        if (earliest_node == NULL) {
            pthread_mutex_unlock(&mutex);
            break;
        }

        // Executar a tarefa com a menor deadline
        Task *task = earliest_node->task;
        // Incrementa o tempo total de execução pelo burst da tarefa atual
        running += task->burst;
        // Chama a função de execução da tarefa
        run(task, task->burst,running);

        // Remover a tarefa concluída da lista de aptos
        if (earliest_prev == NULL) {
            lista_aptos[earliest_priority] = earliest_node->next;
        } else {
            earliest_prev->next = earliest_node->next;
        }

        // Pausa para simular a execução do burst da tarefa
        sleep((earliest_node->task->burst)/10);
        printf("\n%s concluída em %d unidades de tempo\n\n\n", earliest_node->task->name, running);

        // Libera a memória alocada
        free(earliest_node->task->name);
        free(earliest_node->task);
        free(earliest_node);

        pthread_mutex_unlock(&mutex);
    }
    printf("Todas as tarefas foram concluídas.\n");
}