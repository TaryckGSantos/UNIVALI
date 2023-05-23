#include "../../headers/PetsTypes/ListaPassaros.h"
#include <vector>
#include <iostream>

// Construtores e destrutores
ListaPassaros::ListaPassaros(){}
ListaPassaros::ListaPassaros(std::vector<Passaro> vPassaros){
  this->vPassaros = vPassaros;
}

/*getters*/
std::vector<Passaro> ListaPassaros::getListaPassaros(){
  return this->vPassaros;
}

void ListaPassaros::addPassaro(Passaro& passaro){ // função para adicionar um objeto pássaro
  this->vPassaros.push_back(passaro);
}

void ListaPassaros::rmvPassaro(Passaro& passaro){ // função para remover um objeto pássaro
  if (this->vPassaros.size() == 0) return; // caso não tenha nada na lista 
  if (this->vPassaros.size() == 1){ // caso haja apenas um elemento
    this->vPassaros.erase(this->vPassaros.begin());
    return;
  }
  std::vector<Passaro>::iterator iter = this->vPassaros.begin();

  for ( ; iter != this->vPassaros.end(); iter++){
    if (iter->getId() == passaro.getId()){
      this->vPassaros.erase(iter);
    }
  }
}
void ListaPassaros::imprimeLista(){ // função para imprimir a lista 
  if (this->vPassaros.size() == 0) {  // caso esteja vazia 
    std::cout << "Nenhum Passaro" << std::endl;
    return;
  };
  for (std::vector<Passaro>::iterator iter = this->vPassaros.begin(); iter != this->vPassaros.end(); iter++){
    std::cout << iter->getId() << "- " << iter->getNome() << std::endl;
  }
}

Passaro ListaPassaros::getPassaro(std::string id){ // função para retornar um elemento através de seu ID
    std::vector<std::string> rp;
    std::vector<Servico> sd;
    Passaro p = Passaro("","","","","",rp,"",sd);
  if (this->vPassaros.size() == 0){ // caso a lista esteja vazia 
    return p;
  }
  if (this->vPassaros.size() == 1){ // caso haja apenas um elemento
    if (this->vPassaros[0].getId() == id){
      p = this->vPassaros[0];
    }
    return p;
  }
  for ( int i = 0; i > this->vPassaros.size(); i++){
    if (this->vPassaros[i].getId() == id){
      p = this->vPassaros[i];
    }
  }
  return p;
}