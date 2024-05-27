#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "list.h"
#include "task.h"

// Função para inserir uma nova tarefa na lista
void insert(struct node **head, Task *task) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));  // Aloca memória para um novo nó
    new_node->task = task;  // Define a tarefa do novo nó
    new_node->next = *head;  // O próximo nó do novo nó é o atual cabeça da lista
    *head = new_node;  // Atualiza a cabeça da lista para o novo nó
}

// Função para remover uma tarefa específica da lista
void delete_t(struct node **head, Task *task) {
    struct node *temp = *head;  // Inicializa o nó temporário com a cabeça da lista
    struct node *prev = NULL;  // Inicializa o nó anterior como NULL

    // Se a cabeça da lista contém a tarefa a ser removida
    if (temp != NULL && strcmp(task->name, temp->task->name) == 0) {
        *head = temp->next;  // Atualiza a cabeça para o próximo nó
        free(temp);  // Libera a memória do nó removido
        return;
    }

    // Procura a tarefa na lista, mantendo o nó anterior
    while (temp != NULL && strcmp(task->name, temp->task->name) != 0) {
        prev = temp;  // Atualiza o nó anterior
        temp = temp->next;  // Avança para o próximo nó
    }

    // Se a tarefa não foi encontrada na lista
    if (temp == NULL) return;

    // Remove o nó da lista
    prev->next = temp->next;
    free(temp);  // Libera a memória do nó removido
}