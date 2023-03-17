#ifndef POKER_H_INCLUDED
#define POKER_H_INCLUDED

struct cartas{
    int numero;
    int naipe;
};

template <typename TIPO>
int mostrar_cartas(TLista <TIPO> &lista){

    Elemento<TIPO> aux;
    Elemento <TIPO> * nav = lista.inicio;
    aux = *nav;

    if(lista.inicio == NULL){
        cout << "Não há nenhum elemento inserido!";
    } else {
        while(nav->proximo != NULL) {
            cout << endl << endl << endl;
            cout << "\t\t\tNúmero " << aux.dado.numero;
            cout << endl << "\t\t\tNaipe " << aux.dado.naipe;
            nav = nav->proximo;
            aux = *nav;
        }
        cout << endl << endl << endl;
        cout << "\t\t\tNúmero " << aux.dado.numero;
        cout << endl << "\t\t\tNaipe " << aux.dado.naipe;
    }
}

template <typename TIPO>
int aux_inserir(Elemento<TIPO> &el){
    system("cls");

    cout << endl << endl << endl << "\t\t\tInsira o número da carta: ";
    cin >> el.dado.numero;
    if (el.dado.numero > 13 || el.dado.numero < 1){
        cout << endl << endl << endl << "\t\t\tInsira apenas cartas de 1 a 13!";
        system("pause>nul");
        return aux_inserir(el);
    }

    cout << endl << endl <<"\t\t\t1 - Copas\n\t\t\t2 - Ouro\n\t\t\t3 - Paus\n\t\t\t4 - Espadas" << "\n\n\t\t\tInsira o naipe da carta: ";
    cin >> el.dado.naipe;
    if (el.dado.naipe > 4 || el.dado.naipe < 1){
        cout << endl << endl << endl << "\t\t\tInsira apenas números de 1 a 4!";
        system("pause>nul");
        return aux_inserir(el);
    }
}
#endif // POKER_H_INCLUDED
