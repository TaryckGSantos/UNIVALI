#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <agenda.h>
using namespace std;

int main()
{
    setlocale(LC_ALL,"Portuguese");

    int select;

    Agenda<pessoal,30> agp; // declara��o da variavel que vai ser usada no codigo todo para pessoas, al�m do tipo e tamanho da template
    Agenda<comercial,30> agc; // declara��o da variavel que vai ser usada no codigo todo para empresas, al�m do tipo e tamanho da template

    inicializa_agenda(agp); // fun��es para atribuir 0 na quantidade (inicio do codigo)
    inicializa_agenda(agc);

    system("cls");

    do{
        Menu_contato(select,agp,agc); // la�o para fazer o c�digo rodar sempre na sequencia correta
    }while(select!=6);

    return 0;
}
