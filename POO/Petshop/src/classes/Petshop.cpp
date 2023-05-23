#include "../headers/Petshop.h"
#include <iostream>

// Construtores e destrutores
Petshop::Petshop(ListaClientes listaClientes, ListaProdutos listProdutos, ListaProdutos listaCompras, ListaServicos listaServicos, ListaPassaros listaPassaros, ListaCachorros listaCachorros)
{
  this->listaClientes = listaClientes;
  this->listaProdutos = listProdutos;
  this->listaCompras = listaCompras;
  this->listaServicos = listaServicos;
  this->listaPassaros = listaPassaros;
  this->listaCachorros = listaCachorros;
}

/*getters*/
ListaClientes Petshop::getlistaClientes(){
  return this->listaClientes;
}
ListaProdutos Petshop::getlistaProdutos(){
  return this->listaProdutos;
}
ListaProdutos Petshop::getlistaCompras(){
  return this->listaCompras;
}
ListaServicos Petshop::getlistaServicos(){
  return this->listaServicos;
}
ListaPassaros Petshop::getlistaPassaros(){
  return this->listaPassaros;
}
ListaCachorros Petshop::getlistaCachorros(){
  return this->listaCachorros;
}

/*setters*/
Produto Petshop::getProduto(std::string id){
  return this->listaProdutos.getProduto(id);
}
Servico Petshop::getServico(std::string id){
  return this->listaServicos.getServico(id);
}
Cliente Petshop::getCliente(std::string id){
  return this->listaClientes.getCliente(id);
}
Cachorro Petshop::getCachorro(std::string id){
  return this->listaCachorros.getCachorro(id);
}
Passaro Petshop::getPassaro(std::string id){
  return this->listaPassaros.getPassaro(id);
}

// Funções de adição
void Petshop::adcionarProduto(Produto produto){
  this->listaProdutos.addProduto(produto);
}
void Petshop::adcionarServico(Servico servico){
  this->listaServicos.addServico(servico);
}
void Petshop::adcionarCliente(Cliente cliente){
  this->listaClientes.addCliente(cliente);
}
void Petshop::adcionarCompra(Produto produto)
{ 
  if (produto.getQuantidade() == 0)  {
    std::cout << "impossivel, não possui produtos";
    return;
    };
  this->listaProdutos.rmvProduto(produto);
  produto.rmvQuantidade(1);
  this->listaProdutos.addProduto(produto);
  produto.setQuantidade(1);
  this->listaCompras.addProduto(produto);

}

// Funções de remoção
void Petshop::removerCompra(Produto produto){
  this->listaCompras.rmvProduto(produto);
  this->getProduto(produto.getId()).addQuantidade(1);
}

void Petshop::adcionarCachorro(Cachorro cachorro){
  this->listaCachorros.addCachorro(cachorro);
}
void Petshop::adcionarPassaro(Passaro passaro){
  this->listaPassaros.addPassaro(passaro);
}
void Petshop::removerProduto(Produto produto){
  this->listaProdutos.rmvProduto(produto);
}
void Petshop::removerServico(Servico servico){
  this->listaServicos.rmvServico(servico);
}
void Petshop::removerClinete(Cliente clinete){
  this->listaClientes.rmvCliente(clinete);
}
void Petshop::removerCachorro(Cachorro cachorro){
  this->listaCachorros.rmvCachorro(cachorro);
}
void Petshop::removerPassaro(Passaro passaro){
  this->listaPassaros.rmvPassaro(passaro);
}

void Petshop::finalizarCompra() // Função de finalizar compra 
{
  std::vector<Produto>::iterator iter = this->listaCompras.getListaProdutos().begin();
  float total;
  for (; iter != this->listaCompras.getListaProdutos().end(); iter++)
  {
    total += iter->getValor();
  }
  std::cout << "Total: " << total << std::endl;
}

