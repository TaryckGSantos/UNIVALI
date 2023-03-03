#include "poker.h"

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
        cout << "\t\t6 - Remover todas as cartas" << endl;
        cout << "\t\t7 - Iniciar o BlackJack" << endl;
        cout << "\t\t8 - Encerrar a lista" << endl << endl;
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
                zerar_baralho(poker);
                system("pause>nul");
                system("cls");
                break;

            case 7:
                system("cls");
                menu_blackjack(poker);
                system("cls");
                break;

            case 8:
                system("cls");
                cout << "\n\n\t\tLista encerrada! :)" << "\n\n\t\t";
                system("pause>nul");
                exit(0);
                break;
        }
    } while(aux_menu != 8);
    return 0;
}
