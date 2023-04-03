#include <iostream>
using namespace std;
#include <windows.h>
#include <time.h>

#include "clientes.h"

int main()
{
    TFila<Clientes> fila;

    Clientes dado1, dado2, dado3, dado4, dado5;

    srand(time(NULL));

    dado1.nome = "cliente_1";
    dado2.nome = "cliente_2";
    dado3.nome = "cliente_3";
    dado4.nome = "cliente_4";
    dado5.nome = "cliente_5";

    inicializa_fila(fila);
    novo_elemento_fila_de(dado1);
    novo_elemento_fila_de(dado2);
    novo_elemento_fila_de(dado3);
    novo_elemento_fila_de(dado4);
    novo_elemento_fila_de(dado5);

    inserir_cliente(fila, dado1);
    inserir_cliente(fila, dado2);
    inserir_cliente(fila, dado3);
    inserir_cliente(fila, dado4);
    inserir_cliente(fila, dado5);
    system("pause>nul");

    mostrar_elementos(fila);
    system("pause>nul");

    /*simulacao(fila);*/

    return 0;
}
