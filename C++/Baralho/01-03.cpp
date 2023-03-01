///Fazer mensagem pra caso o baralho estiver vazio!!!!!!!

#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#define maximo 52
using namespace std;

struct cartas{
    int numero;
    int naipe;
};

struct Lista{
    cartas elemento[maximo];
    int tamanho_baralho;
};

bool inicializa_baralho(Lista &poker){
    poker.tamanho_baralho = 0;

    if (poker.tamanho_baralho == 0){
        return true;
    } else {
        return false;
    }
}

int preenche_aux(cartas &aux){

    cout << endl << endl << endl << "\t\t\tInsira o número da carta: ";
    cin >> aux.numero;
    if (aux.numero > 13 || aux.numero < 1){
        cout << endl << endl << endl << "\t\t\tInsira apenas cartas de 1 a 13!";
        return preenche_aux(aux);
    }

    cout << endl << endl <<"\t\t\t1 - Copas\n\t\t\t2 - Ouro\n\t\t\t3 - Paus\n\t\t\t4 - Espadas" << "\n\n\t\t\tInsira o naipe da carta: ";
    cin >> aux.naipe;
    if (aux.naipe > 4 || aux.naipe < 1){
        cout << endl << endl << endl << "\t\t\tInsira apenas números de 1 a 4!";
        return preenche_aux(aux);
    }
}

int verifica_insercao(Lista &poker, cartas &aux){

    for(int i=0; i<poker.tamanho_baralho; i++){
        if(aux.numero == poker.elemento[i].numero && aux.naipe == poker.elemento[i].naipe){
            cout << endl << endl << endl << "\t\t\tCarta já existente! ";
            system("pause>nul");
            system("cls");
            return preenche_aux(aux);
        }
    }
}

int insere_final(Lista &poker, cartas &aux){

    system("cls");

    preenche_aux(aux);
    verifica_insercao(poker,aux);
    poker.elemento[poker.tamanho_baralho] = aux;
    poker.tamanho_baralho++;
}

int insere_inicio(Lista &poker, cartas &aux){

    system("cls");

    for(int i=poker.tamanho_baralho; i>=0; i--){
        poker.elemento[i] = poker.elemento[i-1];
    }

    preenche_aux(aux);
    verifica_insercao(poker,aux);
    poker.elemento[0] = aux;
    poker.tamanho_baralho++;
}

int insere_posicao(Lista &poker, cartas &aux){
    int aux_posicao;

    system("cls");

    cout << endl << endl << endl;
    cout << "\t\t\tInsira em qual posição inserir: ";
    cin >> aux_posicao;
    aux_posicao = aux_posicao-1;

    for(int i=poker.tamanho_baralho; i>=aux_posicao; i--){
        poker.elemento[i] = poker.elemento[i-1];
    }
    preenche_aux(aux);
    verifica_insercao(poker,aux);
    poker.elemento[aux_posicao] = aux;
    poker.tamanho_baralho++;
}

int menu_inserir(Lista &poker, cartas &aux){
    int aux_menu;

    cout << endl << endl << endl;
    cout << "\t\t\tEscolha a maneira de inserção: ";
    cout << endl << endl << "\t\t\t1 - Inserir no final";
    cout << endl << "\t\t\t2 - Inserir no início";
    cout << endl <<  "\t\t\t3 - Inserir em uma posição específica" << endl << endl << "\t\t\t";
    cin >> aux_menu;

    switch (aux_menu){

        case 1:
            insere_final(poker,aux);
            break;

        case 2:
            insere_inicio(poker,aux);
            break;

        case 3:
            insere_posicao(poker,aux);
            break;
    }
}

int remove_final(Lista &poker){
    poker.tamanho_baralho--;
}

int remove_inicio(Lista &poker){
    for(int i = 0; i < poker.tamanho_baralho; i++){
        poker.elemento[i] = poker.elemento[i+1];
    }
    poker.tamanho_baralho--;
}

int remove_posicao(Lista &poker){
    int aux_posicao;

    system("cls");

    cout << endl << endl << endl;
    cout << "\t\t\tInsira em qual posição remover: ";
    cin >> aux_posicao;
    aux_posicao = aux_posicao-1;

    for(int i = aux_posicao; i < poker.tamanho_baralho; i++){
        poker.elemento[i] = poker.elemento[i+1];
    }
    poker.tamanho_baralho--;
}

