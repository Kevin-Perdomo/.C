#include <stdio.h>
#include <stdlib.h>
#define N 20

void preencheVetor(int vetor[N]) {
  for(int i=0; i<N; i++) {
    printf("\n\n------------------------------------------------------------------\n\n");
    printf("Digite a %d posicao do vetor: ", i);
    scanf("%d", &vetor[i]);
  }
}

int composto(int n){
    
  int i, cont = 0;
  for(i=1; i <= n; i++){ 
    if((n % i) == 0) 
      cont++;       
  }

  if(cont > 2)
  return 1;

  else
  return 0;
}

void organizaVetor(int vetor[N], int inicio, int fim) {

  if(inicio < fim){

    if(composto(vetor[inicio]) == 1){

      organizaVetor(vetor, inicio+1, fim);

    } else{

      int aux = vetor[inicio];
      vetor[inicio] = vetor[fim];
      vetor[fim] = aux;
      organizaVetor(vetor, inicio, fim-1);
    }
  }
}


int main() {

  int vetor[N];
  preencheVetor(vetor);
  organizaVetor(vetor, 0, N-1);
  printf("\n\n-------------------------Vetor Organizado-------------------------\n\n");
  for(int i=0; i<N; i++) {
    printf("|%02d|", vetor[i]);
  }
  printf("\n\n------------------------------------------------------------------\n\n");
  return 0;
}