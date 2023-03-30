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
    el.elementos[el.tamanho] = aux;
    el.tamanho++;
}

template <typename TIPO, int MAX>
int insere_inicio(Lista<TIPO, MAX> &el, Elemento <TIPO> &aux){
    for(int i=el.tamanho; i>=0; i--){
        el.elementos[i] = el.elementos[i-1];
    }
    el.elementos[0] = aux;
    el.tamanho++;
}

template <typename TIPO, int MAX>
int insere_posicao(Lista<TIPO, MAX> &el, Elemento <TIPO> &aux, int aux_posicao){
    for(int i=el.tamanho; i>=aux_posicao; i--){
        el.elementos[i] = el.elementos[i-1];
    }
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
    for(int i = 0; i < el.tamanho and cond == 1; i++){
        cond = 0;
        for(int j = 0; j < el.tamanho-i-1; j++){
            if(el.elementos[j+1].dado < el.elementos[j].dado){
                tmp = el.elementos[j].dado;
                el.elementos[j].dado = el.elementos[j+1].dado;
                el.elementos[j+1].dado = tmp;
                cond = 1;
            }
        }
    }
}

template <typename TIPO, int MAX>
int particao(Lista <TIPO, MAX> &el, int baixo, int alto){
    Elemento<TIPO> pivo = el.elementos[alto];
    int i = (baixo-1);
    Elemento<TIPO> aux_troca;

    for (int j = baixo; j <= alto - 1; j++) {
        if (el.elementos[j].dado < pivo.dado) {
            i++;
            aux_troca = el.elementos[i];
            el.elementos[i] = el.elementos[j];
            el.elementos[j] = aux_troca;
        }
    }
    aux_troca = el.elementos[i+1];
    el.elementos[i+1] = el.elementos[alto];
    el.elementos[alto] = aux_troca;
    return i+1;
}

template <typename TIPO, int MAX>
int ordenar_quick(Lista <TIPO, MAX> &el, int baixo, int alto){
    if(baixo < alto){
        int aux = particao(el, baixo, alto);
        ordenar_quick(el, baixo, aux-1);
        ordenar_quick(el, aux+1, alto);
    }
}

#endif // LISTA_EST_GENERICA_H_INCLUDED
