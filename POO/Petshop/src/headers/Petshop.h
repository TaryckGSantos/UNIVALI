#ifndef Petshop_h
#define Petshop_h

#include "./ListaClientes.h"
#include "./ListaProdutos.h"
#include "./ListaServicos.h"
#include "./PetsTypes/ListaCachorros.h"
#include "./PetsTypes/ListaPassaros.h"

class Petshop // Declaração da classe PetShop
{
private: // Membros privados da Classe petshop
  ListaClientes listaClientes;
  ListaProdutos listaProdutos;
  ListaProdutos listaCompras;
  ListaServicos listaServicos;
  ListaPassaros listaPassaros;
  ListaCachorros listaCachorros;
public:
  // Construtor da classe Petshop
  Petshop(ListaClientes listaClientes, ListaProdutos listProdutos,ListaProdutos listaCompras, ListaServicos listaServicos, ListaPassaros listaPassaros,ListaCachorros listaCachorros);

  // retornam objetos de suas respectivas classes através de uma string
  Produto getProduto(std::string);
  Servico getServico(std::string);
  Cliente getCliente(std::string);
  Cachorro getCachorro(std::string);
  Passaro getPassaro(std::string);
  
  ListaClientes getlistaClientes();
  ListaProdutos getlistaProdutos();
  ListaProdutos getlistaCompras();
  ListaServicos getlistaServicos();
  ListaPassaros getlistaPassaros();
  ListaCachorros getlistaCachorros();

  // funções que adicionam objetos em suas respectivas classes
  void adcionarProduto(Produto);
  void adcionarCliente(Cliente);
  void adcionarServico(Servico);
  void adcionarCompra(Produto);
  void adcionarCachorro(Cachorro);
  void adcionarPassaro(Passaro);

  // funções que removem objetos em suas respectivas classes
  void removerProduto(Produto);
  void removerCachorro(Cachorro);
  void removerPassaro(Passaro);
  void removerServico(Servico);
  void removerClinete(Cliente);
  void removerCompra(Produto);

  void finalizarCompra(); // função de finalizar a compra
  void realizarServico(Servico, Passaro&); // Função que realiza um Serviço específico no animal "pássaro"
  void realizarServico(Servico, Cachorro&); // Função que realiza um Serviço específico no animal "cachorro"

  // Criam novos clientes e recebendo os dados e retornando um novo objeto    
  Cliente criarCliente(std::string id ,std::string nome, std::string rua, std::string bairro, std::string telefone);
  Cliente criarCliente(std::string id ,Pet_data pet ,std::string nome, std::string rua, std::string bairro, std::string telefone);
  
  // Cria um novo serviço recebendo seus respectivos dados
  Servico criarServico(std::string tipoServico,std::string id, double preco);

  // Cria um objeto produto recebendo seus dados
  Produto criarProduto(std::string id, float valor, std::string nome ,std::string descricao , int quantidade);
  
  // Criam novos animais com as informações recebidas
  Cachorro criarCachorro(std::string tipoPelo,bool isCastrado,std::string raca, std::string tamanho,std::string nome,std::string);
  Passaro criarPassaro(std::string tipoBico, std::string tipoPena,std::string raca, std::string tamanho,std::string nome, std::string);
};

#endif