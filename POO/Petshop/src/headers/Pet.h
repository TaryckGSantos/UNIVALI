#ifndef Pet_h
#define Pet_h

#include <string>
#include <vector>
#include "Servico.h"

class Pet // criação da classe Pet
{
protected:
  std::string raca; // Membros privados da classe Pet
  std::string tamanho;
  std::string nome;
  std::vector<std::string> remediosPossiveis;
  std::string id;
  std::vector<Servico> servicosDisponiveis;
public:
  // Construtores declarados para a classe Pet
  Pet(std::string raca, std::string tamanho,std::string nome, std::vector<std::string> remediosPossiveis, std::string id, std::vector<Servico> servicosDisponiveis);
  Pet();

  // Métodos que retornam as strings citadas
  std::string getRaca(); 
  std::string getTamanho();
  std::string getNome();
  std::string getId();

  // Métodos que retornam vetor 
  std::vector<std::string> getRemediosPossiveis(); // vetor de remedios
  std::vector<Servico> getServicosDisponiveis(); // vetor de serviços
   
  // Definição dos atributos 
  void setRaca(std::string);
  void setTamanho(std::string);
  void setNome(std::string);
  void setId(std::string);

  // Métodos:
  void addRemedioPossivel(std::string); // Adiciona um remédio no vetor de remédios
  void rmvRemedioPossivel(std::string); // Remove um remédio no vetor de remédios
  void addServicoDisponivel(Servico); // Adiciona um serviço no vetor de serviços
  void rmvServicoDisponivel(Servico); // Remove um serviço no vetor de serviços
};

#endif