#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <fstream>
using namespace std;

struct Produto{
    int codigo;
    string nome;
    float preco;
    Produto *proximo;
};

/*struct ListaE{
    Produto *inicial;
};

bool inicializa_lista (ListaE &inicio){
    inicio.inicial = NULL;
}*/

void *inserir_produto(Produto *inicio){

    Produto *novo;
    novo = new Produto;

    int codigo_res, tst;
    string nome_res;
    float preco_res;

    system("cls");
    cout << endl << endl << endl << endl;
    cout << "\t\t" << " - LISTA DE PRODUTOS - ";
    cout << endl << endl << endl;
    cout << "\t\t" << "- Insira o nome do produto: ";
    cin >> nome_res;
    cout << endl << endl << "\t\t" << "- Insira o código do produto: ";
    cin >> codigo_res;
    cout << endl << endl << "\t\t" << "- Insira o preço do produto: ";
    cin >> preco_res;

    novo->nome = nome_res;
    novo->codigo = codigo_res;
    novo->preco = preco_res;

    if(inicio == NULL){
        novo->proximo = NULL;
        inicio = novo;
    } else {
        novo->proximo = inicio;
        inicio = novo;
    }
    cout << endl << endl << endl << inicio->nome << "\t\t" << inicio->codigo;
    cin >> tst;

}

void *mostra_produtos(Produto *inicio){

    Produto *continuacao = inicio;

    int i=0;

    while(continuacao != NULL){
        cout << endl << endl << endl << endl;
        cout << "\t\t" << " - LISTA DE PRODUTOS - ";
        cout << endl << endl << endl;
        cout << "\t\t" << "Nome do produto: " << continuacao->nome;
        cout << endl << endl << "\t\tCódigo do produto: " << continuacao->codigo;
        cout << endl << endl << "\t\tPreço do produto:" << continuacao->preco;
        continuacao = continuacao->proximo;
    }
}

int remover_produto(Produto *Produtos){
}

void menu(int confirma_menu){
    Produto *inicio = NULL, *atual;

    cout << endl << endl << endl << endl;
    cout << "\t\t" << " - LISTA DE PRODUTOS - ";
    cout << endl << endl << endl;
    cout << "\t\t" << "Para inserir mais um produto, pressione 1: ";
    cout << endl << endl;
    cout << "\t\t" << "Para mostrar os produtos, pressione 2: ";
    cout << endl << endl;
    cout << "\t\t" << "Para remover um dos produtos, pressione 3: ";
    cout << endl << endl;
    cout << "\t\t" << "Para encerrar a lista, pressione 4: ";
    cout << endl << endl << "\t\t";
    cin >> confirma_menu;

    if(confirma_menu == 1){
        inserir_produto(atual);
    } else if (confirma_menu == 2) {
        mostra_produtos(inicio);
    } else if(confirma_menu == 4){
        system("cls");
        cout << endl << endl << endl << endl;
        cout << "\t\t" << "Agenda encerrada :)";
        cout << endl << endl << endl;
        exit(0);
    }
}

void menu_inicial(int &confirma_inicio){
    Produto *produtos = NULL, *atual;
    int confirma_menu;

    cout << endl << endl << endl << endl;
    cout << "\t\t" << "LISTA DE PRODUTOS - MENU INICIAL";
    cout << endl << endl << endl;
    cout << "\t\t" << "Para inserir o primeiro produto, pressione 1: ";
    cout << endl << endl;
    cout << "\t\t" << "Para sair da lista sem adicionar nenhum produto, pressione 2: ";
    cout << endl << endl << "\t\t";
    cin >> confirma_inicio;


    if(confirma_inicio == 1){

        inserir_produto(atual);
        system("cls");

    } else if(confirma_inicio == 2){
        system("cls");
        cout << endl << endl << endl << endl;
        cout << "\t\t" << "Agenda encerrada :)";
        cout << endl << endl << endl;
        exit(0);
    }
    else {
        cout << endl << endl << "Pressione apenas 1 ou 2!";
        return menu_inicial(confirma_inicio);
    }
}

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int confirma_menu, confirma_inicio;
    Produto *inicio = NULL;
    Produto *atual;

    menu_inicial(confirma_inicio);

    do{
        menu(confirma_menu);
    } while (confirma_menu != 4);
}
