#include "../headers/Cliente.h"
#include "../headers/Pet.h"

// Implementações dos construtores. inicializando os valores dos atributos
Cliente::Cliente(std::string id, std::string nome, std::string rua, std::string bairro, std::string telefone) {
  this->id = id;
  this->nome = nome;
  this->rua = rua;
  this->bairro = bairro;
  this->telefone = telefone;
}
Cliente::Cliente(std::string id,Pet_data pet, std::string nome, std::string rua, std::string bairro, std::string telefone) {
  this->id = id;
  this->pet = pet;
  this->nome = nome;
  this->rua = rua;
  this->bairro = bairro;
  this->telefone = telefone;
}

// Métodos que retornam os valores de seus atributos
Cliente::Cliente() {}

std::string Cliente::getId(){
  return this->id;
}
std::string Cliente::getPetId(){
  return this->pet.id;
}
std::string Cliente::getPetTipo(){
  return this->pet.tipo;
}
std::string Cliente::getNome(){
  return this->nome;
}
std::string Cliente::getEndereco(){
  return this->rua + "," + this->bairro;
}
std::string Cliente::getTelefone(){
  return this->telefone;
}

// Métodos de agregação de valores recebidos como parâmetro nos atributos das classes
void Cliente::setId(std::string id){
  this->id = id;
}
void Cliente::setPet(std::string petId, std::string petTipo){
  this->pet.id = petId;
  this->pet.tipo = petTipo;
}
void Cliente::setNome(std::string nome){
  this->nome = nome;
}
void Cliente::setEndereco(std::string rua, std::string bairro){
  this->rua = rua;
  this->bairro = bairro;
}
void Cliente::setTelefone(std::string telefone){
  this->telefone = telefone;
}

