#ifndef LISTA_EST_GENERICA_H_INCLUDED
#define LISTA_EST_GENERICA_H_INCLUDED

template <typename TIPO>
struct Elemento{
    TIPO dado;
};

template <typename TIPO, int MAX>
struct Lista{
    Elemento <TIPO> elementos[MAX];
    int tamanho;
};

template <typename TIPO, int MAX>
int inicializa_lista_gen(Lista<TIPO, MAX> &el){
    el.tamanho = 0;
}

template <typename TIPO, int MAX>
int insere_final(Lista<TIPO, MAX> &el, Elemento <TIPO> &aux){

    preenche_aux(aux);
    verifica_insercao(el,aux);
    el.elementos[el.tamanho] = aux;
    el.tamanho++;
}

template <typename TIPO, int MAX>
int insere_inicio(Lista<TIPO, MAX> &el, Elemento <TIPO> &aux){

    for(int i=el.tamanho; i>=0; i--){
        el.elementos[i] = el.elementos[i-1];
    }

    preenche_aux(aux);
    verifica_insercao(el,aux);
    el.elementos[0] = aux;
    el.tamanho++;
}

template <typename TIPO, int MAX>
int insere_posicao(Lista<TIPO, MAX> &el, Elemento <TIPO> &aux, int aux_posicao){

    for(int i=el.tamanho; i>=aux_posicao; i--){
        el.elementos[i] = el.elementos[i-1];
    }
    preenche_aux(aux);
    verifica_insercao(el,aux);
    el.elementos[aux_posicao] = aux;
    el.tamanho++;
}

template <typename TIPO, int MAX>
int remove_final(Lista<TIPO, MAX> &el){
    el.tamanho--;
}

template <typename TIPO, int MAX>
int remove_inicio(Lista<TIPO, MAX> &el){
    for(int i = 0; i < el.tamanho; i++){
        el.elementos[i] = el.elementos[i+1];
    }
    el.tamanho--;
}

template <typename TIPO, int MAX>
int remove_posicao(Lista<TIPO, MAX> &el, int aux_posicao){

    for(int i = aux_posicao; i < el.tamanho; i++){
        el.elementos[i] = el.elementos[i+1];
    }
    el.tamanho--;
}

template <typename TIPO, int MAX>
int qtd_Elemento(Lista<TIPO, MAX> &el){
    return el.tamanho;
}

template <typename TIPO, int MAX>
int zerar_baralho(Lista<TIPO, MAX> &el){
    el.tamanho = 0;
}

template <typename TIPO, int MAX>
int embaralhar(Lista<TIPO, MAX> &el){
    int num1, num2, contagem = 0;
    Elemento <TIPO> aux_troca;

    srand(time(NULL));

    do {
        num1 = rand()%52;
        num2 = rand()%52;
        aux_troca = el.elementos[num1];
        el.elementos[num1] = el.elementos[num2];
        el.elementos[num2] = aux_troca;
        contagem++;
    } while (contagem <= 100);
}

template <typename TIPO, int MAX>
int ordenar_bubble(Lista <TIPO, MAX> &el){
    TIPO tmp;
    int cond = 1;
    for(int i = el.tamanho; i>= 1 and cond == 1; i--){
        cond = 0;
        for(int j = 0; j < i; j++){
            if(el.elementos[j+1].dado < el.elementos[j].dado){
                tmp = el.elementos[j+1].dado;
                el.elementos[j+1].dado = el.elementos[j].dado;
                el.elementos[j].dado = tmp;
                cond = 1;
            }
        }
    }
}

/*template <typename TIPO, int MAX>
int comparador(int a, int b){
    return
}

template <typename TIPO, int MAX>
int particao(Lista <TIPO, MAX> &el, int inicio, int fim){

    TIPO aux_1 = el.elementos[inicio].dado;
    int cont = 0;

    for(int i = inicio + 1; i <= fim; i++){
        if(el.elementos[inicio].dado <= aux_1){
            cont++;
        }
    }

    int aux_indice = inicio + cont;

    TIPO tmp;
    tmp = el.elementos[aux_indice].dado;
    el.elementos[aux_indice].dado = el.elementos[inicio].dado;
    el.elementos[inicio].dado = tmp;

    int i = inicio; j = fim;

    while( i < )
}

template <typename TIPO, int MAX>
int ordenar_bubble(Lista <TIPO, MAX> &el){
    TIPO tmp;

}*/

#endif // LISTA_EST_GENERICA_H_INCLUDED
