#ifndef ListaClientes_h
#define ListaClientes_h
#include <vector>

#include "Cliente.h"

class ListaClientes
{
private:
  std::vector<Cliente> vClientes; // Declaração do vetor clientes
public:
  ListaClientes(std::vector<Cliente> vClientes); // Construtores da ListaClientes
  ListaClientes();

  std::vector<Cliente> getListaClientes(); // Método que retorna o vetor Clientes

  // Métodos públicos: 
  void imprimeLista(); // Imprime a lista de clientes
  void addCliente(Cliente& Cliente); // Adiciona um novo Cliente
  void rmvCliente(Cliente& Cliente); // Remove um Cliente
  Cliente getCliente(std::string id); // Método que retorna um cliente por seu ID
};

#endif