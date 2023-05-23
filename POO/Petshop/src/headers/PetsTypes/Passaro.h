#ifndef Passaro_h
#define Passaro_h

#include "../Pet.h"
class Passaro : public Pet // criação da classe pet
{
private: // dados da classe
  /* data */
  std::string tipoBico;
  std::string tipoPena;
public:
  // Construtores e destrutores
  Passaro(std::string tipoBico, std::string tipoPena,std::string raca, std::string tamanho,std::string nome, std::vector<std::string> remediosPossiveis, std::string id, std::vector<Servico> servicosDisponiveis);
  Passaro();

   //getters
  std::string getTipoPena();
  std::string getTipoBico();

  //setters
  void setTipoPena(std::string);
  void setTipoBico(std::string);
};

 #endif