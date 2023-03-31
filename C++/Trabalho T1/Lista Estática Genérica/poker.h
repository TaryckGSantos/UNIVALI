#ifndef POKER_H_INCLUDED
#define POKER_H_INCLUDED

struct cartas{ /// Estrutura de cartas
    int numero;
    int naipe;
};

template <typename TIPO, int MAX>
int mostrar_cartas(Lista<TIPO, MAX> &el){ /// mostrar as cartas inseridas
    if (el.tamanho == 0){ /// caso não haja carta
        cout << endl << endl << endl << "\t\t\tNão há nenhum elemento inserido! :( " << endl << endl;
    } else {
        cout << endl << endl << endl;
        for(int i = 0; i<el.tamanho; i++){
            switch (el.elementos[i].dado.naipe){

        case 1:
            cout << "\t\t - " << el.elementos[i].dado.numero << " | copas" << endl << endl;
            break;

        case 2:
            cout << "\t\t - " << el.elementos[i].dado.numero << " | ouro" << endl << endl;
            break;

        case 3:
            cout << "\t\t - " << el.elementos[i].dado.numero << " | paus" << endl << endl;
            break;

        case 4:
            cout << "\t\t - " << el.elementos[i].dado.numero << " | espadas" << endl << endl;
            break;
            }
        }
    }
}

template <typename TIPO, int MAX>
int buscar_elementos(Lista<TIPO, MAX> &el){ /// buscar elementos através da posição
    int aux_posicao;

    if (el.tamanho == 0){ /// caso esteja zerado
        cout << endl << endl << endl << "\t\t\tNão há nenhum elemento inserido! :( " << endl << endl;
    } else {
        cout << endl << endl << endl << "\t\t\tInsira a posição do elemento que quer buscar: ";
        cin >> aux_posicao;

        if(aux_posicao > el.tamanho){ /// quando a posição inserida for maior que o tamanho
            cout << endl << endl << "\t\t\tNão há nenhuma carta nesta posição!";
        } else {
            cout << endl << endl << "\t\t\tElemento inserido na posição " << aux_posicao << ":   ";
            aux_posicao--;
            for (int i=0; i < MAX; i++){
                if (aux_posicao == i){
                   switch (el.elementos[i].dado.naipe){

                        case 1:
                            cout << el.elementos[i].dado.numero << " | copas" << endl << endl;
                            break;

                        case 2:
                            cout << el.elementos[i].dado.numero << " | ouro" << endl << endl;
                            break;

                        case 3:
                            cout << el.elementos[i].dado.numero << " | paus" << endl << endl;
                            break;

                        case 4:
                            cout << el.elementos[i].dado.numero << " | espadas" << endl << endl;
                            break;
                    }
                }
            }
        }
    }
}

template <typename TIPO, int MAX>
int verifica_insercao(Lista<TIPO, MAX> &el, Elemento <TIPO> &aux){ /// auxiliar de verificação de cartas repetidas
    for(int i=0; i<el.tamanho; i++){
        if(aux.dado == el.elementos[i].dado){
            return 1;
        }
    }
    return 0;
}

template <typename TIPO, int MAX>
int preenche_aux(Lista<TIPO, MAX> &el, Elemento <TIPO> &aux){ /// Auxiliar de preencher

    cout << endl << endl << endl << "\t\t\tInsira o número da carta: ";
    cin >> aux.dado.numero;
    if (aux.dado.numero > 13 || aux.dado.numero < 1){ /// Caso o numero seja maior que 13 ou menor que 1, voltar para a inserção
        cout << endl << endl << endl << "\t\t\tInsira apenas cartas de 1 a 13!";
        return preenche_aux(el,aux);
    }

    cout << endl << endl <<"\t\t\t1 - Copas\n\t\t\t2 - Ouro\n\t\t\t3 - Paus\n\t\t\t4 - Espadas" << "\n\n\t\t\tInsira o naipe da carta: ";
    cin >> aux.dado.naipe;
    if (aux.dado.naipe > 4 || aux.dado.naipe < 1){ /// Caso o naipe seja maior que 4 ou menor que 1, voltar para a inserção
        cout << endl << endl << endl << "\t\t\tInsira apenas números de 1 a 4!";
        return preenche_aux(el,aux);
    }
}

