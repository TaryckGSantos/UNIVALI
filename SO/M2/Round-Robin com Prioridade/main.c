#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "task.h"
#include "list.h"
#include "schedule_rr_p.h"

#define SIZE 100

int main(int argc, char *argv[]){
    
    FILE *in;
    char *temp;
    char task[SIZE];

    char *name;
    int priority;
    int burst;

    // Open the file in read mode
    in = fopen("tasks.txt", "r"); // replace "input.txt" with your file name
    
    if (in == NULL) {
        printf("Error opening file\n");
        return 1;
    } 

    while (fgets(task,SIZE,in) != NULL) {
        temp = strdup(task);
        name = strsep(&temp,",");
        priority = atoi(strsep(&temp,","));
        burst = atoi(strsep(&temp,","));

        printf("Nome: %s Prioridade: %d Burst: %d\n\n", name, priority, burst);

        // adicionar a task na lista do escalonador
        add(name,priority,burst);

        free(temp);
    }

    fclose(in);
    
    // Invocar o escalonador
    schedule();

    return 0;
}