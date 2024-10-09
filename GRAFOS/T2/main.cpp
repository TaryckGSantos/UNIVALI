#include <iostream>
#include <vector>
#include <fstream>  // Para criar o arquivo .dot
#include <cstdlib>  // Para chamar o Graphviz via sistema
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

// Função que mostra a matriz de adjacência
void exibirMatriz(const vector<vector<int>>& matrizAdj) {
    int n = matrizAdj.size(); // Número de vértices

    cout << "\nMatriz de adjacência:\n\n";
    cout << "   "; // Espaço para alinhar com a primeira coluna de números
    for (int i = 0; i < n; ++i) {
        cout << " " << i; // Cabeçalho das colunas
    }
    cout << endl;

    cout << "   "; // Linha de separação após os números das colunas
    for (int i = 0; i < n; ++i) {
        cout << " -";
    }
    cout << endl;

    for (int i = 0; i < n; ++i) {
        if (i<10){
            cout << " ";
        } else if (i>=10){
            cout << "";
        }
        cout << i << "|"; // Número da linha e barra vertical para separar
        for (int j = 0; j < n; ++j) {
            cout << " " << matrizAdj[i][j];
        }
        cout << endl;
    }
    system("pause>nul");
    system("cls");
}

// Função que gera o arquivo .dot para o Graphviz
void gerarArquivoDot(const vector<vector<int>>& matrizAdj, const vector<int>& cores) {
    ofstream arquivo("grafo.dot"); // Cria e abre um arquivo .dot

    // Início do arquivo .dot
    arquivo << "graph G {\n"; // Define que estamos criando um grafo não-direcionado no formato Graphviz

    int n = matrizAdj.size();  // Número de vértices no grafo

    // Definição de cores para os vértices
    vector<string> nomeCores = {"red", "blue", "green", "yellow", "purple", "orange", "pink", "brown", "gray", "cyan"};

    // Adicionar vértices com cores
    for (int i = 0; i < n; ++i) {
        // Cada vértice é adicionado ao arquivo com sua cor respectiva, conforme definida no vetor "cores"
        arquivo << "    " << i << " [style=filled, fillcolor=" << nomeCores[cores[i] % nomeCores.size()] << "];\n";
    }

    // Adicionar arestas entre os vértices
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (matrizAdj[i][j] == 1) {
                // Para cada aresta presente na matriz de adjacência, uma conexão é adicionada entre os vértices
                arquivo << "    " << i << " -- " << j << ";\n";
            }
        }
    }

    // Fim do arquivo .dot
    arquivo << "}\n";
    arquivo.close();

    // Comando para gerar o arquivo PNG usando o Graphviz
    system("dot -Tpng grafo.dot -o grafo.png");
    cout << "\nGrafo gerado como 'grafo.png'.\n";
}

// Algoritmo para coloração de vértices
int colorirGrafo(const vector<vector<int>>& matrizAdj) {
    int n = matrizAdj.size();
    vector<int> cor(n, -1); // -1 significa que o vértice ainda não foi colorido
    vector<bool> coresDisponiveis(n + 1, true); // Aumenta o tamanho para lidar com a cor 1 em diante

    cor[0] = 1; // Primeiro vértice recebe a cor 1

    // Colore os vértices restantes
    for (int u = 1; u < n; u++) {
        fill(coresDisponiveis.begin(), coresDisponiveis.end(), true); // Marca todas as cores como disponíveis

        // Verifica as cores dos vértices adjacentes
        for (int v = 0; v < n; v++) {
            if (matrizAdj[u][v] && cor[v] != -1) {
                coresDisponiveis[cor[v]] = false; // Marca a cor do vizinho como indisponível
            }
        }

        // Encontra a primeira cor disponível
        int corEscolhida;
        for (corEscolhida = 1; corEscolhida <= n; corEscolhida++) {
            if (coresDisponiveis[corEscolhida]) {
                break;
            }
        }
        cor[u] = corEscolhida; // Atribui a primeira cor disponível ao vértice
    }

    // Exibe a cor de cada vértice
    cout << "\nCores atribuídas a cada vértice:\n";
    for (int u = 0; u < n; u++) {
        cout << "Vértice " << u << " -> Cor " << cor[u] << endl << endl;
    }

    // Calcula o número cromático, que é a maior cor usada
    int numeroCromatico = *max_element(cor.begin(), cor.end());
    cout << "Número cromático: " << numeroCromatico << endl;

    // Gera o arquivo .dot e cria a imagem do grafo
    gerarArquivoDot(matrizAdj, cor);

    return numeroCromatico;
}

// Função para contar arestas
int contarArestas(const vector<vector<int>>& matrizAdj) {
    int n = matrizAdj.size();
    int contagem = 0;

    // Conta as arestas na matriz de adjacência (considerando apenas metade superior)
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            if (matrizAdj[i][j]) {
                contagem++;
            }
        }
    }
    return contagem;
}

