#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Cliente {
private:
    int codigo;
    string nome;
    string rua;
    string bairro;
    int telefone;
public:
    Cliente(int codigo, string nome, string rua, string bairro, int telefone) {
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
    Cliente * clientes;
public:
    void adicionarCliente(const Cliente& cliente) {
        clientes.push_back(cliente);
    }
    void removerCliente(int codigo) {
        for (auto it = clientes.begin(); it != clientes.end(); ++it) {
            if (it->getCodigo() == codigo) {
                clientes.erase(it);
                break;
            }
        }
    }
    void imprimirClientes() const {
        for (const auto& cliente : clientes) {
            cout << "Código: " << cliente.getCodigo() << endl;
            cout << "Nome: " << cliente.getNome() << endl;
            cout << "Endereço: " << cliente.getEndereco() << endl;
            cout << endl;
        }
    }
};

int main() {
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
