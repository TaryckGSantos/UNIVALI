#include <iostream>
using namespace std;

class Calculadora {
public:
    int somar(int a, int b) {
        return a + b;
    }

    double somar(double a, double b) {
        return a + b;
    }

    string somar(string a, int b){
        cout << a << " " << b;
    }
};

int main() {
    Calculadora calc;

    int resultado1 = calc.somar(2, 3);
    cout << "Resultado 1: " << resultado1 << endl;

    double resultado2 = calc.somar(7.5, -2.545);
    cout << "Resultado 2: " << resultado2 << endl;

    cout << "Resultado 3: ";
    calc.somar("Taryck", 5);

    return 0;
}
