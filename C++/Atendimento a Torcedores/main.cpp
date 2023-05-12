///Alunos: Taryck Santos e Thiago Pacheco
#include <iostream>
using namespace std;
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include "Atendimento.h"
#include "Torcedor.h"

int main()
{
    setlocale(LC_ALL,"Portuguese"); // Caracteres em pt-br
    srand(time(NULL)); // Numeros aleatórios

    // Declaração de variáveis de para uso
    Torcedor torcedores;
    int select=0, carga_inicial, tempoSim, numGST, numGN, cont=0, qtdpTEMP, ins, auxEntrarN=0, auxEntrarS=0;

    // Menu inicial
    cout << "\n\t\t\t\tAtendimento - Estádio";
    cout<<"\n\n\n\t\tQuantidade de Guichês Sócio Torcedor: ";
    cin>>numGST;
    cout<<"\n\n\t\tQuantidade de Guichês Normal: ";
    cin>>numGN;
    cout<<"\n\n\t\tQuantidade de Pessoas que estão aguardando antes do ínicio da simulação(carga inicial): ";
    cin>>carga_inicial;
    cout<<"\n\n\t\tQuantidade de Pessoas que procuram os Guichês a cada unidade de Tempo: ";
    cin>>qtdpTEMP;
    cout<<"\n\n\t\tQuantidade de Tempo em que o Modelo será 'Simulado': ";
    cin>>tempoSim;

    int vet_qtd_ST[numGST], vet_qtd_N[numGN]; // Declaração dos vetores que são usados na contagem de torcedores

    if (numGN == 0 && numGST == 0){ // Caso o usuário coloque 0 guichês para uso, o programa encerra
        system("cls");
        cout << "\n\n\t\t\tNenhum guichê foi inserido! Programa encerrado!\n\n\n";
        return 0;
    }

    ins = qtdpTEMP;
    TFila<Torcedor> fila; // Criação do modelo de fila

    ///CRIAÇÃO DAS FILAS SÓCIO TORCEDOR
    TFila<Torcedor> *filaST; // Criação do vetor ponteiro filaST
    filaST = new TFila<Torcedor>[numGST];

    for(int i=0;i<numGST;i++){ // Cada posição do vetor recebe o modelo de fila
        filaST[i]=fila;
    }

    for(int i=0;i<numGST;i++){ // Inicialização de cada posição do vetor
        inicializa_fila(filaST[i]);
    }

    ///CRIAÇÃO DAS FILAS NORMAIS
    TFila<Torcedor> *filaN; // Criação do vetor ponteiro filaN
    filaN = new TFila<Torcedor>[numGN];

    for(int i=0;i<numGN;i++){ // Cada posição do vetor recebe omodelo de fila
        filaN[i]=fila;
    }

    for(int i=0;i<numGN;i++){ // Inicialização de cada posição do vetor
        inicializa_fila(filaN[i]);
    }

    ///MONTAGEM DAS FILAS
    int auxST, auxN;

    if(numGST == 0){ // Caso o numero de guichê de sórcio torcedor seja 0, todos irão para o guichê normal
        auxN=carga_inicial;
        auxST = 0;
    } else if (numGN == 0){ // Caso o numero de guichê normal seja 0, todos irão para o de sócios
        auxST = carga_inicial;
        auxN = 0;
    } else  { // Caso ambos != 0
        auxST=carga_inicial/20; // O numero de sócio torcedores iniciais é igual a 5% da carga inicial
        auxN=carga_inicial-auxST; // O numero de torcedores normais é o numero total menos o numero de sócios
    }

    /// LAÇOS PARA CRIAÇÃO DAS FILAS COM OS DADOS INSERIDOS
    while(auxST!=0){ // Enquanto auxST seja diferente de 0
        if(cont==numGST){ // Se cont for igual ao numero de guiches de sócios, cont = 0
            cont=0;
        }
        montar_filaST(filaST[cont],torcedores,auxST); // monta a fila na posição cont do vetor
        entrar_na_fila(filaST[cont],torcedores); // insere os valores na fila
        vet_qtd_ST[cont] = filaST[cont].tamanho; // A posição const no vetor de quantidade recebe o tamanho da fila cont
        cont++;
    }
    cont=0;

    while(auxN!=0){ // Enquanto auxN seja diferente de 0
        if(cont==numGN){ // Se cont for igual ao numero de guiches torcedores normais, cont = 0
            cont=0;
        }
        montar_filaN(filaN[cont],torcedores,auxN);  // monta a fila na posição cont do vetor
        entrar_na_fila(filaN[cont],torcedores); // insere os valores na fila
        vet_qtd_N[cont] = filaN[cont].tamanho; // A posição const no vetor de quantidade recebe o tamanho da fila cont
        cont++;
    }
    cont=0;

    // Declaração dos vetores da quantidade de tempo
    int vet_qtdTMP_N[numGN] = {0};
    int vet_qtdTMP_ST[numGST] = {0};

    for(int i=0; i<numGN; i++){ // laço para andar por todas as posições de todas as filas
        TElementoF<Torcedor> *nav1 = filaN[i].inicio; // nav = inicio da fila i
        while(nav1!=NULL){ // enquanto nav != null
            vet_qtdTMP_N[i]=vet_qtdTMP_N[i]+nav1->dado.qtd_tempo; // a posição i do vetor recebe a soma das quantidades de tempo da fila
            nav1 = nav1->proximo;
        }
    }

    for(int i=0; i<numGST; i++){
        TElementoF<Torcedor> *nav2 = filaST[i].inicio; // nav2 = inicio da fila i
        while(nav2!=NULL){
            vet_qtdTMP_ST[i]=vet_qtdTMP_ST[i]+nav2->dado.qtd_tempo;
            nav2 = nav2->proximo;
        }
    }

    system("cls");

    ///MENU DO SISTEMA
    if(tempoSim == 0){ // Caso o tempo de simulação seja 0, o programa encerra sem acontecer nenhuma ação
        system("cls");
        cout << "\n\n\t\tPrograma encerrado por não iniciar com tempo! \t Situação da fila: \n\n\n";
        for(int i=0;i<numGST;i++){
            cout << "-------------------------------------------";
            cout <<"\n\t· Guichê Sócio-Torcedor "<<i+1<<": · \n";
            cout << "-------------------------------------------\n\n";
            cout << "Início da fila: \n\n";
            imprime_fila(filaST[i]);
        }
        for(int i=0;i<numGN;i++){
            cout << "-------------------------------------------";
            cout<<"\n\t· Guichê Normal "<<i+1<<": · \n";
            cout << "-------------------------------------------\n\n";
            cout << "Início da fila: \n\n";
            imprime_fila(filaN[i]);
        }
        system("pause>nul");
        return 0;
    } else { // caso seja maior que 0
        do{
            system("cls");

            // Laços para imprimir as listas constantemente
            for(int i=0;i<numGST;i++){
                cout << "-------------------------------------------";
                cout <<"\n\t· Guichê Sócio-Torcedor "<<i+1<<": · \n";
                cout << "-------------------------------------------\n\n";
                cout << "Início da fila: \n\n";
                imprime_fila(filaST[i]);
            }
            for(int i=0;i<numGN;i++){
                cout << "-------------------------------------------";
                cout<<"\n\t· Guichê Normal "<<i+1<<": · \n";
                cout << "-------------------------------------------\n\n";
                cout << "Início da fila: \n\n";
                imprime_fila(filaN[i]);
            }
            cout << "\n\n\t\t\t\t\t- MENU DE ATENDIMENTO -\t\t\t\t\tTempo Restante: "<<tempoSim << endl << endl << endl;
            cout << "\t\t\t1 - Inserir Pessoa no Final da Fila" << endl;
            cout << "\t\t\t2 - Primeira Posição" <<endl;
            cout << "\t\t\t3 - Rodar uma Unidade de Tempo (sem entrada de novos torcedores)" << endl;
            cout << "\t\t\t4 - Zerar" << endl;
            cout << "\t\t\t5 - Simular 1 Tempo (com entrada)" << endl;
            cout << "\t\t\t6 - Encerrar Programa" << endl;
            select = getch(); // Verifica a tecla pressionada no teclado

            // Inserção no final da fila
            if (select == '1') { // Caso a tecla pressionada seja 1
                qtdpTEMP=ins;
                while(qtdpTEMP!=0){ // Enquanto a quantidade de tempo restante não for igual a 0
                    if(cont%20==0){ // Caso a contagem seja multiplo de 20 (5%)
                        auxEntrarS = seleciona_menor(filaST, numGST); // Seleciona a menor fila
                        montar_filaST(filaST[auxEntrarS],torcedores,qtdpTEMP); // Monta a fila
                        entrar_na_fila(filaST[auxEntrarS],torcedores); // Insere na fila
                        vet_qtdTMP_ST[auxEntrarS]=vet_qtdTMP_ST[auxEntrarS]+torcedores.qtd_tempo; // A quantidade de tempo da posição aumenta de acordo com a quantidade de tempo do novo torcedor
                        vet_qtd_ST[auxEntrarS]++; // quantidade de torcedores que passaram na fila aumenta
                    }
                    // Caso a contagem seja os outros 95%
                    else{
                        auxEntrarN = seleciona_menor(&filaN[numGN], numGN); // Seleciona a menor fila
                        montar_filaN(filaN[auxEntrarN],torcedores,qtdpTEMP); // Monta a fila
                        entrar_na_fila(filaN[auxEntrarN],torcedores); // Insere na fila
                        vet_qtdTMP_N[auxEntrarN]=vet_qtdTMP_N[auxEntrarN]+torcedores.qtd_tempo; // A quantidade de tempo da posição aumenta de acordo com a quantidade de tempo do novo torcedor
                        vet_qtd_N[auxEntrarN]++; // quantidade de torcedores que passaram na fila aumenta
                    }
                    cont++; // Aumenta a contagem de quantos foram inseridos no total
                }
                system("pause>nul");
                system("cls");

            // Retorno de todas as primeiras posições
            } else if (select == '2') {
                system("cls");
                for(int i=0;i<numGST;i++){ // Laço para passar por todos os guichês de Socio
                    Torcedor * aux = primeiro(filaST[i]);
                    cout << "-------------------------------------------";
                    cout <<"\n\t· Guichê Sócio-Torcedor "<<i+1<<": · \n";
                    cout << "-------------------------------------------\n\n";
                    cout << "Início da fila: \n\n";
                    if (aux == NULL) { // Caso não haja nenhum elemento na fila
                        cout<<"\tNão há nenhuma pessoa na fila \n"<<endl;
                    } else {
                       imprimir_pFila(*aux); // Imprime o primeiro elemento
                    }
                    cout << "\n\n";
                }
                for(int i=0;i<numGN;i++){ // Laço para passar por todos os guichês de Socio
                    Torcedor * aux = primeiro(filaN[i]);
                    cout << "-------------------------------------------";
                    cout<<"\n\t· Guichê Normal "<<i+1<<": · \n";
                    cout << "-------------------------------------------\n\n";
                    cout << "Início da fila: \n\n";
                    cout << "\tTorcedor 1";
                    if (aux == NULL) {
                        cout<<"\tNão há nenhuma pessoa na fila \n"<<endl;
                    } else {
                        imprimir_pFila(*aux);
                    }
                    cout << "\n\n";
                }
                system("pause>nul");
                system("cls");

            // Roda uma unidade de tempo (sem entrada de novos torcedores)
            } else if (select == '3') {
                for(int i=0;i<numGST;i++){ // roda por todas as filas de sócio
                    int confirma = rodar_tempo(filaST[i]); // confirma recebe o retorno de rodar_tempo
                    if(confirma == 3){ // caso confirma == 3
                        system("cls");
                        cout << "\n\n\t\tO primeiro torcedor do guichê " << i+1 << " de Sócio Torcedor acabou seu atendimento!";
                        system("pause>nul");
                        system("cls");
                    }
                }
                for(int i=0;i<numGN;i++){ // roda por todas as filas normais
                    int confirma = rodar_tempo(filaN[i]);
                    if(confirma == 3){
                        system("cls");
                        cout << "\n\n\t\tO primeiro torcedor do guichê normal " << i+1 << " acabou seu atendimento!";
                        system("pause>nul");
                        system("cls");
                    }
                }

            // zera todas as filas
            } else if (select == '4') {
                for(int i=0;i<numGN;i++){ // roda por todas as filas
                    zerar(filaN[i]); // chama a função zerar em todas elas
                }
                for(int i=0;i<numGST;i++){
                    zerar(filaST[i]);
                }
                system("cls");
                cout << "\n\n\t\Toda as filas ficaram vazias!";
                system("pause>nul");
                system("cls");

            // Simulação de 1 tempo (simulação completa)
            } else if (select == '5') {
                // Eliminação de torcedores (igual ao item 3)
                for(int i=0;i<numGST;i++){
                    int confirma = rodar_tempo(filaST[i]);
                    if(confirma == 3){
                        system("cls");
                        cout << "\n\n\t\tO primeiro torcedor do guichê " << i+1 << " de Sócio Torcedor acabou seu atendimento!";
                        system("pause>nul");
                        system("cls");
                    }
                }
                for(int i=0;i<numGN;i++){
                    int confirma = rodar_tempo(filaN[i]);;
                    if(confirma == 3){
                        system("cls");
                        cout << "\n\n\t\tO primeiro torcedor do guichê normal " << i+1 << " acabou seu atendimento!";
                        system("pause>nul");
                        system("cls");
                    }
                }

                qtdpTEMP=ins;
                while(qtdpTEMP!=0){ // Enquanto a quantidade de tempo for diferente de 0
                    if(cont%20==0){ // caso cont seja multiplo de 20 (5%)
                        auxEntrarS = seleciona_menor(filaST, numGST); // seleciona a menor fila
                        montar_filaST(filaST[auxEntrarS],torcedores,qtdpTEMP); // mosta a fila
                        entrar_na_fila(filaST[auxEntrarS],torcedores); // insere o elemento na fila
                        vet_qtdTMP_ST[auxEntrarS]=vet_qtdTMP_ST[auxEntrarS]+torcedores.qtd_tempo; // A quantidade de tempo da posição aumenta de acordo com a quantidade de tempo do novo torcedor
                        vet_qtd_ST[auxEntrarS]++; // quantidade de torcedores que passaram pela fila aumenta
                    }
                    else{ // caso cont não seja multiplo de 20 (95%)
                        auxEntrarN = seleciona_menor(filaN, numGN);
                        montar_filaN(filaN[auxEntrarN],torcedores,qtdpTEMP);
                        entrar_na_fila(filaN[auxEntrarN],torcedores);
                        vet_qtdTMP_N[auxEntrarN]=vet_qtdTMP_N[auxEntrarN]+torcedores.qtd_tempo;
                        vet_qtd_N[auxEntrarN]++;
                    }
                    cont++; // aumenta o cont a cada inserção
                }

            // Programa encerra
            } else if (select == '6') {
                system("cls");
                cout << "\n\n\t\tPrograma encerrado!";
                system("pause>nul");
                exit(0);
            } else { // Caso a tecla pressionada não seja um numero entre 1 e 6
               system("cls");
               cout << "\n\n\t\tPressione apenas os números de 1 a 6!";
               system("pause>nul");
               system("cls");
               tempoSim++;
            }
            tempoSim--; // A cada laço, diminuito 1 do tempo de simulação
            if (tempoSim == 0){ // Caso o tempo = 0, roda o final do sistema

                // Declaração de variáveis
                float total_ST=0, total_N=0, media_GST=0, media_GN=0;
                float tempo_medio_ST[numGST]={0}, tempo_medio_N[numGN]={0};
                float aux1, aux2;

                for(int i=0; i<numGST; i++){ // laço para passar em todas as posições do vetor de sócios
                    if(vet_qtdTMP_ST[i]==NULL ){ // se não houver nada na posição, a quantidade de tempo - 0
                        vet_qtdTMP_ST[i] = 0;
                    }
                    if(vet_qtd_ST[i]==NULL){ // se não houver nada na posição, a quantidade de tempo - 0
                        vet_qtd_ST[i] = 0;
                    }
                    total_ST = total_ST + vet_qtd_ST[i]; // o total de torcedores presentes é a soma de todos que passaram pelos guichÊs
                    aux1 = vet_qtdTMP_ST[i];
                    aux2 = vet_qtd_ST[i];
                    tempo_medio_ST[i] = aux1 / aux2; // o tempo medio é a divisão da quantidade de tempo somada pela quantidade de torcedores que passaram
                }

                for(int i=0; i<numGN; i++){ // laço para realizar as equações anteriores no laço de torcedores normais
                    if(vet_qtdTMP_N[i] == NULL){
                        vet_qtdTMP_N[i] = 0;
                    }
                    if(vet_qtd_N[i]==NULL){
                        vet_qtd_N[i] = 0;
                    }
                    total_N = total_N + vet_qtd_N[i];
                    aux1 = vet_qtdTMP_N[i];
                    aux2 = vet_qtd_N[i];
                    tempo_medio_N[i] = aux1 / aux2;
                }

                media_GST = total_ST / numGST; // media de Sócios-Torcedores por guichê de sócios
                if (media_GST == NULL){ // Caso o valor de media_GST seja nulo, apresentar-se como 0
                    media_GST = 0;
                }

                media_GN = total_N / numGN; // media de torcedores comuns por guichê normal
                if (media_GN == NULL){ // Caso o valor de media_GN seja nulo, apresentar-se como 0
                    media_GN = 0;
                }

                if (total_ST == NULL){ // Caso o valor de total_ST seja nulo, apresentar-se como 0
                    total_ST = 0;
                }
                if (total_N == NULL){ // Caso o valor de total_N seja nulo, apresentar-se como 0
                    total_N = 0;
                }

                system("cls");
                cout << "\n\t\t\t- DADOS FINAIS DA SIMULAÇÃO - ";
                cout << "\n\n\n\t\tTotal de Sócio-Torcedores que passaram pela fila: " << total_ST;
                cout << "\n\n\t\tTotal de torcedores comuns que passaram pela fila: " << total_N;
                cout << "\n\n\n\t\tMédia de Sócio-Torcedores por guichê de sócios: " << media_GST;
                cout << "\n\n\t\tMédia de torcedores comuns por guichê comuns: " << media_GN << endl << endl;
                system("pause>nul");
                system("cls");

                cout << "\n\t\t\t- NÚMERO DE TORCEDORES - \n\n";
                for(int i=0; i<numGST; i++){
                    cout << "\n\n\t\tQuantidade de torcedores que passaram no " << i+1 << "º guichê de sócio-torcedores: " << vet_qtd_ST[i];
                }
                cout << endl << endl;
                for(int i=0; i<numGN; i++){
                    cout << "\n\n\t\tQuantidade de torcedores que passaram no " << i+1 << "º guichê de torcedores comuns: " << vet_qtd_N[i];
                }
                system("pause>nul");
                system("cls");

                cout << "\n\t\t\t- MÉDIA DE TEMPO POR GUICHÊ - \n\n";
                for(int i=0; i<numGST; i++){
                    cout << "\n\t\tMédia de tempo que os sócios-torcedores do " << i+1 << "º guichê ficaram esperando: " << tempo_medio_ST[i];
                }
                cout << endl << endl;
                for(int i=0; i<numGN; i++){
                    cout << "\n\t\tMédia de tempo que os torcedores comuns do " << i+1 << "º guichê ficaram esperando: " << tempo_medio_N[i];
                }
                system("pause>nul");
            }
        }while(select!=6 && tempoSim>0);
    }
    return 0;
}
