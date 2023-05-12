#ifndef ATENDIMENTO_H_INCLUDED
#define ATENDIMENTO_H_INCLUDED

template <typename TIPO>
struct TElementoF{ // Template de elemento
    TIPO dado;
    TElementoF<TIPO> * proximo;
};

template<typename TIPO>
struct TFila{ // Template da fila
    TElementoF<TIPO> * inicio;
    int tamanho;
};

template <typename TIPO>
int inicializa_fila(TFila <TIPO> &fila){ // Função de inicialização da fila
    fila.inicio = NULL;
    fila.tamanho = 0;
}

template <typename TIPO>
int entrar_na_fila(TFila <TIPO> &fila, TIPO dado){ // Função de entrar na fila
    TElementoF <TIPO> * nav = fila.inicio; // Nav = inicio da fila
    TElementoF<TIPO> * novo = novo_elemento_fila_de(dado); // Declaração de novo elemento
    if(fila.inicio != NULL){ // Caso não seja o primeiro elemento a ser inserido
        while(nav->proximo != NULL){ // Navegação para o ultimo elemento
            nav = nav->proximo;
        }
        novo->proximo = NULL; // o novo aponta pra null
        nav->proximo = novo; // Nav aponta pro novo
        fila.tamanho++; // tamanho da fila aumenta
    } else { // caso seja o primeiro a ser inserido
        novo->proximo = fila.inicio; // novo aponta pra null
        fila.inicio = novo; // o inicio da fila = novo
        fila.tamanho++; // tamanho da fila aumenta
    }
}

template <typename TIPO>
TIPO atender(TFila <TIPO> &fila){ // Função para retirada do torcedor com 0 de tempo
    TIPO tmp; // variavel auxiliar
    TElementoF <TIPO> * nav = fila.inicio; // criação de nav = primeiro elemento
    if(nav->proximo == NULL){ // caso só haja 1 elemento na fila
        tmp=nav->dado; // variavel auxiliar recebe o dado de nav
        fila.inicio = NULL; // inicio da fila = null
        delete nav; // remoção de nav
        fila.tamanho--; // diminuição do tamanho da fila
        return tmp; // retorno dos dados
    } else { // caso não seja o unico elemento
        tmp=nav->dado; // variavel auxiliar recebe o dado de nav
        fila.inicio = nav->proximo; // inicio da fila = segundo elemento
        delete nav; // remoção de nav
        fila.tamanho--; // diminuição do tamanho da fila
        return tmp; // retorno dos dados
    }
}

template <typename TIPO>
TIPO * primeiro(TFila <TIPO> &fila){ // Função para retirada do torcedor com 0 de tempo
    if(fila.inicio==NULL){
        return NULL;
    } else {
        return &(fila.inicio->dado);
    }
}

template <typename TIPO>
TElementoF<TIPO> * novo_elemento_fila_de(TIPO &dado){ // criação de um novo elemento
    TElementoF<TIPO> * novo = new TElementoF<TIPO>; // novo ponteiro de TElementoF
    novo->dado = dado; // recebe o dado que veio por parametro
    novo->proximo = NULL; // aponta pra NULL
}

#endif // ATENDIMENTO_H_INCLUDED
