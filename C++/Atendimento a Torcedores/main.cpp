#include <iostream>
using namespace std;

#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <iostream>

#include "atendimento.h"
#include "torcedor.h"

int main()
{
    srand(time(NULL));
    setlocale(LC_ALL,"Portuguese");

    Torcedor torcedores;
    int select=0,carga_inicial,tempoSim,numGST,numGN,variavel;
    char tecla;

    cout<<"\n\n\t\tQuantidade de Guichês Sócio Torcedor: ";
    cin>>numGST;
    cout<<"\n\n\t\tQuantidade de Guichês Normal: ";
    cin>>numGN;
    cout<<"\n\n\t\tQuantidade de Pessoas que estão aguardando antes do ínicio da simulação(carga inicial): ";
    cin>>carga_inicial;
    ///cout<<"\n\n\t\tQuantidade de Pessoas que procuram os Guichês a cada unidade de Tempo: ";
    ///cin>>;
    ///cout<<"\n\n\t\tQuantidade de Tempo em que o Modelo será 'Simulado': ";
    ///cin>>tempoSim;

    TFila<Torcedor> fila;
    variavel=numGST+numGN;

    TFila<Torcedor> *vet;
    vet = new TFila<Torcedor>[variavel];
    for(int i=0;i<numGST;i++){
        vet[i]=fila;    ///0 é igual a Guichê Sócio Torcedor
    }
    for(int i=0;i<numGN;i++){
                     ///1 é igual a Guichê Normal
    }

    inicializa_fila(fila);
    montar_fila(fila,carga_inicial);

    system("pause>nul");
    system("cls");

    do{
        cout << "\n\n\t\t\t- MENU FILA -" << endl << endl << endl;
        cout << "\t\t\t1 - Inserir Pessoa no Final da Fila" << endl;
        cout << "\t\t\t2 - Remover Pessoa do Inicio da Fila" << endl;
        cout << "\t\t\t3 - Mostrar pessoas na Fila" << endl;
        cout << "\t\t\t4 - Primeira Posição" <<endl;
        cout << "\t\t\t5 - Rodar uma Unidade de Tempo" << endl;
        cout << "\t\t\t6 - Zerar" << endl;
        cout << "\t\t\t7 - Encerrar Programa" << endl;
        select = getch(); // Verifica comando do jogador

        if (select == '1') {
            entrar_na_fila(fila,torcedores,carga_inicial);
            system("pause>nul");
            system("cls");
        } else if (select == '2') {
            atender(fila);
            system("pause>nul");
            system("cls");
        } else if (select == '3') {
            imprime_fila(fila);
            system("pause>nul");
            system("cls");
        } else if (select == '4') {
            primeiro(fila,torcedores);
            system("pause>nul");
            system("cls");
        } else if (select == '5') {
            rodar_tempo(fila);
            cout << "\n\n\tTempo rodado!";
            system("pause>nul");
            system("cls");
        } else if (select == '6') {
            zerar();
            system("pause>nul");
            system("cls");
            break;
        } else if (select == '7') {
            return 0;
        }
    }while(select!=7);
    return 0;
}
