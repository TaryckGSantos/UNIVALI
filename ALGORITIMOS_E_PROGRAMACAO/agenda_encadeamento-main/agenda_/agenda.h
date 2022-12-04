//Pedro Kons, Thiago Pacheco, Taryck

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <fstream>
using namespace std;

struct Produto{ //Struct usada em todo o c�digo
    int codigo;
    string nome;
    float preco;
    Produto *proximo;
};

bool inicializa_lista(Produto* inicio){ //Fun��o booleana que indica o in�cio da lista
    if (inicio == NULL) {
        return true;
    }
    else {
        return false;
    }
}

void inserir_primeiro(Produto* &inicio, Produto* &ultimo, Produto auxiliar){ //Fun��o de inserir o primeiro produto

    Produto* temp = new Produto; //cria um novo ponteiro auxiliar
    temp->codigo = auxiliar.codigo; // o ponteiro criado recebe os valores da estrada passados por par�metro
    temp->nome = auxiliar.nome;
    temp->preco = auxiliar.preco;
    temp->proximo = NULL; // o novo ponteiro aponta para o NULL
    inicio = temp; // o primeiro produto recebe o novo ponteiro
    ultimo = temp; // o ultimo produto tamb�m recebe o novo ponteiro
}

void inserir(Produto* &inicio, Produto* &ultimo, Produto auxiliar){ // Fun��o de inser��o
    Produto* temp; // declara��o da vari�vel auxiliar

    if (inicializa_lista(inicio)) { // retorno para a fun��o booleana: caso seja a primeira inser��o do c�digo
        inserir_primeiro(inicio, ultimo, auxiliar); // retorna para a fun��o de inserir o primeiro
    }
    else {
        temp = new Produto; // novo ponteiro
        temp->codigo = auxiliar.codigo; // o ponteiro criado recebe os valores da estrada passados por par�metro
        temp->nome = auxiliar.nome;
        temp->preco = auxiliar.preco;
        temp->proximo = NULL; // proximo aponta para null
        ultimo->proximo = temp; // primeiro aponta para o novo ponteiro
        ultimo = temp; // temp passa a ser o primeiro
    }
}

int buscar_produto(Produto* prod_buscar, int &busca_aux){ // fun��o para busca de produtos

    if(prod_buscar->codigo == busca_aux){ // caso o codigo seja igual ao auxiliar de busca(passado por parametro)
        cout << endl << "\t\t----------------------" <<endl << endl;
        cout << "\t\t" << " - PRODUTO: - ";
        cout << endl << endl << endl;
        cout << "\t\t" << "Nome do produto: " << prod_buscar->nome;
        cout << endl << endl << "\t\tC�digo do produto: " << prod_buscar->codigo;
        cout << endl << endl << "\t\tPre�o do produto: " << prod_buscar->preco << " R$";
        cout << endl << endl << "\t\t";
        system("pause>nul");
    }
    else if(prod_buscar->proximo == NULL){ // Caso n�o haja proximo e ainda n�o foi encontrado o produto
        cout << endl << endl;
        cout << "\t\t" << " | - PRODUTO N�O ENCONTRADO!! - |";
        cout << endl << endl << endl;
        system("pause>nul");
    }
    else {
        return (buscar_produto(prod_buscar->proximo, busca_aux));// caso nenhum dos anteriores aconte�a, retorna para a mesma fun��o, mas com um ponteiro diferente
    }
}


int remover_produto(Produto* &prod_remover, int &remover_aux){ //Fun��o de remover
    Produto* aux_mostrar; // ponteiro criado apenas para mostrar o produto excluido
    Produto* prod_aux; // ponteiro auxiliar para remo��o

    if(prod_remover->codigo == remover_aux){ //Caso o primeiro ponteiro seja o encontrado
       prod_aux = prod_remover; // auxiliar recebe o endere�o do ponteiro
       prod_remover = prod_remover->proximo; // o ponteiro inicial aponta para o proximo
       aux_mostrar = prod_aux; // recebendo para apenas mostrar
       delete prod_aux; //primeira posi��o � deletada
    }
    else {
        Produto* prod_atual = prod_remover; //criado um ponteiro atual
        while(prod_atual->proximo != NULL){ // caso o proximo ponteiro n�o seja NULL
            if(prod_atual->proximo->codigo == remover_aux){ // o ponteiro atual aponta para o codigo do proximo para compara��o com o codigo desejado para remo��o
                prod_aux = prod_atual->proximo; // caso encontrado, o auxiliar recebe o endere�o do proximo ponteiro
                prod_atual->proximo = prod_atual->proximo->proximo; // o ponteiro atual recebe o endere�o do produto posterior ao que ser� eliminado
                aux_mostrar = prod_aux; // recebendo para apenas mostrar
                delete prod_aux; // posi��o seguinte ao atual � deletada
                break; //caso aconte�a, parar o la�o
            } else {
                return remover_produto(prod_remover->proximo, remover_aux); // caso o ponteiro atual n�o se encaixe, retorna o proximo endere�o
            }
        }
    }

    if(aux_mostrar->codigo == remover_aux){ // mostrar o nome do produto eliminado
        cout << endl << endl;
        cout << "\t\tRemo��o conclu�da! Produto removido: " << aux_mostrar->nome;
        cout << endl << endl << "\t\t";
    }
}

int mostra_produtos(Produto* prod_mostrar){ // fun��o para a amostra constante

    if (prod_mostrar == NULL) { // caso n�o haja mais produtos no encadeamento
        return 1;
    }

    else if (prod_mostrar != NULL) { // caso o produto atual seja diferente de NULL
        cout << "\t\t" << "Nome do produto: " << prod_mostrar->nome;
        cout << endl << endl << "\t\tC�digo do produto: " << prod_mostrar->codigo;
        cout << endl << endl << "\t\tPre�o do produto: " << prod_mostrar->preco << " R$";
        cout << endl << endl << "\t\t" << "----------------------" << endl << endl;
    }
    return mostra_produtos(prod_mostrar->proximo);// retorna para o proximo produto
}

int menu(){ // menu usado na sele��o das funcionalidades

    int confirma_menu;

    cout << endl << endl << endl;
    cout << "\t\t" << " - LISTA DE FUNCIONALIDADES - ";
    cout << endl << endl << endl;
    cout << "\t\t" << "Para inserir um produto, pressione 1: ";
    cout << endl << endl;
    cout << "\t\t" << "Para remover um dos produtos, pressione 2: ";
    cout << endl << endl;
    cout << "\t\t" << "Para buscar um produto dentro da lista, pressione 3: ";
    cout << endl << endl;
    cout << "\t\t" << "Para encerrar a lista, pressione 4: ";
    cout << endl << endl << "\t\t";
    cin >> confirma_menu;

    return confirma_menu; // retorna o valor inserido;
}
