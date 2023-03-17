#ifndef LISTA_ENC_H_INCLUDED
#define LISTA_ENC_H_INCLUDED

template <typename TIPO>
struct Elemento{
    TIPO dado;
    Elemento<TIPO> * proximo;
};

template <typename TIPO>
struct TLista{
    Elemento<TIPO> * inicio;
    int tamanho;
};

template <typename TIPO>
int inicializa_lista(TLista <TIPO> &lista){
    lista.inicio = NULL;
    lista.tamanho = 0;
}

template <typename TIPO>
Elemento<TIPO> * novo_elemento_pista_de(TIPO &dado){

    Elemento<TIPO> * novo = new Elemento<TIPO>;
    novo->dado = dado;
    novo->proximo = NULL;

}

template <typename TIPO>
int insere_final(TLista <TIPO> &lista, TIPO dado){

    Elemento <TIPO> * nav = lista.inicio;

    if(lista.inicio != NULL){
        while(nav->proximo != NULL){
            nav = nav->proximo;
        }
        Elemento<TIPO> * novo = novo_elemento_pista_de(dado);
        novo->proximo = NULL;
        nav->proximo = novo;
        lista.tamanho++;
    } else {
        Elemento<TIPO> * novo = novo_elemento_pista_de(dado);
        novo->proximo = lista.inicio;
        lista.inicio = novo;
        lista.tamanho++;
    }
}

template <typename TIPO>
int insere_posicao(TLista <TIPO> &lista, TIPO dado, int &posicao){

    Elemento <TIPO> * nav = lista.inicio;
    Elemento <TIPO> * p = lista.inicio->proximo;
    int aux = 0;

    if(posicao-1 > lista.tamanho || posicao-1 < 0){
        cout << "\n\n\n\t\t\tNão há como inserir neste local";
    } else {
        while(aux > posicao-1){
            nav = nav->proximo;
            p = p->proximo;
            aux++;
        }
        Elemento<TIPO> * novo = novo_elemento_pista_de(dado);
        novo->proximo = nav->proximo;//pode ser nav->proximo
        nav->proximo = novo;
        lista.tamanho++;
    }
}

template <typename TIPO>
int insere_inicio(TLista <TIPO> &lista, TIPO dado){

    Elemento<TIPO> * novo = novo_elemento_pista_de(dado);
    novo->proximo = lista.inicio;
    lista.inicio = novo;
    lista.tamanho++;
}

template <typename TIPO>
int remove_fim(TLista <TIPO> &lista){
    if(lista.inicio == NULL){
        cout << "Nenhuma carta inserida! ";
    } else {
        Elemento <TIPO> * nav = lista.inicio;
        if(nav->proximo == NULL){
            lista.inicio = NULL;
            delete nav;
            lista.tamanho--;
        } else {
            Elemento <TIPO> * p = lista.inicio->proximo;
            while(p->proximo != NULL){
                nav = nav->proximo;
                p = p->proximo;
            }
            nav->proximo = NULL;
            delete p;
            lista.tamanho--;
        }
    }
}

template <typename TIPO>
int remove_inicio(TLista <TIPO> &lista){
    if(lista.inicio == NULL){
        cout << "Nenhuma carta inserida! ";
    } else {
        Elemento <TIPO> * nav = lista.inicio;
        if(nav->proximo == NULL){
            lista.inicio = NULL;
            delete nav;
            lista.tamanho--;
        } else {
            lista.inicio = nav->proximo;
            delete nav;
            lista.tamanho--;
        }
    }
}

template <typename TIPO>
int remove_posicao(TLista <TIPO> &lista, TIPO dado, int &posicao_r){

    Elemento <TIPO> * nav = lista.inicio;
    Elemento <TIPO> * p = lista.inicio->proximo;
    int aux = 0;

    if(posicao_r-1 > lista.tamanho || posicao_r-1 < 0){
        cout << "\n\n\n\t\t\tNão há como remover neste local";
    } else {
        while(aux-1 > posicao_r-1){
            nav = nav->proximo;
            p = p->proximo;
            aux++;
        }
        nav->proximo = p->proximo;
        delete p;
        lista.tamanho--;
    }
}

template <typename TIPO>
int qtd_lista(TLista <TIPO> &lista){
    return lista.tamanho;
}

#endif // LISTA_ENC_H_INCLUDED
