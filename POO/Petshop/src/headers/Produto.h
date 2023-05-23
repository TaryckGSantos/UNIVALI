#ifndef Produto_H
#define Produto_H

#include <string>

class Produto { // Define uma classe chamada produto
  
  private: // variáveis privadas
    std::string id;
    float valor;
    std::string nome;
    std::string descricao;
    int quantidade;

  public:
    // Construtores da classe Produto
    Produto();
    Produto(std::string id, float valor, std::string nome ,std::string descricao , int quantidade);

    // Métodos que retornam as variáveis
    std::string getId();
    float getValor();
    std::string getDescricao();
    std::string getNome();
    int getQuantidade();

    // Define cada variável 
    void setId(std::string id);
    void setValor(float valor);
    void setNome(std::string nome);
    void setDescricao(std::string descricao);
    void setQuantidade(int quantidade);
	
    // Funções de remover e adicionar uma quantidade
    void rmvQuantidade(int quantidade);
    void addQuantidade(int quantidade);
};

#endif