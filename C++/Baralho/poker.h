#ifndef POKER_H_INCLUDED
#define POKER_H_INCLUDED

struct cartas{
    int numero;
    int naipe;
};

int mostrar_cartas(cartas el){
   switch (el.naipe){

        case 1:
            cout << "\t\t - " << el.numero << " | copas" << endl << endl;
            break;

        case 2:
            cout << "\t\t - " << el.numero << " | ouro" << endl << endl;
            break;

        case 3:
            cout << "\t\t - " << el.numero << " | paus" << endl << endl;
            break;

        case 4:
            cout << "\t\t - " << el.numero << " | espadas" << endl << endl;
            break;
        }
}

int montar_baralho_poker(Lista <cartas, 52> &el){
    el.tamanho = 0;

    for(int i=1; i<=12; i++){
        for(int j=1; j<=4; j++){
            el.elementos[el.tamanho].dado.naipe = j;
            el.elementos[el.tamanho].dado.numero = i;
            el.tamanho++;
        }
    }
    cout << endl << endl << endl << "\t\tBaralho montado! :)";
}

bool operator < (cartas a, cartas b){
    return a.naipe*10+a.numero < b.naipe*10+b.numero;
}

#endif // POKER_H_INCLUDED
