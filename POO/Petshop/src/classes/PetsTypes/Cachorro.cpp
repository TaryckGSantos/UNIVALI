#include "../../headers/PetsTypes/Cachorro.h"

// construtores e destrutores
Cachorro::Cachorro(std::string tipoPelo, bool isCastrado,std::string raca, std::string tamanho,std::string nome, std::vector<std::string> remediosPossiveis, std::string id, std::vector<Servico> servicosDisponiveis){
  this->tipoPelo = tipoPelo;
  this->isCastrado = isCastrado;
  this->raca = raca;
  this->tamanho = tamanho;
  this->remediosPossiveis = remediosPossiveis;
  this->id = id;
  this->servicosDisponiveis = servicosDisponiveis;
  this->nome = nome;
}
Cachorro::Cachorro(){}

// getters
std::string Cachorro::getTipoPelo(){
  return this->tipoPelo;
}
bool Cachorro::getIsCastrado(){
  return this->isCastrado;
}

// setters
void Cachorro::setTipoPelo(std::string tipoPelo){
  this->tipoPelo = tipoPelo;
}
void Cachorro::setIsCastrado(bool isCastrado){
  this->isCastrado = isCastrado;
}