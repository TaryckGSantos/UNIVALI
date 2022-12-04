//Pedro Kons, Thiago Pacheco, Taryck

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <fstream>
#include "agenda.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "Portuguese");

    Produto* inicio = NULL; // declarado o produto inicial como nulo
    Produto* ultimo = NULL; // declarado o produto final como nulo
    Produto auxiliar; // auxiliar nas inser��es

    int confirma_menu, confirma_inicio, a;

    cout << endl << endl << endl << endl;
    cout << "\t\t" << "LISTA DE PRODUTOS - MENU INICIAL";
    cout << endl << endl << endl;
    cout << "\t\t" << "Para iniciar a agenda, pressione 1: ";
    cout << endl << endl;
    cout << "\t\t" << "Para sair da lista sem adicionar nenhum produto, pressione 2: ";
    cout << endl << endl << "\t\t";
    cin >> confirma_inicio;

    if(confirma_inicio == 1){ // caso opte por come�ar a agenda
        system("cls");

    } else if(confirma_inicio == 2){ // caso queira encerrar sem nenhuma a��o
        system("cls");
        cout << endl << endl << endl << endl;
        cout << "\t\t" << "Agenda encerrada :)";
        cout << endl << endl << endl;
        exit(0);
    }
    else { // caso n�o pressione 1 ou 2
        cout << endl << endl << "Pressione apenas 1 ou 2!";
        cin >> confirma_inicio;
    }

    do{ // caso confirma_inicio = 1, o c�digo vem direto para o do
        fstream escrita; // cria��o do fstream
        escrita.open("agenda.txt",ios::in); // abertura do .txt e declara��o do ios::in
        string linha; // string usada na mostragem das linhas do .txt

        cout << endl << endl << "\t\t- LISTA DE PRODUTOS SALVOS -" << endl;
        cout << endl << "\t\tNome do produto  |  C�digo do produto  |  Pre�o do produto (R$)" << endl;
        if(escrita.is_open()){// caso o fstream esteja aberto
            while(getline(escrita,linha)){ // la�o para verificar todas as linhas
                cout << "\t\t" << linha << endl; // amostra do conte�do do .txt
            }
        }

        cout << endl << endl;
        cout << "\t\t" << " - LISTA DE PRODUTOS INSERIDOS- ";
        cout << endl << endl;
        mostra_produtos(inicio); // amostra constante dos produtos inseridos (fun��o de amostra)
        confirma_menu = menu(); // confirma_menu recebe o retorno da fun��o menu

        switch(confirma_menu){

            case 1: {//inser��o
                system("cls");
                cout << endl << endl << endl << endl;
                cout << "\t\t" << " - LISTA DE PRODUTOS - ";
                cout << endl << endl << endl;
                cout << "\t\t" << "- Insira o nome do produto: ";
                cin >> auxiliar.nome;
                cout << endl << endl << "\t\t" << "- Insira o c�digo do produto: ";
                cin >> auxiliar.codigo;
                cout << endl << endl << "\t\t" << "- Insira o pre�o do produto: ";
                cin >> auxiliar.preco;
                inserir(inicio, ultimo, auxiliar); // ap�s inserir os valores no auxiliar, � chamada a fun��o de inserir
                system("cls");
                break;
            }
            case 2: {//remover
                int select;

                system("cls");
                cout << endl << endl << endl << endl;
                cout << "\t\t" << " - LISTA DE PRODUTOS - ";
                cout << endl << endl << endl;
                cout << "\t\t" << "- Insira o c�digo do produto que ser� removido: ";
                cin >> select;
                remover_produto(inicio, select); // chama a fun��o de remo��o passando o codigo como parametro
                system("pause>nul");
                system("cls");
                break;
            }
            case 3: {// busca
                int busca_aux;

                system("cls");
                cout << endl << endl << endl << endl;
                cout << "\t\t" << " - LISTA DE PRODUTOS - ";
                cout << endl << endl << endl;
                cout << "\t\t" << "Digite o c�digo do produto: ";
                cin >> busca_aux;
                buscar_produto(inicio,busca_aux); // chama a fun��o de busca atrav�s da passagem do codigo como parametro
                system("cls");
                break;
            }
             case 4: {// sa�da do c�digo e escrita no .txt
                system("cls");
                fstream escrita;
                escrita.open("agenda.txt",ios::out|ios::app); // chama o fstream como sa�da e integra os dados no final

                while(inicio->proximo != NULL){ // la�o para escrita de todos os produtos (antes do primeiro) no .txt
                    escrita << endl << inicio->nome << endl;
                    escrita << inicio->codigo << endl;
                    escrita << inicio->preco << endl << endl;
                    inicio = inicio->proximo;
                }

                if(inicio->proximo == NULL) { // la�o para a escrita do primeiro no .txt
                    escrita << endl << inicio->nome << endl;
                    escrita << inicio->codigo << endl;
                    escrita << inicio->preco << endl << endl;
                }
                escrita.close(); // fechamento do fstream
                cout << endl << endl << endl << endl;
                cout << "\t\t" << "Agenda encerrada :)";
                cout << endl << endl << endl;
                system("pause>nul");
                exit(0);
                break;
             }
            default:
                cout << endl << endl << endl << endl;
                cout << "\t\tOp��o inv�lida!";
                cout << endl << endl << endl;
                break;
        }
    } while(confirma_menu != '4'); // do funcionar� infinitamente caso confirma_menu seja diferente de 4

    delete inicio;
    delete ultimo;
    return 0;
}
