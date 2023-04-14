#include <iostream>
using namespace std;

#include "clientes.h"

int main()
{
    setlocale(LC_ALL, "POrtuguese");

    char aux[100];

    TPilha<char> pilha;

    inicializa_pilha(pilha);

    inserir_expressao(pilha);

    mostrar_verificacao(pilha);
}
