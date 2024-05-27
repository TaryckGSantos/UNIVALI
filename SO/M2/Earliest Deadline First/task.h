#ifndef TASK_H
#define TASK_H

// Define a struct Task
typedef struct Task {
    char *name;
    int priority;
    int burst;
    int deadline;
} Task;

#endif