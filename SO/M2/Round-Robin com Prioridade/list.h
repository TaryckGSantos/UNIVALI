#ifndef LIST_H
#define LIST_H

#include "task.h"

struct node {
    Task *task;
    struct node *next;
};

// insert and delete operations.
void insert(struct node **head, Task *task);
void delete_t(struct node **head, Task *task);
void traverse(struct node *head);

#endif