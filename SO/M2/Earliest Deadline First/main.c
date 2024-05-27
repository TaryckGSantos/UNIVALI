#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "task.h"
#include "list.h"
#include "schedule_edf.h"

#define SIZE 100

int main(int argc, char *argv[]){

    // Declaração de variáveis
    FILE *in;
    char *temp;
    char task[SIZE];
    char *name;
    int priority;
    int burst;
    int deadline;

    // Abre o arquivo em modo de leitura
    in = fopen("tasks.txt", "r");

    // Verifica se o arquivo foi aberto corretamente
    if (in == NULL) {
        printf("Error opening file\n");
        return 1;
    } 

    // Lê cada linha do arquivo e adiciona as tarefas à lista de aptos do escalonador
    while (fgets(task,SIZE,in) != NULL) {
        temp = strdup(task);
        name = strsep(&temp,",");
        priority = atoi(strsep(&temp,","));
        burst = atoi(strsep(&temp,","));
        deadline = atoi(strsep(&temp,","));

        // adicionar a task na lista do escalonador
        add(name,priority,burst,deadline);

        free(temp); // Libera a memória alocada para o ponteiro temporário
    }

    fclose(in); // Fecha o arquivo de entrada

    print_lista_aptos(); // Imprime a lista de tarefas aptas

    // Invocar o escalonador
    schedule();

    return 0;
}