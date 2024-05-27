#ifndef CPU_H
#define CPU_H

// Define o valor do quantum de tempo como 10 unidades
#define QUANTUM 10

#include "task.h"

// Declara a função run, que executa a tarefa especificada pelo tempo fornecido
void run(Task *task, int slice);

#endif