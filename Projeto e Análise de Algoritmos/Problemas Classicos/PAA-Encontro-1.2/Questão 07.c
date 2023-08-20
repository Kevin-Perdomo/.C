#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 50

void preencheVetor(int vetor[N]) {
  srand(time(NULL));
  for(int i=0; i < N; i++) {
    vetor[i] = (rand() % 100) + 1;
    printf("|%d|", vetor[i]);
  }
}

int encontraMaiorValor(int vetor[N], int maior, int atual) {
  if(atual < N) {

    if(vetor[atual] > maior) {
      maior = vetor[atual];
    }
    encontraMaiorValor(vetor, maior, atual+1);

  } else {
    return maior;
  }
}

int main() {

  int vetor[N], maior = 0, atual = 0;
  preencheVetor(vetor);
  printf("\n");
  int resultado = encontraMaiorValor(vetor, maior, atual);
  printf("\n\n O maior numero e: %d \n\n", resultado);

  return 0;
}