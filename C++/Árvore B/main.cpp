#include <iostream>
using namespace std;

#include <windows.h>

#define M 2

struct TRegistroB{
    int chave;
    int dado;
};

struct TPaginaB{
    TRegistroB registros[2*M];
    TPaginaB * paginas[2*M+1];
    int nRegistros;
};

int inicializa_pag(TPaginaB * pag){
    for(int i=0; i<2*M; i++){
        pag->registros[i].dado = NULL;
        pag->registros[i].chave = NULL;
    }
    pag->nRegistros = 0;
}

TRegistroB remover_max(TPaginaB * pag){
    TRegistroB aux;
    aux = pag->registros[2];
    for(int j = 2; j < 5; j++){
        pag->registros[j] = pag->registros[j+1];
        pag->nRegistros--;
    }
    return aux;
}

void inserir(TPaginaB * pag, int dado, int chave){
    if(pag->nRegistros == 0){
        pag->registros[0].chave = chave;
        pag->registros[0].dado = dado;
        pag->nRegistros++;
    } else {
        if(pag->nRegistros <= 2*M){
            if(chave < pag->registros[0].chave){
                for(int i = pag->nRegistros; i > 0; i--){
                    pag->registros[i].chave = pag->registros[i-1].chave;
                    pag->registros[i].dado = pag->registros[i-1].dado;
                }
                pag->registros[0].chave = chave;
                pag->registros[0].dado = dado;
                pag->nRegistros++;
            } else if (chave > pag->registros[pag->nRegistros-1].chave){
                pag->registros[pag->nRegistros].chave = chave;
                pag->registros[pag->nRegistros].dado = dado;
                pag->nRegistros++;
            } else {
                for(int i = 0; i < pag->nRegistros; i++){
                    if(chave > pag->registros[i].chave && chave < pag->registros[i+1].chave){
                        for(int j = pag->nRegistros; j >= i+1; j--){
                            pag->registros[j].chave = pag->registros[j-1].chave;
                            pag->registros[j].dado = pag->registros[j-1].dado;
                        }
                        pag->registros[i+1].chave = chave;
                        pag->registros[i+1].dado = dado;
                        pag->nRegistros++;
                        return;
                    }
                }
            }
        }

        if(pag->nRegistros == 2*M+1){ /// Remover quando atingir o maximo de elementos
            TRegistroB teste;
            teste = remover_max(pag);
            cout << "\n\n\n" << teste.chave << "   " << teste.dado;
            system("pause>nul");
        }
    }
}

void mostrar(TPaginaB * pag){
    for(int i = 0; i < pag->nRegistros; i++){
        cout << pag->registros[i].chave << " - ";
    }
}

int main(){
    int cont = 0;
    int qtd_pag = 1;
    int aux;

    TPaginaB * pag = new TPaginaB[qtd_pag];

    inicializa_pag(pag);

    do{
        system("cls");
        mostrar(pag);
        cout << endl << endl;
        cout << "Insira o valor: ";
        cin >> aux;
        inserir(pag, aux, aux);
    } while(cont < 100);

}
