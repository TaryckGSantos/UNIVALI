#ifndef CPU_H
#define CPU_H

#include "task.h"

// Declara a função run, que executa a tarefa especificada pelo tempo fornecido
void run(Task *task, int slice, int deadline);

#endif