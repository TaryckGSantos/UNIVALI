#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

// Função que mostra a matriz
void exibirMatriz(const vector<vector<int>>& matrizAdj) {
    int n = matrizAdj.size();

    cout << "\nMatriz de adjacência:\n";
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
        cout << i << " |"; // Número da linha e barra vertical para separar
        for (int j = 0; j < n; ++j) {
            cout << " " << matrizAdj[i][j];
        }
        cout << endl;
    }
    system("pause>nul");
    system("cls");
}

// Função que calcula BFS
void bfs(const vector<vector<int>>& matrizAdj, int inicio, int n, int elemento = -1) {
    vector<bool> visitado(n, false); // Vetor para marcar os vértices já visitados
    queue<int> fila; // Fila para gerenciar os vértices a serem visitados na ordem correta
    vector<int> sequenciaBusca; // Vetor para armazenar a sequência de vértices na ordem de busca

    // Função para realizar a BFS a partir de um vértice dado
    auto bfs_aux = [&](int v) {
        fila.push(v);
        visitado[v] = true;

        // Continua enquanto houver vértices na fila
        while (!fila.empty()) {
            int vertice = fila.front(); // Retira o vértice da frente da fila
            fila.pop();
            sequenciaBusca.push_back(vertice); // Adiciona o vértice à sequência de busca

            if (vertice == elemento) { // Verifica se o vértice atual é o elemento procurado
                cout << "\nElemento " << elemento << " encontrado!\n";
                return true;
            }

            for (int i = 0; i < n; i++) { // Explora os vértices adjacentes
                if (matrizAdj[vertice][i] == 1 && !visitado[i]) { // Se houver uma aresta e o vértice não foi visitado
                    fila.push(i); // Adiciona o vértice à fila e marca como visitado
                    visitado[i] = true;
                }
            }
        }
        return false;
    };

    if (bfs_aux(inicio)) { // Inicia a BFS a partir do vértice inicial
        // Se o elemento foi encontrado, não precisa continuar
        return;
    }

    // Verifica e executa BFS para componentes desconectados
    for (int i = 0; i < n; i++) {
        if (!visitado[i]) {
            if (bfs_aux(i)) { // Executa BFS para o componente desconectado
                // Se o elemento foi encontrado, não precisa continuar
                return;
            }
        }
    }

    // Imprime a sequência de busca se o elemento não foi encontrado ou se não foi especificado
    cout << "Sequência de busca (BFS): ";
    for (int v : sequenciaBusca) {
        cout << v << " ";
    }
    cout << endl;

    // Verifica se o elemento especificado foi encontrado
    if (elemento != -1 && find(sequenciaBusca.begin(), sequenciaBusca.end(), elemento) == sequenciaBusca.end()) {
        cout << "Elemento " << elemento << " não encontrado.\n";
    }
}

// Função que calcula DFS
void dfs(const vector<vector<int>>& matrizAdj, int inicio, int n, int elemento = -1) {
    vector<bool> visitado(n, false);
    stack<int> pilha; // Pilha para gerenciar os vértices a serem visitados na ordem correta
    vector<int> sequenciaBusca;

    auto dfs_aux = [&](int v) {
        pilha.push(v);

        while (!pilha.empty()) { // Continua enquanto houver vértices na pilha
            int vertice = pilha.top(); // Retira o vértice do topo da pilha
            pilha.pop();

            if (!visitado[vertice]) {
                visitado[vertice] = true;
                sequenciaBusca.push_back(vertice);

                if (vertice == elemento) {
                    cout << "\nElemento " << elemento << " encontrado!\n";
                    return true;
                }

                for (int i = n - 1; i >= 0; i--) { // Explora os vértices adjacentes na ordem inversa
                    if (matrizAdj[vertice][i] == 1 && !visitado[i]) {
                        pilha.push(i);
                    }
                }
            }
        }
        return false;
    };

    if (dfs_aux(inicio)) { // Inicia a DFS a partir do vértice inicial
        // Se o elemento foi encontrado, não precisa continuar
        return;
    }

    // Verifica e executa DFS para componentes desconectados
    for (int i = 0; i < n; i++) {
        if (!visitado[i]) {
            if (dfs_aux(i)) {
                // Se o elemento foi encontrado, não precisa continuar
                return;
            }
        }
    }

    // Imprime a sequência de busca se o elemento não foi encontrado ou se não foi especificado
    cout << "Sequência de busca (DFS): ";
    for (int v : sequenciaBusca) {
        cout << v << " ";
    }
    cout << endl;

    // Verifica se o elemento especificado foi encontrado
    if (elemento != -1 && find(sequenciaBusca.begin(), sequenciaBusca.end(), elemento) == sequenciaBusca.end()) {
        cout << "Elemento " << elemento << " não encontrado.\n";
    }
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    int n, dir;
    cout << "Digite o número inicial de vértices do grafo: ";
    cin >> n; // Numero de vertices e tamanho da linha/coluna da matriz

    cout << "O grafo é direcionado (1) ou não direcionado (0)? ";
    cin >> dir; // Informa se o grafo é direcionado ou nao
    cout << endl;

    vector<vector<int>> matrizAdj(n, vector<int>(n, 0)); // Inicializa a matriz de adjacência com zeros, de tamanho n x n

    while (true) {
        cout << "Menu:\n";
        cout << "1. Adicionar mais um vértice\n";
        cout << "2. Remover vértice\n";
        cout << "3. Adicionar aresta/arco\n";
        cout << "4. Remover aresta/arco\n";
        cout << "5. Exibir matriz de adjacência\n";
        cout << "6. Busca em Largura (BFS)\n";
        cout << "7. Busca em Profundidade (DFS)\n";
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
                matrizAdj[v1][v2] = 1; // Adiciona a aresta ou arco na matriz 155947
                if (dir == 0) {
                    matrizAdj[v2][v1] = 1; // Se o grafo não for direcionado, adiciona a aresta também na outra direção
                }
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
                if (dir == 0) {
                    matrizAdj[v2][v1] = 0; // Se o grafo não for direcionado, remove a aresta também na outra direção
                }
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

        } else if (opcao == 6) { // Realizar busca em largura (BFS)
            cout << "Digite o vértice de início da busca: ";
            int inicio;
            cin >> inicio;
            cout << "Digite o elemento a buscar (ou -1 para listar todos): ";
            int elemento;
            cin >> elemento;
            cout << "\nBFS a partir do vértice " << inicio << ":\n";
            bfs(matrizAdj, inicio, n, elemento);
            system("pause>nul");
            system("cls");

        } else if (opcao == 7) { // Realizar busca em profundidade (DFS)
            cout << "Digite o vértice de início da busca: ";
            int inicio;
            cin >> inicio;
            cout << "Digite o elemento a buscar (ou -1 para listar todos): ";
            int elemento;
            cin >> elemento;
            cout << "\nDFS a partir do vértice " << inicio << ":\n";
            dfs(matrizAdj, inicio, n, elemento);
            system("pause>nul");
            system("cls");

        } else if (opcao == 8) {
            // Sair
            break;

        } else {
            cout << "Opção inválida. Tente novamente.\n";
            system("pause>nul");
            system("cls");
        }
    }

    return 0;
}
