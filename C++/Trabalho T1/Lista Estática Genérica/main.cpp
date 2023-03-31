///Taryck G. Santos e Thiago Pacheco

#include <iostream>
using namespace std;
#include <stdlib.h>
#include <time.h>
#include "lista_est_generica.h"
#include "poker.h"

int main(){

    setlocale (LC_ALL ,"Portuguese");

    int aux_menu;
    int cond_verif;
    Lista <cartas, 52> el; /// declaração da lista
    Elemento <cartas> aux;

    inicializa_lista_gen(el); /// inicializando a lista

    do{
        cout << "\n\n\t\t- Menu -" << endl << endl << endl;
        cout << "\t\t1 - Inserir carta" << endl;
        cout << "\t\t2 - Remover carta" << endl;
        cout << "\t\t3 - Mostrar as cartas" << endl;
        cout << "\t\t4 - Buscar alguma carta" << endl;
        cout << "\t\t5 - Mostrar quantidade de cartas inseridas" << endl;
        cout << "\t\t6 - Fazer um baralho completo" << endl;
        cout << "\t\t7 - Embaralhar cartas" << endl;
        cout << "\t\t8 - Ordenar as cartas com Bubble" << endl;
        cout << "\t\t9 - Ordenar as cartas com Quick" << endl;
        cout << "\t\t10 - Remover todas as cartas" << endl;
        cout << "\t\t11 - Encerrar a lista" << endl << endl;
        cout << "\t\tDigite o que você deseja fazer: ";
        cin >> aux_menu;

        switch(aux_menu){

            case 1:
                system("cls");
                menu_inserir(el,aux, cond_verif);
                system("cls");
                break;

            case 2:
                system("cls");
                menu_remover(el,aux);
                system("cls");
                break;

            case 3:
                system("cls");
                mostrar_cartas(el);
                system("pause>nul");
                system("cls");
                break;

            case 4:
                system("cls");
                buscar_elementos(el);
                system("pause>nul");
                system("cls");
                break;

            case 5:
                system("cls");
                if (el.tamanho == 0){ /// caso a lista esteja zerada
                    cout << endl << endl << endl << "\t\t\tNão há nenhum elemento inserido! :( " << endl << endl;
                } else {
                    cout << endl << endl << endl << "\t\t\tQuantidade de Elemento inseridas: " << qtd_Elemento(el) << endl << endl;
                }
                system("pause>nul");
                system("cls");
                break;

            case 6:
                system("cls");
                montar_baralho_poker(el);
                cout << endl << endl << endl << "\t\t\tBaralho montado! :)";
                system("pause>nul");
                system("cls");
                break;

            case 7:
                system("cls");
                embaralhar(el);
                cout << endl << endl << endl << "\t\t\tCartas embaralhadas! :)";
                system("pause>nul");
                system("cls");
                break;

            case 8:
                system("cls");
                ordenar_bubble(el);
                cout << endl << endl << endl << "\t\t\tBaralho ordenado! :)";
                system("pause>nul");
                system("cls");
                break;

            case 9:
                system("cls");
                ordenar_quick(el, 0, el.tamanho-1);
                cout << endl << endl << endl << "\t\t\tBaralho ordenado! :)";
                system("pause>nul");
                system("cls");
                break;

            case 10:
                system("cls");
                zerar_baralho(el);
                cout << endl << endl << endl << "\t\t\tBaralho Excluído! :)";
                system("pause>nul");
                system("cls");
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
