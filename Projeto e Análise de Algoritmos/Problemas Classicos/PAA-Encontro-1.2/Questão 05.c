#include <stdio.h>
#include <stdlib.h>

int calculaPotencia(int a, int b){

    if(b == 0)
    return 1;
    else 
    return a * calculaPotencia(a, b-1);
}

int main(){

    int a, b, resposta;
    printf("\n\n Digite o valor de (a), sendo (a=!0): ");
    scanf("%d", &a);
    printf("\n\n Digite o valor de (b), sendo (b>=0): ");
    scanf("%d", &b);
    resposta = calculaPotencia(a, b); // ((a)^b)*1;
    printf("\n\n Resultado: %02d \n\n", resposta);
    return 0;
}