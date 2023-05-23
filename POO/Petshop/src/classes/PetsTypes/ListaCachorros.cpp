#include "../../headers/PetsTypes/ListaCachorros.h"
#include <vector>
#include <iostream>

// construtores e destrutores
ListaCachorros::ListaCachorros(){}
ListaCachorros::ListaCachorros(std::vector<Cachorro> vCachorros){
  this->vCachorros = vCachorros;
}

/*getters*/
std::vector<Cachorro> ListaCachorros::getListaCachorros(){
  return this->vCachorros;
}

void ListaCachorros::addCachorro(Cachorro& cachorro){ // função para adicionar um objeto cachorro
  this->vCachorros.push_back(cachorro);
}
void ListaCachorros::rmvCachorro(Cachorro& cachorro){ // função para remover um objeto cachorro
  if (this->vCachorros.size() == 0) return; // caso não tenha nada na lista 
  if (this->vCachorros.size() == 1){ // caso haja apenas um elemento
    this->vCachorros.erase(this->vCachorros.begin());
    return;
  }
  std::vector<Cachorro>::iterator iter = this->vCachorros.begin();

  for ( ; iter != this->vCachorros.end(); iter++){
    if (iter->getId() == cachorro.getId()){
      this->vCachorros.erase(iter);
    }
  }
}
void ListaCachorros::imprimeLista(){ // função para imprimir a lista 
  if (this->vCachorros.size() == 0) { // caso esteja vazia 
    std::cout << "Nenhum Cachorro" << std::endl;
    return;
  };
  for (std::vector<Cachorro>::iterator iter = this->vCachorros.begin(); iter != this->vCachorros.end(); iter++){
    std::cout << iter->getId() << "- " << iter->getNome() << std::endl;
  }
}

Cachorro ListaCachorros::getCachorro(std::string id){ // função para retornar um elemento através de seu ID
    std::vector<std::string> rp;
    std::vector<Servico> sd;
    Cachorro p = Cachorro("",false,"","","",rp,"",sd);
  if (this->vCachorros.size() == 0){ // caso a lista esteja vazia 
    return p;
  }
  if (this->vCachorros.size() == 1){ // caso haja apenas um elemento
    if (this->vCachorros[0].getId() == id){
      p = this->vCachorros[0];
    }
    return p;
  }
  for ( int i = 0; i < this->vCachorros.size(); i++){
    if (this->vCachorros[i].getId() == id){
      p = this->vCachorros[i];
    }
  }
  return p;
}