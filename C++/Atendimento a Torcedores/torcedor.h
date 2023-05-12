#ifndef TORCEDOR_H_INCLUDED
#define TORCEDOR_H_INCLUDED

struct Torcedor{ // Struct torcedor
    string tipo_torcedor;
    int qtd_tempo;
};

int montar_filaST(TFila <Torcedor> &filaST,Torcedor &aux,int &carga_inicial){ // Monta uma nova fila de sócios
    int varT;
    aux.tipo_torcedor="s"; // define o tipo como "s"
    varT=rand()%100+1; // varT = um numero de 1 a 100
    if(varT<=85){ // caso varT seja menor ou igual a 85
        aux.qtd_tempo=1;
    }
    else{ // caso varT seja maior que 85
        aux.qtd_tempo=2;
    }
    carga_inicial--;
}

int montar_filaN(TFila <Torcedor> &filaN,Torcedor &aux,int &carga_inicial){ // Monta uma nova fila de sócios
    int varT;
    aux.tipo_torcedor="n"; // define o tipo como "n"
    varT=rand()%100+1; // varT = um numero de 1 a 100
    if(varT<=25){ // caso varT seja menor ou igual a 25
        aux.qtd_tempo=1;
    }
    else if(varT>25 && varT<=55){ // caso varT seja menor que 55 e maior que 25
        aux.qtd_tempo=2;
    }
    else{ // caso varT seja maior que 55
        aux.qtd_tempo=3;
    }
    carga_inicial--;
}

int seleciona_menor(TFila<Torcedor> fila[], int max_posicao){ // Seleciona a menor fila
    int posicao_menor = 0; // define a posição 0 como a menor inicialmente

    for(int i=1; i<max_posicao; i++){ // laço que faz i ir de 1 até o maximo de itens na fila
        if(fila[i].tamanho < fila[posicao_menor].tamanho){ // caso o tamanho na posição seja menor que posicao_menor
            posicao_menor = i;
        }
    }
    return posicao_menor; // retorna o guichê com menos torcedores
}

void insere_dados(Torcedor &aux){ // função se inserir os dados de cada torcedor
    int varT,varP;
    varT=rand()%100+1; // varT = um numero de 1 a 100
    varP=rand()%100+1; // varP = um numero de 1 a 100
    if(varP<=95){ // Caso varP seja menor ou igual a 95
        aux.tipo_torcedor="n";
    }
    else{ // Caso varP seja maior que 95
        aux.tipo_torcedor="s";
    }

    if(aux.tipo_torcedor=="s"){ // Caso tipo_torcedor = "s"
        if(varT<=85){ // caso vart seja menor ou igual a 85, qtd_tempo=1
            aux.qtd_tempo=1;
        }
        else{ // caso vart seja maior que 85, qtd_tempo=2
            aux.qtd_tempo=2;
        }
    }
    else if(aux.tipo_torcedor=="n"){ // Caso tipo_torcedor = "n"
        if(varT<=25){ // caso vart seja menor ou igual a 25, qtd_tempo=1
            aux.qtd_tempo=1;
        }
        else if(varT>25 && varT<=55){ // caso vart seja maior que 25 e menor ou igual a 55, qtd_tempo=2
            aux.qtd_tempo=2;
        }
        else{ // caso vart seja maior  55, qtd_tempo=3
            aux.qtd_tempo=3;
        }
    }
}

void imprimir_pFila(Torcedor torcedores){ // função de imprimir a quantidade de tempo de cada elemento nas filas

    if(torcedores.qtd_tempo == NULL){ // caso não haja quantidade de tempo
        cout<<"\n\tNão há nenhuma pessoa na fila \n"<<endl;
    }
    cout<<" - Tempo : "<<torcedores.qtd_tempo<<endl; // mostra a quantidade de tempo de cada torcedor
}

void zerar(TFila<Torcedor>&fila){ // função de zerar uma fila
    inicializa_fila(fila);
}

int rodar_tempo(TFila<Torcedor>&fila){ // função de rodar um tempo
    TElementoF <Torcedor> *nav = fila.inicio; // declaração do navegador como o inicio da fila
    Torcedor aux; // variavel auxiliar
    if(fila.inicio==NULL){ // caso a fila esteja vazia
        return 1;
    }
    else{ // caso não esteja
        aux=nav->dado; // auxiliar = dado de nav
        int var=aux.qtd_tempo; // declara variavel como a quantidade de tempo de aux
        if(aux.qtd_tempo!=0){ // caso a quantidade de tempo seja diferente de 0
            aux.qtd_tempo=var-1; // qtq_tempo = var - 1
        }
        if(aux.qtd_tempo==0){ // caso a quantidade de tempo seja igual a 0, pula para a função atender
            atender(fila);
            return 3; // retorna o inteiro 3 para fins de comparação
        }
    }
    nav->dado=aux;
}

bool imprime_fila(TFila<Torcedor>fila){ // função de imprimir a fila completa
    int i=1;
    TElementoF <Torcedor> *nav = fila.inicio; // declara um navegador
    if(fila.inicio==NULL){ // caso não haja nada na fila
        cout<<"\n\tNão há nenhuma pessoa na fila \n"<<endl;
        return false;
    }
    else{ // caso haja algo
        while(nav!=NULL){ // enquanto nav for diferente de null
            cout << "\tTorcedor " << i;
            imprimir_pFila(nav->dado);  // imprime cada dado por vez
            nav=nav->proximo; // nav = proximo
            i++;
            if(nav == NULL){ // caso nav seja o ultimo elemento, salta linhas
                cout << "\n\n";
            }
        }
        return true;
    }
}

#endif // TORCEDOR_H_INCLUDED
