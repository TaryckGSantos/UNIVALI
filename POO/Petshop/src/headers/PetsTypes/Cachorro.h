#ifndef Cachorro_h
#define Cachorro_h

#include "../Pet.h"

class Cachorro: public Pet // criação da classe cachorro
{
private: // dados da classe
  /* data */
  std::string tipoPelo;
  bool isCastrado;
public:
  // Construtores e destrutores
  Cachorro(std::string tipoPelo,bool isCastrado,std::string raca, std::string tamanho,std::string nome, std::vector<std::string> remediosPossiveis, std::string id, std::vector<Servico> servicosDisponiveis);
  Cachorro();

  //getters
  std::string getTipoPelo();
  bool getIsCastrado();
  
  //setters
  void setTipoPelo(std::string tipoPelo);
  void setIsCastrado(bool isCastrado);
};

#endif
