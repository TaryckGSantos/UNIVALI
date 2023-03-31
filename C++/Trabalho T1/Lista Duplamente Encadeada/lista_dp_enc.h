#ifndef LISTA_DP_ENC_H_INCLUDED
#define LISTA_DP_ENC_H_INCLUDED

template <typename TIPO>
struct Elemento{ ///Declara��o da estrutura do elemento
    TIPO dado;
    Elemento<TIPO> * proximo;
    Elemento<TIPO> * anterior;
};

template <typename TIPO>
struct TLista{ /// Declara��o da estrutura da lista
    Elemento<TIPO> * inicio;
    Elemento<TIPO> * fim;
    int tamanho;
};

template <typename TIPO>
int inicializa_lista(TLista <TIPO> &lista){ ///Inicializando a lista
    lista.inicio = NULL;
    lista.fim = NULL;
    lista.tamanho = 0;
}

template <typename TIPO>
Elemento<TIPO> * novo_elemento_lista_de(TIPO &dado){ /// Fun��o para cria��o de um novo elemento

    Elemento<TIPO> * novo = new Elemento<TIPO>;
    novo->dado = dado;
    novo->proximo = NULL;
    novo->anterior = NULL;
}

template <typename TIPO>
int insere_final(TLista <TIPO> &lista, TIPO dado){ ///Fun��o para inserir no final

    if(lista.tamanho != 0){ /// Caso seja o primeiro elemento que ser� inserido
        Elemento<TIPO> * novo = novo_elemento_lista_de(dado);
        novo->anterior = lista.fim;
        lista.fim->proximo = novo;
        novo->proximo = NULL;
        lista.fim = novo;
        lista.tamanho++;
    } else { /// Caso j� tenha outros elementos
        Elemento<TIPO> * novo = novo_elemento_lista_de(dado);
        lista.inicio = novo;
        lista.fim = novo;
        novo->proximo = NULL;
        novo->anterior = NULL;
        lista.tamanho++;
    }
}

template <typename TIPO>
int insere_inicio(TLista <TIPO> &lista, TIPO dado){ ///Fun��o para inserir no in�cio

    if(lista.tamanho != 0){ /// Caso seja o primeiro elemento que ser� inserido
        Elemento<TIPO> * novo = novo_elemento_lista_de(dado);
        lista.inicio->anterior = novo;
        novo->anterior = NULL;
        novo->proximo = lista.inicio;
        lista.inicio = novo;
        lista.tamanho++;
    } else { /// Caso j� tenha outros elementos
        Elemento<TIPO> * novo = novo_elemento_lista_de(dado);
        lista.inicio = novo;
        lista.fim = novo;
        novo->proximo = NULL;
        novo->anterior = NULL;
        lista.tamanho++;
    }
}

template <typename TIPO>
int insere_posicao(TLista <TIPO> &lista, TIPO dado, int &posicao){ ///Fun��o para inserir em uma posi��o espec�fica

    int aux = 0;
    float aux_nav = 0;

    if(posicao == 1){ /// Caso seja a primeira posi��o
        insere_inicio(lista, dado);
    } else if (posicao == lista.tamanho+1){ /// Caso seja a �ltima posi��o
        insere_final(lista, dado);
    } else {
        aux_nav = ((lista.tamanho)/2)-1;
        if(posicao-1 > aux_nav){ /// Caso esteja antes da metade
            aux = lista.tamanho - 1;
            Elemento <TIPO> * nav = lista.fim;
            Elemento <TIPO> * p = lista.fim->anterior;
            while(aux > posicao-1){
                nav = nav->anterior;
                p = p->anterior;
                aux--;
            }
            Elemento<TIPO> * novo = novo_elemento_lista_de(dado);
            p->proximo = novo;
            novo->proximo = nav;
            lista.tamanho++;
        } else { /// Caso esteja depois da metade
            Elemento <TIPO> * nav = lista.inicio;
            Elemento <TIPO> * p = lista.inicio->proximo;
            while(aux < posicao-1){
                nav = nav->proximo;
                p = p->proximo;
                aux++;
            }
            Elemento<TIPO> * novo = novo_elemento_lista_de(dado);
            p->anterior = novo;
            novo->anterior = nav;
            lista.tamanho++;
        }
    }
}

