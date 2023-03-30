#include <iostream>
#include <windows.h>
using namespace std;

///   Inserir produto:
    string id;
    float valor;
    string nome;
    string descricao;
    int quantidade;

    cout << "\n\n\t\t\t\t\tInserir produto\n\n\n";
    cout << "\t\t\tInsira o ID do produto: ";
    cin >> id;
    cout << "\n\n\t\t\tInsira o nome do produto: ";
    cin >> nome;
    cout << "\n\n\t\t\tInsira o valor do produto: ";
    cin >> valor;
    cout << "\n\n\t\t\tInsira a descrição do produto: ";
    cin >> descricao;
    cout << "\n\n\t\t\tInsira a quantidade desse produto: ";
    cin >> quantidade;
    cout << "\n\n\t\t\tProduto inserido! :)";
    system("pause>nul");

///    Inserir serviço:
    string id;
    string tipoServico;
    double preco;

    cout << "\n\n\t\t\t\t\tInserir serviço\n\n\n";
    cout << "\t\t\tInsira o ID do serviço: ";
    cin >> id;
    cout << "\n\n\t\t\tInsira tipo de serviço: ";
    cin >> tipoServico;
    cout << "\n\n\t\t\tInsira o preço deste serviço: ";
    cin >> preco;
    cout << "\n\n\t\t\tServiço cadastrado! :)";
    system("pause>nul");

///     Inserir Pet
    string id;
    string tipo;

    cout << "\n\n\t\t\t\tCadastro de um novo pet\n\n\n";
    cout << "\t\t\tInsira o ID do PET: ";
    cin >> id;
    cout << "\n\n\t\t\tInsira o tipo de PET: ";
    cin >> tipo;
    cout << "\n\n\t\t\tTipo de PET cadastrado! :)";
    system("pause>nul");

///  Inserir Clientes
    string id;
    Pet_data pet;
    string nome;
    string rua;
    string bairro;
    string telefone;

    cout << "\n\n\t\t\t\t\tInserir clientes\n\n\n";
    cout << "\t\t\tInsira o ID do cliente: ";
    cin >> id;
    cout << "\n\n\t\t\tInsira o nome do cliente: ";
    cin >> nome;
    cout << "\n\n\t\t\tInsira o nome da rua do cliente: ";
    cin >> rua;
    cout << "\n\n\t\t\tInsira o nome do bairro do cliente: ";
    cin >> bairro;
    cout << "\n\n\t\t\tInsira o telefone do cliente: ";
    cin >> telefone;
    cout << "\n\n\t\t\tInsira o ID do pet do cliente : ";
    cin >> pet.id;
    cout << "\n\n\t\t\tCliente cadastrado! :)";
    system("pause>nul");

///  Remover produtos
    string aux_r;

    cout << "\n\n\t\t\t\t\tRemover produto\n\n\n";
    cout << "\t\t\tInsira o ID do produto que será removido: ";
    cin >> aux_r;

    //Lógica de remoção

    system("cls");
    cout << "\n\n\t\t\t\t\tProduto removido! :)";
    system("pause>nul");
    system("cls");

///    Remover serviço
    string aux_r;

    cout << "\n\n\t\t\t\t\tRemover serviço\n\n\n";
    cout << "\t\t\tInsira o ID do serviço que será removido: ";
    cin >> aux_r;

    //Lógica de remoção

    system("cls");
    cout << "\n\n\t\t\tServiço removido! :)";
    system("pause>nul");
    system("cls");

///   Remover PET
    string aux_r;

    cout << "\n\n\t\t\t\t\tRemover PETs\n\n\n";
    cout << "\t\t\tInsira o ID do PET que será removido: ";
    cin >> aux_r;

    //Lógica de remoção

    system("cls");
    cout << "\n\n\t\t\tPET removido! :)";
    system("pause>nul");
    system("cls");

///  Remover Cliente
    string aux_r;

    cout << "\n\n\t\t\t\t\tRemover cliente\n\n\n";
    cout << "\t\t\tInsira o ID do cliente que será removido: ";
    cin >> aux_r;

    //Lógica de remoção

    system("cls");
    cout << "\n\n\N\t\t\tCliente removido! :)";
    system("pause>nul");
    system("cls");

