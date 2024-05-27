#include <stdio.h>  
#include "task.h"

// Executa esta tarefa pelo tempo especificado
void run(Task *task, int slice) {
    // Imprime uma mensagem indicando que a tarefa está sendo executada
    printf("Running task = [%s] [%d] [%d] for %d units\n", 
           task->name, task->priority, task->burst, slice);
}