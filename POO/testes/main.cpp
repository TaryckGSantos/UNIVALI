#include <iostream>
using namespace std;

class Aluno{
private:
    int num1;
    int num2;
    float mensalidade;
public:
    Aluno(int num1, int num2, int mensalidade){
        this->num1 = num1;
        this->num2 = num2;
        this->mensalidade = mensalidade;
    }
    float getMensalidade(){
        return this-> mensalidade;
    }
    void mostrar(){
        cout << this->num1 << "\t\t" << this->num2 << "\t\t" << mensalidade;
    }
};

class Aluno_bolsista: public Aluno{
private:
    float desc;
    public:
        void setDesconto(float desconto){
            this->desc = desconto;
        }
        float getMensalidade(){
            return this->mensalidade - this->desc;
        }
        void mostrar(){
            cout << endl << endl;
            cout << this->num1 << "\t\t" << this->num2 << "\t\t" << this->mensalidade << "\t\t" << this->desc;
        }
};

int main()
{
    Aluno al = Aluno(2,6, 1500);
    al.mostrar();
    Aluno_bolsista al2;
    al2.setDesconto(750);
    al2.desc = getMensalidade();
    al2.mostrar();
    return 0;
}
