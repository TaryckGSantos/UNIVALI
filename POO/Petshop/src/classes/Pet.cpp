#include "../headers/Pet.h"

/*Construtores e destrutores*/
Pet::Pet(std::string raca, std::string tamanho,std::string nome, std::vector<std::string> remediosPossiveis, std::string id, std::vector<Servico> servicosDisponiveis){
  this->raca = raca;
  this->tamanho = tamanho;
  this->remediosPossiveis = remediosPossiveis;
  this->id = id;
  this->servicosDisponiveis = servicosDisponiveis;
  this->nome = nome;
};
Pet::Pet(){}

/*getters*/
std::string Pet::getRaca(){
  return this->raca;
}
std::string Pet::getTamanho(){
  return this->tamanho;
}
std::string Pet::getNome(){
  return this->nome;
}
std::string Pet::getId(){
  return this->id;
}
std::vector<std::string> Pet::getRemediosPossiveis(){
  return this->remediosPossiveis;
}
std::vector<Servico> Pet::getServicosDisponiveis(){
  return this->servicosDisponiveis;
}


/*setters*/
void Pet::setRaca(std::string raca){
  this->raca = raca;
}
void Pet::setTamanho(std::string tamanho){
  this->tamanho = tamanho;
}
void Pet::setNome(std::string nome){
  this->nome = nome;
}
void Pet::setId(std::string id){
  this->id = id;
}

void Pet::addRemedioPossivel(std::string remedio){ // Função de adicionar um Pet
  this->remediosPossiveis.push_back(remedio);
}
void Pet::rmvRemedioPossivel(std::string remedio){ // Função de remover um Pet
  std::vector<std::string>::iterator iter = this->remediosPossiveis.begin();
  for(   ; iter < this->remediosPossiveis.end() ; iter++){
    if( *iter == remedio){
      this->remediosPossiveis.erase(iter);
    }
  }
}

void Pet::addServicoDisponivel(Servico servico){ // Função de adicionar um serviço 
  this->servicosDisponiveis.push_back(servico);
}
void Pet::rmvServicoDisponivel(Servico servico) { // Função de remover um serviço 
  if (this->servicosDisponiveis.size() == 0) return; // Caso não haja serviços disponíveis
  if (this->servicosDisponiveis.size() == 1){ // caso haja apenas um serviço disponível
    this->servicosDisponiveis.erase(this->servicosDisponiveis.begin());
    return;
  }
  std::vector<Servico>::iterator iter = this->servicosDisponiveis.begin();

  for ( ; iter != this->servicosDisponiveis.end(); iter++){ 
    if (iter->getTipoServico() == servico.getTipoServico()){
      this->servicosDisponiveis.erase(iter);
    }
  }
}