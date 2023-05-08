#ifndef TORCEDOR_H_INCLUDED
#define TORCEDOR_H_INCLUDED

struct Torcedor{
    string tipo_torcedor;
    int qtd_tempo;
    int posicao;
};

int montar_fila(TFila <Torcedor> &fila,int &carga_inicial){
    Torcedor aux;
    int varT,varP;
    for(int i=0;i<carga_inicial;i++){
        varT = rand()%100+1;
        varP = rand()%100+1;
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
        entrar_na_fila(fila,aux,carga_inicial);
    }
    carga_inicial=0;
}

void insere_dados(Torcedor &aux){
    cout<<"Digite o tipo de Torcedor: "<<endl;
    cin>>aux.tipo_torcedor;
    if(aux.tipo_torcedor=="s"){
        aux.qtd_tempo=rand()%2+1;
    }
    else if(aux.tipo_torcedor=="n"){
        aux.qtd_tempo=rand()%3+1;
    }
    //posicao(aux,tam);
}

void imprimir_pFila(Torcedor torcedores){
    if(torcedores.tipo_torcedor=="s"){
        cout<<"Sócio Torcedor "<<endl;
    }
    else if(torcedores.tipo_torcedor=="n"){
        cout<<"Torcedor Normal "<<endl;
    }
    cout<<"Quantidade de Tempo: "<<torcedores.qtd_tempo<<endl/*<<"Posição: "<<torcedores.posicao<<endl*/;
}

void zerar(){

}

bool rodar_tempo(TFila<Torcedor>&fila){
    TElementoF <Torcedor> *nav = fila.inicio;
    Torcedor aux;
    if(fila.inicio==NULL){
        cout<<"\t\tNão há nenhuma pessoa na fila \t\t";
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
