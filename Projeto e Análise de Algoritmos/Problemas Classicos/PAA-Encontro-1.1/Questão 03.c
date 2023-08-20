#include <stdio.h>
#define TAMANHO 20

// Função para preencher o vetor pelo teclado
void preencherVetor(int vetor[TAMANHO]) {
    printf("\n\n");
    printf("Digite os %d numeros do vetor:\n", TAMANHO);
    for (int i = 0; i < TAMANHO; i++) {
        scanf("%d", &vetor[i]);
    }
    printf("\n\n");
}

// Função para organizar o vetor
void organizarVetor(int vetor[TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = i ; j < TAMANHO; j++) {
            if ((i % 2 == 0 && vetor[j] % 2 != 0) || (i % 2 != 0 && vetor[j] % 2 == 0)) {
                int aux = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = aux;
                break;
            }
        }
    }
}

// Função para imprimir o vetor
void imprimirVetor(int vetor[TAMANHO]) {
    printf("Vetor organizado:\n");
    printf("|");
    for (int i = 0; i < TAMANHO; i++) {
        printf(" %d |", vetor[i]);
    }
    printf("\n\n");
}

int main() {

    int vetor[TAMANHO];

    preencherVetor(vetor);
    organizarVetor(vetor);
    imprimirVetor(vetor);

    return 0;
}
