#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <agenda.h>
using namespace std;

int main()
{
    setlocale(LC_ALL,"Portuguese");

    int select;

    Agenda<pessoal,30> agp; // declaração da variavel que vai ser usada no codigo todo para pessoas, além do tipo e tamanho da template
    Agenda<comercial,30> agc; // declaração da variavel que vai ser usada no codigo todo para empresas, além do tipo e tamanho da template

    inicializa_agenda(agp); // funções para atribuir 0 na quantidade (inicio do codigo)
    inicializa_agenda(agc);

    system("cls");

    do{
        Menu_contato(select,agp,agc); // laço para fazer o código rodar sempre na sequencia correta
    }while(select!=6);

    return 0;
}
