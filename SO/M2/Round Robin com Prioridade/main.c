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

    // Abrir o arquivo no modo de leitura
    in = fopen("tasks.txt", "r"); 
    
    if (in == NULL) { // Verificar se houve erro na abertura do arquivo
        printf("Error opening file\n");
        return 1;
    } 

    init_lista_aptos(); // Inicializar a lista de tarefas aptas

    while (fgets(task,SIZE,in) != NULL) { // Ler o arquivo linha por linha
        temp = strdup(task); // Copiar a linha para o buffer temporário
        name = strsep(&temp,",");
        priority = atoi(strsep(&temp,","));
        burst = atoi(strsep(&temp,","));

        printf("Nome: %s Prioridade: %d Burst: %d\n\n", name, priority, burst);

        // Adicionar a tarefa na lista do escalonador
        add(name,priority,burst);

        free(temp); // Liberar a memória alocada para o buffer temporário
    }

    fclose(in); // Fechar o arquivo de entrada
    
    // Invocar o escalonador
    schedule();

    return 0;
}