#include <iostream>
using namespace std;

#include <windows.h>

struct TNo {
    int dado;
    int chave;
    string situacao;
    TNo * proximo;
};

void inicia_tabela(TNo *&tab, int TAM){
    for(int i = 0; i<TAM; i++){
        tab[i].situacao = "L";
        tab[i].dado = NULL;
        tab[i].chave = NULL;
    }
}

int inserir(TNo *&tab, int chave, int dado, int posicao){

    if(tab[posicao].situacao == "L" || tab[posicao].situacao == "R"){
        tab[posicao].dado = dado;
        tab[posicao].chave = chave;
        tab[posicao].situacao = "O";
        return 1;
    } else {
        inserir(tab,chave,dado,posicao+1);
    }
}

bool remover(TNo *&tab, int chave_remover, int TAM, int &comp){
    for(int i=0; i<TAM; i++){
        if(tab[i].chave == chave_remover){
            tab[i].dado = NULL;
            tab[i].chave = NULL;
            tab[i].situacao = "R";
            comp--;
            return true;
        }
    }
    return false;
}

void mostrar(TNo *&tab, int TAM){
    for (int i = 0; i < TAM; i++){
        cout << "Posição: " << i << " Situação: " << tab[i].situacao << " | Chave: " << tab[i].chave << " | Dado: " << tab[i].dado;
        cout << endl << endl;
    }
}

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int TAM, chave, dado, comp = 0, posicao, menu, chave_remover;
    bool removerrr;

    cout << "Insira o tamanho da tabela: ";
    cin >> TAM;
    system("cls");

    TNo * tab = new TNo[TAM];

    inicia_tabela(tab, TAM);

    do {
        mostrar(tab, TAM);

        cout << endl << endl << endl;

        cout << "1 - Inserir | 2 - Remover: ";
        cin >> menu;

        switch(menu){

            case 1:
                cout << "\n\nDigite a chave de sua inserção: ";
                cin >> chave;

                cout << "Digite o dado a ser guardado: ";
                cin >> dado;

                posicao = chave % TAM;

                comp = comp + inserir(tab,chave,dado,posicao);

                if(comp >= TAM){
                    system("cls");
                    mostrar(tab, TAM);
                    cout << "\n\n\nTabela Cheia!!!";
                    system("pause>nul");
                }
                break;

            case 2:
                cout << "\n\nDigite a chave da posição para ser removida: ";
                cin >> chave_remover;

                removerrr = remover(tab,chave_remover,TAM, comp);

                if(remover){
                    cout << "\n\nElemento removido!";
                    system("pause>nul");
                } else {
                    cout << "\n\nNão foi possível realizar a remoção!";
                }
                break;

        }

        system("cls");

    } while(comp < TAM);
}
