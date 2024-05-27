#include <stdio.h>
#include "task.h"

// Executa esta tarefa pelo tempo especificado
void run(Task *task, int slice, int line) {
    // Imprime uma mensagem indicando que a tarefa está sendo executada em tal período
    printf("Running task = [%s] [Priority = %d] [Burst = %d] [Deadline = %d] for %d units no período de %d unidades de tempo\n\n",
    task->name, task->priority, task->burst, task->deadline, slice, line);
}