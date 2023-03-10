#include <iostream>
using namespace std;
#include <stdlib.h>
#include <time.h>
#include "lista_est_generica.h"
#include "poker.h"

int main(){

    setlocale (LC_ALL ,"Portuguese");

    int aux_menu;
    Lista <cartas, 52> el;
    Elemento <cartas> aux;

    inicializa_lista_gen(el);

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
        cout << "\t\t9 - Remover todas as cartas" << endl;
        cout << "\t\t10 - Encerrar a lista" << endl << endl;
        cout << "\t\tDigite o que você deseja fazer: ";
        cin >> aux_menu;

        switch(aux_menu){

            case 1:
                system("cls");
                menu_inserir(el,aux);
                system("cls");
                break;

            case 2:
                system("cls");
                menu_remover(el,aux);
                system("cls");
                break;

            case 3:
                system("cls");
                mostrar_elementos(el);
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
                qtd_Elemento(el);
                system("pause>nul");
                system("cls");
                break;

            case 6:
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
                break;
        }
    } while(aux_menu != 10);
    return 0;
}
