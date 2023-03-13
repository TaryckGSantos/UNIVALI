#include <iostream>
using namespace std;

#include "lista_enc.h"

struct cartas{
    int numero;
    int naipe;
};

int main()
{

    TLista <cartas> lista;
    Elemento<cartas> el;
    cartas dado, au;

    inicializa_lista(lista);

    insere_inicio(lista, dado);

}
