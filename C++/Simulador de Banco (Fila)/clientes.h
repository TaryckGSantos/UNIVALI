#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED

struct Clientes{
    string nome;
    int unid_tempo;
};

template <typename TIPO>
struct TElemento{
    TIPO dado;
    TElemento * proximo;
};

template <typename TIPO>
struct TFila{
    TElemento<TIPO> * inicio;
    int cont_clientes;
};

template <typename TIPO>
int inicializa_fila(TFila<TIPO> &fila){
    fila.inicio = NULL;
    fila.cont_clientes = 0;
}

template <typename TIPO>
TElemento<TIPO> * novo_elemento_fila_de(TIPO &dado){

    int aux_aleatorio = 0;
    aux_aleatorio = rand()%9+1;

    TElemento<TIPO> * novo = new TElemento<TIPO>;
    novo->dado = dado;
    novo->proximo = NULL;
    novo->dado.unid_tempo = aux_aleatorio;
}

template <typename TIPO>
int inserir_cliente(TFila<TIPO> &fila, TIPO dado){

    TElemento<TIPO> * nav = fila.inicio;

    if(fila.cont_clientes == 0){
        TElemento<TIPO> * novo = novo_elemento_fila_de(dado);
        novo->proximo = NULL;
        fila.inicio = novo;
        fila.cont_clientes++;
    } else {
        while(nav->proximo != NULL){
            nav = nav->proximo;
        }
        TElemento<TIPO> * novo = novo_elemento_fila_de(dado);
        novo->proximo = NULL;
        nav->proximo = novo;
        fila.cont_clientes++;
    }
}

template <typename TIPO>
int remove_primeiro(TFila<TIPO> &fila){
    TElemento<TIPO> * nav = fila.inicio;
    fila.inicio = nav->proximo;
    delete nav;
    fila.cont_clientes--;
}

template <typename TIPO>
void mostrar_elementos(TFila<TIPO> &fila){
    TElemento<TIPO> aux;
    TElemento <TIPO> * nav = fila.inicio;

    while(nav != NULL){
        aux = *nav;
        cout << endl << endl;
        cout << "Cliente: " << aux.dado.nome << "\t\t | \t\t Quantidade de boletos: " << aux.dado.unid_tempo;
        nav = nav->proximo;
    }
}

template <typename TIPO>
int simulacao(TFila<TIPO> &fila){
    TElemento<TIPO> * nav = fila.inicio;
    cout << endl << endl;
    while(nav->proximo != NULL){
        system("cls");
        mostrar_elementos(fila);
        nav->dado.unid_tempo--;
        if(nav->dado.unid_tempo < 0){
            remove_primeiro(fila);
            nav = nav->proximo;
        }
        system("pause>nul");
    }
    system("cls");
    cout << endl << endl << "\t\t\tFila encerrada!\n\n";
    system("pause>nul");
}

#endif // CLIENTES_H_INCLUDED
