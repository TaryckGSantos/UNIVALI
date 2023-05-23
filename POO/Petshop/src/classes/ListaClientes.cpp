#include "../headers/ListaClientes.h"
#include <vector>
#include <iostream>

// Inicialização dos construtores
ListaClientes::ListaClientes(){}
ListaClientes::ListaClientes(std::vector<Cliente> vClientes){
  this->vClientes = vClientes;
}

/*getters*/
std::vector<Cliente> ListaClientes::getListaClientes(){ // retorna a lista de clientes
  return this->vClientes;
}

void ListaClientes::addCliente(Cliente& cliente){ // adiciona um cliente à lista
  this->vClientes.push_back(cliente);
}

void ListaClientes::rmvCliente(Cliente& cliente){ // remove um cliente da lista
  if (this->vClientes.size() == 0) return; // caso a lista esteja vazia
  if (this->vClientes.size() == 1){ // caso haja apenas 1 cliente 
    this->vClientes.erase(this->vClientes.begin());
    return;
  }
  std::vector<Cliente>::iterator iter = this->vClientes.begin();
  for ( ; iter != this->vClientes.end(); iter++){
    if (iter->getId() == cliente.getId()){
      this->vClientes.erase(iter);
    }
  }
}

void ListaClientes::imprimeLista(){ // função de imprimir lista
  if (this->vClientes.size() == 0) { // caso esteja vazia
    std::cout << "Nenhum Cliente" << std::endl;
    return;
  };
  // caso não esteja
  for (std::vector<Cliente>::iterator iter = this->vClientes.begin(); iter != this->vClientes.end(); iter++){
    std::cout << iter->getId() << "- " << iter->getNome() << std::endl;
  }
}

Cliente ListaClientes::getCliente(std::string id){ // Função que busca um cliente na lista de clientes através de seu ID
    Cliente p = Cliente("","","","","");
  if (this->vClientes.size() == 0){ // caso a lista esteja vazia 
    return p;
  }
  if (this->vClientes.size() == 1){ // caso a lista tenha apenas 1 elemento
    if (this->vClientes[0].getId() == id){
      p = this->vClientes[0];
    }
    return p;
  }
  for ( int i = 0; i < this->vClientes.size(); i++){
    if (this->vClientes[i].getId() == id){
      p = this->vClientes[i];
    }
  }
  return p;
}