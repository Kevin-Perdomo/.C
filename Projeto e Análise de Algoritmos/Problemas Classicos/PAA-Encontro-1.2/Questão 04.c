#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 30

void geraVetorAleatorio(int vetor[N]){
    srand(time(NULL));
    for(int i=0; i<N; i++) {
        vetor[i] = (rand() % 30) + 1;
    }
}

void ordenaVetor(int vetor[N]){

    for(int i=0; i<N; i++){
        for(int j=i; j<N; j++){
            if(vetor[j] > vetor[i]){

                int aux = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = aux;
            }
        }
    }
}

void exibeVetor(int vetor[N]){

    printf("\n\n------------------------------------------------------------\n\n");
    for(int i=0; i<N; i++){
        printf("|%02d|", vetor[i]);
    }
    printf("\n\n------------------------------------------------------------\n\n");
}

int main(){

    int vetor[N];
    geraVetorAleatorio(vetor);
    exibeVetor(vetor);
    ordenaVetor(vetor);
    exibeVetor(vetor);
    return 0;
}