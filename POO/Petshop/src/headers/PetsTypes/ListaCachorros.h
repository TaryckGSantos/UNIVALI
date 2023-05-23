#ifndef ListaCachorros_h
#define ListaCachorros_h
#include <vector>

#include "Cachorro.h"

class ListaCachorros // criação da classe listaCachorros
{
private:
  std::vector<Cachorro> vCachorros; // vetor de cachorros 
public:
  // Construtores e destrutores
  ListaCachorros(std::vector<Cachorro> vCachorros);
  ListaCachorros();
  
  std::vector<Cachorro> getListaCachorros(); // getter da lista

  void imprimeLista(); // função de imprimir a lista
  void addCachorro(Cachorro& Cachorro); // função de adicionar um cachorro 
  void rmvCachorro(Cachorro& Cachorro); // função de remover um cachorro 
  Cachorro getCachorro(std::string id); // getter do objeto
};

#endif