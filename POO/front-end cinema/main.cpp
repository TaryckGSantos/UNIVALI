#include <iostream>
using namespace std;
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <cstring>
#include <string.h>

#include "testes.h"

#define MAX 4
#define MAX_HORAIOS 5

float consulta_horario(filmes vet_filmes[], int &aux){
    float escolha;

    for(int i = 0; i < MAX; i++){
        if(i == aux-1){
            system("cls");
            cout << "\n\t\t\t\t\t----------------------------";
            cout << "\n\t\t\t\t\t|    CINECON - HORÁRIOS    |";
            cout << "\n\t\t\t\t\t----------------------------";
            cout << "\n\n\n\n\t\t\t\t . Horários disponíveis para '" << vet_filmes[i].nome << "' : \n\n\n\n\n\t\t\t";
            for(int j = 0; j < MAX_HORAIOS; j++){
                cout << "   -   " << vet_filmes[i].horarios[j];
            }
            cout << "\n\n\n\t\t\tEscolha um horário: ";
            cin >> escolha;
            for(int j = 0; j < MAX_HORAIOS; j++){
                if(escolha == j){
                    return escolha;
                } else {
                    cout << "\n\n\n\t\t\tNão há nenhum filme neste horário!";
                    return consulta_horario(vet_filmes, aux);
                }
            }
        }
    }
}

int adicionarFilme(){

}

int main()
{
    setlocale(LC_ALL, "Portuguese");

    string select;

    filmes * vet_filmes;
    vet_filmes = new filmes[MAX];

    vet_filmes[0].nome = "Chupa Cu Do Lago Ness";
    vet_filmes[1].nome = "Code Blocks ateu";
    vet_filmes[2].nome = "A Morte De Abel Ferreira";
    vet_filmes[3].nome = "Um Romance Para Taryck";

    vet_filmes[0].horarios[0] = 18.50;
    vet_filmes[0].horarios[1] = 12.35;
    vet_filmes[0].horarios[2] = 11.20;
    vet_filmes[0].horarios[3] = 22.15;

    menu_acesso(vet_filmes);
    return 0;
}
