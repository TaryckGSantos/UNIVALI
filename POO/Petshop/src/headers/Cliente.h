#ifndef Cliente_h
#define Cliente_h

#include <string>
#include <array>

struct Pet_data{ // estrutura com informações do animal cadastrado
    std::string id;
    std::string tipo;
};
class Cliente { // Criação da classe cliente e seus atributos
private:
    std::string id;
    Pet_data pet;
    std::string nome;
    std::string rua;
    std::string bairro; 
    std::string telefone;
public:
    Cliente(std::string id ,std::string nome, std::string rua, std::string bairro, std::string telefone); // criado três tipos de construtores da mesma classe que irão ser usados ->
    Cliente(std::string id ,Pet_data pet ,std::string nome, std::string rua, std::string bairro, std::string telefone); // -> em condições diferentes ao deccorrer do código 
    Cliente();                                                                                                  
    
    // métodos de acesso dos atributos da classe
    std::string getId();  
    std::string getPetId();
    std::string getPetTipo();
    std::string getNome();
    std::string getEndereco();
    std::string getTelefone();
    
    // métodos de alteração dos atributos da classe
    void setId(std::string id); 
    void setPet(std::string petId, std::string petTipo);
    void setNome(std::string nome);
    void setEndereco(std::string rua, std::string bairro);
    void setTelefone(std::string telefone);
};

#endif