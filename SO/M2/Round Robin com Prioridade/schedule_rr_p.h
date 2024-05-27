#ifndef SCHEDULE_RR_P_H
#define SCHEDULE_RR_P_H

#include "list.h"
#include "task.h"
#include "CPU.h"

// Declaração das funções de adicionar, escalonar e inicialização
void add(char *name, int priority, int burst);
void schedule();
void init_lista_aptos();

#endif