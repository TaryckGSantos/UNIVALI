#ifndef LIST_H
#define LIST_H

#include "task.h"

// Define a estrutura node para a lista encadeada
struct node {
    Task *task;  // Ponteiro para uma tarefa
    struct node *next;  // Ponteiro para o próximo nó na lista
};

// insert and delete operations.
void insert(struct node **head, Task *task);
void delete_t(struct node **head, Task *task);

#endif