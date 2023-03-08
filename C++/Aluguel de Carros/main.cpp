#include <iostream>
#include <locale.h>
using namespace std;

class carro{
    string nome;
    string cor;
    string montadora;
    int qtd_lugares;
    float preco;
    string situacao;

public:
    int inserir_nome(string &aux_nome){
        cout << endl << "Insira o nome: ";
        cin >> aux_nome;
    }

    int inserir_montadora(string &aux_montadora){
        cout << endl << "Insira a montadora: ";
        cin >> aux_montadora;
    }

    int inserir_cor(string &aux_cor){
        cout << endl << "Insira a cor: ";
        cin >> aux_cor;
    }

    int inserir_lugares(int &aux_lugares){
        cout << endl << "Insira a quantidade de lugares: ";
        cin >> aux_lugares;
    }

    int inserir_preco(float &aux_preco){
        cout << endl << "Insira o preço do veículo: ";
        cin >> aux_preco;
    }

    int inserir_situcao(string &aux_situacao){
        cout << endl << "O carro está livre ou alugado? ";
        cin >> aux_situacao;
    }

    int mostrar(string &aux_nome, string &aux_montadora, string &aux_cor, int &aux_qtd_lugares, float &aux_preco, string &aux_situacao){
        nome = aux_nome;
        montadora = aux_montadora;
        cor = aux_cor;
        qtd_lugares = aux_qtd_lugares;
        preco = aux_preco;
        situacao = aux_situacao;

        cout << endl << endl << "Nome: " << nome;
        cout << endl << "Montadora: " << montadora;
        cout << endl << "Cor: " << cor;
        cout << endl << "Lugares: " << qtd_lugares;
        cout << endl << "Preço: " << preco;
        cout << endl << "Situação: " << situacao;
    }
};

class dados_cliente{
    string nome;
    int documento;
    int acompanhantes;
};

int main()
{
    setlocale(LC_ALL,"Portuguese");

    carro elemento;

    string aux_nome;
    string aux_montadora;
    string aux_cor;
    int aux_qtd_lugares;
    float aux_preco;
    string aux_situacao;

    elemento.inserir_nome(aux_nome);
    elemento.inserir_montadora(aux_montadora);
    elemento.inserir_cor(aux_cor);
    elemento.inserir_lugares(aux_qtd_lugares);
    elemento.inserir_preco(aux_preco);
    elemento.inserir_situcao(aux_situacao);
    elemento.mostrar(aux_nome, aux_montadora, aux_cor, aux_qtd_lugares, aux_preco, aux_situacao);

}
