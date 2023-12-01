#include <iostream>
using namespace std;

class Animal {
public:
    virtual void fazerSom() {
        cout << "Animal fazendo som!" << endl;
    }
};

class Cachorro : public Animal {
public:
    void fazerSom() override {
        cout << "Cachorro fazendo som!" << endl;
    }
};

int main() {
    Animal animal;
    Cachorro cachorro;

    animal.fazerSom();   // Chamada para o objeto Animal
    cachorro.fazerSom(); // Chamada para o objeto Cachorro

    return 0;
}
