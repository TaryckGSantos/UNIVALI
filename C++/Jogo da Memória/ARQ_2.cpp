//  Pedro Kons, Taryck Santos, Thiago Pacheco, Vinicius Pereira
#include <iostream>
#define TAM 4
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
using namespace std;

int main()
{
    setlocale(LC_ALL, "portuguese");
    int mat[TAM][TAM]={1,4,5,2,7,2,8,7,3,6,1,4,6,5,3,8}; //Declarando variaveis
    int mat1[TAM][TAM]={0}; //matriz gabarito 1
    int mat2[TAM][TAM]={0}; //matriz gabarito 2
    int num, confirmacao;
    int jogadas=24;
    int jogaf, pontos=0;
    int l1,l2,c1,c2,escolha1,escolha2;
    int k = 3; // Utilizado na hora de inverter matrizes por coluna e linha

    cout << endl << "Bem vindo ao jogo da memoria. Essas sao as regras: " << endl;
    cout << endl << "1 - Voce tera 24 tentativas de acertar os 8 pares de numeros";
    cout << endl << "2 - O numero de linhas e colunas comecam do 0 (mais a esquerda) e vai ate o 3 (mais a direita) ";
    cout << endl << "3 - Digite 1 para iniciar o jogo.";
    cout << endl << endl;
    cout << "Pressione 1 para iniciar: ";
    cin >> confirmacao;
    if (confirmacao == 1) {
        system("cls");
    } else {
        cout << endl << "Pressione apenas 1" << endl;
        return 0;
        }

    srand(time(NULL));
    num= rand()%4; //Declarando aleatoriedade para a escolha de operações da matriz princial, logo, ele ira "sortear" aleatoriamente um numero de 0 a 3
    switch(num){ // Usamos o comando switch como um menu de seleção, logo aquele numero sorteado do comentario anterior sera atribuido aqui, selecionando a operação da matriz
        case 0: //Matriz principal
            for(int i=0;i<TAM;i++){
                for(int j=0;j<TAM;j++){
                    mat1[i][j]=mat[i][j];
                }
            }
            break;

        case 1: // Matriz transposta
            for(int i=0;i<TAM;i++){
                for(int j=0;j<TAM;j++){
                    mat1[i][j]=mat[j][i];
                }
            }
            break;

        case 2: //Matriz invertida por linha
            for(int i=0;i<TAM;i++){
                for(int j=0;j<TAM;j++){
                    mat1[i][j]=mat[k][j];
                }
                k--;
            }
            break;

        case 3: //Matriz invertida por coluna
            for(int j=0;j<TAM;j++){
                for(int i=0;i<TAM;i++){
                    mat1[i][j]=mat[i][k];
                }
                k--;
            }
            break;
    }

    cout<<"\t|X|\t|X|\t|X|\t|X|\n\t|X|\t|X|\t|X|\t|X|\n\t|X|\t|X|\t|X|\t|X|\n\t|X|\t|X|\t|X|\t|X|"<<endl; // Contruir a matriz "escondida" dentro do jogo

    if(jogadas>0){ //Enquanto o numero de jogadas for maior que 0 ele vai executar o laço abaixo...
        do{
            cout<< endl;
            cout<< "Sua pontuacao: "<< pontos <<endl;
            cout<< "Sua tentativas: "<< jogadas <<endl;
            cout<<"\nEscolha uma linha e uma coluna de 0 a 3 : "<<endl; //Escolha do jogador das "coordenadas" da peça para ser virada
            cin>>l1>>c1;
            while(l1>3 ||l1<0 || c1>3 || c1<0 || mat2[l1][c1]!=0){ //Enquanto a linha e a coluna forem maior que 3 e menor que , ou o valor da matriz do mat2 for diferente de 0 aparecera a mensagem abaixo
                cout<<"Você escolheu um número inválido"<<endl;
                cout<<"Escolha uma linha e uma coluna de 0 a 3 : "<<endl; //Nova chance para o jogador escolher a "coordenada"
                cin>>l1>>c1;
            }
            for(int i=0;i<TAM;i++){ // Declarando a matriz de acordo com as escolhas feitas pelo jogador, revelando a peça virada
                for(int j=0;j<TAM;j++){
                    if(i==l1 && j==c1){
                        cout<<"|"<<mat1[i][j]<<"|";
                        escolha1=mat1[i][j];
                    }else{
                        cout<<"|X|";
                    }
                }
                cout<<endl;
            }
            cout<<"\t"<<escolha1<<endl;
            cout<<"Escolha outra linha e uma coluna de 0 a 3 : "<<endl; //Escolha da posição da segunda peça a ser virada
            cin>>l2>>c2;

            while(l2>3 ||l2<0 || c2>3 || c2<0|| mat2[l2][c2]!=0){ //Enquanto a linha e a coluna forem maior que 3 e menor que , ou o valor da matriz do mat2 for diferente de 0 aparecera a mensagem abaixo
                cout<<"Você escolheu um número inválido"<<endl;
                cout<<" Escolha outra linha e uma coluna de 0 a 3 : "<<endl;
                cin>>l2>>c2;
            }
            while(l1==l2&&c1==c2){
                cout<<"O ponto ja foi escolhido, escolha outra linha e outra coluna de 0 a 3: "<<endl;
                cin>>l2>>c2; // Caso o ponto ja tenha sido escolhido anteriormente, a mensagem acima aparece
            }

            jogadas=jogadas-1; // Diminui o numero de jogadas
            escolha2 = mat1[l2][c2]; // Segunda escolha do jogador se igualando com o gabarito

            for(int i=0;i<TAM;i++){
                for(int j=0;j<TAM;j++){ // Declarando a matriz de acordo com as escolhas feitas pelo jogador, revelando a peça virada
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
            if(escolha1==escolha2){ // Se ambas as escolhas do jogador forem de valores iguais...
                pontos=pontos+1; // o numero de pontos aumenta
                for(int i=0;i<TAM;i++){ // e o valor das escolhas é revelado na matriz em suas respectivas posições
                    for(int j=0;j<TAM;j++){
                        if(mat1[i][j]==escolha1){
                            cout<<"|"<<mat1[i][j]<<"|";
                            mat2[i][j]=mat1[i][j];
                        } else if(mat1[i][j]==escolha2){
                            cout<<"|"<<mat1[i][j]<<"|";
                            mat2[i][j]=mat1[i][j];
                        } else{cout<<"|X|";
                        }
                    }
                    cout << endl;
                }
                system("cls"); // Clear
                cout<<"Você acertou! Parabéns! \nAgora você ainda tem "<<jogadas<<" jogadas para terminar o jogo. "<<endl; //caso o jogador acerta, ira mostrar quantos pontos o jogador esta no momento e quantas jogadas faltam
                system("pause");
                system("cls");

            } else if (escolha1!=escolha2){ // Caso os valores das escolhas feitas pelo jogador sejam diferentes, a mensagem abaixo aparece
                system("pause");
                system("cls");
                cout<<"Você errou, tente novamente\nVocê ainda tem "<<jogadas<<" jogadas "<<endl;
                system("pause");
                system("cls");
            }
            for(int i=0;i<TAM;i++){// os valores não são revelados na matriz, que continua "oculta"
                for(int j=0;j<TAM;j++){
                    if(mat2[i][j]==0){
                        cout<<"|X|";
                    } else {
                        cout<<"|"<<mat2[i][j]<<"|";
                    }
                }
                cout<<endl;
            }
            if(jogadas==0){ //Se o numero de jogadas chegar a 0, significa que voce perdeu o jogo
                cout<<"____";
                cout<<"\n\n\tVocê perdeu!\n"<<endl;
                cout<<"____";
                for(int i=0;i<TAM;i++){
                    for(int j=0;j<TAM;j++){
                        cout << endl << endl << "Matriz resposta: " << endl << endl << mat1[i][j] << "\t"; // Caso o jogador perca, a matriz resposta é mostrada na tela
                    }
                    cout << endl;
                }
                system("pause");
                system("cls");
            }
        } while(pontos!=8 && jogadas>0);// O laço de repetição só vai rodar enquanto os pontos forem diferentes de 8 e o numero de jogadas maior do que 0
    }
    if(pontos>=8){ // Se o numero de pontos for maior ou igual a oito, significa que voce ganhou o jogo
        jogaf=24-jogadas;
        cout<<"__";
        cout<<"\n\nVocê ganhou! Você terminou o jogo com apenas "<<jogaf<<" jogadas."<<endl;
        cout<<"__";
    }
    return 0;
}