// Função para verificar se o grafo é planar usando a fórmula de Euler
void verificarPlanaridade(const vector<vector<int>>& matrizAdj) {
    int V = matrizAdj.size(); // Número de vértices
    int E = contarArestas(matrizAdj); // Número de arestas


    cout << "\nNúmero de vértices: " << V << endl;
    cout << "Número de arestas: " << E << endl;

    // Fórmula de Euler: V - E + R = 2, onde R é o número de regiões
    int R = E - V + 2;

    if (E <= 3*V - 6) { // Condição de planaridade para grafos simples
        cout << "O grafo é planar." << endl;
        cout << "Número de regiões: " << R << endl;
    } else {
        cout << "O grafo não é planar." << endl;
    }
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    int n;
    cout << "Digite o número inicial de vértices do grafo: ";
    cin >> n; // Numero de vertices e tamanho da linha/coluna da matriz
    system("cls");

    vector<vector<int>> matrizAdj(n, vector<int>(n, 0)); // Inicializa a matriz de adjacência com zeros, de tamanho n x n

    while (true) {
        cout << "Menu:\n";
        cout << "1. Adicionar mais um vértice\n";
        cout << "2. Remover vértice\n";
        cout << "3. Adicionar aresta/arco\n";
        cout << "4. Remover aresta/arco\n";
        cout << "5. Exibir matriz de adjacência\n";
        cout << "6. Verificar planaridade\n";
        cout << "7. Colorir e gerar grafo\n";
        cout << "8. Sair\n";
        cout << "Escolha uma opção: ";

        int opcao;
        cin >> opcao; // Lê a opção escolhida pelo usuário

        if (opcao == 1) { // Adicionar um novo vértice ao grafo
            n++;
            for (auto& linha : matrizAdj) {
                linha.push_back(0);  // Adiciona uma nova coluna com zeros
            }
            matrizAdj.push_back(vector<int>(n, 0));  // Adiciona uma nova linha com zeros

            cout << "Vértice adicionado.\n";
            system("pause>nul");
            system("cls");

        } else if (opcao == 2) { // Remover um vértice do grafo
            cout << "Digite o vértice a ser removido (0 a " << n-1 << "): ";
            int verticeRemover;
            cin >> verticeRemover;

            if (verticeRemover >= 0 && verticeRemover < n) {
                matrizAdj.erase(matrizAdj.begin() + verticeRemover);  // Remove a linha

                for (auto& linha : matrizAdj) {
                    linha.erase(linha.begin() + verticeRemover);  // Remove a coluna correspondente
                }

                n--;
                cout << "Vértice removido.\n";
                system("pause>nul");
                system("cls");
            } else {
                cout << "Vértice inválido.\n";
                system("pause>nul");
                system("cls");
            }

        } else if (opcao == 3) { // Adicionar uma aresta ou arco ao grafo
            int v1, v2;
            cout << "Digite o vértice de origem: ";
            cin >> v1;
            cout << "Digite o vértice de destino: ";
            cin >> v2;

            if (v1 >= 0 && v1 < n && v2 >= 0 && v2 < n) {
                matrizAdj[v1][v2] = 1; // Adiciona a aresta ou arco na matriz
                matrizAdj[v2][v1] = 1; // Se o grafo não for direcionado, adiciona a aresta também na outra direção

                cout << "Aresta/Arco adicionado.\n";
                system("pause>nul");
                system("cls");
            } else {
                cout << "Vértices inválidos.\n";
                system("pause>nul");
                system("cls");
            }

        } else if (opcao == 4) { // Remover uma aresta ou arco do grafo
            int v1, v2;
            cout << "Digite o vértice de origem: ";
            cin >> v1;
            cout << "Digite o vértice de destino: ";
            cin >> v2;

            if (v1 >= 0 && v1 < n && v2 >= 0 && v2 < n) {
                matrizAdj[v1][v2] = 0; // Remove a aresta ou arco na matriz
                matrizAdj[v2][v1] = 0; // Se o grafo não for direcionado, remove a aresta também na outra direção

                cout << "Aresta/Arco removido.\n";
                system("pause>nul");
                system("cls");
            } else {
                cout << "Vértices inválidos.\n";
                system("pause>nul");
                system("cls");
            }

        } else if (opcao == 5) { // Exibir a matriz
            exibirMatriz(matrizAdj);

        } else if (opcao == 6) { // Verificar se o grafo é planar
            verificarPlanaridade(matrizAdj);
            system("pause>nul");
            system("cls");

        } else if (opcao == 7) { // Colorir os vértices e gerar o grafo visualmente
            colorirGrafo(matrizAdj);
            system("pause>nul");
            system("cls");

        } else if (opcao == 8) { // Sair do programa
            return 0;

        }else {
            cout << "Opção inválida. Tente novamente.\n";
            system("pause>nul");
            system("cls");
        }
    }

    return 0;
}
