#include <iostream>
using namespace std;

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
    novo->dir = NULL;
    novo->esq = NULL;
    novo->bal = 0;
    return novo;
}

int inserir (TNo *&no, int dado, int chave){
    int n = 0;
    if(no == NULL){
        no = novo_no(dado, chave);
        return 1;
    } else {
        if(chave > no->chave){
            n = inserir(no->esq, dado, chave);
            if (n == 1){
                no->orientD = HORIZONTAL;
                n++;
            } else {
                if(n == 2 && no->orientD == HORIZONTAL){
                    n = 1;
                    balanceaDir(no, chave);
                } else {
                    n = 0;
                }
            }
        } else {
            if(chave < no->chave){
                n = inserir(no->esq, dado, chave);
            }
            if(n == 1){
                no->orientE = HORIZONTAL;
                n++;
            } else {
                if(n == 2 && no->orientE == HORIZONTAL){
                    n = 1;
                    balanceaEsq(no, chave);
                } else {
                    n = 0;
                }
            }
        }
    }
}


int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
