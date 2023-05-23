#include "./headers/Servico.h"
#include "./headers/ListaServicos.h"
#include "./headers/Cliente.h"
#include "./headers/ListaClientes.h"
#include "./headers/Produto.h"
#include "./headers/ListaProdutos.h"
#include "./headers/PetsTypes/Cachorro.h"
#include "./headers/PetsTypes/ListaCachorros.h"
#include "./headers/PetsTypes/ListaPassaros.h"
#include "./headers/PetsTypes/Passaro.h"
#include "./headers/Petshop.h"
#include <string>
#include <vector>
#include <iostream>
/* trabalho feito por: Paulo Martino Hermans, Eduardo Lechinski Ramos e Taryck Gean Santos Pego  */

int main(){
  /*lists default*/
  ListaPassaros listaPassaros;
  ListaCachorros listaCachorros;
  ListaServicos listaServicos;
  ListaProdutos listaProdutos;
  ListaProdutos listaCompras;
  ListaClientes listaClientes;
  Pet_data pet;
  Petshop petshop = Petshop(listaClientes,listaProdutos,listaCompras,listaServicos,listaPassaros,listaCachorros);
 /*lists default*/

  /*variables for constructors*/
  Produto produto;
  Cliente cliente;
  Servico servico;
  Passaro passaro;
  Cachorro cachorro;
  std::string nome;
  int static idProduto;
  int static idServico;
  int static idCliente;
  int static idCachorro;
  int static idPassaro;
  int amount;
  std::string id;
  float valor;
  std::string descricao;
  int quantidade;
  std::string selecter;
  std::string tipoServico;
  int which;
  std::string rua;
  std::string bairro;
  std::string telefone;
  std::string tipoPelo;
  bool isCastrado;
  std::string raca;
  std::string tamanho;
  std::string tipoPena;
  std::string tipoBico;

    setlocale(LC_ALL, "Portuguese");


    int aux_menu;

     do{
        std::cout << "\n\n\t\t\t\t\tLoja de Petshop\n\n\n\n";
        std::cout << "\t\t\t1 | Menu de produtos" << std::endl;
        std::cout << "\t\t\t2 | Menu de serviços" << std::endl;
        std::cout << "\t\t\t3 | Menu de clientes" << std::endl;
        std::cout << "\t\t\t4 | Menu de pedidos" << std::endl;
        std::cout << "\t\t\t5 | Menu de Pets" << std::endl;
        std::cout << "\t\t\t6 | Encerrar o sistema" << std::endl << std::endl << std::endl;
        std::cout << "\t\t\tDigite onde você deseja navegar: ";
        std::cin >> aux_menu;

        switch(aux_menu){

            case 1:
                system("clear");
                int aux_menu_produtos;

                std::cout << "\n\n\t\t\t\t\tMenu de produtos";
                std::cout << "\n\n\n\t\t\t1 | Cadastrar um produto";
                std::cout << std::endl << "\t\t\t2 | Remover um produto";
                std::cout << std::endl <<  "\t\t\t3 | Vizualizar os produtos";
                std::cout << std::endl << "\t\t\t4 | Remover quantidade de um produto";
                std::cout << std::endl << "\t\t\t5 | Adcionar quandtidade de um produto";
                std::cout << "\n\n\n\t\t\tEscolha o que você deseja fazer: ";
                std::cin >> aux_menu_produtos;

                switch (aux_menu_produtos){

                    case 1:
                        system("clear");
                        ///Chama o inserir
                        
                        std::cout << "insira o nome do produto:" << std::endl;
                        std::cin.ignore();
                        std::getline(std::cin,nome);
                        std::cout << "\ninsira o valor do produto:" << std::endl;
                        std::cin >> valor;
                        std::cout << "\ninsira uma descrição do produto:" << std::endl;
                        std::cin.ignore();
                        std::getline(std::cin,descricao);
                        std::cout << "\ninsira uma quantidade para o produto:" << std::endl;
                        std::cin >> quantidade;
                        idProduto += 1;
                        id = std::to_string(idProduto);
                        produto = petshop.criarProduto(id,valor,nome,descricao,quantidade);
                        petshop.adcionarProduto(produto);
                        system("clear");
                        break;

                    case 2:
                        system("clear");
                        ///Chama remover;
                        petshop.getlistaProdutos().imprimeLista();
                        system("sleep 2");
                        system("clear");
                        if(petshop.getlistaProdutos().getListaProdutos().size() < 1) break;
                        std::cout << "qual produto deseja remover?" << std::endl;
                        std::cin >> selecter;
                        petshop.removerProduto(petshop.getProduto(selecter));
                        petshop.getlistaProdutos().imprimeLista();
                        
                        std::cout << "\n\n\n\t\t\tProduto removido! :)";
                        system("sleep 2");
                        system("clear");
                        break;

                    case 3:
                        system("clear");
                        ///Chama mostrar produtos;
                        petshop.getlistaProdutos().imprimeLista();
                        system("sleep 2");
                        system("clear");
                        break;

                    case 4:
                        system("clear");
                        ///Chama mostrar produtos;
                        petshop.getlistaProdutos().imprimeLista();
                        if(petshop.getlistaProdutos().getListaProdutos().size() < 1) break;
                        std::cout << "De qual produto deseja remover?" << std::endl;
                        std::cin >> selecter;
                        std::cout << "Quanto deseja Remover?" << std::endl;
                        std::cin >> amount;
                        petshop.getlistaProdutos().getProduto(selecter).rmvQuantidade(amount);
                        system("sleep 2");
                        system("clear");
                        break;

                    case 5: 
                        system("clear");
                        ///Chama mostrar produtos;
                        petshop.getlistaProdutos().imprimeLista();
                        if(petshop.getlistaProdutos().getListaProdutos().size() < 1) break;
                        std::cout << "De qual produto deseja adcionar?" << std::endl;
                        std::cin >> selecter;
                        std::cout << "Quanto deseja adcionar?" << std::endl;
                        std::cin >> amount;
                        petshop.getlistaProdutos().getProduto(selecter).addQuantidade(amount);
                        system("sleep 2");
                        system("clear");
                        break;
                }
                break;

            case 2:
                system("clear");
                int aux_menu_servicos;

                std::cout << "\n\n\t\t\t\t\tMenu de serviços";
                std::cout << "\n\n\n\t\t\t1 | Cadastrar um serviço";
                std::cout << std::endl << "\t\t\t2 | Remover um serviço";
                std::cout << std::endl <<  "\t\t\t3 | Vizualizar serviços";
                std::cout << std::endl <<  "\t\t\t4 | Realizar serviço";
                std::cout << "\n\n\n\t\t\tEscolha o que você deseja fazer: ";
                std::cin >> aux_menu_servicos;

                switch (aux_menu_servicos){

                    case 1:
                        system("clear");
                        ///Chama o inserir
                        std::cout << "Qual o tipo de servico?" << std::endl;
                         std::cin.ignore();
                        std::getline(std::cin,tipoServico);
                        std::cout << "Qual o preço do serviço?" << std::endl;
                        std::cin >> valor;
                        idServico += 1;
                        id = std::to_string(idServico);
                        servico = petshop.criarServico(tipoServico,id,valor);
                        petshop.adcionarServico(servico);
                        system("clear");
                        break;

                    case 2:
                        system("clear");
                        ///Chama remover;
                        petshop.getlistaServicos().imprimeLista();
                        if(petshop.getlistaServicos().getListaServicos().size() < 1) break;
                        std::cout << "qual serviço deseja remover?" << std::endl;
                        std::cin >> selecter;
                        petshop.removerServico(petshop.getServico(selecter));
                        petshop.getlistaServicos().imprimeLista();
                        std::cout << "\n\n\n\t\t\tServiço removido! :)";
                        system("sleep 2");
                        system("clear");
                        break;

                    case 3:
                        system("clear");
                        ///Chama mostrar serviços;
                        petshop.getlistaServicos().imprimeLista();
                        system("sleep 2");
                        system("clear");
                        break;

                    case 4:
                        system("clear");
                        ///Chama mostrar serviços;
                        petshop.getlistaServicos().imprimeLista();

                        std::cout << "\n Qual deseja realizar?" << std::endl;
                        std::cin >> selecter;
                        servico = petshop.getServico(selecter);
                        std::cout << "\nDeseja realizar em \n 1- Cachorro \n 2- Passaro" << std::endl;
                        std::cin >> which;
                        if (which == 1){
                          petshop.getlistaCachorros().imprimeLista();
                          if (petshop.getlistaCachorros().getListaCachorros().size() < 1) break;
                          std::cout<< "em qual Pet deseja realizar?";
                          std::cin >> selecter;
                          cachorro = petshop.getCachorro(selecter);
                          petshop.realizarServico(servico,cachorro);
                        } else if (which == 2){
                          petshop.getlistaPassaros().imprimeLista();
                          if (petshop.getlistaPassaros().getListaPassaros().size() < 1) break;
                          std::cout<< "em qual Pet deseja realizar?";
                          std::cin >> selecter;
                          passaro = petshop.getPassaro(selecter);
                          petshop.realizarServico(servico,passaro);
                        }
                        
                        system("sleep 2");
                        system("clear");

                }
                break;

            case 3:
                system("clear");
                int aux_menu_clientes;

                std::cout << "\n\n\t\t\t\t\tMenu de clientes";
                std::cout << "\n\n\n\t\t\t1 | Cadastrar um novo cliente";
                std::cout << std::endl << "\t\t\t2 | Remover um cliente";
                std::cout << std::endl <<  "\t\t\t3 | Vizualizar todos os cliente";
                std::cout << "\n\n\n\t\t\tEscolha o que você deseja fazer: ";
                std::cin >> aux_menu_clientes;

                switch (aux_menu_clientes){

                    case 1:
                        system("clear");
                        ///Chama o inserir
                        std::cout << "Nome do Cliente:"<< std::endl;
                        std::cin.ignore();
                        std::getline(std::cin,nome);
                        std::cout << "Rua:" << std::endl;
                        std::cin.ignore();
                        std::getline(std::cin,rua);
                        std::cout << "Bairro:" << std::endl;
                        std::cin.ignore();
                        std::getline(std::cin,bairro);
                        std::cout << "Telefone:" << std::endl;
                        std::cin.ignore();
                        std::getline(std::cin,telefone);
                        idCliente += 1;
                        id = std::to_string(idCliente);
                        cliente = petshop.criarCliente(id,pet,nome,rua,bairro,telefone);
                        petshop.adcionarCliente(cliente);
                        system("clear");
                        break;

                    case 2:
                        system("clear");
                        ///Chama remover;
                        petshop.getlistaClientes().imprimeLista();
                        if(petshop.getlistaClientes().getListaClientes().size() < 1) break;
                        std::cout << "qual Cliente deseja remover?" << std::endl;
                        std::cin.clear();
                        std::cin >> selecter;
                        std::cout << listaClientes.getCliente("1").getNome();
                        std::cout << "\n\n\n\t\t\tCliente removido! :)";
                        system("sleep 2");
                        system("clear");
                        break;

                    case 3:
                        system("clear");
                        ///Chama mostrar clientes;
                        petshop.getlistaClientes().imprimeLista();
                        system("sleep 2");
                        system("clear");
                        break;
                }
                break;

            case 4:
                system("clear");
                int aux_menu_pedidos;

                std::cout << "\n\n\t\t\t\t\tMenu de pedidos";
                std::cout << "\n\n\n\t\t\t1 | Fazer um novo pedido";
                std::cout << std::endl << "\t\t\t2 | Remover um pedido";
                std::cout << std::endl <<  "\t\t\t3 | Finalizar pedidos";
                std::cout << "\n\n\n\t\t\tEscolha o que você deseja fazer: ";
                std::cin >> aux_menu_pedidos;

                switch (aux_menu_pedidos){

                    case 1:
                        system("clear");
                        petshop.getlistaProdutos().imprimeLista();
                        std::cout <<"Qual deseja pedir?" << std::endl;
                        std::cin >> selecter;
                        ///Chama o inserir
                        petshop.adcionarCompra(petshop.getProduto(selecter));
                        system("sleep 2");
                        system("clear");
                        break;

                    case 2:
                        system("clear");
                        ///Chama remover;
                        petshop.getlistaCompras().imprimeLista();
                        std::cout <<"Qual deseja remover?" << std::endl;
                        std::cin >> selecter;
                        
                        petshop.removerCompra(petshop.getProduto(selecter));
                        std::cout << "\n\n\n\t\t\tPedido removido! :)";
                        system("sleep 2");
                        system("clear");
                        break;

                    case 3:
                        system("clear");
                        ///Chama Finalizar pedidos;
                        petshop.finalizarCompra();
                        petshop.getlistaCompras().getListaProdutos().clear();
                        system("sleep 2");
                        system("clear");
                        break;
                }
                break;
            case 5:
                  system("clear");
                int aux_menu_pets;

                std::cout << "\n\n\t\t\t\t\tMenu de Pets";
                std::cout << "\n\n\n\t\t\t1 | Adcionar um novo Pet";
                std::cout << std::endl << "\t\t\t2 | Remover um Pet";
                std::cout << std::endl <<  "\t\t\t3 | Mostrar Pets";
                std::cout << std::endl <<  "\t\t\t4 | Adcionar serviços disponíveis";
                std::cout << std::endl <<  "\t\t\t5 | Adcionar remédios possíveis";
                std::cout << "\n\n\n\t\t\tEscolha o que você deseja fazer: ";
                std::cin >> aux_menu_pets;

                switch (aux_menu_pets){

                    case 1:
                        system("clear");
                        ///Chama o inserir
                        std::cout << "\nDeseja inserir: \n1- Cachorro\n2- Passaro" << std::endl;
                        std::cin >> which;
                        if (which == 1) {
                          system("clear");
                          std::cout << "Qual o nome do cachorro" << std::endl;
                          std::cin.ignore();
                          std::getline(std::cin,nome);
                          std::cout << "Qual o tipo de pelo do cachorro?" << std::endl;
                          std::cin.ignore();
                          std::getline(std::cin,tipoPelo);
                          std::cout << "ele é castrado?" << std::endl << "1-Sim" << "\n2-Não\n";
                          std::cin >> which;
                          if (which == 1) isCastrado = true;
                          if (which == 2) isCastrado = false;
                          std::cout << "Qual a raça?" << std::endl;
                          std::cin.ignore();
                          std::getline(std::cin,raca);
                          std::cout << "Tamanho:" << std::endl;
                          std::cin.ignore();
                          std::getline(std::cin,tamanho);
                          system("clear");
                          petshop.getlistaClientes().imprimeLista();
                          std::cout << "De qual Cliente é o cachorro?" << std::endl;
                          std::cin >> id;
                          cachorro = petshop.criarCachorro(tipoPelo,isCastrado,raca,tamanho,nome,id);
                          petshop.adcionarCachorro(cachorro);
                        } else if (which == 2){
                          system("clear");
                          std::cout << "Qual o Nome do passaro?" << std::endl;
                          std::cin.ignore();
                          std::getline(std::cin,nome);
                          std::cout << "Qual o tipo de bico do passaro?" << std::endl;
                          std::cin.ignore();
                          std::getline(std::cin,tipoBico);
                          std::cout << "Qual o tipo de Pena?" << std::endl;
                          std::cin.ignore();
                          std::getline(std::cin,tipoPena);
                          std::cout << "Qual a raça?" << std::endl;
                          std::cin.ignore();
                          std::getline(std::cin,raca);
                          std::cout << "Tamanho:" << std::endl;
                          std::cin.ignore();
                          std::getline(std::cin,tamanho);
                          
                          system("clear");
                          petshop.getlistaClientes().imprimeLista();
                          std::cout << "De qual Cliente é o Passaro?" << std::endl;
                          std::cin >> id;
                          passaro = petshop.criarPassaro(tipoPelo,tipoPena,raca,tamanho,nome,id);
                          petshop.adcionarPassaro(passaro);
                        }
                        system("clear");
                        break;

                    case 2:
                        system("clear");
                        ///Chama remover;
                        std::cout << "\nDeseja remover: \n1- Cachorro\n2- Passaro" << std::endl;
                        std::cin >> which;
                        if (which == 1){
                          petshop.getlistaCachorros().imprimeLista();
                          std::cout << "Qaul deseja remover?";
                          std::cin >> selecter;
                          petshop.removerCachorro(petshop.getCachorro(selecter));
                        } else if (which == 2) {
                          petshop.getlistaPassaros().imprimeLista();
                          std::cout << "Qaul deseja remover?";
                          std::cin >> selecter;
                          petshop.removerPassaro(petshop.getPassaro(selecter));
                        }


                        std::cout << "\n\n\n\t\t\tPet removido! :)";
                        system("sleep 2");
                        system("clear");
                        break;

                    case 3:
                        system("clear");
                        
                        ///Chama Mostrar pets;
                        std::cout << "\nDeseja listar: \n1- Cachorro\n2- Passaro" << std::endl;
                        std::cin >> which;
                        if (which == 1){
                          petshop.getlistaCachorros().imprimeLista();

                        } else if (which == 2) {
                          petshop.getlistaPassaros().imprimeLista();
                        }
                        system("sleep 2");
                        system("clear");
                        break;
                    case 4:
                        system("clear");
                        std::cout << "Deseja fazer a operação com: \n1-Cachorro \n2-Passaro\n";
                        std::cin >> which;
                        petshop.getlistaServicos().imprimeLista();
                        std::cout << "Qual seriço deseja colocar?" << std::endl;
                        std::cin >> selecter;
                        servico = petshop.getServico(selecter);
                        if (which == 1){
                          system("clear");
                          petshop.getlistaCachorros().imprimeLista();
                          std::cout << "Em qual Cachorro deseja Colocar?" << std::endl;
                          std::cin >> selecter;
                          cachorro = petshop.getCachorro(selecter);
                          cachorro.addServicoDisponivel(servico);
                          petshop.removerCachorro(cachorro);
                          petshop.adcionarCachorro(cachorro);
                        } else if (which == 2) { 
                          system("clear");
                          petshop.getlistaPassaros().imprimeLista();
                          std::cout << "Em qual Passaro deseja Colocar?" << std::endl;
                          std::cin >> selecter;
                          passaro = petshop.getPassaro(selecter);
                          passaro.addServicoDisponivel(servico);
                          petshop.removerPassaro(passaro);
                          petshop.adcionarPassaro(passaro);
                          std::cout << passaro.getServicosDisponiveis().back().getTipoServico() << std::endl;
                        }

                        system("sleep 2");
                        system("clear");
                }
                break;


            case 6:
                system("clear");
                std::cout << "\n\n\t\tSistema encerrado! :)";
                system("sleep 2");
                exit(0);
                break;
        }
    } while(aux_menu != 6);

  return 0;
}
