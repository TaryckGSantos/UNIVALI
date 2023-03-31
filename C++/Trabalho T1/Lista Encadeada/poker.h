#ifndef POKER_H_INCLUDED
#define POKER_H_INCLUDED

struct cartas{
    int numero;
    int naipe;
};

template <typename TIPO>
int verifica_insercao(TLista <TIPO> &lista, Elemento<TIPO> &el){
    Elemento <TIPO> * nav = lista.inicio;

    while(nav != NULL){
        if(el.dado == nav->dado){
            return 1;
        } else {
            nav = nav->proximo;
        }
    }
    return 0;
}

template <typename TIPO>
int mostrar_cartas(TLista <TIPO> &lista){

    Elemento<TIPO> aux;
    Elemento <TIPO> * nav = lista.inicio;
    aux = *nav;

    while(nav->proximo != NULL) {
        cout << endl << endl << endl;
        cout << "\t\t\t" << aux.dado.numero << " | ";
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
    cout << "\t\t\t" << aux.dado.numero << " | ";
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
        cout << endl << endl << endl << "\t\t\tInsira apenas cartas de 1 a 13!"; /// Caso o numero seja maior que 13 ou menor que 1, voltar para a inserção
        system("pause>nul");
        return aux_inserir(el);
    }

    cout << endl << endl <<"\t\t\t1 - Copas\n\t\t\t2 - Ouro\n\t\t\t3 - Paus\n\t\t\t4 - Espadas" << "\n\n\t\t\tInsira o naipe da carta: ";
    cin >> el.dado.naipe;
    if (el.dado.naipe > 4 || el.dado.naipe < 1){ /// Caso o naipe seja maior que 4 ou menor que 1, voltar para a inserção
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

    Elemento <TIPO> * nav = lista.inicio;

    while(aux < posicao_b-1){
        nav = nav->proximo;
        aux++;
    }
    Elemento <TIPO> aux_b = *nav;
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

template <typename TIPO>
int menu_remover(TLista <TIPO> &lista, Elemento<TIPO> &el){
    int aux_menu_remover;

    cout << endl << endl << endl;
    cout << "\t\t\tEscolha a maneira de remoção: ";
    cout << endl << endl << "\t\t\t1 - Remover no início";
    cout << endl << "\t\t\t2 - Remover no final";
    cout << endl <<  "\t\t\t3 - Remover em uma posição específica" << endl << endl << "\t\t\t";
    cin >> aux_menu_remover;

    switch (aux_menu_remover){

        case 1:
            if(lista.tamanho == 0){
                system("cls");
                cout << "\n\n\n\t\t\tNenhuma carta inserida! ";
                system("pause>nul");
                system("cls");
            } else {
                remove_inicio(lista);
                system("cls");
                cout << "\n\n\n\t\t\tPrimeiro elemento removido! :) ";
                system("pause>nul");
                system("cls");
            }
            break;

        case 2:
            if(lista.tamanho == 0){
                system("cls");
                cout << "\n\n\n\t\t\tNenhuma carta inserida! ";
                system("pause>nul");
                system("cls");
            } else {
                remove_fim(lista);
                system("cls");
                cout << "\n\n\n\t\t\tÚltimo elemento removido! :) ";
                system("pause>nul");
                system("cls");
            }
            break;

        case 3:
            if(lista.tamanho == 0){
                system("cls");
                cout << "\n\n\n\t\t\tNenhuma carta inserida! ";
                system("pause>nul");
                system("cls");
            } else {
                system("cls");
                int posicao_r;
                cout << "\n\n\n\t\t\tEscolha a posição para remover: ";
                cin >> posicao_r;
                if(posicao_r > lista.tamanho || posicao_r-1 < 0){
                    cout << "\n\n\n\t\t\tNão há como remover neste local";
                    system("pause>nul");
                    system("cls");
                } else {
                    remove_posicao(lista, el.dado, posicao_r);
                    system("cls");
                    cout << "\n\n\n\t\t\tElemento na posição " << posicao_r << " removido! :) ";
                    system("pause>nul");
                    system("cls");
                }
            }
            break;
    }
}

template <typename TIPO>
int menu_inserir(TLista <TIPO> &lista, Elemento<TIPO> &el){
    int aux_menu_inserir;
    int aux_conf = 0;

    if (lista.tamanho == 52){
        cout << "\n\n\n\t\t\tA lista já está completa!";
        system("pause>nul");
        system("cls");
    } else {
        cout << endl << endl << endl;
        cout << "\t\t\tEscolha a maneira de inserção: ";
        cout << endl << endl << "\t\t\t1 - Inserir no início";
        cout << endl << "\t\t\t2 - Inserir no final";
        cout << endl <<  "\t\t\t3 - Inserir em uma posição específica" << endl << endl << "\t\t\t";
        cin >> aux_menu_inserir;

        switch (aux_menu_inserir){

            case 1:
                aux_inserir(el);
                aux_conf = verifica_insercao(lista, el);
                if(aux_conf == 0){
                    insere_inicio(lista, el.dado);
                    system("cls");
                } else {
                    cout << endl << endl << endl << "\t\t\tEste elemento já existe! ";
                    system("pause>nul");
                    system("cls");
                }
                break;

            case 2:
                aux_inserir(el);
                aux_conf = verifica_insercao(lista, el);
                if(aux_conf == 0){
                    insere_final(lista, el.dado);
                    system("cls");
                } else {
                    cout << endl << endl << endl << "\t\t\tEste elemento já existe! ";
                    system("pause>nul");
                    system("cls");
                }
                break;

            case 3:
                int posicao;
                aux_inserir(el);
                aux_conf = verifica_insercao(lista, el);
                if(aux_conf == 0){
                    cout << "\n\n\n\t\t\tEscolha a posição para inserir: ";
                    cin >> posicao;
                    if(posicao-1 > lista.tamanho || posicao-1 < 0){ /// Caso a posição esteja fora dos padrões
                        cout << "\n\n\n\t\t\tPosição impossível de inserir! :(";
                        system("pause>nul");
                        system("cls");
                    } else {
                        insere_posicao(lista, el.dado, posicao);
                        system("cls");
                    }
                } else {
                    cout << endl << endl << endl << "\t\t\tEste elemento já existe! ";
                    system("pause>nul");
                    system("cls");
                }
                break;
        }
    }
}

bool operator < (cartas a, cartas b){
    return a.naipe*200+a.numero < b.naipe*200+b.numero;
}

bool operator == (cartas a, cartas b){
    return a.naipe*200+a.numero == b.naipe*200+b.numero;
}

#endif // POKER_H_INCLUDED
