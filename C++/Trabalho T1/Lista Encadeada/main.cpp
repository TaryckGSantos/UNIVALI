///Taryck G. Santos e Thiago Pacheco

#include <iostream>
using namespace std;
#include <stdlib.h>
#include <time.h>

#include "lista_enc.h"
#include "poker.h"

int main()
{
    setlocale(LC_ALL, "Portuguese");

    TLista <cartas> lista; /// declaração da lista
    Elemento<cartas> el; /// declaração de elemento
    cartas dado, au;

    int aux_menu;

    inicializa_lista(lista); /// inicializando a lista

    do{
        cout << "\n\n\t\t\t- Menu -" << endl << endl << endl;
        cout << "\t\t\t1 - Inserir carta" << endl;
        cout << "\t\t\t2 - Remover carta" << endl;
        cout << "\t\t\t3 - Mostrar as cartas" << endl;
        cout << "\t\t\t4 - Buscar alguma carta" << endl;
        cout << "\t\t\t5 - Mostrar quantidade de cartas inseridas" << endl;
        cout << "\t\t\t6 - Fazer um baralho completo" << endl;
        cout << "\t\t\t7 - Embaralhar cartas" << endl;
        cout << "\t\t\t8 - Ordenar as cartas com Bubble" << endl;
        cout << "\t\t\t9 - Ordenar as cartas com Quick" << endl;
        cout << "\t\t\t10 - Remover todas as cartas" << endl;
        cout << "\t\t\t11 - Encerrar a lista" << endl << endl;
        cout << "\t\t\tDigite o que você deseja fazer: ";
        cin >> aux_menu;

        switch(aux_menu){

            case 1:
                system("cls");
                menu_inserir(lista,el);
                break;

            case 2:
                system("cls");
                menu_remover(lista,el);
                break;

            case 3:
                system("cls");
                if(lista.inicio == NULL){ /// caso o baralho esteja zerado
                    cout << "\n\n\n\t\t\tNenhuma carta inserida! ";
                } else {
                    mostrar_cartas(lista);
                }
                system("pause>nul");
                system("cls");
                break;

            case 4:
                system("cls");
                if(lista.tamanho == 0){ /// Caso a lista esteja vazia
                    cout << "\n\n\n\t\t\tNenhuma carta inserida! ";
                } else {
                    int posicao_b;
                    Elemento <cartas> aux;
                    cout << "\n\n\n\t\t\tEscolha a posição para buscar: ";
                    cin >> posicao_b;
                    mostrar_carta_busca(lista, posicao_b);
                }
                system("pause>nul");
                system("cls");
                break;

            case 5:
                system("cls");
                if(lista.tamanho == 0){ /// caso o baralho esteja zerado
                    cout << "\n\n\n\t\t\tNenhum elemento inserido! ";
                } else {
                    cout << "\n\n\n\t\t\tNúmero de elementos inseridos: " << qtd_lista(lista);
                }
                system("pause>nul");
                system("cls");
                break;

            case 6:
                system("cls");
                zera_baralho(lista);
                montar_baralho(lista);
                cout << "\n\n\n\t\t\tBaralho montado! :)";
                system("pause>nul");
                system("cls");
                break;

            case 7:
                embaralhar(lista);
                system("cls");
                cout << "\n\n\n\t\t\tCartas embaralhadas! :)";
                system("pause>nul");
                system("cls");
                break;

            case 8:
                ordenar_bubble(lista);
                system("cls");
                cout << "\n\n\n\t\t\tCartas ordenadas! :)";
                system("pause>nul");
                system("cls");
                break;

            case 9:
                quicksort_lista(lista);
                system("cls");
                cout << "\n\n\n\t\t\tCartas ordenadas! :)";
                system("pause>nul");
                system("cls");
                break;

            case 10:
                if(lista.tamanho == 0){ /// caso o baralho esteja zerado
                    cout << "\n\n\n\t\t\tNenhum elemento na lista! ";
                } else {
                    zera_baralho(lista);
                    system("cls");
                    cout << "\n\n\n\t\t\tTodos os elementos removidos! :)";
                    system("pause>nul");
                    system("cls");
                }
                break;

            case 11:
                system("cls");
                cout << "\n\n\t\tLista encerrada! :)" << "\n\n\t\t";
                system("pause>nul");
                exit(0);
                break;
        }
    } while(aux_menu != 11);
    return 0;
}
