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
    Produto auxiliar; // auxiliar nas inserções

    int confirma_menu, confirma_inicio, a;

    cout << endl << endl << endl << endl;
    cout << "\t\t" << "LISTA DE PRODUTOS - MENU INICIAL";
    cout << endl << endl << endl;
    cout << "\t\t" << "Para iniciar a agenda, pressione 1: ";
    cout << endl << endl;
    cout << "\t\t" << "Para sair da lista sem adicionar nenhum produto, pressione 2: ";
    cout << endl << endl << "\t\t";
    cin >> confirma_inicio;

    if(confirma_inicio == 1){ // caso opte por começar a agenda
        system("cls");

    } else if(confirma_inicio == 2){ // caso queira encerrar sem nenhuma ação
        system("cls");
        cout << endl << endl << endl << endl;
        cout << "\t\t" << "Agenda encerrada :)";
        cout << endl << endl << endl;
        exit(0);
    }
    else { // caso não pressione 1 ou 2
        cout << endl << endl << "Pressione apenas 1 ou 2!";
        cin >> confirma_inicio;
    }

    do{ // caso confirma_inicio = 1, o código vem direto para o do
        fstream escrita; // criação do fstream
        escrita.open("agenda.txt",ios::in); // abertura do .txt e declaração do ios::in
        string linha; // string usada na mostragem das linhas do .txt

        cout << endl << endl << "\t\t- LISTA DE PRODUTOS SALVOS -" << endl;
        cout << endl << "\t\tNome do produto  |  Código do produto  |  Preço do produto (R$)" << endl;
        if(escrita.is_open()){// caso o fstream esteja aberto
            while(getline(escrita,linha)){ // laço para verificar todas as linhas
                cout << "\t\t" << linha << endl; // amostra do conteúdo do .txt
            }
        }

        cout << endl << endl;
        cout << "\t\t" << " - LISTA DE PRODUTOS INSERIDOS- ";
        cout << endl << endl;
        mostra_produtos(inicio); // amostra constante dos produtos inseridos (função de amostra)
        confirma_menu = menu(); // confirma_menu recebe o retorno da função menu

        switch(confirma_menu){

            case 1: {//inserção
                system("cls");
                cout << endl << endl << endl << endl;
                cout << "\t\t" << " - LISTA DE PRODUTOS - ";
                cout << endl << endl << endl;
                cout << "\t\t" << "- Insira o nome do produto: ";
                cin >> auxiliar.nome;
                cout << endl << endl << "\t\t" << "- Insira o código do produto: ";
                cin >> auxiliar.codigo;
                cout << endl << endl << "\t\t" << "- Insira o preço do produto: ";
                cin >> auxiliar.preco;
                inserir(inicio, ultimo, auxiliar); // após inserir os valores no auxiliar, é chamada a função de inserir
                system("cls");
                break;
            }
            case 2: {//remover
                int select;

                system("cls");
                cout << endl << endl << endl << endl;
                cout << "\t\t" << " - LISTA DE PRODUTOS - ";
                cout << endl << endl << endl;
                cout << "\t\t" << "- Insira o código do produto que será removido: ";
                cin >> select;
                remover_produto(inicio, select); // chama a função de remoção passando o codigo como parametro
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
                cout << "\t\t" << "Digite o código do produto: ";
                cin >> busca_aux;
                buscar_produto(inicio,busca_aux); // chama a função de busca através da passagem do codigo como parametro
                system("cls");
                break;
            }
             case 4: {// saída do código e escrita no .txt
                system("cls");
                fstream escrita;
                escrita.open("agenda.txt",ios::out|ios::app); // chama o fstream como saída e integra os dados no final

                while(inicio->proximo != NULL){ // laço para escrita de todos os produtos (antes do primeiro) no .txt
                    escrita << endl << inicio->nome << endl;
                    escrita << inicio->codigo << endl;
                    escrita << inicio->preco << endl << endl;
                    inicio = inicio->proximo;
                }

                if(inicio->proximo == NULL) { // laço para a escrita do primeiro no .txt
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
                cout << "\t\tOpção inválida!";
                cout << endl << endl << endl;
                break;
        }
    } while(confirma_menu != '4'); // do funcionará infinitamente caso confirma_menu seja diferente de 4

    delete inicio;
    delete ultimo;
    return 0;
}