template <typename TIPO, int MAX>
int menu_inserir(Lista<TIPO, MAX> &el, Elemento <TIPO> &aux, int &cond_verif){ /// menu de inserção
    int aux_menu;
    int aux_posicao;
    int aux_conf;

    if(el.tamanho == 52){ /// Caso já esteja no tamanho máximo
        cout << endl << endl << endl << "\t\t\tO baralho já está completo! :(";
        system("pause>nul");
    } else { /// Caso ainda nao
        cout << endl << endl << endl;
        cout << "\t\t\tEscolha a maneira de inserção: ";
        cout << endl << endl << "\t\t\t1 - Inserir no final";
        cout << endl << "\t\t\t2 - Inserir no início";
        cout << endl <<  "\t\t\t3 - Inserir em uma posição específica" << endl << endl << "\t\t\t";
        cin >> aux_menu;

        switch (aux_menu){

            case 1:
                system("cls");
                preenche_aux(el,aux);
                aux_conf = verifica_insercao(el, aux);
                if(aux_conf == 0){ /// caso nao tenha carta repetida
                    insere_final(el,aux);
                    system("cls");
                } else {
                    cout << endl << endl << endl << "\t\t\tEste elemento já existe! ";
                    system("pause>nul");
                    system("cls");
                }
                break;

            case 2:
                system("cls");
                preenche_aux(el,aux);
                aux_conf = verifica_insercao(el, aux);
                if(aux_conf == 0){ /// caso nao tenha carta repetida
                    insere_posicao(el,aux,aux_posicao);
                } else {
                    cout << endl << endl << endl << "\t\t\tEste elemento já existe! ";
                    system("pause>nul");
                    system("cls");
                }
                break;

            case 3:
                system("cls");
                preenche_aux(el,aux);
                aux_conf = verifica_insercao(el, aux);
                if(aux_conf == 0){ /// caso nao tenha carta repetida
                    cout << endl << endl << endl;
                    cout << "\t\t\tInsira em qual posição inserir: ";
                    cin >> aux_posicao;
                    if(aux_posicao-1 > el.tamanho || aux_posicao-1 < 0){ /// Caso a posição esteja fora dos padrões
                        cout << "\n\n\n\t\t\tPosição impossível de inserir! :(";
                        system("pause>nul");
                        system("cls");
                    } else {
                        insere_posicao(el,aux, aux_posicao-1);
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

template <typename TIPO, int MAX>
int menu_remover(Lista<TIPO, MAX> &el, Elemento <TIPO> &aux){
    int aux_menu;
    int aux_posicao;

    if(el.tamanho == 0){
        cout << endl << endl << endl << "\t\t\tNenhuma carta inserida! :(";
        system("pause>nul");
    } else {
        cout << endl << endl << endl;
        cout << "\t\t\tEscolha a maneira de remoção: ";
        cout << endl << endl << "\t\t\t1 - Remover no final";
        cout << endl << "\t\t\t2 - Remover no início";
        cout << endl <<  "\t\t\t3 - Remover em uma posição específica" << endl << endl << "\t\t\t";
        cin >> aux_menu;

        switch (aux_menu){

            case 1:
                remove_final(el);
                break;

            case 2:
                remove_inicio(el);
                break;

            case 3:
                if(el.tamanho == 0){
                    system("cls");
                    cout << "\n\n\n\t\t\tNenhuma carta inserida! ";
                    system("pause>nul");
                    system("cls");
                } else {
                    system("cls");
                    int posicao_r;
                    cout << "\n\n\n\t\t\tEscolha a posição para remover: ";
                    cin >> posicao_r;
                    if(posicao_r > el.tamanho || posicao_r-1 < 0){ /// Caso a posição esteja fora dos padrões
                        cout << "\n\n\n\t\t\tNão há como remover neste local";
                        system("pause>nul");
                        system("cls");
                    } else {
                        remove_posicao(el, posicao_r);
                        system("cls");
                        cout << "\n\n\n\t\t\tElemento na posição " << posicao_r << " removido! :) ";
                        system("pause>nul");
                        system("cls");
                    }
                }
                break;
        }
    }
}

int montar_baralho_poker(Lista <cartas, 52> &el){ /// Função para montar baralho completo
    el.tamanho = 0;

    for(int i=1; i<=13; i++){
        for(int j=1; j<=4; j++){
            el.elementos[el.tamanho].dado.naipe = j;
            el.elementos[el.tamanho].dado.numero = i;
            el.tamanho++;
        }
    }
}

bool operator < (cartas a, cartas b){ /// Operator de comparação
    return a.naipe*200+a.numero < b.naipe*200+b.numero;
}

bool operator == (cartas a, cartas b){ /// operator de igualdade
    return a.naipe*200+a.numero == b.naipe*200+b.numero;
}

#endif // POKER_H_INCLUDED
