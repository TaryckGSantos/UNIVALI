#ifndef ListaPassaros_h
#define ListaPassaros_h
#include <vector>

#include "Passaro.h"

class ListaPassaros // criação da classe listaPassaros
{
private:
  std::vector<Passaro> vPassaros; // vetor de Passaros
public:
  // Construtores e destrutores
  ListaPassaros(std::vector<Passaro> vPassaros);
  ListaPassaros();

  std::vector<Passaro> getListaPassaros(); // getter da lista

  void imprimeLista(); // função de imprimir a lista
  void addPassaro(Passaro& Passaro); // função de adicionar um passaro
  void rmvPassaro(Passaro& Passaro); // função de remover um passaro
  Passaro getPassaro(std::string id);  // getter do objeto
}; 

#endif