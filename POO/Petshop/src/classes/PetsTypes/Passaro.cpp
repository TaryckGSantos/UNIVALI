#include "../../headers/PetsTypes/Passaro.h"

// Construtores e destrutores
Passaro::Passaro(std::string tipoBico, std::string tipoPena,std::string raca, std::string tamanho,std::string nome, std::vector<std::string> remediosPossiveis, std::string id, std::vector<Servico> servicosDisponiveis){
  this->tipoBico = tipoBico;
  this->tipoPena = tipoPena;
  this->raca = raca;
  this->tamanho = tamanho;
  this->remediosPossiveis = remediosPossiveis;
  this->id = id;
  this->servicosDisponiveis = servicosDisponiveis;
  this->nome = nome;
}
Passaro::Passaro(){}

//getters
std::string Passaro::getTipoBico(){
  return this->tipoBico;
}
std::string Passaro::getTipoPena(){
  return this->tipoPena;
}

// setters
void Passaro::setTipoBico(std::string tipoBico){
  this->tipoBico = tipoBico;
}
void Passaro::setTipoPena(std::string tipoPena){
  this->tipoPena = tipoPena;
}