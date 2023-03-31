#ifndef LISTA_ENC_H_INCLUDED
#define LISTA_ENC_H_INCLUDED

template <typename TIPO>
struct Elemento{ /// Estrutura de elementos
    TIPO dado;
    Elemento<TIPO> * proximo;
};

template <typename TIPO>
struct TLista{ /// Estrutura da lista
    Elemento<TIPO> * inicio;
    int tamanho;
};

template <typename TIPO>
int inicializa_lista(TLista <TIPO> &lista){ /// Fun��o de inicializa��o da lista
    lista.inicio = NULL;
    lista.tamanho = 0;
}

template <typename TIPO>
Elemento<TIPO> * novo_elemento_lista_de(TIPO &dado){ /// Fun��o cria��o de um novo elemento

    Elemento<TIPO> * novo = new Elemento<TIPO>;
    novo->dado = dado;
    novo->proximo = NULL;
}

template <typename TIPO>
int insere_final(TLista <TIPO> &lista, TIPO dado){ /// Fun��o para inserir no final

    Elemento <TIPO> * nav = lista.inicio;

    if(lista.inicio != NULL){ /// Caso n�o seja o primeiro elemento da lista
        while(nav->proximo != NULL){
            nav = nav->proximo;
        }
        Elemento<TIPO> * novo = novo_elemento_lista_de(dado);
        novo->proximo = NULL;
        nav->proximo = novo;
        lista.tamanho++;
    } else { /// Caso seja o primeiro elemento da lista
        Elemento<TIPO> * novo = novo_elemento_lista_de(dado);
        novo->proximo = lista.inicio;
        lista.inicio = novo;
        lista.tamanho++;
    }
}

template <typename TIPO>
int insere_inicio(TLista <TIPO> &lista, TIPO dado){ /// Fun��o para inserir no inicio

    Elemento<TIPO> * novo = novo_elemento_lista_de(dado);
    novo->proximo = lista.inicio;
    lista.inicio = novo;
    lista.tamanho++;
}

