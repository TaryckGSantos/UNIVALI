#include <iostream>
using namespace std;
#include <stdlib.h>
#include <time.h>

class dado_Cliente {
private:
    int codigo;
    string nome;
    string rua;
    string bairro;
    string numero;
    long long int telefone;
    dado_Cliente * proximo;
public:
    dado_Cliente(int codigo, string nome, string rua, string bairro, string numero, int telefone) {
        this->codigo = codigo;
        this->nome = nome;
        this->rua = rua;
        this->bairro = bairro;
        this->telefone = telefone;
    }
    int getCodigo() const {
        return codigo;
    }
    string getNome() const {
        return nome;
    }
    string getEndereco() const {
        return rua + ", " + bairro;
    }
    int getTelefone() const {
        return telefone;
    }
};

class ConjuntoClientes {
private:
    ConjuntoClientes * inicio;
    int tamanho;
public:
    int getConjuntoClientes(ConjuntoClientes &lista_clientes){
        lista_clientes.inicio = NULL;
        this->inicio = &lista_clientes;
        this->tamanho = tamanho;
    }
    bool inicializar_lista_clientes(ConjuntoClientes &lista_clientes) {
        lista_clientes.inicio = NULL;
        this->inicio = &lista_clientes;
        this->tamanho = 0;
        return true;
    }
    int adicionarCliente(ConjuntoClientes &lista_clientes) {
        if(lista_clientes.inicio == NULL){
            dado_Cliente * novo = new dado_Cliente;
            novo->proximo = NULL;
            lista.inicio = novo;
        } else {
            dado_Cliente * novo = new dado_Cliente;
            novo->proximo = lista.inicio;
            lista.inicio = novo;
        }
    }
    int removerCliente(int codigo, const ConjuntoClientes &lista_clientes){
        dado_Cliente * nav = lista_clientes.inicio;
        while(codigo != nav.codigo){
            nav = nav->proximo;
        }
    }
    void imprimirClientes() const {
        dado_Cliente * nav = lista_clientes.inicio;
        while(nav->proximo != NULL) {
            cout << "Código: " << dado_Cliente.getCodigo() << endl;
            cout << "Nome: " << dado_Cliente.getNome() << endl;
            cout << "Endereço: " << dado_Cliente.getEndereco() << endl;
            cout << "Número de Telefone: " << dado_Cliente.getTelefone() << endl;
            cout << endl;
        }
    }
};

int main() {
    setlocale(LC_ALL, "Portuguese");

    ConjuntoClientes conjunto;
    Cliente cliente1(1, "Fulano", "Rua A", "Bairro X", 10);
    Cliente cliente2(2, "Ciclano", "Rua B", "Bairro Y", 20);
    Cliente cliente3(3, "Beltrano", "Rua C", "Bairro Z", 30);
    conjunto.adicionarCliente(cliente1);
    conjunto.adicionarCliente(cliente2);
    conjunto.adicionarCliente(cliente3);
    conjunto.imprimirClientes();
    conjunto.removerCliente(2);
    conjunto.imprimirClientes();
    return 0;
}
