#ifndef ELEMENTOS_H_INCLUDED
#define ELEMENTOS_H_INCLUDED

template <typename TIPO>
struct TNo{
    char chave;
    int fator_equilibrio;
    TIPO dado;
    TNo<TIPO> * direita;
    TNo<TIPO> * esquerda;
};

template <typename TIPO>
struct TArvore{
    TNo<TIPO> *Raiz;
};

template<typename TIPO>
void inicializarNo(TArvore<TIPO> &no){
    no.Raiz=NULL;
    ///cout<<endl<<"Arvore Inicializada"<<endl;
}

template <typename TIPO>
TNo<TIPO> * novo_elemento_arvore_de(TIPO &dado){
    TNo<TIPO> * novo = new TNo<TIPO>;
    novo->dado = dado;
    novo->direita = NULL;
    novo->esquerda = NULL;
    novo->fator_equilibrio = 0;
    return novo;
}

template<typename TIPO>
int insere(TNo<TIPO> *&no,TIPO chave,int dado){
    if(no==NULL){
        no = new TNo<TIPO>;
        no->chave = chave;
        no->dado = dado;
        no->direita = NULL;
        no->esquerda = NULL;
        no->fator_equilibrio = 0;
        return 1;
    }
    else{
        if(chave>no->chave){
            int n = insere(no->direita,chave,dado);
            no->fator_equilibrio = no->fator_equilibrio+n;
            if(no->fator_equilibrio>1){
                if(no->direita->chave>chave){
                    RL(no);
                }
                else{
                    RR(no);
                }
                return 0;
            }else{
                if(no->fator_equilibrio==0){
                    return 0;
                }else{
                    return 1;
                }
            }
        }
        else{
            if(chave<no->chave){
                int n = insere(no->esquerda,chave,dado);
                no->fator_equilibrio = no->fator_equilibrio-n;
                if(no->fator_equilibrio<-1){
                    if(no->esquerda->chave>chave){
                        LL(no);
                    }else{
                        LR(no);
                    }
                    return 0;
                }else{
                    if(no->fator_equilibrio==0){
                        return 0;
                    }else{
                        return 1;
                    }
                }
            }
        }
    }
}

template<typename TIPO>
void pos_ordem(TNo<TIPO> *no){
    if(no!=NULL){
        pos_ordem(no->esquerda);
        pos_ordem(no->direita);
        cout<<no->chave<<", ";
    }
}

template<typename TIPO>
void pre_ordem(TNo<TIPO> *no){
    if(no!=NULL){
        cout<<no->chave<<", ";
        pre_ordem(no->esquerda);
        pre_ordem(no->direita);
    }
}

template<typename TIPO>
void in_ordem(TNo<TIPO> *no){
    if(no!=NULL){
        in_ordem(no->esquerda);
        cout<<no->chave<<", ";
        in_ordem(no->direita);
    }
}

template<typename TIPO>
void remover(TNo<TIPO> *&no){
    TNo<TIPO> * apagar;
    TNo<TIPO>* maior = no->esquerda;
    if(maior == NULL){
        apagar = no;
        no = no->direita;
        delete apagar;
        return;
    }
    TNo<TIPO>* pai = NULL;
    while (maior->direita !=NULL){
        pai = maior;
        maior = maior->direita;
    }
    maior->direita = no->direita;
    if (pai != NULL){
        pai->direita = maior->esquerda;
        maior->esquerda = no->esquerda;
    }
    apagar = no;
    no = maior;
    delete apagar;
}

template<typename TIPO>
bool procura_remove(TNo<TIPO> *&no,char chave){
    if(no != NULL){
        if(no->chave == chave){
            remover(no);
            return true;
        }else{
            if(chave > no->chave){
                procura_remove(no->direita, chave);
            }else{
                procura_remove(no->esquerda, chave);
            }
        }
    }
    return false;
}

template<typename TIPO>
bool procura(TNo<TIPO> *&no,char chave){
    if(no != NULL){
        if(no->chave == chave){
            return true;
        }else{
            if(chave > no->chave){
                procura(no->direita, chave);
            }else{
                procura(no->esquerda, chave);
            }
        }
    }
}

template<typename TIPO>
void RR(TNo<TIPO>*&r){
    TNo<TIPO>* a = r;
    TNo<TIPO>* b = a->direita;
    a->direita = b->esquerda;
    b->esquerda = a;
    a->fator_equilibrio=0;
    b->fator_equilibrio=0;
    r = b;
}

template<typename TIPO>
void LL(TNo<TIPO>*&r){
    TNo<TIPO>* a = r;
    TNo<TIPO>* b = a->esquerda;
    a->esquerda = b->direita;
    b->direita = a;
    b->fator_equilibrio=0;
    a->fator_equilibrio=0;
    r = a;
}

template<typename TIPO>
void RL(TNo<TIPO>*&r){
    TNo<TIPO>* a = r;
    TNo<TIPO>* c = a->direita;
    TNo<TIPO>* b = c->esquerda;
    c->esquerda = b->direita;
    a->direita = b->esquerda;
    b->esquerda = a;
    b->direita = c;
    switch(b->fator_equilibrio){
    case -1:
        a->fator_equilibrio = 0;
        c->fator_equilibrio = +1;
        break;
    case 0:
        a->fator_equilibrio = 0;
        c->fator_equilibrio = 0;
        break;
    case 1:
        a->fator_equilibrio = -1;
        c->fator_equilibrio = 0;
        break;
    }
    b->fator_equilibrio = 0;
    r = b;
}

template<typename TIPO>
void LR(TNo<TIPO>*&r){
    TNo<TIPO>* a = r;
    TNo<TIPO>* c = a->esquerda;
    TNo<TIPO>* b = c->direita;
    c->direita = b->esquerda;
    a->esquerda = b->direita;
    b->direita = a;
    b->esquerda = c;
    switch(b->fator_equilibrio){
    case -1:
        a->fator_equilibrio = 0;
        c->fator_equilibrio = +1;
        break;
    case 0:
        a->fator_equilibrio = 0;
        c->fator_equilibrio = 0;
        break;
    case 1:
        a->fator_equilibrio = -1;
        c->fator_equilibrio = 0;
        break;
    }
    b->fator_equilibrio = 0;
    r = b;
}

void imprimeNo(char c,int b){
    for(int i=0;i<b;i++){
        cout<<"\t";
    }
    cout<<c<<endl;
}
template<typename TIPO>
void mostrarArvore(TNo<TIPO>*a,int b){
    if(a==NULL){
        imprimeNo('*',b);
        return;
    }
    mostrarArvore(a->direita,b+1);
    imprimeNo(a->chave,b);
    mostrarArvore(a->esquerda,b+1);
}

#endif // ELEMENTOS_H_INCLUDED