template <typename TIPO>
int insere_posicao(TLista <TIPO> &lista, TIPO dado, int &posicao){ /// Fun��o para inserir em uma posi��o espec�fica

    Elemento <TIPO> * nav = lista.inicio;
    int aux = 0;

    if(posicao == 1){ /// caso seja a primeira posi��o
        insere_inicio(lista, dado);
    } else if (posicao == lista.tamanho){ /// caso seja a ultima posi��o
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
int remove_fim(TLista <TIPO> &lista){ /// Fun��o para remover no fim

    Elemento <TIPO> * nav = lista.inicio;
    if(nav->proximo == NULL){ /// caso haja apenas um elemento na lista
        lista.inicio = NULL;
        delete nav;
        lista.tamanho--;
    } else { /// caso haja mais de um elemento na lista
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
int remove_inicio(TLista <TIPO> &lista){ /// Fun��o para remover no in�cio

    Elemento <TIPO> * nav = lista.inicio;
    if(nav->proximo == NULL){ /// caso haja apenas um elemento na lista
        lista.inicio = NULL;
        delete nav;
        lista.tamanho--;
    } else { /// caso haja mais de um elemento na lista
        lista.inicio = nav->proximo;
        delete nav;
        lista.tamanho--;
    }
}

template <typename TIPO>
int remove_posicao(TLista <TIPO> &lista, TIPO dado, int &posicao_r){ /// Fun��o para remover em uma posi��o espec�fica

    Elemento <TIPO> * nav = lista.inicio;
    Elemento <TIPO> * p = lista.inicio->proximo;
    int aux = 0;

    if(posicao_r == 1){  /// caso seja a primeira posi��o
       remove_inicio(lista);
    } else { /// caso n�o seja a primeira posi��o
        while(aux < posicao_r-2){ ///Busca at� uma posi��o anterior a ser deletado
            nav = nav->proximo;
            p = p->proximo;
            aux++;
        }
        if (p->proximo == NULL){ /// caso seja o ultimo elemento
            nav->proximo = NULL;
        } else { /// caso nao seja
            nav->proximo = p->proximo;
        }
        delete p;
        lista.tamanho--;
    }
}

template <typename TIPO>
int qtd_lista(TLista <TIPO> &lista){ /// Retorna a quantidade de elementos na lista
    return lista.tamanho;
}

template <typename TIPO>
int zera_baralho(TLista <TIPO> &lista){ /// Zera todo o conteudo do baralho

    Elemento <TIPO> * nav;

    if(lista.inicio == NULL){ /// caso ja esteja zerado
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
int embaralhar(TLista <TIPO> &lista){ /// embaralha as cartas
    int aux_emb = 0;

    Elemento <TIPO> aux;
    srand(time(NULL));

    while(aux_emb<60){
        Elemento <TIPO> * nav1 = lista.inicio;
        Elemento <TIPO> * nav2 = lista.inicio;

        int aux_pos1 = rand()%lista.tamanho;
        int aux_pos2 = rand()%lista.tamanho;
        int aux_nav1 = 0;
        int aux_nav2 = 0;
        while(aux_nav1 < aux_pos1){ /// enquanto pos ainda for maior que nav, v�o avan�ando de posi��o
            nav1 = nav1->proximo;
            aux_nav1++;
        }
        while(aux_nav2 < aux_pos2){
            nav2 = nav2->proximo;
            aux_nav2++;
        }
        aux.dado = nav1->dado; /// troca de elementos
        nav1->dado = nav2->dado;
        nav2->dado = aux.dado;
        aux_emb++;
    }
}

template <typename TIPO>
int ordenar_bubble(TLista <TIPO> &lista){ /// ordena��o com bubble
    TIPO tmp;
    int cond = 1;

    do{
        cond = 0;
        Elemento <TIPO> * nav = lista.inicio;

        while (nav->proximo != NULL){ /// enquanto nao seja o ultimo elemento
            if(nav->proximo->dado < nav->dado){ /// caso o anterior seja maior que o proximo
                tmp = nav->dado; /// troca de componente
                nav->dado = nav->proximo->dado;
                nav->proximo->dado = tmp;
                cond = 1;
            }
            nav = nav->proximo;
        }
    } while (cond != 0); /// enquanto cond for 1
}


template <typename TIPO>
Elemento<TIPO>* partition(Elemento<TIPO>* head, Elemento<TIPO>* end, Elemento<TIPO>** newHead, Elemento<TIPO>** newEnd) {///a fun��o ir� particionar a lista encadeada em duas partes, primeira parte ser� um grupo de n�meros menorque o pivo e outro ser� com n�meros maiores
    Elemento<TIPO>* pivot = end;
    Elemento<TIPO>* prev = NULL;
    Elemento<TIPO>* cur = head;
    Elemento<TIPO>* tail = pivot;

    while (cur != pivot) {
        if (cur->dado < pivot->dado) { ///Verifica��o do dado da lista, se o dado atual � menor que o dado piv�, caso seja verdade o dado atual � movido a lista de itens menores que o piv�
            if (*newHead == NULL) { ///Verifica��o se o dado � o primeiro da lista
                *newHead = cur;
            }
            prev = cur;
            cur = cur->proximo;
        } else {///Se o elemento for maior, ent�o ele � adicionado na lista de itens maiores que o piv�
            if (prev) {
                prev->proximo = cur->proximo;
            }
            Elemento<TIPO>* tmp = cur->proximo;
            cur->proximo = NULL;///O elemento � removido da lista original e adicionado na lista de itens maiores que o piv�
            tail->proximo = cur;
            tail = cur;
            cur = tmp;
        }
    }

    if (*newHead == NULL) {///Verifica��o da lista menor, se estiver vazia retorna o valor do piv�
        *newHead = pivot;
    }
    *newEnd = tail;
    return pivot;
}

template <typename TIPO>
Elemento<TIPO>* quicksort(Elemento<TIPO>* head, Elemento<TIPO>* fim) {
    if (!head || head == fim) {///Verifica��o do tamanho da lista, se estiver com zero ou um de tamanho retorna o valor de head
        return head;
    }
    Elemento<TIPO>* newHead = NULL;
    Elemento<TIPO>* newEnd = NULL;

    Elemento<TIPO>* pivot = partition(head, fim, &newHead, &newEnd);///

    if (newHead != pivot) {///Caso sejam diferentes a lista ser� dividida
        Elemento<TIPO>* tmp = newHead;
        while (tmp->proximo != pivot) {///Loop do c�digo at� que o pr�ximo valor de tmp seja igual ao piv�
            tmp = tmp->proximo;
        }
        tmp->proximo = NULL;///posi��o que tem como pr�ximo valor, o valor do piv�, que � zerado

        newHead = quicksort(newHead, tmp);///newHead recebe o valor de newHead da fun��o do quicksort com o novo fim, que � um valor antes do piv�

        tmp = getTail(newHead);
        tmp->proximo = pivot;
    }
    pivot->proximo = quicksort(pivot->proximo, newEnd);///O pr�ximo valor de pivot recebe o quicksort com parametros no proximo valor do piv� e do novo fim da lista
    return newHead;
}

template <typename TIPO>
void quicksort_lista(TLista<TIPO>& lista) {
    lista.inicio = quicksort(lista.inicio, getTail(lista.inicio));///A lista recebe o quicksort com parametros do inicio e fim da lista
}

template <typename TIPO>
Elemento<TIPO>* getTail(Elemento<TIPO>* head) {///Fun��o para por em tmp o valor do ultimo item
    Elemento<TIPO>* tmp = head;
    while (tmp != NULL && tmp->proximo != NULL) {
        tmp = tmp->proximo;
    }
    return tmp;
}

#endif // LISTA_ENC_H_INCLUDED