void Petshop::realizarServico(Servico servico, Passaro& pet) { // função de realizar serviços no objeto "passaro"
  
  if (pet.getServicosDisponiveis().size() == 0){ // caso não haja serviços disponíveis
    std::cout << "este pet não possui serviços disponiveis" << std::endl;
    return;
  }
  if (pet.getServicosDisponiveis().size() == 1) { // caso haja apenas um serviço 
    if (pet.getServicosDisponiveis()[0].getId() == servico.getId()){
      std::cout << "Serviço " << pet.getServicosDisponiveis()[0].getTipoServico() << " custou: " << pet.getServicosDisponiveis()[0].getPreco() << std::endl;
      return;
    }
  }
  for ( int i = 0; i < pet.getServicosDisponiveis().size(); i++){ 
    if (pet.getServicosDisponiveis()[i].getId() == servico.getId()){
      std::cout << "Serviço " << pet.getServicosDisponiveis()[i].getTipoServico() << " custou: " << pet.getServicosDisponiveis()[i].getPreco() << std::endl;
      return;
    }
  }
  std::cout << "este Pet não pode ter esse serviço, adicione na lista de possivéis se necessário" << std::endl;
}

void Petshop::realizarServico(Servico servico, Cachorro &pet) { // função de realizar serviços no objeto "cachorro"
  if (pet.getServicosDisponiveis().size() == 0){ // caso não haja serviços disponíveis
    std::cout << "este pet não possui serviços disponiveis" << std::endl;
    return;
  }
  if (pet.getServicosDisponiveis().size() == 1) { // caso haja apenas um serviço 
    if (pet.getServicosDisponiveis()[0].getId() == servico.getId()){
      std::cout << "Serviço " << pet.getServicosDisponiveis()[0].getTipoServico() << " custou: " << pet.getServicosDisponiveis()[0].getPreco() << std::endl;
      return;
    }
  }
  for ( int i = 0; i < pet.getServicosDisponiveis().size(); i++){
    if (pet.getServicosDisponiveis()[i].getId() == servico.getId()){
      std::cout << "Serviço " << pet.getServicosDisponiveis()[i].getTipoServico() << " custou: " << pet.getServicosDisponiveis()[i].getPreco() << std::endl;
      return;
    }
  }
  std::cout << "algo deu errado" << std::endl;
}

// Funções de criar um objeto cliente
Cliente Petshop::criarCliente(std::string id, std::string nome, std::string rua, std::string bairro, std::string telefone) {
  Cliente cliente = Cliente(id,nome,rua,bairro,telefone);
  return cliente;
}

Cliente Petshop::criarCliente(std::string id, Pet_data pet, std::string nome, std::string rua, std::string bairro, std::string telefone) {
  Cliente cliente = Cliente(id,pet,nome,rua,bairro,telefone);
  return cliente;
}

Servico Petshop::criarServico(std::string tipoServico,std::string id, double preco) { // função de criar um objeto serviço
  Servico servico = Servico(tipoServico,id,preco);
  return servico;
}

Produto Petshop::criarProduto(std::string id, float valor, std::string nome, std::string descricao, int quantidade) { // função de criar um objeto produto
  Produto prduto = Produto(id, valor, nome, descricao,quantidade);
  return prduto;
}

// função de criar um novo objeto: cachorro
Cachorro Petshop::criarCachorro(std::string tipoPelo, bool isCastrado, std::string raca, std::string tamanho, std::string nome, std::string idCliente) {
  
  std::vector<std::string> remediosPossiveis;
  std::vector<Servico> servicosDisponiveis;
  if(this->getlistaClientes().getCliente(idCliente).getId() == idCliente){
    Cachorro cachorro = Cachorro(tipoPelo,isCastrado,raca,tamanho,nome,remediosPossiveis,idCliente,servicosDisponiveis);
    return cachorro;
  }
  Cachorro c = Cachorro("",true,"","","",remediosPossiveis,"",servicosDisponiveis);
  return c;
}

// função de criar um novo objeto: pássaro
Passaro Petshop::criarPassaro(std::string tipoBico,std::string tipoPena, std::string raca, std::string tamanho, std::string nome, std::string idCliente) {
  
  std::vector<std::string> remediosPossiveis;
  std::vector<Servico> servicosDisponiveis;
  if (this->getlistaClientes().getCliente(idCliente).getId() == idCliente){
    Passaro passaro = Passaro(tipoBico,tipoPena,raca,tamanho,nome,remediosPossiveis,idCliente,servicosDisponiveis);
    return passaro;
  }
  Passaro p = Passaro("","","","","",remediosPossiveis,"",servicosDisponiveis);
  std::cout << "ERROR: ";
  return p;
}
