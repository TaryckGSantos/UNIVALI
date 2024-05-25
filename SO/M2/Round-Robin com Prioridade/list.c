#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "list.h"
#include "task.h"

void insert(struct node **head, Task *task) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->task = task;
    new_node->next = *head;
    *head = new_node;
}

// Remove a tarefa selecionada da lista
void delete_t(struct node **head, Task *task) {
    struct node *temp = *head;
    struct node *prev = NULL;

    if (temp != NULL && strcmp(task->name, temp->task->name) == 0) {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && strcmp(task->name, temp->task->name) != 0) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;

    prev->next = temp->next;
    free(temp);
}

// traverse the list
void traverse(struct node *head) {
    struct node *temp;
    temp = head;

    while (temp != NULL) {
        printf("[%s] [%d] [%d]\n",temp->task->name, temp->task->priority, temp->task->burst);
        temp = temp->next;
    }
}