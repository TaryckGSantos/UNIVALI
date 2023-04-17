#include <iostream>
using namespace std;
#include <windows.h>

#include "arvore.h"

int main()
{
    setlocale(LC_ALL, "Portuguese");

    TArvore arv;
    TNo * no;
    int dado;
    int aux_menu;

    inicializa_arvore(arv);

    cout << "\n\n\t\t\t\tMENU";
    cout << "\n\n\n\t\t1 - Inserir um nó";
    cout << "\n\n\t\t2 - Mostrar arvore\n\n\n\t\t";
    cin >> aux_menu;

    do {
        system("cls");
        cout << "\n\n\t\t\t\tMENU";
        cout << "\n\n\n\t\t1 - Inserir um nó";
        cout << "\n\n\t\t2 - Mostrar arvore\n\n\n\t\t";
        cin >> aux_menu;

        switch (aux_menu){
            case 1:
                system("cls");
                cout << "\n\n\t\tInsira o valor do nó: ";
                cin >> dado;
                insere(arv, no, dado);
                break;

            case 2:
                mostrar_arv(no);
                system("pause>nul");
                break;
        }
    } while (aux_menu != 3);
}
