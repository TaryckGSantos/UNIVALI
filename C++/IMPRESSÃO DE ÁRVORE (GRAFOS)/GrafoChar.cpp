double pow(double a, double b){

    double result;

    result = a;

    for(int cont = 1; cont < b; cont++){
        result = result * a;
    }

    return result;
}

int altura(TNo *raiz) { // Ta correto
    if (raiz == NULL){
        return 0;
    }

    int alturaEsquerda = altura(raiz->esquerda);
    int alturaDireita = altura(raiz->direita);

    if (alturaEsquerda > alturaDireita){
        return alturaEsquerda + 1;
    } else {
        return alturaDireita + 1;
    }
}

int qtd_coluna(int h) {
    if (h == 1)
        return 1;
    return qtd_coluna(h - 1) + qtd_coluna(h - 1) + 1;
}

void mostraArv(char **M, TNo *raiz, int coluna, int linha, int altura) {
    if (raiz == NULL){
        return;
    }
    M[linha][coluna] = raiz->dado;
    mostraArv(M, raiz->esquerda, coluna - pow(2, altura - 2), linha + 1, altura - 1);
    mostraArv(M, raiz->direita, coluna + pow(2, altura - 2), linha + 1, altura - 1);
}

void mostrar(TArvore &arv) {
    int h = altura(arv.raiz)+1;
    int coluna = qtd_coluna(h);
    char **M = new char*[h];
    for (int i = 0; i < h; i++) {
        M[i] = new char[coluna];
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < coluna; j++) {
            M[i][j] = 0;
        }
    }

    mostraArv(M, arv.raiz, coluna / 2, 0, h);

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < coluna; j++) {
            if (M[i][j] == 0){
                cout << " " << " ";
            }
            else{
                cout << M[i][j] << " ";
            }
        }
        cout << endl << endl;
    }
}
