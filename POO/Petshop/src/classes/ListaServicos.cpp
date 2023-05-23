#include "../headers/ListaServicos.h"
#include <vector>
#include <iostream>

// Inicialização dos construtores
ListaServicos::ListaServicos(){}
ListaServicos::ListaServicos(std::vector<Servico> vServicos){
  this->vServicos = vServicos;
}


/*getters*/
std::vector<Servico> ListaServicos::getListaServicos(){ // retorna a lista de serviços
  return this->vServicos;
}

void ListaServicos::addServico(Servico& servico){ // adiciona um serviço na lista 
  this->vServicos.push_back(servico);
}

void ListaServicos::rmvServico(Servico& servico){ // remove um serviço da lista 
  if (this->vServicos.size() == 0) return; // caso a lista esteja vazia
  if (this->vServicos.size() == 1){ // caso haja apenas 1 serviço 
    this->vServicos.erase(this->vServicos.begin());
    return;
  }
  std::vector<Servico>::iterator iter = this->vServicos.begin();

  for ( ; iter != this->vServicos.end(); iter++){
    if (iter->getTipoServico() == servico.getTipoServico()){
      this->vServicos.erase(iter);
    }
  }
}
void ListaServicos::imprimeLista(){ // função de imprimir a lista 
  if (this->vServicos.size() == 0) { // caso esteja vazia
    std::cout << "Nenhum servico" << std::endl;
    return;
  };
  // caso não esteja
  for (std::vector<Servico>::iterator iter = this->vServicos.begin(); iter != this->vServicos.end(); iter++){
    std::cout <<iter->getId() << "-" << iter->getTipoServico() << std::endl;
  }
}

Servico ListaServicos::getServico(std::string id){ // Função que busca um serviço na lista de serviços através de seu ID
    Servico p = Servico("","",0); // caso a lista esteja vazia 
  if (this->vServicos.size() == 0){
    return p;
  }
  if (this->vServicos.size() == 1){ // caso a lista tenha apenas 1 elemento
    if (this->vServicos[0].getId() == id){
      p = this->vServicos[0];
    }
    return p;
  }
  for ( int i = 0; i < this->vServicos.size(); i++){
    if (this->vServicos[i].getId() == id){
      p = this->vServicos[i];
    }
  }
  return p;
}