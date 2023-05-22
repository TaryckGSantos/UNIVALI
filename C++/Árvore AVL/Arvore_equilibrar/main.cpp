#include <iostream>
using namespace std;
#include "elementos.h"

int main()
{
    setlocale(LC_ALL,"portuguese");
    TArvore<char> arvore;
    int select,i=0;
    char var;
    inicializarNo(arvore);
//    insere(arvore.Raiz,50,i);
//    insere(arvore.Raiz,60,i);
//    insere(arvore.Raiz,40,i);
//    insere(arvore.Raiz,45,i);
//    insere(arvore.Raiz,30,i);
//    insere(arvore.Raiz,20,i);

    /*insere(arvore.Raiz,8,i);
    insere(arvore.Raiz,11,i);
    insere(arvore.Raiz,3,i);
    insere(arvore.Raiz,4,i);
    insere(arvore.Raiz,1,i);
    insere(arvore.Raiz,7,i);
    insere(arvore.Raiz,2,i);
    insere(arvore.Raiz,5,i);
    insere(arvore.Raiz,6,i);*/
    do{
        ///cout << "\n\nOrdem de Inserção dos Números:\t 8, 11, 3, 4, 1, 9, 2, 5, 10";
        mostrarArvore(arvore.Raiz,1);
        cout << "\n\n\t\t\t- Menu -" << endl << endl << endl;
        cout << "\t\t\t1 - Inserir " << endl;
        cout << "\t\t\t2 - Remover " << endl;
        cout << "\t\t\t3 - Pre-Ordem " << endl;
        cout << "\t\t\t4 - In-Ordem " << endl;
        cout << "\t\t\t5 - Pos-Ordem " << endl;
        cout << "\t\t\t6 - Buscar " << endl;
        cout << "\t\t\t7 - Equilibrar" << endl;
        cout << "\t\t\t8 - Encerrar a lista" << endl << endl;
        cout << "\t\t\tDigite o que você deseja fazer: ";
        cin>>select;
        cout<<endl;
        switch(select){
        case 1:
            cout<<"\t\t\tDigite o valor que deseja adicionar na Árvore: ";
            cin>>var;
            insere(arvore.Raiz,var,i);
            break;
        case 2:
            cout<<"\t\t\tDigite o valor que deseja remover da Árvore: ";
            cin>>var;
            procura_remove(arvore.Raiz,var);
            break;
        case 3:
            cout<<"\t\t\tPré Ordem: \n\t\t\t";
            pre_ordem(arvore.Raiz);
            break;
        case 4:
            cout<<"\t\t\tIn Ordem: \n\t\t\t";
            in_ordem(arvore.Raiz);
            break;
        case 5:
            cout<<"\t\t\tPós Ordem: \n\t\t\t";
            pos_ordem(arvore.Raiz);
            break;
        case 6:
            cout<<"\t\t\tDigite o valor que deseja buscar da Árvore: ";
            cin>>var;
            if(procura(arvore.Raiz,var)==true){
                cout<<"\n\t\t\tNúmero foi achado";
            }
            break;
        case 7:

            break;
        case 8:
            exit(0);
            break;
        }
    }while(select!=8);
    return 0;
}

