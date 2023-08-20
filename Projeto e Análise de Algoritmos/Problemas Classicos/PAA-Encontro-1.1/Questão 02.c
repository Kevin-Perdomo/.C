#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LINHAS 4
#define COLUNAS 4

void geraMatriz(int matriz[LINHAS][COLUNAS]) {
  srand(time(NULL));
  for(int i = 0; i < LINHAS; i++) {
    for(int j = 0; j < COLUNAS; j++) {
      matriz[i][j] = rand() % 100;
    }
  }
}

void geraMatrizTransposta(int matriz[LINHAS][COLUNAS], int matrizTransposta[LINHAS][COLUNAS]) {
  for(int i = 0; i < LINHAS; i++) {
    for(int j = 0; j < COLUNAS; j++) {
      matrizTransposta[j][i] = matriz[i][j];
    }
  }
}

void multiplicaMatriz(int matriz[LINHAS][COLUNAS], int matrizTransposta[LINHAS][COLUNAS], int matrizResposta[LINHAS][COLUNAS]) {
  for(int i = 0; i < LINHAS; i++) {
    for(int j = 0; j < COLUNAS; j++) {
        
      matrizResposta[i][j] = 0;

      for (int k = 0; k < LINHAS; k++) {
        matrizResposta[i][j] += matriz[i][k] * matrizTransposta[k][j];
      }

    }
  }
}

int verificaOrtogonal(int matrizResposta[LINHAS][COLUNAS]) {
  for(int i = 0; i < LINHAS; i++) {
    for(int j = 0; j < COLUNAS; j++) {
      if(i==j) {
        if(matrizResposta[i][j] == 1) 
        continue;
        else
        return 0;
      } else {
          if(matrizResposta[i][j] == 0)
          continue;
          else
          return 0;
          }

    }
  }
  return 1;
}

int main() {

  int matriz[LINHAS][COLUNAS];
  int matrizTransposta[LINHAS][COLUNAS];
  int matrizResposta[LINHAS][COLUNAS];

  //Função 1 -> Criar Matriz:
  geraMatriz(matriz);

  //Função 2 -> Calcular Transposta:
  geraMatrizTransposta(matriz, matrizTransposta);

  //Função 3 -> Multiplicar Matrizes:
  multiplicaMatriz(matriz, matrizTransposta, matrizResposta);

  //Função 4 -> Verificar se a matriz é Ortogonal:
  int resposta = 0;
  resposta = verificaOrtogonal(matrizResposta);

  //Exibindo Matriz:
  printf("\n\n-------------------------Matriz Gerada Aleatoriamente------------------------\n");
  for(int i = 0; i < LINHAS; i++) {
    for(int j = 0; j < COLUNAS; j++) {
      printf(" %02d ", matriz[i][j]);
    }
    printf("\n");
  }

  //Exibindo Matriz Transposta:
  printf("------------------------------Matriz Transposta------------------------------\n");
  for(int i = 0; i < LINHAS; i++) {
    for(int j = 0; j < COLUNAS; j++) {
      printf(" %02d ", matrizTransposta[i][j]);
    }
    printf("\n");
  }

  //Exibindo Matriz Resposta:
  printf("------------------------------Matriz Resposta--------------------------------\n");
  for(int i = 0; i < LINHAS; i++) {
    for(int j = 0; j < COLUNAS; j++) {
      printf(" %05d ", matrizResposta[i][j]);
    }
    printf("\n");
  }

  printf("-----------------------------------------------------------------------------\n");
  
  if(resposta == 1)
    printf("Matriz Ortogonal!");
  else
    printf("Matriz Nao Ortogonal!");

  printf("\n-----------------------------------------------------------------------------\n\n");

  return 0;
}