#include <iostream>
using namespace std;
#include <stdlib.h>
#include <time.h>

#include "lista_dp_enc.h"
#include "poker.h"

int main()
{
    setlocale(LC_ALL, "Portuguese");

    TLista <cartas> lista;
    Elemento<cartas> el;
    cartas dado, au;

    int cont = 1, aux_menu;

    inicializa_lista(lista);

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
        cout << "\t\t\t9 - Remover todas as cartas" << endl;
        cout << "\t\t\t10 - Encerrar a lista" << endl << endl;
        cout << "\t\t\tDigite o que você deseja fazer: ";
        cin >> aux_menu;

        switch(aux_menu){

            case 1:
                system("cls");
                menu_inserir(lista, el);
                break;

            case 2:
                system("cls");
                menu_remover(lista, el);
                break;

            case 3:
                system("cls");
                if(lista.tamanho == 0){
                    cout << "\n\n\n\t\t\tNenhuma carta inserida! ";
                } else {
                    mostrar_cartas(lista);
                }
                system("pause>nul");
                system("cls");
                break;

            case 4:
                system("cls");
                if(lista.tamanho == 0){
                    cout << "\n\n\n\t\t\tNenhuma carta inserida! ";
                } else {
                    int posicao_b;
                    Elemento <cartas> aux;
                    cout << "\n\n\n\t\t\tEscolha a posição para buscar: ";
                    cin >> posicao_b;
                    mostrar_carta_busca(lista, posicao_b);
                    system("pause>nul");
                    system("cls");
                }
                break;

            case 5:
                if(lista.tamanho == 0){
                    cout << "\n\n\n\t\t\tNenhum elemento inserido! ";
                } else {
                    system("cls");
                    cout << "\n\n\n\t\t\tNúmero de elementos inseridos: " << qtd_lista(lista);
                    system("pause>nul");
                    system("cls");
                }
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
                system("cls");
                ordenar_bubble(lista);
                cout << "\n\n\n\t\t\tLista ordenada! :)";
                system("pause>nul");
                system("cls");
                break;

            case 9:
                if(lista.tamanho == 0){
                    cout << "\n\n\n\t\t\tNenhum elemento na lista! ";
                } else {
                    zera_baralho(lista);
                    system("cls");
                    cout << "\n\n\n\t\t\tTodos os elementos removidos! :)";
                    system("pause>nul");
                    system("cls");
                }
                break;

            case 10:
                system("cls");
                cout << "\n\n\t\tLista encerrada! :)" << "\n\n\t\t";
                system("pause>nul");
                exit(0);
                break;
        }
    } while(aux_menu != 10);

    return 0;
}
