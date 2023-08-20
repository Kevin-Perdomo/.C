#include <stdlib.h>
#include <stdio.h>

void lerVetores(int vetor1[], int vetor2[], int N) {
    printf("\n\nDigite os %d elementos do vetor V1:\n", N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &vetor1[i]);
    }

    printf("\n\nDigite os %d elementos do vetor V2:\n", N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &vetor2[i]);
    }
}

int verificarCondicao(int vetor1[], int vetor2[], int N, int x, int y) {
    int somatorio = 0, produtorio = 1;

    for (int i = 1; i < N; i += 2) {
        somatorio += x * abs(vetor1[i]);
    }

    for (int j = 0; j < N; j += 2) {
        produtorio *= y * vetor2[j];
    }

    if (somatorio <= produtorio) 
    return 1; // Condição é verdadeira
    else
    return 0; // Condição não é verdadeira
}

int main() {
    int N = 40;
    int vetor1[N];
    int vetor2[N];
    lerVetores(vetor1, vetor2, N);

    int x, y;
    printf("\n\nDigite o valor de x: ");
    scanf("%d", &x);
    printf("\n\nDigite o valor de y: ");
    scanf("%d", &y);

    int resultado = verificarCondicao(vetor1, vetor2, N, x, y);
    
    if (resultado == 1) {
        printf("\n\nCondicao verdadeira.\n\n");
    } else {
        printf("\n\nCondicao falsa.\n\n");
    }

    return 0;
}
