#include <iostream>
using namespace std;
#include <windows.h>

#define M 2

struct TNo{
    int chave;
    int dado;
};

struct TPag{
    TNo * comp[2*M];
    int qtd_comp;
    TPag * filho[2*M+1];
    int qtd_filhos;
};

struct TArv{
    TPag * raiz;
};

void inicializa(TArv &arv){
    arv.raiz = NULL;
}

TPag * 

int insere(TPag *&pag, int dado, int chave){
    if(pag == NULL){
        pag->comp = new TNo[2*M];
        pag->comp[0].chave = chave;
        pag->comp[0].dado = dado;
    } else {
        return 0;
    }
}

int main()
{
    setlocale(LC_ALL, "Portuguese");

    TArv arv;

    int dado;

    inicializa(arv);

    cout << "Dado para inserção: ";
    cin >> dado;
    insere(arv.raiz, dado, dado);

    cout << "\n\n\n" << arv.raiz->comp[0].dado;

    system("pause>nul");
}
