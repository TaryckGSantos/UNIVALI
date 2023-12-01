#include <iostream>
using namespace std;

class Aluno {
private:
    float mensalidade;
public:
    Aluno(float mensalidade) {
        this->mensalidade = mensalidade;
    }

    float getMensalidade() {
        return this->mensalidade;
    }
};

class Aluno_bolsista : public Aluno {
private:
    float desc;
public:
    Aluno_bolsista(float mensalidade, float desc) : Aluno(mensalidade) {
        this->desc = desc;
    }

    float getMensalidade() {
        return Aluno::getMensalidade() - this->desc;
    }

    void mostrar() {
        cout << endl << endl;
        cout << "mensalidade: " << getMensalidade();
    }
};

int main() {
    Aluno al(500);
    Aluno_bolsista al2(500, 250);
    al2.mostrar();

    return 0;
}
