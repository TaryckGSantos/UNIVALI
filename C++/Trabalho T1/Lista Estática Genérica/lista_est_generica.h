#ifndef LISTA_EST_GENERICA_H_INCLUDED
#define LISTA_EST_GENERICA_H_INCLUDED

template <typename TIPO>
struct Elemento{ /// Estrutura do elemento
    TIPO dado;
};

template <typename TIPO, int MAX>
struct Lista{ /// Estrutura da lista
    Elemento <TIPO> elementos[MAX];
    int tamanho;
};

template <typename TIPO, int MAX>
int inicializa_lista_gen(Lista<TIPO, MAX> &el){ /// Inicialização da lista
    el.tamanho = 0;
}

template <typename TIPO, int MAX>
int insere_final(Lista<TIPO, MAX> &el, Elemento <TIPO> &aux){ /// Inserir final
    el.elementos[el.tamanho] = aux;
    el.tamanho++;
}

template <typename TIPO, int MAX>
int insere_inicio(Lista<TIPO, MAX> &el, Elemento <TIPO> &aux){ /// Inserir inicio
    for(int i=el.tamanho; i>=0; i--){
        el.elementos[i] = el.elementos[i-1];
    }
    el.elementos[0] = aux;
    el.tamanho++;
}

template <typename TIPO, int MAX>
int insere_posicao(Lista<TIPO, MAX> &el, Elemento <TIPO> &aux, int aux_posicao){ /// Inserir numa posição específica
    for(int i=el.tamanho; i>=aux_posicao; i--){
        el.elementos[i] = el.elementos[i-1];
    }
    el.elementos[aux_posicao] = aux;
    el.tamanho++;
}

template <typename TIPO, int MAX>
int remove_final(Lista<TIPO, MAX> &el){ /// remover final
    el.tamanho--;
}

template <typename TIPO, int MAX>
int remove_inicio(Lista<TIPO, MAX> &el){ /// remover inicio
    for(int i = 0; i < el.tamanho; i++){
        el.elementos[i] = el.elementos[i+1];
    }
    el.tamanho--;
}

template <typename TIPO, int MAX>
int remove_posicao(Lista<TIPO, MAX> &el, int aux_posicao){ /// remover numa posição especifica

    for(int i = aux_posicao; i < el.tamanho; i++){
        el.elementos[i] = el.elementos[i+1];
    }
    el.tamanho--;
}

template <typename TIPO, int MAX>
int qtd_Elemento(Lista<TIPO, MAX> &el){ /// Retorna a quantidade de elementos na lista
    return el.tamanho;
}

template <typename TIPO, int MAX>
int zerar_baralho(Lista<TIPO, MAX> &el){  /// Zera a quantidade de elementos
    el.tamanho = 0;
}

template <typename TIPO, int MAX>
int embaralhar(Lista<TIPO, MAX> &el){ /// Embaralha as cartas
    int num1, num2, contagem = 0;
    Elemento <TIPO> aux_troca;

    srand(time(NULL));

    do {
        num1 = rand()%el.tamanho; /// rands com tamanho maximo
        num2 = rand()%el.tamanho;
        aux_troca = el.elementos[num1]; // troca
        el.elementos[num1] = el.elementos[num2];
        el.elementos[num2] = aux_troca;
        contagem++;
    } while (contagem <= 100); /// trocam 100 vezes
}

template <typename TIPO, int MAX>
int ordenar_bubble(Lista <TIPO, MAX> &el){ /// ordenação do bubble
    TIPO tmp;
    int cond = 1;
    for(int i = 0; i < el.tamanho and cond == 1; i++){
        cond = 0;
        for(int j = 0; j < el.tamanho-i-1; j++){
            if(el.elementos[j+1].dado < el.elementos[j].dado){ /// caso o anterior seja maior que o proximo
                tmp = el.elementos[j].dado; /// troca
                el.elementos[j].dado = el.elementos[j+1].dado;
                el.elementos[j+1].dado = tmp;
                cond = 1;
            }
        }
    }
}

template <typename TIPO, int MAX>
int particao(Lista <TIPO, MAX> &el, int baixo, int alto){ /// partição do quick
    Elemento<TIPO> pivo = el.elementos[alto]; /// pivô = alto
    int i = (baixo-1);
    Elemento<TIPO> aux_troca;

    for (int j = baixo; j <= alto - 1; j++) {
        if (el.elementos[j].dado < pivo.dado) { ///caso elemento de j seja maior que o pivô
            i++;
            aux_troca = el.elementos[i]; /// troca o i e o j
            el.elementos[i] = el.elementos[j];
            el.elementos[j] = aux_troca;
        }
    }
    aux_troca = el.elementos[i+1]; /// após troca o i+1 e o alto
    el.elementos[i+1] = el.elementos[alto];
    el.elementos[alto] = aux_troca;
    return i+1;
}

template <typename TIPO, int MAX>
int ordenar_quick(Lista <TIPO, MAX> &el, int baixo, int alto){ /// ordena o quick
    if(baixo < alto){ /// caso o alto seja maior
        int aux = particao(el, baixo, alto); /// particao
        ordenar_quick(el, baixo, aux-1); /// recursividade
        ordenar_quick(el, aux+1, alto);
    }
}

#endif // LISTA_EST_GENERICA_H_INCLUDED