///        *IDEIA DE IMPRIMIR*

    //  ***produto***
    //laço de repetição
        cout << endl << endl;
        cout << "\t\t\tNome: " << nome << endl;
        cout << "\t\t\tValor: " << valor << endl;
        cout << "\t\t\tQuantidade: " << quantidade << endl;
        cout << "\t\t\tID: " << id << endl;
        cout << "\t\t\tDescrição: " << descricao << endl;
        system("pause>nul");
        system("cls");

    //  ***Serviços***
    //laço de repetição
        cout << endl << endl;
        cout << "\t\t\tServiço: " << tipoServico << endl;
        cout << "\t\t\tPreço: " << preco << endl;
        cout << "\t\t\tID: " << id << endl;
        system("pause>nul");
        system("cls");

    //  ***PETs***
    //laço de repetição
        cout << endl << endl;
        cout << "\t\t\tTipo de PET: " << tipo << endl;
        cout << "\t\t\tID: " << id << endl;
        system("pause>nul");
        system("cls");

    //  ***Cliente***
    //laço de repetição

        cout << endl << endl;
        cout << "\t\t\tNome: " << nome << endl;
        cout << "\t\t\tPET: " << pet.tipo << " - ID: " << pet.id << endl;
        cout << "\t\t\tTelefone: " << telefone << endl;
        cout << "\t\t\tEndereço: Rua " << rua << " - " << bairro << endl;
        cout << "\t\t\tID: " << id << endl;
        system("pause>nul");
        system("cls");

int main()
{
    setlocale(LC_ALL, "Portuguese");


    int aux_menu;

     do{
        cout << "\n\n\t\t\tLoja de Petshop\n\n\n\n";
        cout << "\t\t\t1 | Menu de produtos" << endl;
        cout << "\t\t\t2 | Menu de serviços" << endl;
        cout << "\t\t\t3 | Menu de clientes" << endl;
        cout << "\t\t\t4 | Menu de pedidos" << endl;
        cout << "\t\t\t5 | Encerrar o sistema" << endl << endl << endl;
        cout << "\t\t\tDigite onde você deseja navegar: ";
        cin >> aux_menu;

        switch(aux_menu){

            case 1:
                system("cls");
                int aux_menu_produtos;

                cout << "\n\n\t\t\tMenu de produtos";
                cout << "\n\n\n\t\t\t1 | Cadastrar um produto";
                cout << endl << "\t\t\t2 | Remover um produto";
                cout << endl <<  "\t\t\t3 | Vizualizar os produtos";
                cout << "\n\n\n\t\t\tEscolha o que você deseja fazer: ";
                cin >> aux_menu_produtos;

                switch (aux_menu_produtos){

                    case 1:
                        system("cls");

                        ///Chama o inserir

                        break;

                    case 2:
                        system("cls");

                        ///Chama remover;

                        break;

                    case 3:
                        system("cls");

                        ///Chama mostrar produtos;

                        break;
                }
                break;

            case 2:
                system("cls");
                int aux_menu_servicos;

                cout << "\n\n\t\t\tMenu de serviços";
                cout << "\n\n\n\t\t\t1 | Cadastrar um serviço";
                cout << endl << "\t\t\t2 | Remover um serviço";
                cout << endl <<  "\t\t\t3 | Vizualizar serviços";
                cout << "\n\n\n\t\t\tEscolha o que você deseja fazer: ";
                cin >> aux_menu_servicos;

                switch (aux_menu_servicos){

                    case 1:
                        system("cls");

                        ///Chama o inserir

                        break;

                    case 2:
                        system("cls");

                        ///Chama remover;

                        break;

                    case 3:
                        system("cls");

                        ///Chama mostrar serviços;

                        break;
                }
                break;

            case 3:
                system("cls");
                int aux_menu_clientes;

                cout << "\n\n\t\t\tMenu de clientes";
                cout << "\n\n\n\t\t\t1 | Cadastrar um novo cliente";
                cout << endl << "\t\t\t2 | Remover um cliente";
                cout << endl <<  "\t\t\t3 | Vizualizar todos os cliente";
                cout << "\n\n\n\t\t\tEscolha o que você deseja fazer: ";
                cin >> aux_menu_servicos;

                switch (aux_menu_clientes){

                    case 1:
                        system("cls");

                        ///Chama o inserir

                        break;

                    case 2:
                        system("cls");

                        ///Chama remover;

                        break;

                    case 3:
                        system("cls");

                        ///Chama mostrar clientes;

                        break;
                }
                break;

            case 4:
                system("cls");
                int aux_menu_pedidos;

                cout << "\n\n\t\t\tMenu de pedidos";
                cout << "\n\n\n\t\t\t1 | Fazer um novo pedido";
                cout << endl << "\t\t\t2 | Remover um pedido";
                cout << endl <<  "\t\t\t3 | Vizualizar pedidos";
                cout << "\n\n\n\t\t\tEscolha o que você deseja fazer: ";
                cin >> aux_menu_pedidos;

                switch (aux_menu_pedidos){

                    case 1:
                        system("cls");

                        ///Chama o inserir

                        break;

                    case 2:
                        system("cls");

                        ///Chama remover;

                        break;

                    case 3:
                        system("cls");

                        ///Chama mostrar pedidos;

                        break;
                }
                break;

            case 5:
                system("cls");
                cout << "\n\n\t\tSistema encerrado! :)";
                system("pause>nul");
                exit(0);
                break;
        }
    } while(aux_menu != 5);
    return 0;
}
