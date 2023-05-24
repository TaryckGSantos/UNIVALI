#include <iostream>
using namespace std;
#include <vector>

struct teste{
private:
    int id;
    string nome;
public:
    teste(int x, string y){
        this->id = x;
        this->nome = y;
    }
    void mostrar(){
        cout << endl << endl << this->nome << " - " << this->id;
    }
};

int getID(){
    int id;
    cout << "\n\nID: ";
    cin >> id;
    return id;
}

string getNome(){
    string nome;

    cout << "\n\nNome: ";
    cin >> nome;
    return nome;
}

void inserir(vector<teste> &vet, int &id, string &nome){
    vet.push_back(teste(id, nome));
}

void mostrar(vector<teste> &vet){
    for(auto i = 0; i < vet.size(); i++){
        vet[i].mostrar();
    }
}

int main()
{
    int id, menu;
    string nome;

    vector<teste> vet;

    do {
        cout << endl << endl << "Escolha: ";
        cin >> menu;
        cout << endl;

        if(menu == 1){
            id = getID();

            nome = getNome();

            inserir(vet, id, nome);
        } else if (menu == 2){
            mostrar(vet);
        }
    } while(menu != 3);
    return 0;
}
