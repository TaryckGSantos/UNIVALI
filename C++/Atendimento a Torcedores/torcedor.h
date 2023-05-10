#ifndef TORCEDOR_H_INCLUDED
#define TORCEDOR_H_INCLUDED

struct Torcedor{
    string tipo_torcedor;
    int qtd_tempo;
    int posicao;
};

int montar_filaST(TFila <Torcedor> &filaST,Torcedor &aux,int &carga_inicial){
    int varT;
    aux.tipo_torcedor="s";
    varT=rand()%100+1;
    if(varT<=85){
        aux.qtd_tempo=1;
    }
    else{
        aux.qtd_tempo=2;
    }
    carga_inicial--;
}

int montar_filaN(TFila <Torcedor> &filaN,Torcedor &aux,int &carga_inicial){
    int varT;
    aux.tipo_torcedor="n";
    varT=rand()%100+1;
    if(varT<=25){
        aux.qtd_tempo=1;
    }
    else if(varT<=55){
        aux.qtd_tempo=2;
    }
    else{
        aux.qtd_tempo=3;
    }
    carga_inicial--;
}

int verifica_menor(TFila <Torcedor> &fila,int &menor){
    if(menor>fila.tamanho){
        menor=fila.tamanho;
    }
    return menor;
}

void insere_dados(Torcedor &aux){
    int varT,varP;
    varT=rand()%100+1;
    varP=rand()%100+1;
    if(varP<=95){
        aux.tipo_torcedor="n";
    }
    else{
        aux.tipo_torcedor="s";
    }

    if(aux.tipo_torcedor=="s"){
        if(varT<=85){
            aux.qtd_tempo=1;
        }
        else{
            aux.qtd_tempo=2;
        }
    }
    else if(aux.tipo_torcedor=="n"){
        if(varT<=25){
            aux.qtd_tempo=1;
        }
        else if(varT<=55){
            aux.qtd_tempo=2;
        }
        else{
            aux.qtd_tempo=3;
        }
    }
}

void imprimir_pFila(Torcedor torcedores){/*
    if(torcedores.tipo_torcedor=="s"){
        cout<<"\tSócio Torcedor ";
    }
    else if(torcedores.tipo_torcedor=="n"){
        cout<<"\tTorcedor Normal ";
    }*/

    cout<<"\t"/*Quantidade de <<"Tempo: "*/<<torcedores.qtd_tempo<<endl;
}

void zerar(TFila<Torcedor>&fila){
    inicializa_fila(fila);
}

bool rodar_tempo(TFila<Torcedor>&fila){
    TElementoF <Torcedor> *nav = fila.inicio;
    Torcedor aux;
    if(fila.inicio==NULL){
        ///cout<<"\n\t\tNão há nenhuma pessoa na fila \n";
        return false;
    }
    else{
        aux=nav->dado;
        int var=aux.qtd_tempo;
        if(aux.qtd_tempo!=0){
            aux.qtd_tempo=var-1;
        }
        if(aux.qtd_tempo==0){
            atender(fila);
            return true;
        }
    }
    nav->dado=aux;
}
#endif // TORCEDOR_H_INCLUDED
