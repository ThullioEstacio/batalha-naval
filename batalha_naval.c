#include <stdio.h>
#include <stdbool.h>

#define TAMANHO 10
#define TAMANHO_NAVIO 3
#define AGUA 0
#define NAVIO 3

// Protótipos de funções
void inicializarTabuleiro(int tabuleiro[TAMANHO][TAMANHO]);
bool posicionarNavioHorizontal(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna);
bool posicionarNavioVertical(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna);
void exibirTabuleiro(int tabuleiro[TAMANHO][TAMANHO]);
bool coordenadasValidas(int linha, int coluna);
bool verificarSobreposicao(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, bool horizontal);

int main() {
    int tabuleiro[TAMANHO][TAMANHO];
    
    // Inicializa o tabuleiro com água (0)
    inicializarTabuleiro(tabuleiro);
    
    // Posiciona navio horizontal (coordenadas fixas no código)
    int linhaH = 2, colunaH = 3;
    if (!posicionarNavioHorizontal(tabuleiro, linhaH, colunaH)) {
        printf("Erro ao posicionar navio horizontal!\n");
        return 1;
    }
    
    // Posiciona navio vertical (coordenadas fixas no código)
    int linhaV = 5, colunaV = 7;
    if (!posicionarNavioVertical(tabuleiro, linhaV, colunaV)) {
        printf("Erro ao posicionar navio vertical!\n");
        return 1;
    }
    
    // Exibe o tabuleiro com os navios posicionados
    exibirTabuleiro(tabuleiro);
    
    return 0;
}

// Inicializa todas as posições do tabuleiro com água (0)
void inicializarTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

// Posiciona um navio horizontalmente a partir das coordenadas dadas
bool posicionarNavioHorizontal(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna) {
    // Verifica se as coordenadas iniciais são válidas
    if (!coordenadasValidas(linha, coluna)) {
        return false;
    }
    
    // Verifica se o navio cabe na horizontal a partir da coluna dada
    if (coluna + TAMANHO_NAVIO > TAMANHO) {
        return false;
    }
    
    // Verifica sobreposição com outros navios
    if (verificarSobreposicao(tabuleiro, linha, coluna, true)) {
        return false;
    }
    
    // Posiciona o navio
    for (int j = coluna; j < coluna + TAMANHO_NAVIO; j++) {
        tabuleiro[linha][j] = NAVIO;
    }
    
    return true;
}

// Posiciona um navio verticalmente a partir das coordenadas dadas
bool posicionarNavioVertical(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna) {
    // Verifica se as coordenadas iniciais são válidas
    if (!coordenadasValidas(linha, coluna)) {
        return false;
    }
    
    // Verifica se o navio cabe na vertical a partir da linha dada
    if (linha + TAMANHO_NAVIO > TAMANHO) {
        return false;
    }
    
    // Verifica sobreposição com outros navios
    if (verificarSobreposicao(tabuleiro, linha, coluna, false)) {
        return false;
    }
    
    // Posiciona o navio
    for (int i = linha; i < linha + TAMANHO_NAVIO; i++) {
        tabuleiro[i][coluna] = NAVIO;
    }
    
    return true;
}

// Exibe o tabuleiro no console
void exibirTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    printf("Tabuleiro de Batalha Naval:\n\n");
    printf("   ");
    for (int j = 0; j < TAMANHO; j++) {
        printf("%2d ", j); // Cabeçalho das colunas
    }
    printf("\n");
    
    for (int i = 0; i < TAMANHO; i++) {
        printf("%2d ", i); // Número da linha
        for (int j = 0; j < TAMANHO; j++) {
            printf("%2d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("\nLegenda:\n");
    printf("0 - Água\n");
    printf("3 - Navio\n");
}

// Verifica se as coordenadas estão dentro dos limites do tabuleiro
bool coordenadasValidas(int linha, int coluna) {
    return linha >= 0 && linha < TAMANHO && coluna >= 0 && coluna < TAMANHO;
}

// Verifica se há sobreposição com outros navios
bool verificarSobreposicao(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, bool horizontal) {
    if (horizontal) {
        for (int j = coluna; j < coluna + TAMANHO_NAVIO; j++) {
            if (tabuleiro[linha][j] != AGUA) {
                return true;
            }
        }
    } else {
        for (int i = linha; i < linha + TAMANHO_NAVIO; i++) {
            if (tabuleiro[i][coluna] != AGUA) {
                return true;
            }
        }
    }
    return false;
}
