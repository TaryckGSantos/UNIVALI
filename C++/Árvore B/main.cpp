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
    int nRegistros;
};

int inicializa_pag(TPaginaB &pag){
    for(int i=0; i<4; i++){
        pag.registros[i].dado = NULL;
        pag.registros[i].chave = NULL;
    }
    pag.nRegistros = 0;
}

void inserir(TPaginaB &pag, int dado, int chave){
    if(pag.nRegistros == 0){
        pag.registros[0].chave = chave;
        pag.registros[0].dado = dado;
        pag.nRegistros++;
    } else {
        if(pag.nRegistros <= 4){
            if(chave < pag.registros[0].chave){
                for(int i = pag.nRegistros; i > 0; i--){
                    pag.registros[i].chave = pag.registros[i-1].chave;
                    pag.registros[i].dado = pag.registros[i-1].dado;
                }
                pag.registros[0].chave = chave;
                pag.registros[0].dado = dado;
                pag.nRegistros++;
            } else if (chave > pag.registros[pag.nRegistros-1].chave){
                pag.registros[pag.nRegistros].chave = chave;
                pag.registros[pag.nRegistros].dado = dado;
                pag.nRegistros++;
            } else {
                for(int i = 0; i < pag.nRegistros; i++){
                    if(chave > pag.registros[i].chave && chave < pag.registros[i+1].chave){
                        for(int j = pag.nRegistros; j <= i+1; j--){
                            pag.registros[j].chave = pag.registros[j-1].chave;
                            pag.registros[j].dado = pag.registros[j-1].dado;
                        }
                        pag.registros[i+1].chave = chave;
                        pag.registros[i+1].dado = dado;
                        pag.nRegistros++;
                        return;
                    }
                }
            }
        }
    }
}

void mostrar(TPaginaB &pag){
    for(int i = 0; i < pag.nRegistros; i++){
        cout << pag.registros[i].chave << " - ";
    }
}

int main(){
    int cont = 0;
    int aux;

    TPaginaB pag;

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
