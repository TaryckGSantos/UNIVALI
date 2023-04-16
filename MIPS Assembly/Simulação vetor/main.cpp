#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int Vetor_A[8] = {0};
    int tamanho_vetor;
    int indice = 0;
    int busca_posicao;

    while (tamanho_vetor < 2 || tamanho_vetor > 8){
        cout << "\n\n\t\tEntre com o tamanho do Vetor_A (máx. = 8): ";
        cin >> tamanho_vetor;

        if(tamanho_vetor < 2 || tamanho_vetor > 8){
            cout << "\n\t\tValor inválido! ";
        }
    }

    while (indice < tamanho_vetor){
        cout << "\n\n\t\tVetor_A[" << indice << "]: ";
        cin >> Vetor_A[indice];
        indice++;
    }

    do{
        cout << "\n\n\t\tDigite o índice do valor a ser impresso: ";
        cin >> busca_posicao;

        if (busca_posicao < 0 || busca_posicao > tamanho_vetor-1){
            cout << "\n\n\t\tValor inválido! ";
        }
    } while (busca_posicao < 0 || busca_posicao > tamanho_vetor-1);

    cout << "\n\n\n\t\tO elemento do vetor na posição " << busca_posicao << " possui o valor: " << Vetor_A[busca_posicao] << endl << endl;
  
    return 0;
}
