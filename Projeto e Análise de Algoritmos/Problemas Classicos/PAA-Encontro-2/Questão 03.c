#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void lerVetor(int vetor[], int n) {
    printf("\n\nDigite os %d elementos do vetor:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &vetor[i]);
    }
}

int calcularExpressao(int vetor[], int n, int k) {
    int max = INT_MIN;
    for (int i = 0; i <= n - k; i++) {
        int soma = 0;
        for (int j = i; j <= (i + k - 1); j++) {
            soma += vetor[j];
        }
        if (soma > max) {
            max = soma;
        }
    }
    return max;
}

int main() {

    int n = 30;
    int vetor[n];
    lerVetor(vetor, n);

    int k;
    printf("\n\nDigite o valor de k (1 a 4): ");
    scanf("%d", &k);

    int resultado = calcularExpressao(vetor, n, k);
    printf("\n\nResultado da expressao: %d \n\n", resultado);

    return 0;
}
