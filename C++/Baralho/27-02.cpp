#include <iostream>
#include <windows.h>
#include <stdlib.h>
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

int preenche_aux(cartas &aux){

    cout << endl << endl << endl << "\t\t\tInsira o número da carta: ";
    cin >> aux.numero;
    if (aux.numero > 13 || aux.numero < 1){
        cout << endl << endl << endl << "\t\t\tInsira apenas cartas de 1 a 13!";
        return preenche_aux(aux);
    }

    cout << endl << endl <<"\t\t\t1 - Copas\n\t\t\t2 - Ouro\n\t\t\t3 - Paus\n\t\t\t4 - Espadas" << "\n\n\t\t\tInsira o naipe da carta: ";
    cin >> aux.naipe;
    if (aux.naipe > 4 || aux.naipe < 1){
        cout << endl << endl << endl << "\t\t\tInsira apenas números de 1 a 4!";
        return preenche_aux(aux);
    }
}

int insere_final(Lista &poker, cartas &aux){

    system("cls");

    preenche_aux(aux);
    poker.elemento[poker.tamanho_baralho] = aux;
    poker.tamanho_baralho++;
}

int insere_inicio(Lista &poker, cartas &aux){

    system("cls");

    for(int i=poker.tamanho_baralho; i>=0; i--){
        poker.elemento[i] = poker.elemento[i-1];
    }

    preenche_aux(aux);
    poker.elemento[0] = aux;
    poker.tamanho_baralho++;
}

int insere_posicao(Lista &poker, cartas &aux){
    int aux_posicao;

    system("cls");

    cout << endl << endl << endl;
    cout << "\t\t\tInsira em qual posição inserir: ";
    cin >> aux_posicao;
    aux_posicao = aux_posicao-1;

    for(int i=poker.tamanho_baralho; i>=aux_posicao; i--){
        poker.elemento[i] = poker.elemento[i-1];
    }
    preenche_aux(aux);
    poker.elemento[aux_posicao] = aux;
    poker.tamanho_baralho++;
}

int menu_inserir(Lista &poker, cartas &aux){
    int aux_menu;

    cout << endl << endl << endl;
    cout << "\t\t\tEscolha a maneira de inserção: ";
    cout << endl << endl << "\t\t\t1 - Inserir no final";
    cout << endl << "\t\t\t2 - Inserir no início";
    cout << endl <<  "\t\t\t3 - Inserir em uma posição específica" << endl << endl << "\t\t\t";
    cin >> aux_menu;

    switch (aux_menu){

        case 1:
            insere_final(poker,aux);
            break;

        case 2:
            insere_inicio(poker,aux);
            break;

        case 3:
            insere_posicao(poker,aux);
            break;
    }
}

int remove_final(Lista &poker){
    poker.tamanho_baralho--;
}

int remove_inicio(Lista &poker){
    for(int i = 0; i < poker.tamanho_baralho; i--){
        
    }
}

int menu_remover(Lista &poker, cartas &aux){
    int aux_menu;

    cout << endl << endl << endl;
    cout << "\t\t\tEscolha a maneira de remoção: ";
    cout << endl << endl << "\t\t\t1 - Remover no final";
    cout << endl << "\t\t\t2 - Remover no início";
    cout << endl <<  "\t\t\t3 - Remover em uma posição específica" << endl << endl << "\t\t\t";
    cin >> aux_menu;

    switch (aux_menu){

        case 1:
            remove_final(poker);
            break;

        case 2:
            insere_inicio(poker,aux);
            break;

        case 3:
            insere_posicao(poker,aux);
            break;
    }
}

int mostrar_elementos(Lista &poker){
    system("cls");

    cout << endl << endl << endl;

    for(int i=0; i<poker.tamanho_baralho; i++){

        switch (poker.elemento[i].naipe){

            case 1:
                cout << "\t\t - " << poker.elemento[i].numero << " | copas" << endl << endl;
                break;

            case 2:
                cout << "\t\t - " << poker.elemento[i].numero << " | ouro" << endl << endl;
                break;

            case 3:
                cout << "\t\t - " << poker.elemento[i].numero << " | paus" << endl << endl;
                break;

            case 4:
                cout << "\t\t - " << poker.elemento[i].numero << " | espadas" << endl << endl;
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
            if (aux_posicao == i){

                switch (poker.elemento[i].naipe){

                    case 1:
                        cout << " - " << poker.elemento[i].numero << " | copas" << endl << endl;
                        break;

                    case 2:
                        cout << " - " << poker.elemento[i].numero << " | ouro" << endl << endl;
                        break;

                    case 3:
                        cout << " - " << poker.elemento[i].numero << " | paus" << endl << endl;
                        break;

                    case 4:
                        cout << " - " << poker.elemento[i].numero << " | espadas" << endl << endl;
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

    setlocale (LC_ALL ,"Portuguese");

    int aux_menu;
    Lista poker;
    cartas aux;

    inicializa_baralho(poker);

    do{
        cout << "\n\n\t\t- Menu -" << endl << endl << endl;
        cout << "\t\t1 - Inserir carta" << endl;
        cout << "\t\t2 - Remover carta" << endl;
        cout << "\t\t3 - Mostrar as cartas inseridas" << endl;
        cout << "\t\t4 - Buscar alguma carta" << endl;
        cout << "\t\t5 - Mostrar quantidade de cartas inseridas" << endl;
        cout << "\t\t6 - Encerrar a lista" << endl << endl;
        cout << "\t\tDigite o que você deseja fazer: ";
        cin >> aux_menu;

        switch(aux_menu){

            case 1:
                system("cls");
                menu_inserir(poker,aux);
                system("cls");
                break;

            case 2:
                system("cls");
                menu_remover(poker,aux);
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
