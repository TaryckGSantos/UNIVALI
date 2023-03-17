#include <iostream>
using namespace std;
#include <stdlib.h>
#include <time.h>

#include "lista_enc.h"
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
        /*cout << "\t\t4 - Buscar alguma carta" << endl;*/
        cout << "\t\t\t5 - Mostrar quantidade de cartas inseridas" << endl;
        /*cout << "\t\t6 - Fazer um baralho completo" << endl;
        cout << "\t\t7 - Embaralhar cartas" << endl;
        cout << "\t\t8 - Ordenar as cartas com Bubble" << endl;
        cout << "\t\t9 - Remover todas as cartas" << endl;*/
        cout << "\t\t\t10 - Encerrar a lista" << endl << endl;
        cout << "\t\t\tDigite o que você deseja fazer: ";
        cin >> aux_menu;

        switch(aux_menu){

            case 1:
                system("cls");
                int aux_menu_inserir;

                cout << endl << endl << endl;
                cout << "\t\t\tEscolha a maneira de inserção: ";
                cout << endl << endl << "\t\t\t1 - Inserir no início";
                cout << endl << "\t\t\t2 - Inserir no final";
                cout << endl <<  "\t\t\t3 - Inserir em uma posição específica" << endl << endl << "\t\t\t";
                cin >> aux_menu_inserir;

                switch (aux_menu_inserir){

                    case 1:
                        aux_inserir(el);
                        insere_inicio(lista, el.dado);
                        break;

                    case 2:
                        aux_inserir(el);
                        insere_final(lista, el.dado);
                        break;

                    case 3:
                        system("cls");
                        int posicao;
                        cout << "\n\n\n\t\t\tEscolha a posição para inserir: ";
                        cin >> posicao;
                        aux_inserir(el);
                        insere_posicao(lista, el.dado, posicao);
                        break;
                }
                system("cls");
                break;

            case 2:
                system("cls");
                int aux_menu_remover;

                cout << endl << endl << endl;
                cout << "\t\t\tEscolha a maneira de remoção: ";
                cout << endl << endl << "\t\t\t1 - Remover no início";
                cout << endl << "\t\t\t2 - Remover no final";
                cout << endl <<  "\t\t\t3 - Remover em uma posição específica" << endl << endl << "\t\t\t";
                cin >> aux_menu_remover;

                switch (aux_menu_remover){

                    case 1:
                        remove_inicio(lista);
                        system("cls");
                        cout << "\n\n\n\t\t\tPrimeiro elemento removido! :) ";
                        system("pause>nul");
                        break;

                    case 2:
                        remove_fim(lista);
                        system("cls");
                        cout << "\n\n\n\t\t\tÚltimo elemento removido! :) ";
                        system("pause>nul");
                        break;

                    case 3:
                        system("cls");
                        int posicao_r;
                        cout << "\n\n\n\t\t\tEscolha a posição para remover: ";
                        cin >> posicao_r;
                        remove_posicao(lista, el.dado, posicao_r);
                        system("cls");
                        cout << "\n\n\n\t\t\tElemento na posição " << posicao_r << " removido! :) ";
                        system("pause>nul");
                        break;
                }
                system("cls");
                break;

            case 3:
                system("cls");
                mostrar_cartas(lista);
                system("pause>nul");
                system("cls");
                break;

            /*case 4:
                system("cls");
                buscar_elementos(el);
                system("pause>nul");
                system("cls");
                break;*/

            case 5:
                system("cls");
                cout << "\n\n\n\t\t\tNúmero de elementos inseridos: " << qtd_lista(lista);
                system("pause>nul");
                system("cls");
                break;

            /*case 6:
                system("cls");
                montar_baralho_poker(el);
                system("pause>nul");
                system("cls");
                break;

            case 7:
                system("cls");
                embaralhar(el);
                system("pause>nul");
                system("cls");
                break;

            case 8:
                system("cls");
                ordenar_bubble(el);
                system("pause>nul");
                system("cls");
                break;

            case 9:
                system("cls");
                zerar_baralho(el);
                system("cls");
                break;

            case 10:
                system("cls");
                cout << "\n\n\t\tLista encerrada! :)" << "\n\n\t\t";
                system("pause>nul");
                exit(0);
                break;*/
        }
    } while(aux_menu != 10);

    mostrar_cartas(lista);
    cout << endl << endl << "chegou aqui";
    /*system("pause>nul");
    remove_fim(lista);*/
    mostrar_cartas(lista);

    return 0;
}
