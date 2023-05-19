#include <iostream>
using namespace std;

struct TNo{
    int dado;
    TNo * direita;
    TNo * esquerda;
};

struct TArvore{
    TNo * raiz;
};

int inicializa_arv(TArvore &arv){
    arv.raiz = NULL;
}

void inserir(TArvore &arv, TNo *&no, int dado){
    if(arv.raiz == NULL){
        no = new TNo;
        no->dado = dado;
        no->direita = NULL;
        no->esquerda = NULL;
        arv.raiz = no;
    } else {
        if(no == NULL){
            no = new TNo;
            no->dado = dado;
            no->direita = NULL;
            no->esquerda = NULL;
        } else {
            if(dado > no->dado){
                inserir(arv, no->direita, dado);
            } else if (dado < no->dado){
                inserir(arv, no->esquerda, dado);
            } else {
                cout << "\n\n\n\t\t\tJá existe um nó com esse dado!";
            }
        }
    }
}

void mostrar_arv(TNo *no){
    if(no == NULL){
        return;
    }

    cout << no->dado << " - ";

    mostrar_arv(no->esquerda);

    mostrar_arv(no->direita);
}

int main()
{
    setlocale(LC_ALL, "Portuguese");

    TArvore arv;
    TNo * no;
    int aux_menu, aux_insere;

    inicializa_arv(arv);

    do{
        system("cls");
        cout << "\n\t\t1. criar um elemento";
        cout << "\n\t\t2. ver elementos\n\t\t";
        cin >> aux_menu;

        if(aux_menu == 1){
            system("cls");
            cout << "\n\t\tInsira o valor que deseja: ";
            cin >> aux_insere;
            inserir(arv, no, aux_insere);
        } else if (aux_menu == 2){
            system("cls");
            mostrar_arv(arv.raiz);
            system("pause>nul");
        }
    } while (aux_menu != 4);
    return 0;
}
