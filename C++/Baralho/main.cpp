#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <locale.h>
#define maximo 52
using namespace std;

struct cartas{
    int numero;
    int naipe;
};

struct Lista{
    cartas elemento[maximo];
    int tamanho_baralho;
};

bool inicializa_baralho(Lista &poker){
    poker.tamanho_baralho = 0;

    if (poker.tamanho_baralho == 0){
        return true;
    } else {
        return false;
    }
}

int insere_final(Lista &poker){
    cartas aux;

    system("cls");

    cout << endl << endl << endl << "\t\t\tInsira o número da carta: ";
    cin >> aux.numero;
    cout << endl << endl <<"\t\t\t1 - Copas\n\t\t\t2 - Ouro\n\t\t\t3 - Paus\n\t\t\t4 - Espadas" << "\n\n\t\t\tInsira o naipe da carta: ";
    cin >> aux.naipe;

    poker.elemento[poker.tamanho_baralho] = aux;
    poker.tamanho_baralho++;
}

int remove_final(Lista &poker){
    poker.tamanho_baralho--;
}

int mostrar_elementos(Lista &poker){
    system("cls");

    cout << endl << endl << endl;

    for(int i=0; i<52; i++){

        switch (poker.elemento[i].naipe){

            case 1:
                cout << " - " << poker.elemento[i].numero << " ♥" << endl << endl;
                break;

            case 2:
                cout << " - " << poker.elemento[i].numero << " ♦" << endl << endl;
                break;

            case 3:
                cout << " - " << poker.elemento[i].numero << " ♣" << endl << endl;
                break;

            case 4:
                cout << " - " << poker.elemento[i].numero << " ♠" << endl << endl;
                break;
        }
    }
}

int buscar_elementos(Lista &poker){
    cartas aux;
    int aux_posicao;

    cout << endl << endl << endl << "\t\t\tInsira a posição da carta que quer buscar: ";
    cin >> aux_posicao;

    if (aux_posicao > poker.tamanho_baralho){
        cout << endl << endl << "\t\t\tNão há nenhuma carta nesta posição!";
    } else {
        for (int i=0; i < 52; i++){
            if (aux_posicao == poker.tamanho_baralho){
                switch (poker.elemento[i].naipe){

                    case 1:
                        cout << endl << poker.elemento[i].numero << " ♥" << endl << endl;
                        break;

                    case 2:
                        cout << endl  << poker.elemento[i].numero << " ♦" << endl << endl;
                        break;

                    case 3:
                        cout << endl  << poker.elemento[i].numero << " ♣" << endl << endl;
                        break;

                    case 4:
                        cout << endl  << poker.elemento[i].numero << " ♠" << endl << endl;
                        break;
                }
            }
        }
    }
}

int qtd_cartas(Lista &poker){
    system("cls");

    cout << endl << endl << endl << "\t\t\tQuantidade de cartas inseridas: " << poker.tamanho_baralho << endl << endl;
}

int main(){

    setlocale(LC_ALL,"Portuguese");

    int aux_menu;
    Lista poker;

    inicializa_baralho(poker);

    do{
        cout << "\n\n\t\t- Menu -" << endl << endl << endl;
        cout << "\t\t1 - Inserir carta" << endl;
        cout << "\t\t2 - Remover carta" << endl;
        cout << "\t\t3 - Mostrar as cartas inseridas" << endl;
        cout << "\t\t4 - Buscar alguma carta" << endl;
        cout << "\t\t5 - Mostrar quantidade de cartas inseridas" << endl;
        cout << "\t\t6 - Encerrar a lista" << endl << endl;
        cout << "\t\tDigite o que você dejesa fazer: ";
        cin >> aux_menu;

        switch(aux_menu){

            case 1:
                system("cls");
                insere_final(poker);
                system("cls");
                break;

            case 2:
                system("cls");
                remove_final(poker);
                system("cls");
                break;

            case 3:
                system("cls");
                mostrar_elementos(poker);
                system("pause>nul");
                system("cls");
                break;

            case 4:
                system("cls");
                buscar_elementos(poker);
                system("pause>nul");
                system("cls");
                break;

            case 5:
                system("cls");
                qtd_cartas(poker);
                system("pause>nul");
                system("cls");
                break;

            case 6:
                system("cls");
                cout << "\n\n\t\tLista encerrada! :)" << "\n\n\t\t";
                system("pause>nul");
                exit(0);
                break;
        }
    } while(aux_menu != 6);
    return 0;
}
