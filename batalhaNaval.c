#include <stdio.h>

#define TAMANHO 10

// Função para inicializar o tabuleiro com zeros
void inicializarTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

// Função para imprimir o tabuleiro
void imprimirTabuleiro(int tabuleiro[TAMANHO][TAMANHO], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para aplicar habilidade em cone
void aplicarHabilidadeCone(int tabuleiro[TAMANHO][TAMANHO], int x, int y) {
    if (x < TAMANHO && y < TAMANHO) tabuleiro[x][y] = 1;
    if (x + 1 < TAMANHO && y - 1 >= 0 && y + 1 < TAMANHO) {
        tabuleiro[x + 1][y - 1] = 1;
        tabuleiro[x + 1][y] = 1;
        tabuleiro[x + 1][y + 1] = 1;
    }
    if (x + 2 < TAMANHO && y - 2 >= 0 && y + 2 < TAMANHO) {
        tabuleiro[x + 2][y - 2] = 1;
        tabuleiro[x + 2][y - 1] = 1;
        tabuleiro[x + 2][y] = 1;
        tabuleiro[x + 2][y + 1] = 1;
        tabuleiro[x + 2][y + 2] = 1;
    }
}

// Função para aplicar habilidade em cruz
void aplicarHabilidadeCruz(int tabuleiro[TAMANHO][TAMANHO], int x, int y) {
    for (int i = -2; i <= 2; i++) {
        if (x + i >= 0 && x + i < TAMANHO) tabuleiro[x + i][y] = 1;
        if (y + i >= 0 && y + i < TAMANHO) tabuleiro[x][y + i] = 1;
    }
}

// Função para aplicar habilidade em octaedro
void aplicarHabilidadeOctaedro(int tabuleiro[TAMANHO][TAMANHO], int x, int y) {
    if (x < TAMANHO && y < TAMANHO) tabuleiro[x][y] = 1;
    if (x - 1 >= 0 && y < TAMANHO) tabuleiro[x - 1][y] = 1;
    if (x + 1 < TAMANHO && y < TAMANHO) tabuleiro[x + 1][y] = 1;
    if (x < TAMANHO && y - 1 >= 0) tabuleiro[x][y - 1] = 1;
    if (x < TAMANHO && y + 1 < TAMANHO) tabuleiro[x][y + 1] = 1;
}

int main() {
    // Nível Novato - Posicionamento dos Navios
    int tabuleiro5x5[5][5] = {0};  // Inicializa o tabuleiro 5x5 com zeros

    // Posicionando navio verticalmente
    for (int i = 0; i < 3; i++) {
        tabuleiro5x5[i][1] = 1;  // Navio vertical na segunda coluna
        printf("Navio vertical na posição (%d, %d)\n", i, 1);
    }

    // Posicionando navio horizontalmente
    for (int j = 0; j < 3; j++) {
        tabuleiro5x5[3][j] = 1;  // Navio horizontal na quarta linha
        printf("Navio horizontal na posição (%d, %d)\n", 3, j);
    }

    // Imprime o tabuleiro 5x5
    printf("Tabuleiro 5x5:\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", tabuleiro5x5[i][j]);
        }
        printf("\n");
    }

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    int tabuleiro10x10[TAMANHO][TAMANHO];
    inicializarTabuleiro(tabuleiro10x10);

    // Posicionando navios horizontalmente e verticalmente
    for (int i = 0; i < 4; i++) {
        tabuleiro10x10[0][i] = 3;  // Navio horizontal no topo
        tabuleiro10x10[i][0] = 3;  // Navio vertical na lateral
    }

    // Posicionando navios diagonalmente
    for (int i = 0; i < 4; i++) {
        tabuleiro10x10[i][i] = 3;  // Navio na diagonal principal
        tabuleiro10x10[i][3 - i] = 3;  // Navio na diagonal secundária
    }

    // Imprime o tabuleiro 10x10
    printf("Tabuleiro 10x10:\n");
    imprimirTabuleiro(tabuleiro10x10, TAMANHO);

    // Nível Mestre - Habilidades Especiais com Matrizes
    inicializarTabuleiro(tabuleiro10x10);

    // Aplicando habilidades especiais
    aplicarHabilidadeCone(tabuleiro10x10, 4, 4);
    aplicarHabilidadeCruz(tabuleiro10x10, 6, 6);
    aplicarHabilidadeOctaedro(tabuleiro10x10, 2, 2);

    // Imprime o tabuleiro com as áreas afetadas
    printf("Tabuleiro com habilidades especiais aplicadas:\n");
    imprimirTabuleiro(tabuleiro10x10, TAMANHO);

    return 0;
}
