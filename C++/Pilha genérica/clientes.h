#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED

#include <string.h>
#include <windows.h>

template <typename TIPO>
struct TElemento{
    TIPO dado;
};

template <typename TIPO>
struct TPilha{
    TElemento<TIPO> vet[100];
    int tamanho;
};

template <typename TIPO>
int inicializa_pilha(TPilha<TIPO> &pilha){
    pilha.tamanho = 0;
}

template <typename TIPO>
void mostrar_elementos(TPilha<TIPO> pilha, char aux[]){

    cout << endl << endl << "\t\t";

    for(int i = 0; i < strlen(aux); i++){
        cout << endl << endl << "\t\t";
        cout << pilha.vet[i].dado;
    }
    cout << endl << endl;
}

template <typename TIPO>
int inserir_expressao(TPilha<TIPO> &pilha){
    char aux[100];
    int tamanho_vetor;

    cin >> aux;
    tamanho_vetor = strlen(aux);
    cout << endl << endl << tamanho_vetor ;
    system("pause>nul");

    for (int i = 0; i < tamanho_vetor ; i++){
        pilha.vet[i].dado = aux[i];
        pilha.tamanho++;
    }
    return tamanho_vetor;
}

template <typename TIPO>
int verificacao(TPilha<TIPO> pilha){

    int j = inserir_expressao(pilha);

    for (int i = 0; i < j-1; i++){
        if (pilha.vet[i].dado == pilha.vet[j-1].dado){
            return 4;
        } else {
            return 5;
        }
        j++;
    }
}

template <typename TIPO>
int verificacao(TPilha<TIPO> pilha){

    int j = inserir_expressao(pilha);

    for (int i = 0; i < j-1; i++){
        if (pilha.vet[i].dado == pilha.vet[j-1].dado){
            return 4;
        } else {
            return 5;
        }
        j++;
    }
}

template <typename TIPO>
int mostrar_verificacao(TPilha<TIPO> pilha){

    int aux;

    aux = verificacao(pilha);

    if (aux == 0){
        cout << "\n\n\t\tÉ um palindromo!";
    } else {
        cout << "\n\n\t\tNão é um palindromo!";
    }
}

/*
template <typename TIPO>
int remove_primeiro(TPilha<TIPO> &pilha){
    TElemento<TIPO> * nav = pilha.inicio;
    pilha.inicio = nav->proximo;
    delete nav;
    pilha.cont_clientes--;
}

template <typename TIPO>
void mostrar_elementos(TPilha<TIPO> &pilha){
    TElemento<TIPO> aux;
    TElemento <TIPO> * nav = pilha.inicio;

    while(nav != NULL){
        aux = *nav;
        cout << endl << endl;
        cout << "Cliente: " << aux.dado.nome << "\t\t | \t\t Quantidade de boletos: " << aux.dado.unid_tempo;
        nav = nav->proximo;
    }
}

template <typename TIPO>
int simulacao(TPilha<TIPO> &pilha){
    TElemento<TIPO> * nav = pilha.inicio;
    cout << endl << endl;
    while(nav->proximo != NULL){
        system("cls");
        mostrar_elementos(pilha);
        nav->dado.unid_tempo--;
        if(nav->dado.unid_tempo < 0){
            remove_primeiro(pilha);
            nav = nav->proximo;
        }
        system("pause>nul");
    }
    system("cls");
    cout << endl << endl << "\t\t\TPilha encerrada!\n\n";
    system("pause>nul");
}
*/
#endif // CLIENTES_H_INCLUDED
