//Nomes: Pedro Kons, Taryck, Vinicius Pereira, Thiago.
#include <iostream>
#include <time.h>
#include <locale.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>

#define TAM 5 //Quantidade de Cartelas e tamanho da matriz.
#define PED 75//Quantidade de sorteios de pedras.

#define BLACK        0
#define WHITE        7
#define LIGHTGREEN   10
#define LIGHTAQUA    11
#define LIGHTRED     12
#define LIGHTPURPLE  13
#define LIGHTYELLOW  14
#define BRIGHTWHITE  15

using namespace std;

void textcolor (int forecolor, int backcolor) {
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), (WORD) (forecolor | backcolor<<4));
}

void nomear_cartelas(string cart_mat[TAM]){// funcao para nomear cada cartela.
    setlocale(LC_ALL, "Portuguese");

    for(int a = 0; a < TAM; a++){// laco que vai do 1 ao 5.
        cout << "Escreva o nome do jogador da " << a+1 << "ª cartela: ";
        cin >> cart_mat[a];// atribiu o nome do jogador.
        cout << endl;
    }
}

bool verifrep(int mat[TAM][TAM],int temp){// funcao que verifica a repeticao das linhas da matriz generica.

    for(int i=0;i<TAM;i++){ //laco que passa pela linha da matriz.
        for(int j=0;j<TAM;j++){ //laco que passa pela coluna da matriz.
            if(mat[i][j]==temp){ //condicao quando um valor ja atribuido for igual a da variavel temporaria.
                return true;// retorna para fazer um laco na funcao naleatorio.
            }
        }
    }
    return false;// atribui o valor direto na matriz logo que nao ha reticao.
}

void naleatorio(int mat[TAM][TAM], int mat1[TAM][TAM], int mat2[TAM][TAM], int mat3[TAM][TAM], int mat4[TAM][TAM], int mat5[TAM][TAM]){
    srand(time(NULL)); //gerar numeros aleatorios.
    setlocale(LC_ALL, "Portuguese");

    int contcart = 0,iguais,temp;

    while(contcart<5) { // laco principal que quantidade de cartelas.
        for(int i=0;i<TAM;i++){ // movendo-se pela matriz.
            for(int j=0; j<TAM; j++){ //movendo-se pela matriz.
                if(i==0){ // condicao quando a linha for igual a zero.
                    temp=rand()%15+1; // variavel temporaria recebe um valor aleatorio de 1 a 15.
                    while(verifrep(mat,temp)){// caso haja um valor ja existente vai passar por essa funcao para verificar.
                        temp=rand()%15+1;// atribui outra valor aleatorio diferente do anterior "caso for repetido".
                    }
                    mat[i][j]=temp;// valor atribuido na matriz.
                } else if(i==1){ //condicao quando a linha for igual a 1.
                    temp=rand()%15+16;//variavel temporaria recebe um valor aleatorio de 16 ao 30.
                    while(verifrep(mat,temp)){
                        temp=rand()%15+16;
                    }
                    mat[i][j]=temp;
                } else if(i==2){//condicao quando a linha for igual a 2.
                    temp=rand()%15+31;//variavel temporaria recebe um valor aleatorio de 31 ao 45.
                    while(verifrep(mat,temp)){
                        temp=rand()%15+31;
                    }
                    mat[i][j]=temp;
                } else if(i==3){//condicao quando a linha for igual a 3.
                    temp=rand()%15+46;//variavel temporaria recebe um valor aleatorio de 46 ao 60.
                    while(verifrep(mat,temp)){
                        temp=rand()%15+46;
                    }
                    mat[i][j]=temp;
                } else if(i==4){//condicao quando a linha for igual a 4.
                    temp=rand()%15+61;//variavel temporaria recebe um valor aleatorio de 61 ao 75.
                    while(verifrep(mat,temp)){
                        temp=rand()%15+61;
                    }
                    mat[i][j]=temp;
                    }
            if(contcart==0){ //Quando for zero os valores gerados entram nessa condicao.
                    mat1[i][j] = mat[i][j];// matriz 1 recebe valores matriz generica.

                } else if(contcart==1){ //Quando for 1 os valores gerados entram nessa condicao.
                    mat2[i][j] = mat[i][j];// matriz 2 recebe valores matriz generica.

                } else if(contcart==2){//Quando for 2 os valores gerados entram nessa condicao.
                    mat3[i][j] = mat[i][j];// matriz 3 recebe valores matriz generica.

                } else if(contcart==3){//Quando for 3 os valores gerados entram nessa condicao.
                    mat4[i][j] = mat[i][j];// matriz 4 recebe valores matriz generica.

                } else if(contcart==4){//Quando for 4 os valores gerados entram nessa condicao.
                    mat5[i][j] = mat[i][j];// matriz 5 recebe valores matriz generica.
                }
            }
        }
        contcart++; // conta mais 1 para proxima sequencia.
    }
}

