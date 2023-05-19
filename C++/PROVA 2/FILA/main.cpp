#include <iostream>
using namespace std;

template <typename TIPO>
struct TElemento{
    TIPO dado;
    TElemento<TIPO> * proximo;
};

template <typename TIPO>
struct TFila{
    TElemento<TIPO> * inicio;
    int tamanho;
};

template <typename TIPO>
bool inicializa_fila(TFila<TIPO> &fila){
    fila.inicio = NULL;
    fila.tamanho = 0;
}

template <typename TIPO>
TElemento<TIPO> * criar_elemento(TIPO dado){
    TElemento<TIPO> * novo = new TElemento<TIPO>;
    novo->dado = dado;
    novo->proximo = NULL;
}

template <typename TIPO>
void queue_elemento(TFila<TIPO> &fila, TIPO dado){
    TElemento<TIPO> * nav = fila.inicio;

    if(fila.inicio == NULL){
        TElemento<TIPO> * novo = criar_elemento(dado);
        novo->proximo = NULL;
        fila.inicio = novo;
        fila.tamanho++;
    } else {
        while(nav->proximo != NULL){
            nav = nav->proximo;
        }
        TElemento<TIPO> * novo = criar_elemento(dado);
        novo->proximo = NULL;
        nav->proximo = novo;
        fila.tamanho++;
    }
}

template <typename TIPO>
TIPO dequeue_elemento(TFila<TIPO> &fila){
    TElemento<TIPO> * nav = fila.inicio;
    TIPO aux;

    aux = fila.inicio->dado;
    fila.inicio = nav->proximo;
    delete nav;
    fila.tamanho--;
    return aux;
}

template <typename TIPO>
void mostrar(TFila<TIPO> &fila){
    TElemento<TIPO> * nav = fila.inicio;

    while(nav != NULL){
        cout << " - " << nav->dado;
        nav = nav->proximo;
    }
}

int main()
{
    setlocale(LC_ALL, "Portuguese");

    TFila <int> fila;
    int aux_menu, aux_insere;

    inicializa_fila(fila);

    do{
        system("cls");
        cout << "\n\t\t1. criar um elemento";
        cout << "\n\t\t2. remover um elemento";
        cout << "\n\t\t3. ver elementos\n\t\t";
        cin >> aux_menu;

        if(aux_menu == 1){
            system("cls");
            cout << "\n\t\tInsira o valor que deseja: ";
            cin >> aux_insere;
            queue_elemento(fila, aux_insere);
        } else if (aux_menu == 2){
            system("cls");
            cout << "\n\t\tElemento removido: " << dequeue_elemento(fila);
            system("pause>nul");
        }else if (aux_menu == 3){
            system("cls");
            cout << "\n\t\t";
            mostrar(fila);
            system("pause>nul");
        }
    } while (aux_menu != 4);
    return 0;
}
