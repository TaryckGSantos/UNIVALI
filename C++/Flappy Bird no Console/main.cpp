
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <cstdlib>

#define RAND_MAX 2O

using namespace std;

int main()
{
    ///ALERTA: NÃO MODIFICAR O TRECHO DE CÓDIGO, A SEGUIR.
    //INICIO: COMANDOS PARA QUE O CURSOR NÃO FIQUE PISCANDO NA TELA
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO     cursorInfo;
    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = false; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
    //FIM: COMANDOS PARA QUE O CURSOR NÃO FIQUE PISCANDO NA TELA
    //INÍCIO: COMANDOS PARA REPOSICIONAR O CURSOR NO INÍCIO DA TELA
    COORD coord;
    //FIM: COMANDOS PARA REPOSICIONAR O CURSOR NO INÍCIO DA TELA
    ///ALERTA: NÃO MODIFICAR O TRECHO DE CÓDIGO, ACIMA.

    int random1,random2,random3; //Utilizado para criar obstaculos aleatoriamente
    srand(time(NULL));
    random1=rand()%10;
    random2=rand()%10;
    random3=rand()%10;

    int bird_x = 5, bird_y = 10;
    int obstaculo_x = 30, obstaculo_x2 = 60, obstaculo_x3 = 90, obstaculo_y, obstaculo_y2, obstaculo_y3;
    int tecla;
    int pontuacao = 0;

    ///DESENHO DO CENÁRIO
    while (true) { //este laço faz o jogo executar infinitamente
        system("cls"); // Utilizado para limpar rastros do pássaro e dos obstáculos no cmd.
        cout<<"--------------------------------------------------------------------------------------------"; // Desenho das bordas do cenário.
        cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"; // Espaçameto onde será rodado o game
        cout<<"--------------------------------------------------------------------------------------------";
        cout<< "\n- Pontuacao: " << pontuacao << endl; // Pontuação exibida na parte inferior esquerda do game

    /// POSICIONAMENTO DO PÁSSARO
    coord.X = bird_x;    coord.Y = bird_y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    cout<<char(190); //Caractere utilizado para simbolizá-lo


    ///POSICIONA O OBSTÁCULO
    obstaculo_y=1; // Valor inicial dado ao obstáculo 1.
    while(obstaculo_y<20){ // Enquanto o valor de Y estiver dentro dos padrões estabelecidos, o laço será repetido.
        coord.X = obstaculo_x;    coord.Y = obstaculo_y; //
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        if(obstaculo_y<random1|| obstaculo_y>random1+4){ // Valores dados para a ocupação do obstáculo no eixo Y
            cout<<char(219); // Caractere escolhido para representar as colunas
            } else { // Caso não se encaixe nos padrões estabelecidos, haverá uma abertura nos obstáculos.
                cout<<" "; // Caractere de espaçamento
            }
    obstaculo_y++; // Acionar um obstáculo infinitamente enquanto o laço de repetição estiver executando
    }

    obstaculo_y2=1; // Valor inicial dado ao obstáculo 2.
    while(obstaculo_y2<20){ // Enquanto o valor de y2 estiver dentro dos padrões estabelecidos, o laço será repetido.
        coord.X = obstaculo_x2;    coord.Y = obstaculo_y2;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        if(obstaculo_y2<random2 || obstaculo_y2>random2+4){ // Valores dados para a ocupação do obstáculo y2 no eixo Y
            cout<<char(219);
            } else {
                cout<<" ";
            }
    obstaculo_y2++;
    }

    obstaculo_y3=1; // Valor inicial dado ao obstáculo 2.
    while(obstaculo_y3<20){  // Enquanto o valor de y3 estiver dentro dos padrões estabelecidos, o laço será repetido.
        coord.X = obstaculo_x3;    coord.Y = obstaculo_y3;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        if(obstaculo_y3<random3 || obstaculo_y3>random3+4){ // Valores dados para a ocupação do obstáculo y3 no eixo Y
            cout<<char(219);
            } else {
                cout<<" ";
            }
            obstaculo_y3++;
        }

    ///VERIFICA COLISÃO
    if (bird_x  == obstaculo_x && (bird_y >= random1 && bird_y <= random1+4)){ // Caso o pássaro passe pelo espaçamento entre o obstáculo 1, o desvio descrito abaixo será executado.
        pontuacao += 1; // Adiciona 1 na pontuação
        } else if (bird_x  == obstaculo_x){ // Caso haja uma colisão do pássaro no obstáculo 1, realizar o desvio:
            system("cls");
            cout<< "Game Over!" << endl; // Mensagem
            cout<< "Sua pontuacao foi : "<< pontuacao << endl;
            system("pause"); // Pausa a execução da aplicação.
            return 0;
        }

    if (bird_x  == obstaculo_x2 && (bird_y >= random2 && bird_y <= random2+4)){ // Caso o pássaro passe pelo espaçamento entre o obstáculo 2, o desvio descrito abaixo será executado.
        pontuacao += 1;
        } else if (bird_x  == obstaculo_x2){ // Caso haja uma colisão do pássaro no obstáculo 2, realizar o desvio:
            system("cls");
            cout<< "Game Over!" << endl;
            cout<< "Sua pontuacao foi : "<< pontuacao<< endl;
            system("pause");;
            return 0;
        }

    if (bird_x  == obstaculo_x3 && (bird_y >= random3 && bird_y <= random3+4)){ // Caso o pássaro passe pelo espaçamento entre o obstáculo 3, o desvio descrito abaixo será executado.
        pontuacao += 1;
        } else if (bird_x  == obstaculo_x3){ // Caso haja uma colisão do pássaro no obstáculo 3, realizar o desvio:
            system("cls");
            cout<< "Game Over!" << endl;
            cout<< "Sua pontuacao foi : "<< pontuacao<< endl;
            system("pause");
            return 0;
            }

    if (bird_y == 20 ){ // Caso o pássaro toque na borda inferior do jogo, o desvio será realizado
        system("cls");
        cout<< "Game Over!" << endl;
        cout<< "Sua pontuacao foi : "<< pontuacao<< endl;
        system("pause");
        return 0;
        }

    if (bird_y == 0){ // Caso o pássaro toque na borda superior do jogo, o desvio será realizado
        system("cls");
        cout<< "Game Over!" << endl;
        cout<< "Sua pontuacao foi : "<< pontuacao<< endl;
        system("pause");
        return 0;
        }

    ///VERIFICA COMANDO DO JOGADOR
    if (kbhit()) { ///verifica se uma tecla foi pressionada
        tecla=getch(); //verifica comando do jogador
        }
    if ( tecla=='w' ){ // Caso a tecla w seja acionada, o pássaro vai para cima.
        bird_y--;
        tecla='0';
        } else { // Caso a tecla não seja acionada, ele cai uma posição.
            bird_y++;
        }

    ///OBSTÁCULO AVANÇA UMA POSIÇÃO PARA ESQUERDA
    if (obstaculo_x <= 0) { // Quando o obstáculo surgir pela direita, realizar o desvio:
        obstaculo_x = 90; // O obstáculo surge no ponto mais distante
         random1=rand()%10;
        }
    if (obstaculo_x2 <=0){
        obstaculo_x2 =90;
         random2=rand()%10;
        }
    if (obstaculo_x3 <=0){
        obstaculo_x3 =90;
        random3=rand()%10;
        }
    obstaculo_x--; // O obstáculo vai se recuando para a esquerda a cada desvio realizado
    obstaculo_x2--;
    obstaculo_x3--;

    ///TEMPO DE ESPERA
    if ( pontuacao >= 0 && pontuacao < 5) { // Como não conseguimos aumentar a velocidade através do laço de repetição, fizemos por meio de desvios condicionais.
        Sleep(180);
        } else if ( pontuacao >= 5 && pontuacao < 10 ) {
            Sleep(130);
        } else if ( pontuacao >= 10 && pontuacao < 15 ) {
            Sleep(110);
        } else if ( pontuacao >= 15 && pontuacao < 20 ) {
            Sleep(90);
        } else if ( pontuacao >= 25 ) {
            Sleep(50);
        }
    }
    return 0;
}
