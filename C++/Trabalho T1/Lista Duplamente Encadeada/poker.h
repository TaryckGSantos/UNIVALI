#ifndef POKER_H_INCLUDED
#define POKER_H_INCLUDED

struct cartas{ /// declara��o da estrutura espec�fica
    int numero;
    int naipe;
};

template <typename TIPO>
int mostrar_cartas(TLista <TIPO> &lista){ /// Fun��o para mostrar o baralho completo

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
int aux_inserir(Elemento<TIPO> &el){ /// Auxiliar de inser��o
    system("cls");

    cout << endl << endl << endl << "\t\t\tInsira o n�mero da carta: ";
    cin >> el.dado.numero;
    if (el.dado.numero > 13 || el.dado.numero < 1){ /// Caso o numero seja maior que 13 ou menor que 1, voltar para a inser��o
        cout << endl << endl << endl << "\t\t\tInsira apenas cartas de 1 a 13!";
        system("pause>nul");
        return aux_inserir(el);
    }

    cout << endl << endl <<"\t\t\t1 - Copas\n\t\t\t2 - Ouro\n\t\t\t3 - Paus\n\t\t\t4 - Espadas" << "\n\n\t\t\tInsira o naipe da carta: ";
    cin >> el.dado.naipe;
    if (el.dado.naipe > 4 || el.dado.naipe < 1){ /// Caso o naipe seja maior que 4 ou menor que 1, voltar para a inser��o
        cout << endl << endl << endl << "\t\t\tInsira apenas n�meros de 1 a 4!";
        system("pause>nul");
        return aux_inserir(el);
    }
}

template <typename TIPO>
int verifica_insercao(TLista <TIPO> &lista, Elemento<TIPO> &el){ /// Auxiliar para a verifica��o de elementos repetidos
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
int montar_baralho(TLista <TIPO> &lista){ /// Monta um baralho completo utilizando o insere final

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
int mostrar_carta_busca(TLista <TIPO> &lista, int &posicao_b){ /// Fun��o que mostra uma carta em determianda posi��o
    int aux = 0;

    Elemento <TIPO> aux_b;

    Elemento <TIPO> * nav_inicio = lista.inicio;
    Elemento <TIPO> * nav_final = lista.fim;

    if(posicao_b > lista.tamanho || posicao_b-1 < 0){ /// Caso a posi��o seja maior ou menor que as existentes
        cout << "\n\n\n\t\t\tN�o h� nenhuma carta neste local";
    } else {
        if(posicao_b-1 > (lista.tamanho/2)-1){ /// Busca para posi��o maior que a metade
            aux = lista.tamanho-1;
            while(aux < posicao_b-1){
                nav_final = nav_final->anterior;
            }
            aux_b = *nav_final;
        } else { /// Busca para posi��o menor que a metade
            while(aux > posicao_b-1){
                nav_inicio = nav_inicio->proximo;
            }
            aux_b = *nav_inicio;
        }

        cout << "\n\n\n\t\t\tCarta nessa posi��o: " << aux_b.dado.numero << " - "; /// Imprime a carta
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
}

template <typename TIPO>
int menu_inserir(TLista <TIPO> &lista, Elemento<TIPO> &el){ /// Menu de inser��o
    int aux_menu_inserir;
    int aux_conf = 0;

    if (lista.tamanho == 52){
        cout << "\n\n\n\t\t\tA lista j� est� completa!";
        system("pause>nul");
        system("cls");
    } else {
        cout << endl << endl << endl;
        cout << "\t\t\tEscolha a maneira de inser��o: ";
        cout << endl << endl << "\t\t\t1 - Inserir no in�cio";
        cout << endl << "\t\t\t2 - Inserir no final";
        cout << endl <<  "\t\t\t3 - Inserir em uma posi��o espec�fica" << endl << endl << "\t\t\t";
        cin >> aux_menu_inserir;

        switch (aux_menu_inserir){

            case 1:
                aux_inserir(el);
                aux_conf = verifica_insercao(lista, el);
                if(aux_conf == 0){ /// caso n�o seja carta repetida
                    insere_inicio(lista, el.dado);
                    system("cls");
                } else { /// caso seja carta repetida
                    cout << endl << endl << endl << "\t\t\tEste elemento j� existe! ";
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
                    cout << endl << endl << endl << "\t\t\tEste elemento j� existe! ";
                    system("pause>nul");
                    system("cls");
                }
                break;

            case 3:
                int posicao;
                aux_inserir(el);
                aux_conf = verifica_insercao(lista, el);
                if(aux_conf == 0){
                    cout << "\n\n\n\t\t\tEscolha a posi��o para inserir: ";
                    cin >> posicao;
                    if(posicao-1 > lista.tamanho || posicao-1 < 0){ /// Caso a posi��o esteja fora dos padr�es
                        cout << "\n\n\n\t\t\tPosi��o imposs�vel de inserir! :(";
                        system("pause>nul");
                        system("cls");
                    } else {
                        insere_posicao(lista, el.dado, posicao);
                        system("cls");
                    }
                } else {
                    cout << endl << endl << endl << "\t\t\tEste elemento j� existe! ";
                    system("pause>nul");
                    system("cls");
                }
                break;
        }
    }
}

template <typename TIPO>
int menu_remover(TLista <TIPO> &lista, Elemento<TIPO> &el){ /// menu de remo��o
    int aux_menu_remover;

    cout << endl << endl << endl;
    cout << "\t\t\tEscolha a maneira de remo��o: ";
    cout << endl << endl << "\t\t\t1 - Remover no in�cio";
    cout << endl << "\t\t\t2 - Remover no final";
    cout << endl <<  "\t\t\t3 - Remover em uma posi��o espec�fica" << endl << endl << "\t\t\t";
    cin >> aux_menu_remover;

    switch (aux_menu_remover){

        case 1:
            if(lista.tamanho == 0){ /// caso o baralho esteja zerado
                system("cls");
                cout << "\n\n\n\t\t\tNenhuma carta inserida! ";
                system("pause>nul");
                system("cls");
            } else { /// caso n�o esteja
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
                cout << "\n\n\n\t\t\t�ltimo elemento removido! :) ";
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
                cout << "\n\n\n\t\t\tEscolha a posi��o para remover: ";
                cin >> posicao_r;
                if(posicao_r > lista.tamanho || posicao_r-1 < 0){ /// Caso a posi��o esteja fora dos padr�es
                    cout << "\n\n\n\t\t\tN�o h� como remover neste local";
                    system("pause>nul");
                    system("cls");
                } else {
                    remove_posicao(lista, el.dado, posicao_r);
                    system("cls");
                    cout << "\n\n\n\t\t\tElemento na posi��o " << posicao_r << " removido! :) ";
                    system("pause>nul");
                    system("cls");
                }
            }
            break;
    }
}

bool operator < (cartas a, cartas b){ /// operator de compara��o
    return a.naipe*200+a.numero < b.naipe*200+b.numero;
}

bool operator == (cartas a, cartas b){ /// operator de igualdade
    return a.naipe*200+a.numero == b.naipe*200+b.numero;
}

#endif // POKER_H_INCLUDED
