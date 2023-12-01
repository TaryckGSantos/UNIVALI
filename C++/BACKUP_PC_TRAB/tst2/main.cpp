#include <iostream>
using namespace std;

class Pai {
private:
    int a;
    int b;
public:
    Pai(int x, int y){
        this->a = x;
        this->b = y;
    }
    int soma(){
        return a + b;
    }
};

class Filho : public Pai {
private:
    int c;
public:
    Filho(int x, int y, int z) : Pai(x, y) {
        this->c = z;
    }
    int subt(){
        return Pai::soma() - this->c;
    }
};

int main()
{
    Pai teste(6,7);
    int j = teste.soma();
    cout << "Soma de x e y: " << j << endl;

    Filho teste2(6,7,3);
    int k = teste2.subt();
    cout << "Subtração: " << k;
    return 0;
}
