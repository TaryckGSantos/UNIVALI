#include "../headers/Produto.h"

// Construtores e destrutores
Produto::Produto(){}
Produto::Produto(std::string id, float valor, std::string nome ,std::string descricao , int quantidade){
  this->id = id;
  this->valor = valor;
  this->nome = nome;
  this->descricao = descricao;
  this->quantidade = quantidade;
}

/*getters*/
std::string Produto::getId(){
  return this->id;
}
float Produto::getValor(){
  return this->valor;
}
std::string Produto::getNome(){
  return this->nome;
}
std::string Produto::getDescricao(){
  return this->descricao;
}

int Produto::getQuantidade(){
  return this->quantidade;
}

/*setters*/
void Produto::setId(std::string id){
  this->id = id;
}
void Produto::setValor(float valor){
  this->valor = valor;
}
void Produto::setNome(std::string nome){
  this->nome = nome;
}
void Produto::setDescricao(std::string descricao){
  this->descricao = descricao;
}

void Produto::setQuantidade(int quantidade){
  this->quantidade = quantidade;
}

void Produto::addQuantidade(int quantidade){ // adiciona 1 na quantidade de produtos
  this->quantidade = this->quantidade + quantidade;
}
void Produto::rmvQuantidade(int quantidade){ // diminui a quantidade de produtos
  this->quantidade = this->quantidade - quantidade;
}