template <typename TIPO>
int remove_fim(TLista <TIPO> &lista){ /// Fun��o para remover o ultimo elemento

    Elemento <TIPO> * nav = lista.fim;
    if(lista.tamanho == 1){ /// Caso haja apenas 1 elemento
        lista.fim = NULL;
        lista.inicio = NULL;
    } else {
        lista.fim = nav->anterior;
        nav->anterior->proximo = NULL;
    }
    delete nav;
    lista.tamanho--;
}

template <typename TIPO>
int remove_inicio(TLista <TIPO> &lista){ /// Fun��o para remover o primeiro elemento

    Elemento <TIPO> * nav = lista.inicio;
    if(nav->proximo == NULL){ /// Caso haja apenas 1 elemento
        lista.inicio = NULL;
    } else {
        lista.inicio = nav->proximo;
    }
    delete nav;
    lista.tamanho--;
}

template <typename TIPO>
int remove_posicao(TLista <TIPO> &lista, TIPO dado, int &posicao_r){ /// Fun��o para remover um elemento numa posi��o espec�fica

    int aux = 0;
    float aux_nav = 0;

    if(posicao_r == 1){ /// Caso seja a primeira posi��o
        remove_inicio(lista);
    } else if (posicao_r == lista.tamanho){ /// Caso seja a ultima posi��o
        remove_fim(lista);
    } else {
        aux_nav = ((lista.tamanho)/2);
        if(posicao_r-1 > aux_nav){ /// Caso esteja antes da metade
            aux = lista.tamanho - 1;
            Elemento <TIPO> * nav = lista.fim;
            Elemento <TIPO> * p = lista.fim->anterior;
            while(aux > posicao_r-1){
                nav = nav->anterior;
                p = p->anterior;
                aux--;
            }
            Elemento<TIPO> * novo = novo_elemento_lista_de(dado);
            p->proximo = nav->proximo;
            delete nav;
            lista.tamanho--;
        } else { /// Caso esteja depois da metade
            Elemento <TIPO> * nav = lista.inicio;
            Elemento <TIPO> * p = lista.inicio->proximo;
            while(aux < posicao_r-2){
                nav = nav->proximo;
                p = p->proximo;
                aux++;
            }
            Elemento<TIPO> * novo = novo_elemento_lista_de(dado);
            nav->proximo = p->proximo;
            delete p;
            lista.tamanho--;
        }
    }
}

template <typename TIPO>
int qtd_lista(TLista <TIPO> &lista){ /// Fun��o que retorna a quantidade de elementos inseridos
    return lista.tamanho;
}

template <typename TIPO>
int zera_baralho(TLista <TIPO> &lista){ /// Fun��o que exclui o baralho

    Elemento <TIPO> * nav;

    if(lista.tamanho == 0){ /// Caso o tamanho j� seja 0
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
int embaralhar(TLista <TIPO> &lista){ /// Embaralhamento
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
int ordenar_bubble(TLista <TIPO> &lista){ /// Ordenar com bubblesort
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
    } while(cond != 0); /// enquanto cond for 1
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
    lista.inicio = quicksort(lista.inicio, lista.fim);///A lista recebe o quicksort com parametros do inicio e fim da lista
}

template <typename TIPO>
Elemento<TIPO>* getTail(Elemento<TIPO>* head) {///Fun��o para por em tmp o valor do ultimo item
    Elemento<TIPO>* tmp = head;
    while (tmp != NULL && tmp->proximo != NULL) {
        tmp = tmp->proximo;
    }
    return tmp;
}

#endif // LISTA_DP_ENC_H_INCLUDED
