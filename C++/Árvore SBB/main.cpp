#include <iostream>
using namespace std;

#include <windows.h>

const char VERTICAL = 'v';
const char HORIZONTAL = 'h';

struct TNo{
    int chave;
    int dado;
    TNo * dir;
    char orientD;
    TNo * esq;
    char orientE;
};

struct TArvore{
    TNo * raiz;
};

void inicializa_arvore(TArvore &arv){
    arv.raiz = NULL;
}

TNo * novo_no(int dado, int chave){
    TNo * novo = new TNo;
    novo->dado = dado;
    novo->chave = chave;
    novo->orientD = NULL;
    novo->orientE = NULL;
    novo->dir = NULL;
    novo->esq = NULL;
    return novo;
}

void RR(TNo *&ap){
    TNo * ap1 = ap->dir;
    ap->dir = ap1->esq;
    ap1->esq = ap;
    ap1->orientD = VERTICAL;
    ap->orientD = VERTICAL;
    ap = ap1;
}

void LL(TNo *&ap){
    TNo * ap1 = ap->esq;
    ap->esq = ap1->dir;
    ap1->dir = ap;
    ap1->orientE = VERTICAL;
    ap->orientE = VERTICAL;
    ap = ap1;
}

void RL(TNo *&ap){
    TNo * ap1 = ap->dir;
    TNo * ap2 = ap1->esq;
    ap1->orientE = VERTICAL;
    ap->orientD = VERTICAL;
    ap1->esq = ap2->dir;
    ap2->dir = ap1;
    ap->dir = ap2->esq;
    ap2->esq = ap;
    ap = ap2;
}

void LR(TNo *&ap){
    TNo * ap1 = ap->esq;
    TNo * ap2 = ap1->dir;
    ap1->dir = ap2->esq;
    ap->esq = ap2->dir;
    ap2->esq = ap1;
    ap2->dir = ap;
    ap1->orientD = VERTICAL;
    ap->orientE = VERTICAL;
    ap = ap2;
}

int inserir (TNo *&no, int dado, int chave){
    int n = 0;
    if(no == NULL){
        no = novo_no(dado, chave);
        return 1;
    } else if(chave > no->chave){
        n = inserir(no->dir, dado, chave);
        if (n == 1){
            no->orientD = HORIZONTAL;
            n++;
        } else {
            if(n == 2 && no->orientD == HORIZONTAL){
                n = 1;
                if(no->dir->orientD == HORIZONTAL){
                    RR(no);
                } else {
                    RL(no);
                }
            } else {
                n = 0;
            }
        }
    } else if(chave < no->chave){
        n = inserir(no->esq, dado, chave);
        if(n == 1){
            no->orientE = HORIZONTAL;
            n++;
        } else {
            if(n == 2 && no->orientE == HORIZONTAL){
                n = 1;
                if(no->esq->orientE == HORIZONTAL){
                    LL(no);
                } else {
                    LR(no);
                }
            }
        }
    }
    return n;
}

void mostrar_arv(TNo * no) {
    if (no == NULL) {
        return;
    }

    mostrar_arv(no->esq);

    if(no->orientE == VERTICAL){
        cout << " | ";
    } else if (no->orientE == HORIZONTAL){
        cout << " - ";
    }

    cout << no->chave;

    if(no->orientD == VERTICAL){
        cout << " | ";
    } else if (no->orientD == HORIZONTAL){
        cout << " - ";
    }

    mostrar_arv(no->dir);
}

int main()
{
    TArvore arv;

    inicializa_arvore(arv);

    int insere, i = 0;

    while(i < 50){
        system("cls");
        cout << "\t\tValor a ser inserido: ";
        cin >> insere;
        inserir(arv.raiz, insere, insere);
        cout << "\n\n\n\n";
        mostrar_arv(arv.raiz);
        system("pause>nul");
        i++;
    }

    return 0;
}
