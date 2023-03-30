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
Elemento<TIPO> * novo_elemento_lista_de(TIPO &dado){

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
        Elemento<TIPO> * novo = novo_elemento_lista_de(dado);
        novo->proximo = NULL;
        nav->proximo = novo;
        lista.tamanho++;
    } else {
        Elemento<TIPO> * novo = novo_elemento_lista_de(dado);
        novo->proximo = lista.inicio;
        lista.inicio = novo;
        lista.tamanho++;
    }
}

template <typename TIPO>
int insere_inicio(TLista <TIPO> &lista, TIPO dado){

    Elemento<TIPO> * novo = novo_elemento_lista_de(dado);
    novo->proximo = lista.inicio;
    lista.inicio = novo;
    lista.tamanho++;
}

template <typename TIPO>
int insere_posicao(TLista <TIPO> &lista, TIPO dado, int &posicao){

    Elemento <TIPO> * nav = lista.inicio;
    int aux = 0;

    if(posicao == 1){
        insere_inicio(lista, dado);
    } else if (posicao == lista.tamanho){
        insere_final(lista, dado);
    } else {
        while(aux < posicao-2 && nav != NULL){
            nav = nav->proximo;
            aux++;
        }
        Elemento<TIPO> * novo = novo_elemento_lista_de(dado);
        novo->proximo = nav->proximo;
        nav->proximo = novo;
        lista.tamanho++;
    }
}

template <typename TIPO>
int remove_fim(TLista <TIPO> &lista){

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

template <typename TIPO>
int remove_inicio(TLista <TIPO> &lista){

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

template <typename TIPO>
int remove_posicao(TLista <TIPO> &lista, TIPO dado, int &posicao_r){

    Elemento <TIPO> * nav = lista.inicio;
    Elemento <TIPO> * p = lista.inicio->proximo;
    int aux = 0;

    if(posicao_r == 1){
       remove_inicio(lista);
    } else {
        while(aux < posicao_r-2){
            nav = nav->proximo;
            p = p->proximo;
            aux++;
        }
        if (p->proximo == NULL){
            nav->proximo = NULL;
        } else {
            nav->proximo = p->proximo;
        }
        delete p;
        lista.tamanho--;
    }
}

template <typename TIPO>
int qtd_lista(TLista <TIPO> &lista){
    return lista.tamanho;
}

template <typename TIPO>
int zera_baralho(TLista <TIPO> &lista){

    Elemento <TIPO> * nav;

    if(lista.inicio == NULL){
        return 1;
    } else {
        while(lista.inicio != NULL){
            nav = lista.inicio;
            lista.inicio = nav->proximo;
            delete nav;
        }
        lista.inicio = NULL;
        lista.tamanho = 0;
    }

}

template <typename TIPO>
int embaralhar(TLista <TIPO> &lista){
    int aux_emb = 0;

    Elemento <TIPO> aux;
    srand(time(NULL));

    while(aux_emb<60){
        Elemento <TIPO> * nav1 = lista.inicio;
        Elemento <TIPO> * nav2 = lista.inicio;

        int aux_pos1 = rand()%52;
        int aux_pos2 = rand()%52;
        int aux_nav1 = 0;
        int aux_nav2 = 0;
        while(aux_nav1 < aux_pos1){
            nav1 = nav1->proximo;
            aux_nav1++;
        }
        while(aux_nav2 < aux_pos2){
            nav2 = nav2->proximo;
            aux_nav2++;
        }
        aux.dado = nav1->dado;
        nav1->dado = nav2->dado;
        nav2->dado = aux.dado;
        aux_emb++;
    }
}

template <typename TIPO>
int ordenar_bubble(TLista <TIPO> &lista){
    TIPO tmp;
    int cond = 1;

    do{
        cond = 0;
        Elemento <TIPO> * nav = lista.inicio;

        while (nav->proximo != NULL
            if(nav->proximo->dado < nav->dado){
                tmp = nav->dado;
                nav->dado = nav->proximo->dado;
                nav->proximo->dado = tmp;
                cond = 1;
            }
            nav = nav->proximo;
        }
    } while (cond != 0);
}

#endif // LISTA_ENC_H_INCLUDED
