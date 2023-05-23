#ifndef Servico_h
#define Servico_h
#include <string>

class Servico // Criação da classe
{
private: // variáveis privadas 
  /* data */
  std::string id;
  std::string tipoServico;
  double preco;
public:
  // Construtores da classe
  Servico(std::string tipoServico,std::string id, double preco);
  Servico();

  // métodos que retornam as respectivas variáveis
  std::string getTipoServico();
  std::string getId();
  double getPreco();

  // Métodos que definem as respectivas váriaveis
  void setTipoServico(std::string tipoServico);
  void setId(std::string id);
  void setPreco(double preco);
};

#endif