void ordenaMatriz(int mat1[TAM][TAM], int mat2[TAM][TAM], int mat3[TAM][TAM], int mat4[TAM][TAM], int mat5[TAM][TAM]){// ordecao da matriz de forma crescente.

    for (int i = 0; i < TAM; i++) { // movendo-se pelas linhas.
        for (int j = 0; j < TAM; j++) { //movendo-se pelas colunas.

            for (int a = 0; a < TAM; a++) { // movendo-se pelas linhas aux.
                for (int b = 0; b < TAM; b++) { // movendo-se pelas colunas aux.
                    if (mat1[i][j] < mat1[a][b]) { // Caso o valor das proximas pedras da matriz for maior que o valor atual
                        int var = mat1[i][j]; // variavel auxiliar recendo o valor da matriz principal (valor maior)
                        mat1[i][j] = mat1[a][b]; // matriz principal recebendo o valor menor
                        mat1[a][b] = var; // matriz secundaria recebendo o valor maior
                    }
                    if (mat2[i][j] < mat2[a][b]) {
                        int var = mat2[i][j];
                        mat2[i][j] = mat2[a][b];
                        mat2[a][b] = var;
                    }
                    if (mat3[i][j] < mat3[a][b]) {
                        int var = mat3[i][j];
                        mat3[i][j] = mat3[a][b];
                        mat3[a][b] = var;
                    }
                    if (mat4[i][j] < mat4[a][b]) {
                        int var = mat4[i][j];
                        mat4[i][j] = mat4[a][b];
                        mat4[a][b] = var;
                    }
                    if (mat5[i][j] < mat5[a][b]) {
                        int var = mat5[i][j];
                        mat5[i][j] = mat5[a][b];
                        mat5[a][b] = var;
                    }
                }
            }
        }
    }
}

void print(int mat1[TAM][TAM], int mat2[TAM][TAM], int mat3[TAM][TAM], int mat4[TAM][TAM], int mat5[TAM][TAM], string cart_mat[TAM]){ // funcao bingo.
    setlocale(LC_ALL, "Portuguese");

    system("cls");// limpa tela.

    cout << endl;

    textcolor(BRIGHTWHITE,BLACK);
    cout << "\tCartela número 1 - Jogador "<< cart_mat[0] << endl << endl; // Cartela 1 e nome do jogador.
    textcolor(WHITE,BLACK);
    for(int i=0;i<TAM;i++){// movendo-se pelas linhas.
        cout << "\t";
        for(int j=0; j<TAM; j++){ //movendo-se pelas colunas.
            if(mat1[i][j]<10 && mat1[i][j]>0){ //numeros de 1 ao 9 aparecerem com zero na frente.
                cout << "|0" << mat1[i][j] << "|\t";
            } else if(mat1[i][j]==0){ // Quando o numero da pedra for igual ao numero da certela eh marcado x.
                textcolor(LIGHTGREEN,BLACK);
                cout<<"|XX|\t"; // marcacao.
                textcolor(WHITE,BLACK);
            } else {
                cout << "|" << mat1[i][j] << "|\t"; // numeros maiores que 9 ganham as barras.
            }
        }
        cout << endl << endl;
    }



    textcolor(BRIGHTWHITE,BLACK);
    cout << endl << endl << "\tCartela número 2 - Jogador "<< cart_mat[1] << endl << endl;
    textcolor(WHITE,BLACK);
    for(int i=0;i<TAM;i++){
        cout << "\t";
        for(int j=0; j<TAM; j++){
            if(mat2[i][j]<10 && mat2[i][j]>0){
                cout << "|0" << mat2[i][j] << "|\t";
            } else if(mat2[i][j]==0){
                textcolor(LIGHTPURPLE,BLACK);
                cout<<"|XX|\t";
                textcolor(WHITE,BLACK);
            } else {
                cout << "|" << mat2[i][j] << "|\t";
            }
        }
        cout << endl << endl;
    }

    textcolor(BRIGHTWHITE,BLACK);
    cout << endl << endl << "\tCartela número 3 - Jogador " << cart_mat[2] << endl << endl;
    textcolor(WHITE,BLACK);
    for(int i=0;i<TAM;i++){
        cout << "\t";
        for(int j=0; j<TAM; j++){
            if(mat3[i][j]<10 && mat3[i][j]>0){
                cout << "|0" << mat3[i][j] << "|\t";
            } else if(mat3[i][j]==0){
                textcolor(LIGHTAQUA,BLACK);
                cout<<"|XX|\t";
                textcolor(WHITE,BLACK);
            } else {
                cout << "|" << mat3[i][j] << "|\t";
            }
        }
        cout << endl << endl;
    }

    textcolor(BRIGHTWHITE,BLACK);
    cout << endl << endl << "\tCartela número 4 - Jogador "<< cart_mat[3] <<endl << endl;
    textcolor(WHITE,BLACK);
    for(int i=0;i<TAM;i++){
        cout << "\t";
        for(int j=0; j<TAM; j++){
            if(mat4[i][j]<10 && mat4[i][j]>0){
                cout << "|0" << mat4[i][j] << "|\t";
            } else if(mat4[i][j]==0){
                textcolor(LIGHTYELLOW,BLACK);
                cout<<"|XX|\t";
                textcolor(WHITE,BLACK);
            } else {
                cout << "|" << mat4[i][j] << "|\t";
            }
        }
        cout << endl << endl;
    }

    textcolor(BRIGHTWHITE,BLACK);
    cout << endl << endl << "\tCartela número 5 - Jogador "<< cart_mat[4] << endl << endl;
    textcolor(WHITE,BLACK);
    for(int i=0;i<TAM;i++){
        cout << "\t";
        for(int j=0; j<TAM; j++){
            if(mat5[i][j]<10 && mat5[i][j]>0){
                cout << "|0" << mat5[i][j] << "|\t";
            } else if(mat5[i][j]==0){
                textcolor(LIGHTRED,BLACK);
                cout<<"|XX|\t";
                textcolor(WHITE,BLACK);
            } else {
                cout << "|" << mat5[i][j] << "|\t";
            }
        }
        cout << endl << endl;
    }
    cout << endl << endl <<"Aperte W para sortear um número: "; // mensagem inicio do jogo.
}

