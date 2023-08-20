#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void preencherVetor(int vetor[], int N) {
    srand(time(NULL));
    for (int i = 0; i < N; i++) {
        vetor[i] = (rand() % 100) + 1;
    }
}

void modificarVetor(int vetor[], int N) {
    for (int i = 0; i < N; i++) {
        int soma = 0;
        for (int j = 0; j < N; j++) {
            if (i != j) {
                soma += vetor[j];
            }
        }
        vetor[i] = soma;
    }
}

void imprimirVetor(int vetor[], int N) {
    for (int i = 0; i < N; i++) {
        printf("|%02d|", vetor[i]);
    }
    printf("\n\n");
}

int main() {
    int N = 50;
    int vetor[N];

    preencherVetor(vetor, N);

    printf("\n\n Vetor original:\n");
    imprimirVetor(vetor, N);
    modificarVetor(vetor, N);

    printf("\n\n Vetor modificado:\n");
    imprimirVetor(vetor, N);

    return 0;
}
