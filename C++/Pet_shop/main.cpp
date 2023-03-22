#include <iostream>
using namespace std;

class strc_endereco{
    string rua;
    string bairro;
    int numero;
    
    public: 
        strc_endereco(const string &rua, const string &bairro, int &numero);
        void cadastrar_endereco (const string &rua, const string &bairro, int &numero) const;
};

void strc_endereco::cadastrar_endereco() const{
    cout << "\n\n\n\t\t\tDigite o nome da rua: ";
    cin >> rua;
    cout << "\n\n\t\t\tDigite o bairro: ";
    cin >> bairro;
    cout << "\n\n\t\t\tDigite o número da casa: ";
    cin >> numero;
}

class dados_cliente{
    string nome;
    int codigo;
    strc_endereco endereco;
    
    public:
        dados_cliente(const string &nome, int &codigo, strc_endereco &endereco);
        int inserir_dados(const string &nome, int &codigo, strc_endereco &endereco);
        
};

int dados_cliente::inserir_dados() const{
    cout << "\n\n\n\t\t\tDigite o nome dp cliente: ";
    cin >> nome;
    cout << "\n\n\t\t\tDigite o codigo do cliente: ";
    cin >> codigo;
    endereço 
}

class colecao_clientes{
    
    class dados_cliente{
        string nome;
        int codigo;
        class class_endereco{
            string rua;
            string bairro;
            int numero;
        };
        strc_endereco endereco;
    };
    
    dados_cliente cliente;
    colecao_clientes * proximo;
    
    public:
        int cadastra_cliente(colecao_clientes &colecao){
            
        }
};

class cliente{
    string nome;
    int codigo;
    strc_endereco endereco;
    
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
