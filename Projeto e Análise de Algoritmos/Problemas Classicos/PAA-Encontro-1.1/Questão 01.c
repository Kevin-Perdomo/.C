#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

/* Definições de tamanho de matriz e faixa de números aleatórios */
#define N 4
#define M 5
#define MIN 1
#define MAX 20

/* Função para gerar uma matriz de tamanho NxM preenchida com números aleatórios de 1 a 20 */
void generateMatrix(int matrix[N][M]){
    /* Semeia a função rand com o tempo atual para garantir que os números gerados sejam diferentes a cada execução do programa */
    srand(time(NULL));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            /* Preenche a posição atual da matriz com um número aleatório de 1 a 20 */
            matrix[i][j] = (rand() % (MAX)) + MIN;
            printf("%d ", matrix[i][j]);

        }
        printf("\n");
    }
}

/* Função para verificar se a matriz satisfaz a condição especificada */
int verifyCondition(int matrix[N][M]){
    int minSum = INT_MAX, maxMult = INT_MIN;
    
    for(int i = 0; i < N; i++){
        int sum = 0;
        for(int j = 0; j < M; j++){
            sum += abs(matrix[i][j]);
        }
        /* Se a soma da linha atual é menor que o mínimo encontrado até agora, atualiza o mínimo */
        if(sum < minSum){
            minSum = sum;
        }
    }

    printf("\nSomatorio Minimo dentre todas as linhas:%d\n", minSum);

    for(int i = 0; i < M; i++){
        int mult = 1;
        for(int j = 0; j < N; j++){
            mult *= matrix[j][i];
        }
        /* Se a multiplicação da coluna atual é maior que o máximo encontrado até agora, atualiza o máximo */
        if(mult > maxMult){
            maxMult = mult;
        }
    }

    printf("\nProdutorio Maximo dentre todas as colunas:%d\n", maxMult);
    
    /* Retorna 1 (verdadeiro) se o maior produto das colunas é maior ou igual à menor soma das linhas. 
       Caso contrário, retorna 0 (falso). */
    return maxMult >= minSum;
}

int main(){

    printf("\n\nXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n\n");

    int matrix[N][M];
    generateMatrix(matrix);
    
    if(verifyCondition(matrix)){
        printf("\nCondicao satisfeita.\n");
    }
    else{
        printf("\nCondicao nao satisfeita.\n");
    }


    printf("\n\nXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n\n");
    return 0;
}
