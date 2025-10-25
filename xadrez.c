#include <stdio.h>

// ============================
// Funções Recursivas
// ============================

// Torre: movimento recursivo para a direita
void moverTorre(int casas) {
    if (casas <= 0) return;
    printf("Direita\n");
    moverTorre(casas - 1);
}

// Rainha: movimento recursivo para a esquerda
void moverRainha(int casas) {
    if (casas <= 0) return;
    printf("Esquerda\n");
    moverRainha(casas - 1);
}

// Bispo: movimento recursivo para cima e à direita
void moverBispoRecursivo(int casas) {
    if (casas <= 0) return;
    printf("Cima, Direita\n");
    moverBispoRecursivo(casas - 1);
}

// Bispo com loops aninhados: simula diagonal com controle vertical e horizontal
void moverBispoComLoops(int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("Diagonal: Cima, Direita\n");
        }
    }
}

// Cavalo: movimento em "L" (2 cima, 1 direita) com controle de fluxo
void moverCavalo(int movimentos) {
    for (int i = 1; i < movimentos; i++) {
        int cima = 0;
        while (cima < 2) {
            printf("Cima\n");
            cima++;
        }

        int direita = 0;
        while (direita < 1) {
            printf("Direita\n");
            direita++;
        }
    }
}



int main() {
    int movimentoTorre = 5;
    printf("Movimento da Torre:\n");
    moverTorre(movimentoTorre);

    int movimentoBispo = 5;
    printf("\nMovimento do Bispo (Recursivo):\n");
    moverBispoRecursivo(movimentoBispo);

    printf("\nMovimento do Bispo (Loops Aninhados):\n");
    moverBispoComLoops(2, 3);

    int movimentoRainha = 8;
    printf("\nMovimento da Rainha:\n");
    moverRainha(movimentoRainha);

    int movimentosCavalo = 3;
    printf("\nMovimento do Cavalo:\n");
    moverCavalo(movimentosCavalo);

    return 0;
}




