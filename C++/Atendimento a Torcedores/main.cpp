#include <iostream>
using namespace std;
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include "Atendimento.h"
#include "Torcedor.h"


int main()
{
    srand(time(NULL));
    setlocale(LC_ALL,"Portuguese");

    Torcedor torcedores;
    int select=0,carga_inicial,tempoSim,numGST,numGN,cont=0,qtdpTEMP,ins,auxEntrarN=0,auxEntrarS=0;;

    cout<<"\n\n\t\tQuantidade de Guichês Sócio Torcedor: ";
    cin>>numGST;
    cout<<"\n\n\t\tQuantidade de Guichês Normal: ";
    cin>>numGN;
    cout<<"\n\n\t\tQuantidade de Pessoas que estão aguardando antes do ínicio da simulação(carga inicial): ";
    cin>>carga_inicial;
    cout<<"\n\n\t\tQuantidade de Pessoas que procuram os Guichês a cada unidade de Tempo: ";
    cin>>qtdpTEMP;
    cout<<"\n\n\t\tQuantidade de Tempo em que o Modelo será 'Simulado': ";
    cin>>tempoSim;
    ins=qtdpTEMP;
    TFila<Torcedor> fila;

    ///CRIAÇÃO DAS FILAS SÓCIO TORCEDOR
    TFila<Torcedor> *filaST;
    filaST = new TFila<Torcedor>[numGST];

    for(int i=0;i<numGST;i++){
        filaST[i]=fila;
    }

    for(int i=0;i<numGST;i++){
        inicializa_fila(filaST[i]);
    }

    ///CRIAÇÃO DAS FILAS NORMAIS
    TFila<Torcedor> *filaN;
    filaN = new TFila<Torcedor>[numGN];

    for(int i=0;i<numGN;i++){
        filaN[i]=fila;
    }

    for(int i=0;i<numGN;i++){
        inicializa_fila(filaN[i]);
    }

    ///MONTAR AS FILAS
    int auxST,auxN;
    auxST=carga_inicial/20;
    auxN=carga_inicial-auxST;
    cout<<"\nauxST: "<<auxST;
    cout<<"\nauxN: "<<auxN;

    while(auxST!=0){
        if(cont==numGST){
            cont=0;
        }
        montar_filaST(filaST[cont],torcedores,auxST);
        entrar_na_fila(filaST[cont],torcedores);
        cont++;
    }
    cont=0;
    while(auxN!=0){
        if(cont==numGN){
            cont=0;
        }
        montar_filaN(filaN[cont],torcedores,auxN);
        entrar_na_fila(filaN[cont],torcedores);
        cont++;
    }
    cont=0;
    system("cls");
    do{
        cout << "\n\n\t\t\t- MENU FILA -\t\t\t\tTempo: "<<tempoSim << endl << endl << endl;
        cout << "\t\t\t1 - Inserir Pessoa no Final da Fila" << endl;
        cout << "\t\t\t2 - Mostrar pessoas na Fila" << endl;
        cout << "\t\t\t3 - Primeira Posição" <<endl;
        cout << "\t\t\t4 - Rodar uma Unidade de Tempo" << endl;
        cout << "\t\t\t5 - Zerar" << endl;
        cout << "\t\t\t6 - Simular 1 Tempo" << endl;
        cout << "\t\t\t7 - Encerrar Programa" << endl;
        select = getch(); // Verifica comando do jogador

        if (select == '1') {
            qtdpTEMP=ins;
            while(qtdpTEMP!=0){
                if(cont%20==0){
                    montar_filaST(filaST[auxEntrarS],torcedores,qtdpTEMP);
                    entrar_na_fila(filaST[auxEntrarS],torcedores);
                    auxEntrarS++;
                    if(auxEntrarS==numGST){
                        auxEntrarS=0;
                    }
                }
                else{
                    montar_filaN(filaN[auxEntrarN],torcedores,qtdpTEMP);
                    entrar_na_fila(filaN[auxEntrarN],torcedores);
                    auxEntrarN++;
                    if(auxEntrarN==numGN){
                        auxEntrarN=0;
                    }
                }
                cont++;
            }
            system("pause>nul");
            system("cls");
       } else if (select == '2') {
            for(int i=0;i<numGST;i++){
                cout<<"\nGuichê Sócio-Torcedor "<<i+1<<": \n\n";
                imprime_fila(filaST[i]);
            }
            for(int i=0;i<numGN;i++){
                cout<<"\nGuichê Normal "<<i+1<<": \n\n";
                imprime_fila(filaN[i]);
            }
            system("pause>nul");
            system("cls");
       } else if (select == '3') {
            for(int i=0;i<numGST;i++){
                cout<<"\nGuichê Sócio-Torcedor "<<i+1<<": \n";
                imprimir_pFila(filaST[i].inicio->dado);
            }
            for(int i=0;i<numGN;i++){
                cout<<"\nGuichê Normal "<<i+1<<": \n";
                imprimir_pFila(filaN[i].inicio->dado);
            }
            system("pause>nul");
            system("cls");
       } else if (select == '4') {
            for(int i=0;i<numGST;i++){
                rodar_tempo(filaST[i]);
            }
            for(int i=0;i<numGN;i++){
                rodar_tempo(filaN[i]);
            }
            system("pause>nul");
            system("cls");
       } else if (select == '5') {
            for(int i=0;i<numGN;i++){
                zerar(filaN[i]);
            }
            for(int i=0;i<numGST;i++){
                zerar(filaST[i]);
            }
            system("pause>nul");
            system("cls");
            ///numGST=0;
            ///numGN=0;
       } else if (select == '6') {
            system("cls");
            qtdpTEMP=ins;
            while(qtdpTEMP!=0){
                if(cont%20==0){
                    montar_filaST(filaST[auxEntrarS],torcedores,qtdpTEMP);
                    entrar_na_fila(filaST[auxEntrarS],torcedores);
                    auxEntrarS++;
                    if(auxEntrarS==numGST){
                        auxEntrarS=0;
                    }
                }
                else{
                    montar_filaN(filaN[auxEntrarN],torcedores,qtdpTEMP);
                    entrar_na_fila(filaN[auxEntrarN],torcedores);
                    auxEntrarN++;
                    if(auxEntrarN==numGN){
                        auxEntrarN=0;
                    }
                }
                cont++;
            }
            for(int i=0;i<numGST;i++){
                cout<<"\nGuichê Sócio-Torcedor "<<i+1<<": \n";
                imprime_fila(filaST[i]);
            }
            for(int i=0;i<numGN;i++){
                cout<<"\nGuichê Normal "<<i+1<<": \n";
                imprime_fila(filaN[i]);
            }
            for(int i=0;i<numGST;i++){
                rodar_tempo(filaST[i]);
            }
            for(int i=0;i<numGN;i++){
                rodar_tempo(filaN[i]);
            }
            system("pause>nul");
            system("cls");
        } else if (select == '7') {
            system("cls");
            cout << "\n\n\t\tPrograma encerrado!";
            system("pause>nul");
            exit(0);
        } else {
           system("cls");
           cout << "\n\n\t\tPressione apenas os números de 1 a 7!";
           system("pause>nul");
           system("cls");
           tempoSim++;
        }
        tempoSim--;
    }while(select!=7 && tempoSim!=0);
    return 0;
}