bool verif_ped(int pedras[PED], int temp){ // funcao de noa repeticao para as pedras.

    for(int i=0;i<PED;i++){
        if(pedras[i]==temp) //atribui um novo valor aleatorio para variavel temporaria.
            return true;
        }
        return false; // caso o numero nao for igual ao existente retorna atribuindo o valor direto.
}


void imprimePedras(int pedras[PED],int tamanho){ // Método da bolha para uso na ordenação do vetor de sorteio (pedras)

    int auxped;
    for(int a=0;a<=tamanho;a++){
        for(int b=a+1;b<=tamanho;b++){
            if(pedras[a]>pedras[b]){
                auxped=pedras[a];
                pedras[a]=pedras[b];
                pedras[b]=auxped;
            }
        }
    }

    cout << "Números já sorteados: ";

    for(int g=0;g<=tamanho;g++){ // vetor de exibição dos numeros ja sorteados
        pedras[g];
        cout<< " - " << pedras[g];
    }
}

int print_num(int pedras[PED],int mat1[TAM][TAM],int mat2[TAM][TAM],int mat3[TAM][TAM],int mat4[TAM][TAM],int mat5[TAM][TAM],string cart_mat[TAM], int temp,int pont1,int pont2,int pont3,int pont4,int pont5){
    pont1 = 0, pont2 = 0, pont3 = 0, pont4 = 0, pont5 = 0; //funcao pontuacao e geracao de pedras.

    srand(time(NULL));// numero aleatorio
    int tecla;
    tecla=getch(); //funcao habilitada para usar na biblioteca canio.h, ao aperta tal tecla uma funcao vai ser feita.

    for(int i=0;i<PED;i++){ // laco para vetor pedras.
        temp=rand()%75+1; // atribuicao valor aleatorio variavel temporaria.
        while(verif_ped(pedras,temp)){ //caso for igual a um valor existente eh gerado outro valor.
            temp=rand()%75+1;
        }
        pedras[i]=temp;// assume o valor.
        }

    for(int a=0;a<PED;a++){ // eh executado quando acabar as 75 pedras.
        if(tecla=='w'){ // Quando aperta w um valor eh sorteado.
            cout<< endl << endl <<"Número sorteado: "<<pedras[a]<<"\t"; // exibicao da pedra.
            for (int i = 0; i < TAM; i++) {  // percorrendo a linha da matriz.
                for (int j = 0; j < TAM; j++) { //percorrendo a coluna da matriz
                    if(mat1[i][j]==pedras[a]){ //pontuando na cartela 1
                        mat1[i][j]=0; // identificando para poder marcar o x na funcao print
                        pont1 = pont1 + 1; // contagem da pontuacao.
                    }
                    if(mat2[i][j]==pedras[a]){ //pontuando na cartela 2
                        mat2[i][j]=0; // identificando para poder marcar o x na funcao print
                        pont2 = pont2 + 1; // contagem da pontuacao.
                    }
                    if(mat3[i][j]==pedras[a]){ //pontuando na cartela 3
                        mat3[i][j]=0; // identificando para poder marcar o x na funcao print
                        pont3 = pont3 + 1; // contagem da pontuacao.
                    }
                    if(mat4[i][j]==pedras[a]){ //pontuando na cartela 4
                        mat4[i][j]=0; // identificando para poder marcar o x na funcao print
                        pont4 = pont4 + 1; // contagem da pontuacao.
                    }
                    if(mat5[i][j]==pedras[a]){ //pontuando na cartela 5
                        mat5[i][j]=0; // identificando para poder marcar o x na funcao print
                        pont5 = pont5 + 1; // contagem da pontuacao.
                    }
                }
            }
            system("pause>nul");
            print(mat1,mat2,mat3,mat4,mat5,cart_mat);//exibicao das cartelas

            cout << endl << endl << "Pontuação cartela 1: " << pont1; //exibicao pontuacao 1
            cout << endl << "Pontuação cartela 2: " << pont2; //exibicao pontuacao 2
            cout << endl << "Pontuação cartela 3: " << pont3; //exibicao pontuacao 3
            cout << endl << "Pontuação cartela 4: "  << pont4; //exibicao pontuacao 4
            cout << endl << "Pontuação cartela 5: "  << pont5 << endl << endl; //exibicao pontuacao 5

            imprimePedras(pedras,a);
            ///Laços de empate entre ambos
            if(pont1>=25&&pont2>=25||pont1>=25&&pont3>=25||pont1>=25&&pont4>=25||pont1>=25&&pont5>=25){
                system("cls");
                cout<<"\tO JOGO EMPATOU :( ";
                system("pause");
                return 0;
            }
            if(pont2>=25&&pont3>=25||pont2>=25&&pont4>=25||pont2>=25&&pont5>=25){
                system("cls");
                cout<<"\tO JOGO EMPATOU :( ";
                system("pause");
                return 0;
            }
            if(pont3>=25&&pont4>=25||pont3>=25&&pont5>=25){
                system("cls");
                cout<<"\tO JOGO EMPATOU :( ";
                system("pause");
                return 0;
            }
            if(pont4>=25&&pont5>=25){
                system("cls");
                cout<<"\tO JOGO EMPATOU :( ";
                system("pause");
                return 0;
            }
            ///Laços de jogo ganho
            if(pont1>=25){ // Caso o jogador da cartela 1 ganhe
                system("cls");
                cout << endl << "Parabéns! O jogador "<< cart_mat[0] << ", da cartela 1, ganhou o jogo!" << endl; 
                system("pause>nul");
                return 0;
            }
            if(pont2>= 25){ // Caso o jogador da cartela 2 ganhe
                system("cls");
                cout << endl << "Parabéns! O jogador" << cart_mat[1] << ", da cartela 2, ganhou o jogo!" << endl;
                system("pause>nul");
                return 0;
            }
            if(pont3>=25){ // Caso o jogador da cartela 3 ganhe
                system("cls");
                cout << endl << "Parabéns! O jogador "<< cart_mat[2] << ", da cartela 3, ganhou o jogo!" << endl;
                system("pause>nul");
                return 0;
            }

            if(pont4>= 25){ // Caso o jogador da cartela 4 ganhe
                system("cls");
                cout << endl << "Parabéns! O jogador "<< cart_mat[3] << ", da cartela 4, ganhou o jogo!" << endl << endl;
                system("pause>nul");
                return 0;
            }

            if(pont5>=25){ // Caso o jogador da cartela 5 ganhe
                system("cls");
                cout << endl << "Parabéns! O jogador " << cart_mat[4] << ", da cartela 5, ganhou o jogo!" << endl << endl;
                system("pause>nul");
                return 0;
            }
        }
    }
}

int main()
{
    int mat[TAM][TAM],mat1[TAM][TAM],mat2[TAM][TAM],mat3[TAM][TAM],mat4[TAM][TAM],mat5[TAM][TAM],pedras[PED],temp,pont1,pont2,pont3,pont4,pont5,a;
    string cart_mat[TAM];

    nomear_cartelas(cart_mat);// noemacao dos jogadores nas cartelas.
    naleatorio(mat,mat1,mat2,mat3,mat4,mat5); //gerando as cartelas.
    ordenaMatriz(mat1,mat2,mat3,mat4,mat5); //ordenando de forma crescente.
    print(mat1,mat2,mat3,mat4,mat5,cart_mat);//exibindo
    print_num(pedras,mat1,mat2,mat3,mat4,mat5,cart_mat,temp,pont1, pont2, pont3, pont4, pont5);// jogando.

}

