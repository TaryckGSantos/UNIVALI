//Pedro Kons, Thiago Pacheco, Taryck

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <fstream>
using namespace std;

struct Produto{ //Struct usada em todo o código
    int codigo;
    string nome;
    float preco;
    Produto *proximo;
};

bool inicializa_lista(Produto* inicio){ //Função booleana que indica o início da lista
    if (inicio == NULL) {
        return true;
    }
    else {
        return false;
    }
}

void inserir_primeiro(Produto* &inicio, Produto* &ultimo, Produto auxiliar){ //Função de inserir o primeiro produto

    Produto* temp = new Produto; //cria um novo ponteiro auxiliar
    temp->codigo = auxiliar.codigo; // o ponteiro criado recebe os valores da estrada passados por parâmetro
    temp->nome = auxiliar.nome;
    temp->preco = auxiliar.preco;
    temp->proximo = NULL; // o novo ponteiro aponta para o NULL
    inicio = temp; // o primeiro produto recebe o novo ponteiro
    ultimo = temp; // o ultimo produto também recebe o novo ponteiro
}

void inserir(Produto* &inicio, Produto* &ultimo, Produto auxiliar){ // Função de inserção
    Produto* temp; // declaração da variável auxiliar

    if (inicializa_lista(inicio)) { // retorno para a função booleana: caso seja a primeira inserção do código
        inserir_primeiro(inicio, ultimo, auxiliar); // retorna para a função de inserir o primeiro
    }
    else {
        temp = new Produto; // novo ponteiro
        temp->codigo = auxiliar.codigo; // o ponteiro criado recebe os valores da estrada passados por parâmetro
        temp->nome = auxiliar.nome;
        temp->preco = auxiliar.preco;
        temp->proximo = NULL; // proximo aponta para null
        ultimo->proximo = temp; // primeiro aponta para o novo ponteiro
        ultimo = temp; // temp passa a ser o primeiro
    }
}

int buscar_produto(Produto* prod_buscar, int &busca_aux){ // função para busca de produtos

    if(prod_buscar->codigo == busca_aux){ // caso o codigo seja igual ao auxiliar de busca(passado por parametro)
        cout << endl << "\t\t----------------------" <<endl << endl;
        cout << "\t\t" << " - PRODUTO: - ";
        cout << endl << endl << endl;
        cout << "\t\t" << "Nome do produto: " << prod_buscar->nome;
        cout << endl << endl << "\t\tCódigo do produto: " << prod_buscar->codigo;
        cout << endl << endl << "\t\tPreço do produto: " << prod_buscar->preco << " R$";
        cout << endl << endl << "\t\t";
        system("pause>nul");
    }
    else if(prod_buscar->proximo == NULL){ // Caso não haja proximo e ainda não foi encontrado o produto
        cout << endl << endl;
        cout << "\t\t" << " | - PRODUTO NÃO ENCONTRADO!! - |";
        cout << endl << endl << endl;
        system("pause>nul");
    }
    else {
        return (buscar_produto(prod_buscar->proximo, busca_aux));// caso nenhum dos anteriores aconteça, retorna para a mesma função, mas com um ponteiro diferente
    }
}


int remover_produto(Produto* &prod_remover, int &remover_aux){ //Função de remover
    Produto* aux_mostrar; // ponteiro criado apenas para mostrar o produto excluido
    Produto* prod_aux; // ponteiro auxiliar para remoção

    if(prod_remover->codigo == remover_aux){ //Caso o primeiro ponteiro seja o encontrado
       prod_aux = prod_remover; // auxiliar recebe o endereço do ponteiro
       prod_remover = prod_remover->proximo; // o ponteiro inicial aponta para o proximo
       aux_mostrar = prod_aux; // recebendo para apenas mostrar
       delete prod_aux; //primeira posição é deletada
    }
    else {
        Produto* prod_atual = prod_remover; //criado um ponteiro atual
        while(prod_atual->proximo != NULL){ // caso o proximo ponteiro não seja NULL
            if(prod_atual->proximo->codigo == remover_aux){ // o ponteiro atual aponta para o codigo do proximo para comparação com o codigo desejado para remoção
                prod_aux = prod_atual->proximo; // caso encontrado, o auxiliar recebe o endereço do proximo ponteiro
                prod_atual->proximo = prod_atual->proximo->proximo; // o ponteiro atual recebe o endereço do produto posterior ao que será eliminado
                aux_mostrar = prod_aux; // recebendo para apenas mostrar
                delete prod_aux; // posição seguinte ao atual é deletada
                break; //caso aconteça, parar o laço
            } else {
                return remover_produto(prod_remover->proximo, remover_aux); // caso o ponteiro atual não se encaixe, retorna o proximo endereço
            }
        }
    }

    if(aux_mostrar->codigo == remover_aux){ // mostrar o nome do produto eliminado
        cout << endl << endl;
        cout << "\t\tRemoção concluída! Produto removido: " << aux_mostrar->nome;
        cout << endl << endl << "\t\t";
    }
}

int mostra_produtos(Produto* prod_mostrar){ // função para a amostra constante

    if (prod_mostrar == NULL) { // caso não haja mais produtos no encadeamento
        return 1;
    }

    else if (prod_mostrar != NULL) { // caso o produto atual seja diferente de NULL
        cout << "\t\t" << "Nome do produto: " << prod_mostrar->nome;
        cout << endl << endl << "\t\tCódigo do produto: " << prod_mostrar->codigo;
        cout << endl << endl << "\t\tPreço do produto: " << prod_mostrar->preco << " R$";
        cout << endl << endl << "\t\t" << "----------------------" << endl << endl;
    }
    return mostra_produtos(prod_mostrar->proximo);// retorna para o proximo produto
}

int menu(){ // menu usado na seleção das funcionalidades

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
