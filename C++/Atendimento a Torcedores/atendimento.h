#ifndef ATENDIMENTO_H_INCLUDED
#define ATENDIMENTO_H_INCLUDED

template <typename TIPO>
struct TElementoF{
    TIPO dado;
    TElementoF<TIPO> * proximo;
};

template<typename TIPO>
struct TFila{
    TElementoF<TIPO> * inicio;
    int tamanho;
} ;

template <typename TIPO>
int inicializa_fila(TFila <TIPO> &fila){
    fila.inicio = NULL;
    fila.tamanho = 0;
    ///cout<<endl<<"Fila Inicializada"<<endl;
}

template <typename TIPO>
int tamanho_fila(TFila <TIPO> &fila){
    return fila.tamanho;
}

template <typename TIPO>
int entrar_na_fila(TFila <TIPO> &fila, TIPO dado){
    TElementoF <TIPO> * nav = fila.inicio;
    TElementoF<TIPO> * novo = novo_elemento_fila_de(dado);
    if(fila.inicio != NULL){
        while(nav->proximo != NULL){
            nav = nav->proximo;
        }
        novo->proximo = NULL;
        nav->proximo = novo;
        fila.tamanho++;
    } else {
        novo->proximo = fila.inicio;
        fila.inicio = novo;
        fila.tamanho++;
    }
}

template <typename TIPO>
int atender(TFila <TIPO> &fila){
    TIPO tmp;
    TElementoF <TIPO> * nav = fila.inicio;
    if(nav==NULL){
        //cout<<"\t\tNão há nenhuma pessoa na fila \t\t";
        return false;
    }
    tmp=nav->dado;
    if(nav->proximo == NULL){
        fila.inicio = NULL;
        delete nav;
        fila.tamanho--;
    } else {
        fila.inicio = nav->proximo;
        delete nav;
        fila.tamanho--;
    }
    ///cout<<"\nPessoa do inicio da fila foi removida\t\t\n";
    ///777777imprimir_pFila(tmp);
    return true;
}

template <typename TIPO>
TElementoF<TIPO> * novo_elemento_fila_de(TIPO &dado/*,int carga_inicial*/){
    /*if(carga_inicial==0){
        insere_dados(dado);
    }*/
    TElementoF<TIPO> * novo = new TElementoF<TIPO>;
    novo->dado = dado;
    novo->proximo = NULL;
}

template <typename TIPO>
TIPO primeiro(TFila <TIPO> fila,TIPO dado){
    TElementoF <TIPO> * nav = fila.inicio;
    if(nav!=NULL){
        dado=nav->dado;
        return dado;
    }
}

template<typename TIPO>
bool imprime_fila(TFila<TIPO>fila){
    int i=1;
    TElementoF <TIPO> *nav = fila.inicio;
    if(fila.inicio==NULL){
        cout<<"\n\t\tNão há nenhuma pessoa na fila \t\t"<<endl;
        return false;
    }
    else{
        while(nav!=NULL){
            ///cout<<"\tPosição na Fila: "<<i;
            imprimir_pFila(nav->dado);
            nav=nav->proximo;
            i++;
        }
        return true;
    }
}
#endif // ATENDIMENTO_H_INCLUDED
