
#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

template <typename TIPO>
struct Elemento{
    TIPO dado;
};

template <typename TIPO, int MAX>
struct Lista{
    Elemento <TIPO> elementos[MAX];
    int tamanho;
};

template <typename TIPO, int MAX>
int inicializa_lista_gen(Lista<TIPO, MAX> &el){
    el.tamanho = 0;
}

template <typename TIPO, int MAX>
int preenche_aux(Elemento<TIPO> &aux){

    cout << endl << endl << endl << "\t\t\tInsira o(s) dado(s) do elemento: ";
    cin >> aux.dado;
}

template <typename TIPO, int MAX>
int verifica_insercao(Lista<TIPO, MAX> &el, Elemento<TIPO> &aux){

    for(int i=0; i<el.tamanho; i++){
        if(aux.dado == el.elementos[i].dado){
            cout << endl << endl << endl << "\t\t\tEste elemento já existe! ";
            system("pause>nul");
            system("cls");
            return preenche_aux(aux);
        }
    }
}

template <typename TIPO, int MAX>
int insere_final(Lista<TIPO, MAX> &el, Elemento<TIPO> &aux){

    system("cls");

    preenche_aux(aux);
    verifica_insercao(el,aux);
    el.elementos[el.tamanho] = aux;
    el.tamanho++;
}

template <typename TIPO, int MAX>
int insere_inicio(Lista<TIPO, MAX> &el, Elemento<TIPO> &aux){

    system("cls");

    for(int i=el.tamanho; i>=0; i--){
        el.elementos[i] = el.elementos[i-1];
    }

    preenche_aux(aux);
    verifica_insercao(el,aux);
    el.elementos[0] = aux;
    el.tamanho++;
}

template <typename TIPO, int MAX>
int insere_posicao(Lista<TIPO, MAX> &el, Elemento<TIPO> &aux){
    int aux_posicao;

    system("cls");

    cout << endl << endl << endl;
    cout << "\t\t\tInsira em qual posição inserir: ";
    cin >> aux_posicao;
    aux_posicao = aux_posicao-1;

    for(int i=el.tamanho; i>=aux_posicao; i--){
        el.elementos[i] = el.elementos[i-1];
    }
    preenche_aux(aux);
    verifica_insercao(el,aux);
    el.elementos[aux_posicao] = aux;
    el.tamanho++;
}

template <typename TIPO, int MAX>
int menu_inserir(Lista<TIPO, MAX> &el, Elemento<TIPO> &aux){
    int aux_menu;

    cout << endl << endl << endl;
    cout << "\t\t\tEscolha a maneira de inserção: ";
    cout << endl << endl << "\t\t\t1 - Inserir no final";
    cout << endl << "\t\t\t2 - Inserir no início";
    cout << endl <<  "\t\t\t3 - Inserir em uma posição específica" << endl << endl << "\t\t\t";
    cin >> aux_menu;

    switch (aux_menu){

        case 1:
            insere_final(el,aux);
            break;

        case 2:
            insere_inicio(el,aux);
            break;

        case 3:
            insere_posicao(el,aux);
            break;
    }
}

template <typename TIPO, int MAX>
int remove_final(Lista<TIPO, MAX> &el){
    el.tamanho--;
}

template <typename TIPO, int MAX>
int remove_inicio(Lista<TIPO, MAX> &el){
    for(int i = 0; i < el.tamanho; i++){
        el.elementos[i] = el.elementos[i+1];
    }
    el.tamanho--;
}

template <typename TIPO, int MAX>
int remove_posicao(Lista<TIPO, MAX> &el){
    int aux_posicao;

    system("cls");

    cout << endl << endl << endl;
    cout << "\t\t\tInsira em qual posição remover: ";
    cin >> aux_posicao;
    aux_posicao = aux_posicao-1;

    for(int i = aux_posicao; i < el.tamanho; i++){
        el.elementos[i] = el.elementos[i+1];
    }
    el.tamanho--;
}

template <typename TIPO, int MAX>
int menu_remover(Lista<TIPO, MAX> &el, Elemento<TIPO> &aux){
    int aux_menu;

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
            remove_posicao(el);
            break;
    }
}

template <typename TIPO, int MAX>
int mostrar_elementos(Lista<TIPO, MAX> &el){
    system("cls");

    cout << endl << endl << endl;

    for(int i=0; i<el.tamanho; i++){
        cout << "\t\t - " << el.elementos[i].dado << endl << endl;

    }
}

template <typename TIPO, int MAX>
int buscar_elementos(Lista<TIPO, MAX> &el){
    int aux_posicao;

    cout << endl << endl << endl << "\t\t\tInsira a posição do elemento que quer buscar: ";
    cin >> aux_posicao;
    cout << endl << endl << "\t\t\tElemento inserido na posição " << aux_posicao << ": ";
    aux_posicao--;

    if (aux_posicao > el.tamanho){
        cout << endl << endl << "\t\t\tNão há nenhuma carta nesta posição!";
    } else {
        for (int i=0; i < MAX; i++){
            if (aux_posicao == i){
                cout << el.elementos[i].dado << " | copas" << endl << endl;

            }
        }
    }
}

template <typename TIPO, int MAX>
int qtd_Elemento(Lista<TIPO, MAX> &el){
    system("cls");

    cout << endl << endl << endl << "\t\t\tQuantidade de Elemento inseridas: " << el.tamanho << endl << endl;
}

template <typename TIPO, int MAX>
int zerar_baralho(Lista<TIPO, MAX> &el){
    el.tamanho = 0;
    cout << endl << endl << endl << "\t\t\tBaralho Excluído! :)";
}

template <typename TIPO, int MAX>
int embaralhar(Lista<TIPO, MAX> &el){
    int num1, num2, contagem = 0;
    Elemento<TIPO> aux_troca;

    srand(time(NULL));

    do {
        num1 = rand()%52;
        num2 = rand()%52;
        aux_troca = el.elementos[num1];
        el.elementos[num1] = el.elementos[num2];
        el.elementos[num2] = aux_troca;
        contagem++;
    } while (contagem <= 100);
}

int main()
{
    setlocale (LC_ALL ,"Portuguese");

    int aux_menu;
    int teste;
    Lista <int, 52> poker;
    Elemento<int> aux;

    inicializa_lista_gen(poker);

    do{
        cout << "\n\n\t\t- Menu -" << endl << endl << endl;
        cout << "\t\t1 - Inserir carta" << endl;
        cout << "\t\t2 - Remover carta" << endl;
        cout << "\t\t3 - Mostrar as cartas inseridas" << endl;
        cout << "\t\t4 - Buscar alguma carta" << endl;
        cout << "\t\t5 - Mostrar quantidade de cartas inseridas" << endl;
        cout << "\t\t6 - Remover todas as cartas" << endl;
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
                qtd_Elemento(poker);
                system("pause>nul");
                system("cls");
                break;

            case 6:
                system("cls");
                zerar_baralho(poker);
                system("pause>nul");
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
