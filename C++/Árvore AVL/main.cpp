#include <iostream>
using namespace std;

struct TElemento{
    int dado; 
    int bal;
    int chave;
    TElemento * dir;
    TElemento * esq;
};

struct TArvore{
    TElemento * raiz;
};

void inicializa_arvore(TArvore &arv){
    arv.raiz = NULL;
}

TElemento * novo_no(int aux){
    TElemento novo = new TElemento;
    novo->dado = aux;
    novo->dir = NULL;
    novo->esq = NULL;
    novo->bal = 0;
    return novo;
}

int inserir(TArvore &arv, TElemento *&no, int dado, int chave){
    if(arv.raiz == NULL){
        no = novo_no(dado);
        arv.raiz = no;
        return 1;
    } else {
        if(no == NULL){
            no = novo_no(dado);
            return 1;
        } else {
            if(chave>no->chave){
                int n = inserir(arv, no->dir, dado, chave);
                no->bal = no->bal+n;
            } else {
                inserir(arv, no->esq, dado, chave);
            }
        }
    }
}

template<typename TIPO>
void RR(TElemento *&r){
    TElemento * a = r;
    TElemento * b = a->dir;
    a->dir = b->esq;
    b->esq = a;
    a->bal=0;
    b->bal=0;
    r = b;
}

template<typename TIPO>
void LL(TElemento *&r){
    TElemento * a = r;
    TElemento * b = a->esq;
    a->esq = b->dir;
    b->dir = a;
    b->bal=0;
    a->bal=0;
    r = a;
}

template<typename TIPO>
void RL(TElemento *&r){
    TElemento * a = r;
    TElemento * c = a->dir;
    TElemento * b = c->esq;
    c->esq = b->dir;
    a->dir = b->esq;
    b->esq = a;
    b->dir = c;
    switch(b->bal){
    case -1:
        a->bal = 0;
        c->bal = +1;
        break;
    case 0:
        a->bal = 0;
        c->bal = 0;
        break;
    case 1:
        a->bal = -1;
        c->bal = 0;
        break;
    }
    b->bal = 0;
    r = b;
}

template<typename TIPO>
void LR(TElemento*&r){
    TElemento * a = r;
    TElemento * c = a->esq;
    TElemento * b = c->dir;
    c->dir = b->esq;
    a->esq = b->dir;
    b->dir = a;
    b->esq = c;
    switch(b->bal){
    case -1:
        a->bal = 0;
        c->bal = +1;
        break;
    case 0:
        a->bal = 0;
        c->bal = 0;
        break;
    case 1:
        a->bal = -1;
        c->bal = 0;
        break;
    }
    b->bal = 0;
    r = b;
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
