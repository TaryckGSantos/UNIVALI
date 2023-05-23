#include "../headers/ListaProdutos.h"
#include <vector>
#include <iostream>

// Inicializações dos construtores
ListaProdutos::ListaProdutos(){}
ListaProdutos::ListaProdutos(std::vector<Produto> vProdutos){
  this->vProdutos = vProdutos;
}

/*getters*/
std::vector<Produto> ListaProdutos::getListaProdutos(){ // retorna a lista de clientes
  return this->vProdutos;
}

void ListaProdutos::addProduto(Produto& produto){ // adiciona um produto na lista 
  this->vProdutos.push_back(produto);
}

void ListaProdutos::rmvProduto(Produto& produto){ // remove um produto da lista
  if (this->vProdutos.size() == 0) return; // caso a lista esteja vazia
  if (this->vProdutos.size() == 1){ // caso haja apenas 1 produto 
    this->vProdutos.erase(this->vProdutos.begin());
    return;
  }
  std::vector<Produto>::iterator iter = this->vProdutos.begin();

  for ( ; iter != this->vProdutos.end(); iter++){
    if (iter->getId() == produto.getId()){
      this->vProdutos.erase(iter);
    }
  }
}

void ListaProdutos::imprimeLista(){ // imprimir lista
  if (this->vProdutos.size() == 0) { // caso esteja vazia
    std::cout << "Nenhum produto" << std::endl;
    return;
  };
  // caso não esteja
  for (std::vector<Produto>::iterator iter = this->vProdutos.begin(); iter != this->vProdutos.end(); iter++){
    std::cout << iter->getId() << "- " << iter->getNome()<< std::endl;
  }
}

Produto ListaProdutos::getProduto(std::string id){// Função que busca um produto na lista de produtos através de seu ID

  Produto p = Produto("",0,"","",0);
  if (this->vProdutos.size() == 0){ // caso a lista esteja vazia 
    return p;
  }
  if (this->vProdutos.size() == 1){ // caso a lista tenha apenas 1 elemento
    if (this->vProdutos[0].getId() == id){
      p = this->vProdutos[0];
    }
    return p;
  }
  for ( int i = 0; i < this->vProdutos.size(); i++){ 
    if (this->vProdutos[i].getId() == id){
      p = this->vProdutos[i];
    }
  }
  return p;
}