#include <iostream>
using namespace std;

class Calculadora {
public:
    int somar(int a, int b) {
        return a + b;
    }

    int somar(int a, int b, int c) {
        return a + b + c;
    }

    float somar(float a, float b) {
        return a + b;
    }
};

int main() {
    Calculadora calc;

    int resultado1 = calc.somar(2, 3);
    cout << "Resultado 1: " << resultado1 << endl;

    int resultado2 = calc.somar(2, 3, 4);
    cout << "Resultado 2: " << resultado2 << endl;

    float resultado3 = calc.somar(2.5f, 1.5f);
    cout << "Resultado 3: " << resultado3 << endl;

    return 0;
}
