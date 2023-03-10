#ifndef LISTA_ENC_H_INCLUDED
#define LISTA_ENC_H_INCLUDED

template <typename TIPO>
struct Elemento{
    TIPO dado;
    Elemento<TIPO> * proximo;
    int tamanho;
};

template <typename TIPO>
struct TLista{
    Elemento<TIPO> * inicio;
};

template <typename TIPO>
int inicializa_lista(TLista <TIPO> lista){
    lista.inicio = NULL;
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
Elemento<TIPO> * novo_elemento_pista_de(TIPO dado){

    Elemento<TIPO> * novo = new Elemento<TIPO>;
    novo->dado = dado;
    novo->proximo = NULL;

}

template <typename TIPO>
int insere_final(Elemento <TIPO> &lista, TIPO dado){

    Elemento <TIPO> * nav = lista.inicio;

    if(lista.inicio != NULL){
        while(nav->proximo != NULL){
            nav = nav->proximo;
        }
        Elemento<TIPO> * novo = novo_elemento_pista_de(dado);
        preenche_novo(novo);
        novo->proximo = NULL;
        nav->proximo = novo;
    } else {
        Elemento<TIPO> * novo = novo_elemento_pista_de(dado);
        preenche_novo(novo);
        novo->proximo = NULL;
        lista.inicio = novo;
    }
}

#endif // LISTA_ENC_H_INCLUDED
