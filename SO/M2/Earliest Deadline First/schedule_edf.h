#ifndef SCHEDULE_EDF_H
#define SCHEDULE_EDF_H

#include "list.h"
#include "task.h"
#include "CPU.h"

// Declaração das funções de gerenciamento de tarefas e escalonamento
void add(char *name, int priority, int burst, int deadline);
void schedule();
void init_lista_aptos();
void print_lista_aptos();

#endif