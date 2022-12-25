#include <iostream>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define TAM 4
using namespace std;

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int mat[TAM][TAM]={1,4,5,2,7,2,8,7,3,6,1,4,6,5,3,8};
    int mat1[TAM][TAM]={0};
    int mat2[TAM][TAM]={0};
    int num, confirmacao;
    int jogadas=24;
    int jogaf, pontos=0;
    int l1,l2,c1,c2,escolha1,escolha2;
    int k = 3;

    cout << endl << "\n\n\t\t\t    Bem-vindo ao jogo da memória. Regras: " << endl;
    cout << endl << "\t1 - Voce terá 24 tentativas de acertar os 8 pares de números";
    cout << endl << "\t2 - O número de linhas e colunas começam do 0 (mais a esquerda) e vai até o 3 (mais a direita) ";
    cout << endl << "\t3 - Após memorizar a sua matriz, digite 1 para iniciar o jogo. Esta será a sua matriz: ";

    srand(time(NULL));
    num = rand()%4;

    cout << endl << endl;

    switch(num){
        case 0:
            for(int i=0;i<TAM;i++){
                cout << "\t\t\t";
                for(int j=0;j<TAM;j++){
                    cout << "\t";
                    mat1[i][j]=mat[i][j];
                    cout << "|" << mat1[i][j] << "|";
                }
                cout << endl;
            }
            break;

        case 1: // Matriz transposta
            for(int i=0;i<TAM;i++){
                cout << "\t\t\t";
                for(int j=0;j<TAM;j++){
                    cout << "\t";
                    mat1[i][j]=mat[j][i];
                    cout << "|" << mat1[i][j] << "|";
                }
                cout << endl;
            }
            break;

        case 2: //Matriz invertida por linha
            for(int i=0;i<TAM;i++){
                cout << "\t\t\t";
                for(int j=0;j<TAM;j++){
                    cout << "\t";
                    mat1[i][j]=mat[k][j];
                    cout << "|" << mat1[i][j] << "|";
                }
                k--;
                cout << endl;
            }
            break;

        case 3: //Matriz invertida por coluna
            for(int j=0;j<TAM;j++){
                cout << "\t\t\t";
                for(int i=0;i<TAM;i++){
                    cout << "\t";
                    mat1[i][j]=mat[i][k];
                    cout << "|" << mat1[i][j] << "|";
                }
                k--;
                cout << endl;
            }
            break;
    }

    cout << endl << endl;
    cout << "\tPressione 1 para iniciar: ";
    cin >> confirmacao;

    if (confirmacao == 1) {
        system("cls");
    } else {
        cout << endl << "\tPressione apenas 1 ";
        return 0;
    }

    cout << endl << endl << "\t\t\t|X|\t|X|\t|X|\t|X|\n\t\t\t|X|\t|X|\t|X|\t|X|\n\t\t\t|X|\t|X|\t|X|\t|X|\n\t\t\t|X|\t|X|\t|X|\t|X|"<<endl;

    if(jogadas>0){
        do{
            cout << endl << endl;
            cout << "\tSua pontuação: " << pontos << endl;
            cout << "\tSuas tentativas: " << jogadas << endl;
            cout << "\n\t - Pressione qualquer tecla para jogar - ";
            system("pause>nul");
            system("cls");
            cout << "\n\tEscolha uma linha de 0 a 3 : ";
            cin >> l1;

            if (l1>3 ||l1<0){
                cout << endl << endl << "\t - Você escolheu um número inválido! Digite apenas números de 0 a 3! - " << endl << endl;
                cout << "\n\tEscolha uma linha de 0 a 3 : ";
                cin >> l1;
            }

            cout << endl;
            cout << "\n\tEscolha uma coluna de 0 a 3 : ";
            cin >> c1;

            if (c1>3 || c1 < 0){
                cout << endl << endl << "\t - Você escolheu um número inválido! Digite apenas números de 0 a 3! - " << endl << endl;
                cout <<"\n\tEscolha uma coluna de 0 a 3 : ";
                cin >> c1;
            }

            cout << endl << endl << endl;

            for(int i=0;i<TAM;i++){
                cout << "\t\t";
                for(int j=0;j<TAM;j++){
                    cout << "\t";
                    if(i==l1 && j==c1){
                        cout << "|" << mat1[i][j] << "|";
                        escolha1 = mat1[i][j];
                    }else{
                        cout << "|X|";
                    }
                }
                cout << endl;
            }

            cout << endl << endl << "\tNúmero da coordenada escolhida: "<< escolha1 << endl << endl;
            cout << " - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
            cout << "\n\tEscolha outra linha de 0 a 3 : ";
            cin >> l2;
            if (l2>3 ||l2<0){
                cout << endl << endl << "\t - Você escolheu um número inválido! Digite apenas números de 0 a 3! - " << endl << endl;
                cout <<"\n\tEscolha uma linha de 0 a 3 : ";
                cin >> l2;
            }

            cout << endl;
            cout << "\n\tEscolha outra coluna de 0 a 3 : ";
            cin >> c2;
            if (c2>3 || c2<0){
                cout << endl << endl << "\t - Você escolheu um número inválido! Digite apenas números de 0 a 3! - " << endl << endl;
                cout <<"\n\tEscolha uma coluna de 0 a 3 : ";
                cin >> c2;
            }

            while(l1==l2 && c1==c2){
                cout << endl;
                cout<<"O ponto ja foi escolhido! Escolha outras coordenadas novamente " << endl << "\t\t";
                cout <<"\n\tEscolha uma linha de 0 a 3 : ";
                cin >> l2;
                if (l2>3 ||l2<0){
                    cout << endl << endl << "\t - Você escolheu um número inválido! Digite apenas números de 0 a 3! - " << endl << endl;
                    cout <<"\n\tEscolha uma linha de 0 a 3 : ";
                    cin >> l2;
                }

                cout << endl;
                cout << "\n\tEscolha uma coluna de 0 a 3 : ";
                cin >> c2;

                if (c2>3 || c2<0){
                    cout << endl << endl << "\t - Você escolheu um número inválido! Digite apenas números de 0 a 3! - " << endl << endl;
                    cout <<"\n\tEscolha uma coluna de 0 a 3 : ";
                    cin >> c2;
                }
            }

            jogadas = jogadas-1;

            cout << endl << endl << endl;

            for(int i=0;i<TAM;i++){
                cout << "\t\t";
                for(int j=0;j<TAM;j++){
                    cout << "\t";
                    if(i==l2 && j==c2){
                        cout<<"|"<<mat1[i][j]<<"|";
                        escolha2=mat1[i][j];
                    } else if(l1==i && c1==1){
                        cout<<"|"<<mat1[l1][c1]<<"|";
                    } else {
                        cout<<"|X|";
                    }
                }cout<<endl;
            }

            cout << endl << endl << "\tNúmero da coordenada escolhida: "<< escolha2 << endl << endl;

            if(escolha1==escolha2){
                pontos = pontos + 1;
                mat2[l1][c1] = escolha1;
                mat2[l2][c2] = escolha2;
                cout << "\t";
                system("pause>nul");
                system("cls");
                cout << "   ________________________________________________________________";
                cout << endl << endl << "\tVocê acertou! Parabéns!" << endl << endl;
                cout << "\tVocê ainda tem " << jogadas << " jogadas para terminar o jogo. " << endl;
                cout << "   ________________________________________________________________";
                cout << endl << "\t";
                system("pause>nul");
                system("cls");

            } else if (escolha1!=escolha2){
                cout << "\t";
                system("pause>nul");
                system("cls");
                cout << "   ________________________________________________________________";
                cout << endl << endl << "\tVocê errou, tente novamente" << endl << endl;
                cout << "\tVocê ainda tem " << jogadas << " jogadas para terminar o jogo. " << endl;
                cout << "   ________________________________________________________________";
                cout << endl << "\t";
                system("pause>nul");
                system("cls");
            }

            cout << endl << endl;

            for(int i=0;i<TAM;i++){
                cout << "\t\t";
                for(int j=0;j<TAM;j++){
                    cout << "\t";
                    if(mat2[i][j]==0){
                        cout<<"|X|";
                    } else {
                        cout<<"|"<<mat2[i][j]<<"|";
                    }
                }
                cout<<endl;
            }

            if(jogadas==0){
                system("cls");
                cout << "\t\t\t\t_____________________________";
                cout << "\n\n\t\t\t\t\t Você perdeu! " << endl;
                cout << "\t\t\t\t_____________________________";
                cout << endl << endl << endl;
                cout << "\tMatriz resposta: " << endl << endl;
                for(int i=0;i<TAM;i++){
                    cout << "\t\t";
                    for(int j=0;j<TAM;j++){
                        cout << "\t";
                        if(mat1[i][j]==0){
                            cout<<"|X|";
                        } else {
                            cout<<"|"<<mat1[i][j]<<"|";
                        }
                    }
                cout<<endl;
            }
                system("pause>nul");
                system("cls");
            }
        } while(pontos!=8 && jogadas>0);
    }
    if(pontos>=8 && mat1[TAM][TAM] == mat2[TAM][TAM]){
        jogaf=24-jogadas;
        system("cls");
        cout << endl << endl;
        cout << "\t\t___________________________________________________________";
        cout << "\n\n\t\t\tVocê ganhou! \n\t\t\tVocê terminou o jogo com apenas "<<jogaf<<" jogadas."<<endl;
        cout << "\t\t___________________________________________________________";
        cout << endl << endl;
    }
    return 0;
}
