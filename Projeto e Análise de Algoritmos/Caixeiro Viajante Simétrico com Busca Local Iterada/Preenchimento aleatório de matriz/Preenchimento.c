#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void preencherMatriz(int n, int matriz[][n]) {
    
    srand(time(NULL)); // Inicializa a semente aleatória com base no tempo

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                matriz[i][j] = 0;
            } else {
                matriz[i][j] = rand() % 10 + 1; // Preenche com valores aleatórios de 1 a 10
                matriz[j][i] = matriz[i][j];
            }
        }
    }
}

void imprimirMatriz(int n, int matriz[][n]) {
    printf("Matriz resultante:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf(" %02d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;

    printf("Digite o tamanho da matriz quadrada: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Tamanho inválido da matriz.\n");
        return 1;
    }

    int matriz[n][n];

    preencherMatriz(n, matriz);
    imprimirMatriz(n, matriz);

    return 0;
}
