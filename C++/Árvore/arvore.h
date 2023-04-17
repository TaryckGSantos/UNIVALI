#ifndef ARVORE_H_INCLUDED
#define ARVORE_H_INCLUDED

struct TNo{
    int chave;
    int dado;
    TNo * direita;
    TNo * esquerda;
};

struct TArvore{
    TNo * raiz;
};

int inicializa_arvore (TArvore &arv){
    arv.raiz = NULL;
}

int insere(TArvore &arv, TNo *&no, int dado){
    if(arv.raiz == NULL){
        no = new TNo;
        no->dado = dado;
        no->direita = NULL;
        no->esquerda = NULL;
        arv.raiz = no;
    } else {
        if(no == NULL){
            no = new TNo;
            no->dado = dado;
            no->direita = NULL;
            no->esquerda = NULL;
        } else {
            if(dado > no->dado){
                insere(arv, no->direita, dado);
            } else {
                if (dado < no->dado){}
                insere(arv, no->esquerda, dado);
            }
        }
    }
}

void mostrar_arv(TNo * no) {
    if (no == NULL) {
        return;
    }

    mostrar_arv(no->esquerda);

    cout << no->dado << " - ";

    mostrar_arv(no->direita);
}

#endif // ARVORE_H_INCLUDED
