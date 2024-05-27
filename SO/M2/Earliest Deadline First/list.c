#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "list.h"
#include "task.h"

// Função para inserir uma nova tarefa na lista de forma ordenada por deadline
void insert(struct node **head, Task *task) {
    // Alocar memória para um novo nó
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->task = task;
    new_node->next = NULL;

    // Se a lista estiver vazia ou a nova tarefa tiver uma deadline menor que a primeira tarefa
    if (*head == NULL || (*head)->task->deadline > task->deadline) {
        new_node->next = *head; // Novo nó aponta para o antigo primeiro nó
        *head = new_node; // Novo nó se torna o primeiro nó da lista
    } else { // Encontrar a posição correta para inserir o novo nó
        struct node *current = *head;
        while (current->next != NULL && current->next->task->deadline <= task->deadline) { // Avançar para o próximo nó
            current = current->next;
        }
        new_node->next = current->next; // Novo nó aponta para o próximo nó de current
        current->next = new_node; // Current aponta para o novo nó
    }
}

// Remove a tarefa selecionada da lista
void delete_t(struct node **head, Task *task) {
    struct node *temp = *head; // Ponteiro para percorrer a lista
    struct node *prev = NULL; // Ponteiro para o nó anterior ao atual

    // Se a lista não estiver vazia e a primeira tarefa for a que queremos remover
    if (temp != NULL && strcmp(task->name, temp->task->name) == 0) {
        *head = temp->next; // Primeiro nó aponta para o próximo nó
        free(temp);
        return;
    }

    // Percorrer a lista para encontrar a tarefa a ser removida
    while (temp != NULL && strcmp(task->name, temp->task->name) != 0) {
        prev = temp; // Atualizar o nó anterior
        temp = temp->next; // Avançar para o próximo nó
    }

    // Se não encontrar a tarefa, sair da função
    if (temp == NULL) return; 

    // Remover o nó da lista
    prev->next = temp->next;
    free(temp);
}