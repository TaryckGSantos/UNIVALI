#ifndef ListaProdutos_h
#define ListaProdutos_h
#include <vector>

#include "Produto.h"

class ListaProdutos
{
private:
  std::vector<Produto> vProdutos; // Declaração privada do vetor de produtos
public:
  ListaProdutos(std::vector<Produto> vProdutos); // Construtores da calsse ListaProdutos
  ListaProdutos();

  std::vector<Produto> getListaProdutos(); // Método que retorna o vetor de produtos

  /// Métodos:  
  void imprimeLista(); // Imprime o que contém dentro do vetor
  void addProduto(Produto& produto); // Adiciona um novo produto
  void rmvProduto(Produto& produto); // Remove um produto
  Produto getProduto(std::string id); // retorna um produto através da busca pelo seu ID
};

#endif