int menu_remover(Lista &poker, cartas &aux){
    int aux_menu;

    cout << endl << endl << endl;
    cout << "\t\t\tEscolha a maneira de remoção: ";
    cout << endl << endl << "\t\t\t1 - Remover no final";
    cout << endl << "\t\t\t2 - Remover no início";
    cout << endl <<  "\t\t\t3 - Remover em uma posição específica" << endl << endl << "\t\t\t";
    cin >> aux_menu;

    switch (aux_menu){

        case 1:
            remove_final(poker);
            break;

        case 2:
            remove_inicio(poker);
            break;

        case 3:
            remove_posicao(poker);
            break;
    }
}

int mostrar_elementos(Lista &poker){
    system("cls");

    cout << endl << endl << endl;

    for(int i=0; i<poker.tamanho_baralho; i++){

        switch (poker.elemento[i].naipe){

            case 1:
                cout << "\t\t - " << poker.elemento[i].numero << " | copas" << endl << endl;
                break;

            case 2:
                cout << "\t\t - " << poker.elemento[i].numero << " | ouro" << endl << endl;
                break;

            case 3:
                cout << "\t\t - " << poker.elemento[i].numero << " | paus" << endl << endl;
                break;

            case 4:
                cout << "\t\t - " << poker.elemento[i].numero << " | espadas" << endl << endl;
                break;
        }
    }
}

int buscar_elementos(Lista &poker){
    cartas aux;
    int aux_posicao;

    cout << endl << endl << endl << "\t\t\tInsira a posição da carta que quer buscar: ";
    cin >> aux_posicao;
    cout << endl << endl << "\t\t\tCarta inserida na posição " << aux_posicao << ": ";
    aux_posicao--;

    if (aux_posicao > poker.tamanho_baralho){
        cout << endl << endl << "\t\t\tNão há nenhuma carta nesta posição!";
    } else {
        for (int i=0; i < 52; i++){
            if (aux_posicao == i){

                switch (poker.elemento[i].naipe){

                    case 1:
                        cout << poker.elemento[i].numero << " | copas" << endl << endl;
                        break;

                    case 2:
                        cout << poker.elemento[i].numero << " | ouro" << endl << endl;
                        break;

                    case 3:
                        cout << poker.elemento[i].numero << " | paus" << endl << endl;
                        break;

                    case 4:
                        cout << poker.elemento[i].numero << " | espadas" << endl << endl;
                        break;
                }
            }
        }
    }
}

int qtd_cartas(Lista &poker){
    system("cls");

    cout << endl << endl << endl << "\t\t\tQuantidade de cartas inseridas: " << poker.tamanho_baralho << endl << endl;
}

int zerar_baralho(Lista &poker){
    poker.tamanho_baralho = 0;
    cout << endl << endl << endl << "\t\t\tBaralho Excluído! :)";
}

int montar_baralho(Lista &poker){
    poker.tamanho_baralho = 0;

        for(int i=1; i<=12; i++){
            for(int j=1; j<=4; j++){
                poker.elemento[poker.tamanho_baralho].naipe = j;
                poker.elemento[poker.tamanho_baralho].numero = i;
                poker.tamanho_baralho++;
            }
        }
}

int embaralhar(Lista &poker){
    int num1, num2, contagem;
    cartas aux_troca;

    contagem = 0;

    srand(time(NULL));

    do {
        num1 = rand()%52;
        num2 = rand()%52;
        aux_troca = poker.elemento[num1];
        poker.elemento[num1] = poker.elemento[num2];
        poker.elemento[num2] = aux_troca;
        contagem++;
    } while (contagem <= 100);
}

