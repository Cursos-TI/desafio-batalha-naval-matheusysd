#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // Declaração do tabuleiro 10x10
    int tabuleiro[10][10] = {0}; // Inicializa todas as posições com 0 (água)
    
    // Posicionamento do navio horizontal (tamanho 3)
    int navioHorizontalLinha = 2;    // Linha inicial do navio horizontal
    int navioHorizontalColuna = 3;   // Coluna inicial do navio horizontal
    
    // Posicionamento do navio vertical (tamanho 3)
    int navioVerticalLinha = 4;      // Linha inicial do navio vertical
    int navioVerticalColuna = 7;     // Coluna inicial do navio vertical
    
    // Posiciona navio horizontal
    for(int i = 0; i < 3; i++) {
        tabuleiro[navioHorizontalLinha][navioHorizontalColuna + i] = 3;
    }
    
    // Posiciona navio vertical
    for(int i = 0; i < 3; i++) {
        tabuleiro[navioVerticalLinha + i][navioVerticalColuna] = 3;
    }
    
    // Exibe o tabuleiro
    printf("Tabuleiro de Batalha Naval:\n");
    printf("  0 1 2 3 4 5 6 7 8 9\n"); // Índices das colunas
    for(int i = 0; i < 10; i++) {
        printf("%d ", i); // Índice da linha
        for(int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
