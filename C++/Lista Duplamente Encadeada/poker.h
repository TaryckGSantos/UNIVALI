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

    while(nav->proximo != NULL) {
        cout << endl << endl << endl;
        cout << "\t\t\t" << aux.dado.numero << " - ";
        switch(aux.dado.naipe){
            case 1:
                cout<< "copas";
                break;
            case 2:
                cout << "ouro";
                break;
            case 3:
                cout << "paus";
                break;
            case 4:
                cout << "espadas";
                break;
        }
        nav = nav->proximo;
        aux = *nav;
    }
    cout << endl << endl << endl;
    cout << "\t\t\t" << aux.dado.numero << " - ";
    switch(aux.dado.naipe){
            case 1:
                cout<< "copas";
                break;
            case 2:
                cout << "ouro";
                break;
            case 3:
                cout << "paus";
                break;
            case 4:
                cout << "espadas";
                break;
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

template <typename TIPO>
int montar_baralho(TLista <TIPO> &lista){

    cartas aux;

    for(int i = 1; i<=13; i++){
        for(int j = 1; j<=4; j++){
            aux.numero = i;
            aux.naipe = j;
            insere_final(lista, aux);
        }
    }
}

template <typename TIPO>
int mostrar_carta_busca(TLista <TIPO> &lista, int &posicao_b){
    int aux = 0;

    Elemento <TIPO> aux_b;

    Elemento <TIPO> * nav_inicio = lista.inicio;
    Elemento <TIPO> * nav_final = lista.fim;

    if(posicao_b-1 > (lista.tamanho/2)-1){
        aux = lista.tamanho-1;
        while(aux < posicao_b-1){
            nav_final = nav_final->anterior;
        }
        aux_b = *nav_final;
    } else {
        while(aux > posicao_b-1){
            nav_inicio = nav_inicio->proximo;
        }
        aux_b = *nav_inicio;
    }

    cout << "\n\n\n\t\t\tCarta nessa posição: " << aux_b.dado.numero << " - ";
    switch(aux_b.dado.naipe){
        case 1:
            cout<< "copas";
                break;
        case 2:
            cout << "ouro";
            break;
        case 3:
            cout << "paus";
            break;
        case 4:
            cout << "espadas";
            break;
    }
}

/*template <typename TIPO>
int ordenar_bubble(TLista <TIPO> &lista){

    if(lista.inicio == NULL || lista.inicio->proximo == NULL){
        return 1;
    }

    int cond = 1;
    while(cond = 1){
        cond = 0;
        Elemento <TIPO> * nav = lista.inicio;
        while(nav != NULL){
            if(nav->dado.numero > nav->proximo->dado.numero){
                Elemento <TIPO> aux;
                aux.dado = nav->dado;
                nav->proximo->dado = nav->dado;
                nav->proximo->dado = aux.dado;
                cond = 1;
            } else if (nav->dado.numero == nav->proximo->dado.numero && nav->dado.naipe > nav->proximo->dado.naipe){
                Elemento <TIPO> aux;
                aux.dado = nav->dado;
                nav->proximo->dado = nav->dado;
                nav->proximo->dado = aux.dado;
                cout << "entrou aqui: " << nav->dado.numero << " e " << nav->proximo->dado.numero;
                system("pause");
                cond = 1;
            }
            nav = nav->proximo;
        }
    }
}*/

#endif // POKER_H_INCLUDED
