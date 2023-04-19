#include <iostream>
using namespace std;

class empregado {
private:
    int codigoPessoal;
    string nome;
public:
    empregado();
    empregado(int cdg, string nm){
        this->codigoPessoal = cdg;
        this->nome = nm;
    }
    void setCodigoPessoal(int codigo){
        this->codigoPessoal = codigo;
    }
    int getCodigoPessoal (){
        return this->codigoPessoal;
    }
    string getNome(){
        return this->nome;
    }
    void setNome(string Snome){
        this->nome = Snome;
    }
};

class comissionado: public empregado{
private:
    float salario;
    float comissao;
public:
    comissionado();
    comissionado(int codigo, float salario){
        this->codigoPessoal = codigo;
        this->salario = salario;
    }
    void setComissao(float comiss){
        this->comissao = comiss;
    }
    float getComissao(){
        return this->comissao;
    }
    float getSalario(){
        return this->salario;
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
