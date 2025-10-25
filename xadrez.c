#include <stdio.h>

int main() {


    // Movimento da Torre: 5 casas para a direita usando FOR
    int movimentoTorre = 5;

    printf("Movimento da Torre:\n");
    for (int i = 0; i < movimentoTorre; i++) {
        printf("Direita\n");
    }

    // Movimento do Bispo: 5 casas na diagonal para cima e à direita usando WHILE
    int movimentoBispo = 5;
    int contadorBispo = 0;

    printf("\nMovimento do Bispo:\n");
    while (contadorBispo < movimentoBispo) {
        printf("Cima, Direita\n");
        contadorBispo++;
    }

    // Movimento da Rainha: 8 casas para a esquerda usando DO-WHILE
    int movimentoRainha = 8;
    int contadorRainha = 0;

    printf("\nMovimento da Rainha:\n");
    do {
        printf("Esquerda\n");
        contadorRainha++;
    } while (contadorRainha < movimentoRainha);


  




    // ============================
    // DESAFIO 2 - Nível Aventureiro
    // ============================

    // Movimento do Cavalo: 2 casas para baixo e 1 para a esquerda
    // Usando loop FOR externo e loop WHILE interno
    int movimentosCavalo = 1; // número de movimentos em "L"
    int casasBaixo = 2;
    int casasEsquerda = 1;

    printf("\nDesafio 2 - Nível Aventureiro\n");
    printf("Movimento do Cavalo:\n");

    for (int i = 0; i < movimentosCavalo; i++) {
        // Loop interno para mover 2 casas para baixo
        int contadorBaixo = 0;
        while (contadorBaixo < casasBaixo) {
            printf("Baixo\n");
            contadorBaixo++;
        }

        // Movimento perpendicular: 1 casa para a esquerda
        printf("Esquerda\n");
    }

    return 0;
}

