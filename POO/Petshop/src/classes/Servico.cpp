#include "../headers/Servico.h"
#include <string>
/*this file implement a class Servico*/


/*constructor and destructor*/
Servico::Servico(){}
Servico::Servico(std::string tipoServico,std::string id,double preco){
  this->tipoServico = tipoServico;
  this->preco = preco;
  this->id = id;
}


/*getters*/
std::string Servico::getTipoServico(){
  return this->tipoServico;
}
double Servico::getPreco(){
  return this->preco;
}
std::string Servico::getId(){
  return this->id;
}


/*setters*/
void Servico::setTipoServico(std::string tipoServico){
  this->tipoServico = tipoServico;
}
void Servico::setPreco(double preco){
  this->preco = preco;
}
void Servico::setId( std::string id){
  this->id = id;
}