int jogo_bj(Lista &poker){
    int soma_jogador = 0, soma_bot = 0, aux_j = 0, aux_bot = 0;
    int aux_menu;

    srand(time(NULL));
    system("cls");

    aux_bot = rand()%8 + 14;
    cout << endl << endl << endl << "\t\t\tPontuação do BOT: " << aux_bot;

    aux_j = rand()%52;
    soma_jogador = poker.elemento[aux_j].numero;

    cout << endl << endl << endl << endl << "\t\t\tPrimeira carta: ";
    switch (poker.elemento[aux_j].naipe){

        case 1:
            cout << poker.elemento[aux_j].numero << " | copas" << endl << endl;
            break;

        case 2:
            cout << poker.elemento[aux_j].numero << " | ouro" << endl << endl;
            break;

        case 3:
            cout << poker.elemento[aux_j].numero << " | paus" << endl << endl;
            break;

        case 4:
            cout << poker.elemento[aux_j].numero << " | espadas" << endl << endl;
            break;
    }

    aux_j = rand()%52;
    soma_jogador += poker.elemento[aux_j].numero;

    cout << endl << "\t\t\tSegunda carta: ";
    switch (poker.elemento[aux_j].naipe){

        case 1:
            cout << poker.elemento[aux_j].numero << " | copas" << endl << endl;
            break;

        case 2:
            cout << poker.elemento[aux_j].numero << " | ouro" << endl << endl;
            break;

        case 3:
            cout << poker.elemento[aux_j].numero << " | paus" << endl << endl;
            break;

        case 4:
            cout << poker.elemento[aux_j].numero << " | espadas" << endl << endl;
            break;
    }

    do {
        cout << endl << "\t\t\tSoma das cartas: " << soma_jogador;
        cout << endl << endl << endl << endl << endl << "\t\t\tDeseja pedir mais cartas (1 - sim | 2 - não)? ";
        cin >> aux_menu;

        if (aux_menu == 1) {
            aux_j = rand()%52;
            soma_jogador += poker.elemento[aux_j].numero;

            cout << endl << endl << endl << "\t\t\tCarta adicionada: ";
            switch (poker.elemento[aux_j].naipe){

                case 1:
                    cout << poker.elemento[aux_j].numero << " | copas" << endl << endl;
                    break;

                case 2:
                    cout << poker.elemento[aux_j].numero << " | ouro" << endl << endl;
                    break;

                case 3:
                    cout << poker.elemento[aux_j].numero << " | paus" << endl << endl;
                    break;

                case 4:
                    cout << poker.elemento[aux_j].numero << " | espadas" << endl << endl;
                    break;
            }
        }
    } while (aux_menu == 1);

    if (soma_jogador > aux_bot && soma_jogador <= 21){
        cout << endl << endl << endl << "\t\t\tVocê ganhou!!!!! :)))))";
    }
    else if (soma_jogador == aux_bot){
        cout << endl << endl << endl << "\t\t\tVocê empatou!! '-'";
    }
    else {
        cout << endl << endl << endl << "\t\t\tVocê perdeu! :(((";
    }
}

int menu_blackjack(Lista &poker){
    int aux_menu;

    montar_baralho(poker);

    do {

        cout << endl << endl << endl;
        cout << "\t\t\tEscolha o que você quer fazer: ";
        cout << endl << endl << "\t\t\t1 - Mostrar baralho";
        cout << endl << "\t\t\t2 - Embaralhar as cartas";
        cout << endl << "\t\t\t3 - Jogar uma rodada";
        cout << endl <<  "\t\t\t4 - Sair do jogo" << endl << endl << "\t\t\t";
        cin >> aux_menu;

        switch (aux_menu){

            case 1:
                mostrar_elementos(poker);
                system("pause>nul");
                system("cls");
                break;

            case 2:
                system("cls");
                embaralhar(poker);
                cout << endl << endl << endl << "\t\t\tCartas embaralhadas! :)";
                system("pause>nul");
                system("cls");
                break;

            case 3:
                system("cls");
                jogo_bj(poker);
                system("pause>nul");
                system("cls");
                break;
        }
    } while (aux_menu != 4);
}

int main(){

    setlocale (LC_ALL ,"Portuguese");

    int aux_menu;
    Lista poker;
    cartas aux;

    inicializa_baralho(poker);

    do{
        cout << "\n\n\t\t- Menu -" << endl << endl << endl;
        cout << "\t\t1 - Inserir carta" << endl;
        cout << "\t\t2 - Remover carta" << endl;
        cout << "\t\t3 - Mostrar as cartas inseridas" << endl;
        cout << "\t\t4 - Buscar alguma carta" << endl;
        cout << "\t\t5 - Mostrar quantidade de cartas inseridas" << endl;
        cout << "\t\t6 - Remover todas as cartas" << endl;
        cout << "\t\t7 - Iniciar o BlackJack" << endl;
        cout << "\t\t8 - Encerrar a lista" << endl << endl;
        cout << "\t\tDigite o que você deseja fazer: ";
        cin >> aux_menu;

        switch(aux_menu){

            case 1:
                system("cls");
                menu_inserir(poker,aux);
                system("cls");
                break;

            case 2:
                system("cls");
                menu_remover(poker,aux);
                system("cls");
                break;

            case 3:
                system("cls");
                mostrar_elementos(poker);
                system("pause>nul");
                system("cls");
                break;

            case 4:
                system("cls");
                buscar_elementos(poker);
                system("pause>nul");
                system("cls");
                break;

            case 5:
                system("cls");
                qtd_cartas(poker);
                system("pause>nul");
                system("cls");
                break;

            case 6:
                system("cls");
                zerar_baralho(poker);
                system("pause>nul");
                system("cls");
                break;

            case 7:
                system("cls");
                menu_blackjack(poker);
                system("cls");
                break;

            case 8:
                system("cls");
                cout << "\n\n\t\tLista encerrada! :)" << "\n\n\t\t";
                system("pause>nul");
                exit(0);
                break;
        }
    } while(aux_menu != 8);
    return 0;
}
