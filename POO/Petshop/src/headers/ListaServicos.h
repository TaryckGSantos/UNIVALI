#ifndef ListaServicos_h
#define ListaServicos_h
#include <vector>

#include "Servico.h"

class ListaServicos
{
private:
  std::vector<Servico> vServicos; // Declaração privada do vetor de serviços
public:
  ListaServicos(std::vector<Servico> vServicos); // Construtores da classe de serviços
  ListaServicos();

  std::vector<Servico> getListaServicos(); // retorna o vetor de produtos 

  /// Métodos:  
  void imprimeLista(); // imprime a lista de serviços 
  void addServico(Servico& servico); // adiciona um novo serviço
  void rmvServico(Servico& servico); // remove um serviço
  Servico getServico(std::string id); // retorna um serviço através da busca por seu ID
}; 

#endif