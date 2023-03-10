#include <iostream>
using namespace std;

#include "lista_enc.h"

struct cartas{
    int numero;
    int naipe;
};

int main()
{
    Elemento<cartas> el;
    
    inicializa_lista(el);
}
