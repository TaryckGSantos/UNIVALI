#include <iostream>
#include <windows.h>
using namespace std;

///Inserir produto:

int main()
{
    setlocale(LC_ALL, "Portuguese");


    int aux_menu;

     do{
        cout << "\n\n\t\t\t\t\tLoja de Petshop\n\n\n\n";
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

                cout << "\n\n\t\t\t\t\tMenu de produtos";
                cout << "\n\n\n\t\t\t1 | Cadastrar um produto";
                cout << endl << "\t\t\t2 | Remover um produto";
                cout << endl <<  "\t\t\t3 | Vizualizar os produtos";
                cout << "\n\n\n\t\t\tEscolha o que você deseja fazer: ";
                cin >> aux_menu_produtos;

                switch (aux_menu_produtos){

                    case 1:
                        system("cls");
                        ///Chama o inserir
                        system("cls");
                        break;

                    case 2:
                        system("cls");
                        ///Chama remover;
                        cout << "\n\n\n\t\t\tProduto removido! :)";
                        system("pause>nul");
                        system("cls");
                        break;

                    case 3:
                        system("cls");
                        ///Chama mostrar produtos;
                        system("pause>nul");
                        system("cls");
                        break;
                }
                break;

            case 2:
                system("cls");
                int aux_menu_servicos;

                cout << "\n\n\t\t\t\t\tMenu de serviços";
                cout << "\n\n\n\t\t\t1 | Cadastrar um serviço";
                cout << endl << "\t\t\t2 | Remover um serviço";
                cout << endl <<  "\t\t\t3 | Vizualizar serviços";
                cout << "\n\n\n\t\t\tEscolha o que você deseja fazer: ";
                cin >> aux_menu_servicos;

                switch (aux_menu_servicos){

                    case 1:
                        system("cls");
                        ///Chama o inserir
                        system("cls");
                        break;

                    case 2:
                        system("cls");
                        ///Chama remover;
                        cout << "\n\n\n\t\t\tServiço removido! :)";
                        system("pause>nul");
                        system("cls");
                        break;

                    case 3:
                        system("cls");
                        ///Chama mostrar serviços;
                        system("pause>nul");
                        system("cls");
                        break;
                }
                break;

            case 3:
                system("cls");
                int aux_menu_clientes;

                cout << "\n\n\t\t\t\t\tMenu de clientes";
                cout << "\n\n\n\t\t\t1 | Cadastrar um novo cliente";
                cout << endl << "\t\t\t2 | Remover um cliente";
                cout << endl <<  "\t\t\t3 | Vizualizar todos os cliente";
                cout << "\n\n\n\t\t\tEscolha o que você deseja fazer: ";
                cin >> aux_menu_servicos;

                switch (aux_menu_clientes){

                    case 1:
                        system("cls");
                        ///Chama o inserir
                        system("cls");
                        break;

                    case 2:
                        system("cls");
                        ///Chama remover;
                        cout << "\n\n\n\t\t\tCliente removido! :)";
                        system("pause>nul");
                        system("cls");
                        break;

                    case 3:
                        system("cls");
                        ///Chama mostrar clientes;
                        system("pause>nul");
                        system("cls");
                        break;
                }
                break;

            case 4:
                system("cls");
                int aux_menu_pedidos;

                cout << "\n\n\t\t\t\t\tMenu de pedidos";
                cout << "\n\n\n\t\t\t1 | Fazer um novo pedido";
                cout << endl << "\t\t\t2 | Remover um pedido";
                cout << endl <<  "\t\t\t3 | Vizualizar pedidos";
                cout << "\n\n\n\t\t\tEscolha o que você deseja fazer: ";
                cin >> aux_menu_pedidos;

                switch (aux_menu_pedidos){

                    case 1:
                        system("cls");
                        ///Chama o inserir
                        system("cls");
                        break;

                    case 2:
                        system("cls");
                        ///Chama remover;
                        cout << "\n\n\n\t\t\tPedido removido! :)";
                        system("pause>nul");
                        system("cls");
                        break;

                    case 3:
                        system("cls");
                        ///Chama mostrar pedidos;
                        system("pause>nul");
                        system("cls");
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

