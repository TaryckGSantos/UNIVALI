/* criação de lista de cartas de poker:

    criação de biblioteca:

        inicializa_baralho(criar uma lista linear vazia)
        insere_carta_final
        remove_cartas_final
        qtd_cartas
        imprime_carta*/

#include <iostream>
#include <stdlib.h>
using namespace std;

const int maximo = 5;

struct Lista{
    int elementos[maximo];
};

int inicializa_baralho(Lista &poker, int &quantidade){
    for(int i=0; i<maximo; i++){
        poker.elementos[i] = 0;
    }
    quantidade = 0;
}

int insere_carta_inicio(Lista &poker, int &quantidade){
    for(int i=quantidade; i>=0; i--){
        poker.elementos[i] = poker.elementos[i-1];
    }
    cout << "\n\n\t\tInsira o valor desejado: ";
    cin >> poker.elementos[0];
    if(poker.elementos[0]>12 || poker.elementos[0]<1){
        system("cls");
        cout << "\n\n\t\tCarta inválida! Insira um valor entre 1 e 12";
        return insere_carta_inicio(poker,quantidade);
    }
    quantidade++;
}

int insere_carta_final(Lista &poker, int &quantidade){
    cout << "\n\n\t\tInsira o valor desejado: ";
    cin >> poker.elementos[quantidade];
    quantidade++;
}

int remove_cartas_final(Lista &poker, int &quantidade){
    if(quantidade==0){
        cout << "\n\n\t\tNenhuma carta inserida :( ";
    } else {
    cout << "\n\n\t\tCarta removida: " << poker.elementos[quantidade-1];
    quantidade--;
    }
}

int qtd_cartas(int &quantidade){
    if(quantidade==0){
        cout << "\n\n\t\tNenhuma carta inserida :( ";
    } else {
    cout << "\n\n\t\tQuantidade de cartas inseridas: " << quantidade;
    }
}

int imprime_carta(Lista &poker, int &quantidade){
    if(quantidade==0){
        cout << "\n\n\t\tNenhuma carta inserida :( ";
    } else {
    cout << "\n\n\t\tCartas já inseridas: ";
    for(int i=0; i<quantidade; i++){
        cout << "\t" << poker.elementos[i] << "\t";
    }
    cout << endl << endl;
    }
}

int main()
{
    setlocale(LC_ALL,"Portuguese");

    int quantidade, aux_menu, select;
    Lista poker;

    inicializa_baralho(poker, quantidade);

    do {
        int aux_menu;

        cout << "\n\n\t\t- Menu -" << endl << endl << endl;
        cout << "\t\tDigite o que você dejesa fazer: " << endl << endl;
        cout << "\t\t1 - Inserir carta no início" << endl;
        cout << "\t\t2 - Inserir carta no final" << endl;
        cout << "\t\t3 - Remover a carta do final" << endl;
        cout << "\t\t4 - Mostrar a quantidade de cartas inseridas no vetor" << endl;
        cout << "\t\t5 - Imprimir cartas inseridas" << endl;
        cout << "\t\t6 - Encerrar a lista" << endl << endl << "\t\t";
        cin >> aux_menu;

        switch(aux_menu){

            case 1:
                system("cls");
                insere_carta_inicio(poker,quantidade);
                system("cls");
                break;

            case 2:
                system("cls");
                insere_carta_final(poker,quantidade);
                system("cls");
                break;
            case 3:
                system("cls");
                remove_cartas_final(poker,quantidade);
                system("pause>nul");

                system("cls");
                break;
            case 4:
                system("cls");
                qtd_cartas(quantidade);
                system("pause>nul");
                system("cls");
                break;
            case 5:
                system("cls");
                imprime_carta(poker,quantidade);
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
