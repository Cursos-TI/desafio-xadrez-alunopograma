#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define TAMANHO_HABILIDADE 5
#define VALOR_AGUA 0
#define VALOR_NAVIO 3
#define VALOR_HABILIDADE 5

// Verifica se a posição já está ocupada por navio
int estaOcupado(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    return tabuleiro[linha][coluna] == VALOR_NAVIO;
}

// Inicializa o tabuleiro com água
void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++)
        for (int j = 0; j < TAMANHO_TABULEIRO; j++)
            tabuleiro[i][j] = VALOR_AGUA;
}

// Posiciona os navios fixos
void posicionarNavios(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    int lH = 4, cH = 2;
    int lV = 5, cV = 6;
    int lD1 = 0, cD1 = 0;
    int lD2 = 0, cD2 = 8;

    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[lH][cH + i] = VALOR_NAVIO;
        tabuleiro[lV + i][cV] = VALOR_NAVIO;
        tabuleiro[lD1 + i][cD1 + i] = VALOR_NAVIO;
        tabuleiro[lD2 + i][cD2 - i] = VALOR_NAVIO;
    }
}

// Constrói matriz de habilidade em forma de cone
void construirCone(int matriz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (j >= TAMANHO_HABILIDADE / 2 - i && j <= TAMANHO_HABILIDADE / 2 + i)
                matriz[i][j] = 1;
            else
                matriz[i][j] = 0;
        }
    }
}

// Constrói matriz de habilidade em forma de cruz
void construirCruz(int matriz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (i == TAMANHO_HABILIDADE / 2 || j == TAMANHO_HABILIDADE / 2)
                matriz[i][j] = 1;
            else
                matriz[i][j] = 0;
        }
    }
}

// Constrói matriz de habilidade em forma de octaedro (losango)
void construirOctaedro(int matriz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (abs(i - TAMANHO_HABILIDADE / 2) + abs(j - TAMANHO_HABILIDADE / 2) <= TAMANHO_HABILIDADE / 2)
                matriz[i][j] = 1;
            else
                matriz[i][j] = 0;
        }
    }
}

// Aplica matriz de habilidade ao tabuleiro
void aplicarHabilidade(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int matriz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE], int origemLinha, int origemColuna) {
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            int linhaTab = origemLinha - TAMANHO_HABILIDADE / 2 + i;
            int colunaTab = origemColuna - TAMANHO_HABILIDADE / 2 + j;

            if (linhaTab >= 0 && linhaTab < TAMANHO_TABULEIRO &&
                colunaTab >= 0 && colunaTab < TAMANHO_TABULEIRO) {
                if (matriz[i][j] == 1 && tabuleiro[linhaTab][colunaTab] != VALOR_NAVIO)
                    tabuleiro[linhaTab][colunaTab] = VALOR_HABILIDADE;
            }
        }
    }
}

// Exibe o tabuleiro com símbolos visuais
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("\nTabuleiro de Batalha Naval com Habilidades:\n\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            if (tabuleiro[i][j] == VALOR_AGUA)
                printf("~ ");
            else if (tabuleiro[i][j] == VALOR_NAVIO)
                printf("N ");
            else if (tabuleiro[i][j] == VALOR_HABILIDADE)
                printf("* ");
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    int cone[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int cruz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int octaedro[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];

    inicializarTabuleiro(tabuleiro);
    posicionarNavios(tabuleiro);

    construirCone(cone);
    construirCruz(cruz);
    construirOctaedro(octaedro);

    // Pontos de origem das habilidades
    aplicarHabilidade(tabuleiro, cone, 2, 2);       // Cone centrado em (2,2)
    aplicarHabilidade(tabuleiro, cruz, 6, 3);       // Cruz centrado em (6,3)
    aplicarHabilidade(tabuleiro, octaedro, 4, 7);   // Octaedro centrado em (4,7)

    exibirTabuleiro(tabuleiro);
    return 0;
}
