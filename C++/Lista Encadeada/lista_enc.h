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
int inicializa_lista(TLista <TIPO> lista){
    lista.inicio = NULL;
    lista.tamanho = 0;
}

template <typename TIPO>
Elemento<TIPO> * novo_elemento_pista_de(TIPO dado){

    Elemento<TIPO> * novo = new Elemento<TIPO>;
    novo->dado = dado;
    novo->proximo = NULL;

}

template <typename TIPO>
int preenche_aux(Elemento<TIPO> &aux){

    cout << endl << endl << endl << "\t\t\tInsira o número da carta: ";
    cin >> aux->dado->numero;
    if (aux->dado->numero > 13 || aux->dado->numero < 1){
        cout << endl << endl << endl << "\t\t\tInsira apenas cartas de 1 a 13!";
        return novo_elemento_pista_de(aux);
    }

    cout << endl << endl <<"\t\t\t1 - Copas\n\t\t\t2 - Ouro\n\t\t\t3 - Paus\n\t\t\t4 - Espadas" << "\n\n\t\t\tInsira o naipe da carta: ";
    cin >> aux->dado->naipe;
    if (aux->dado->naipe > 4 || aux.dado->naipe < 1){
        cout << endl << endl << endl << "\t\t\tInsira apenas números de 1 a 4!";
        return novo_elemento_pista_de(aux);
    }
}

template <typename TIPO>
int insere_final(TLista <TIPO> &lista, TIPO dado){

    Elemento <TIPO> * nav = lista.inicio;

    if(lista.inicio != NULL){
        while(nav->proximo != NULL){
            nav = nav->proximo;
        }
        Elemento<TIPO> * novo = novo_elemento_pista_de(dado);
        novo->proximo = nav->proximo;
        nav->proximo = novo;
    } else {
        Elemento<TIPO> * novo = novo_elemento_pista_de(dado);
        novo->proximo = lista.inicio;
        lista.inicio = novo;
    }
}

template <typename TIPO>
int insere_inicio(TLista <TIPO> &lista, TIPO dado){
    
    if(lista.inicio == NULL){
        Elemento<TIPO> * novo = novo_elemento_pista_de(dado);
        lista.inicio = novo;
    } else {
        Elemento<TIPO> * novo = novo_elemento_pista_de(dado);
        novo->proximo = lista.inicio;
        lista.inicio = novo;
    }
}

template <typename TIPO>
int insere_inicio(TLista <TIPO> &lista, TIPO dado){

    Elemento<TIPO> * novo = novo_elemento_pista_de(dado);
    novo->proximo = lista.inicio;
    lista.inicio = novo;
    lista.tamanho = lista.tamanho + 1;
}

template <typename TIPO>
bool remove_fim(TLista <TIPO> &lista){
    if(lista.inicio == NULL){
        return false;
    } else {
        Elemento <TIPO> * nav = lista.inicio;
        if(nav->proximo == NULL){
            lista.inicio = nav->proximo;
            delete nav;
            return true;
        } else {
            Elemento <TIPO> * p = lista.inicio->proximo;
            while(p->proximo != NULL){
                nav = nav->proximo;
                p = p->proximo;
            }
            nav->proximo = NULL;
            delete p;
            return true;
        }
    }
}

#endif // LISTA_ENC_H_INCLUDED
