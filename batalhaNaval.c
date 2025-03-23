#include <stdio.h>
#include <stdlib.h>
// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

// Função para verificar se uma posição está dentro do tabuleiro
int dentroDoTabuleiro(int linha, int coluna) {
    return linha >= 0 && linha < 10 && coluna >= 0 && coluna < 10;
}

// Função para verificar se uma posição está ocupada
int posicaoOcupada(int tabuleiro[10][10], int linha, int coluna) {
    return tabuleiro[linha][coluna] == 3;
}

// Função para verificar se é seguro posicionar um navio
int posicaoSegura(int tabuleiro[10][10], int linha, int coluna) {
    return dentroDoTabuleiro(linha, coluna) && !posicaoOcupada(tabuleiro, linha, coluna);
}

#define TAM_HABILIDADE 5

// Função para criar matriz de habilidade em cone
void criarCone(int cone[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for(int i = 0; i < TAM_HABILIDADE; i++) {
        for(int j = 0; j < TAM_HABILIDADE; j++) {
            cone[i][j] = (j >= (TAM_HABILIDADE/2 - i) && j <= (TAM_HABILIDADE/2 + i)) ? 1 : 0;
        }
    }
}

// Função para criar matriz de habilidade em cruz
void criarCruz(int cruz[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for(int i = 0; i < TAM_HABILIDADE; i++) {
        for(int j = 0; j < TAM_HABILIDADE; j++) {
            cruz[i][j] = (i == TAM_HABILIDADE/2 || j == TAM_HABILIDADE/2) ? 1 : 0;
        }
    }
}

// Função para criar matriz de habilidade em octaedro (losango)
void criarOctaedro(int octaedro[TAM_HABILIDADE][TAM_HABILIDADE]) {
    int centro = TAM_HABILIDADE/2;
    for(int i = 0; i < TAM_HABILIDADE; i++) {
        for(int j = 0; j < TAM_HABILIDADE; j++) {
            octaedro[i][j] = (abs(i - centro) + abs(j - centro) <= centro) ? 1 : 0;
        }
    }
}

// Função para aplicar habilidade no tabuleiro
void aplicarHabilidade(int tabuleiro[10][10], int habilidade[TAM_HABILIDADE][TAM_HABILIDADE], 
                      int linhaOrigem, int colunaOrigem) {
    int offset = TAM_HABILIDADE/2;
    
    for(int i = 0; i < TAM_HABILIDADE; i++) {
        for(int j = 0; j < TAM_HABILIDADE; j++) {
            int linhaTab = linhaOrigem - offset + i;
            int colunaTab = colunaOrigem - offset + j;
            
            if(dentroDoTabuleiro(linhaTab, colunaTab) && habilidade[i][j] == 1) {
                // Marca área afetada com valor 5
                if(tabuleiro[linhaTab][colunaTab] != 3) { // Não sobrescreve navios
                    tabuleiro[linhaTab][colunaTab] = 5;
                }
            }
        }
    }
}

int main() {
    // Declaração do tabuleiro 10x10
    int tabuleiro[10][10] = {0}; // Inicializa todas as posições com 0 (água)
    
    // Posições dos navios existentes
    int navioHorizontalLinha = 2;    // Linha inicial do navio horizontal
    int navioHorizontalColuna = 3;   // Coluna inicial do navio horizontal
    int navioVerticalLinha = 4;      // Linha inicial do navio vertical
    int navioVerticalColuna = 7;     // Coluna inicial do navio vertical
    
    // Novas posições para navios diagonais
    int navioDiagonal1Linha = 1;    // Linha inicial do primeiro navio diagonal
    int navioDiagonal1Coluna = 1;   // Coluna inicial do primeiro navio diagonal
    int navioDiagonal2Linha = 8;    // Linha inicial do segundo navio diagonal
    int navioDiagonal2Coluna = 1;   // Coluna inicial do segundo navio diagonal
    
    // Posiciona navio horizontal (com verificação)
    int podeColocarHorizontal = 1;
    for(int i = 0; i < 3; i++) {
        if (!posicaoSegura(tabuleiro, navioHorizontalLinha, navioHorizontalColuna + i)) {
            podeColocarHorizontal = 0;
            break;
        }
    }
    if (podeColocarHorizontal) {
        for(int i = 0; i < 3; i++) {
            tabuleiro[navioHorizontalLinha][navioHorizontalColuna + i] = 3;
        }
    } else {
        printf("Erro: Navio horizontal não pode ser posicionado!\n");
    }
    
    // Posiciona navio vertical (com verificação)
    int podeColocarVertical = 1;
    for(int i = 0; i < 3; i++) {
        if (!posicaoSegura(tabuleiro, navioVerticalLinha + i, navioVerticalColuna)) {
            podeColocarVertical = 0;
            break;
        }
    }
    if (podeColocarVertical) {
        for(int i = 0; i < 3; i++) {
            tabuleiro[navioVerticalLinha + i][navioVerticalColuna] = 3;
        }
    } else {
        printf("Erro: Navio vertical não pode ser posicionado!\n");
    }
    
    // Posiciona primeiro navio diagonal (com verificação)
    int podeColocarDiagonal1 = 1;
    for(int i = 0; i < 3; i++) {
        if (!posicaoSegura(tabuleiro, navioDiagonal1Linha + i, navioDiagonal1Coluna + i)) {
            podeColocarDiagonal1 = 0;
            break;
        }
    }
    if (podeColocarDiagonal1) {
        for(int i = 0; i < 3; i++) {
            tabuleiro[navioDiagonal1Linha + i][navioDiagonal1Coluna + i] = 3;
        }
    } else {
        printf("Erro: Primeiro navio diagonal não pode ser posicionado!\n");
    }
    
    // Posiciona segundo navio diagonal (com verificação)
    int podeColocarDiagonal2 = 1;
    for(int i = 0; i < 3; i++) {
        if (!posicaoSegura(tabuleiro, navioDiagonal2Linha - i, navioDiagonal2Coluna + i)) {
            podeColocarDiagonal2 = 0;
            break;
        }
    }
    if (podeColocarDiagonal2) {
        for(int i = 0; i < 3; i++) {
            tabuleiro[navioDiagonal2Linha - i][navioDiagonal2Coluna + i] = 3;
        }
    } else {
        printf("Erro: Segundo navio diagonal não pode ser posicionado!\n");
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
    
    // Criar e aplicar habilidades
    int cone[TAM_HABILIDADE][TAM_HABILIDADE] = {0};
    int cruz[TAM_HABILIDADE][TAM_HABILIDADE] = {0};
    int octaedro[TAM_HABILIDADE][TAM_HABILIDADE] = {0};
    
    criarCone(cone);
    criarCruz(cruz);
    criarOctaedro(octaedro);
    
    // Aplicar habilidades em diferentes posições
    aplicarHabilidade(tabuleiro, cone, 5, 5);      // Cone no centro
    aplicarHabilidade(tabuleiro, cruz, 2, 2);      // Cruz no canto superior
    aplicarHabilidade(tabuleiro, octaedro, 7, 7);  // Octaedro no canto inferior
    
    // Exibir tabuleiro com habilidades
    printf("\nTabuleiro com áreas de efeito das habilidades:\n");
    printf("  0 1 2 3 4 5 6 7 8 9\n");
    for(int i = 0; i < 10; i++) {
        printf("%d ", i);
        for(int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]); // Mostra os valores numéricos: 0 (água), 3 (navio), 5 (área afetada)
        }
        printf("\n");
    }
    
    return 0;
}
