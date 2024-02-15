// Programa 02 - Diagnóstico;
// Rede neural artificial (RNA) Perceptron para diagnóstico de doenças;
// Desenvolvida por: Kevin Siqueira Perdomo;
// Matrícula: 201911250205;
// Curso: Bacharelado em Engenharia De Computação;

#include <stdio.h>
#include <math.h>

// Vetores de entrada (Sendo a primeira posição do vetor o BIAS)
float entrada[10] = {1, 0, 0, 0, 0, 0, 0, 0, 0, 0};

// Passo 01: vetores de saida do programa de treinamento (com conhecimento)
float pesos1[10] = {-0.50, 0.00, 1.00, 0.50, 0.50, -0.50, -0.50, -0.50, 0.00, 0.00};
float pesos2[10] = {0.00, -0.50, -0.50, 0.00, 0.50, 0.50, 1.00, -1.00, -0.50, -0.50};
float pesos3[10] = {-1.00, -0.50, -0.50, -1.00, -1.00, 0.50, 0.50, 0.00, 1.00, 1.00};

// Zueiras
int easteregg(float entrada[]) {
  int contador = 0;

  for(int i = 0; i < 10; i++) {
    contador += entrada[i];
  }

 printf("\n\n====================================================================================\n\n");
 printf("\n Diagnostico:\n");

  if(contador == 1) {
    printf("\n AIDS \n");
    return 1;
  }
  if(contador == 10) {
    printf("\n Descanse em paz \n");
    return 1;
  }

  printf("\nFIM\n");
  printf("\n\n====================================================================================\n\n");

  return 0;
}

int main()
{
    //  Interface do Usuário 
    printf("\n\n====================================================================================\n\n");
    printf(" Rede neural artificial (RNA) Perceptron para diagnostico de doencas \n\n");

    printf("----> Por favor, insira (1) caso o paciente apresente o sintoma");
    printf(" ou (0) caso o paciente  NAO apresente o sintoma\n");

    printf("\n----> Tosse: ");
    scanf("%f", &entrada[1]);

    printf("\n----> Congestao nasal: ");
    scanf("%f", &entrada[2]);

    printf("\n----> Febre: ");
    scanf("%f", &entrada[3]);

    printf("\n----> Dor: ");
    scanf("%f", &entrada[4]);

    printf("\n----> Manchas na pele: ");
    scanf("%f", &entrada[5]);

    printf("\n----> Nauseas: ");
    scanf("%f", &entrada[6]);

    printf("\n----> Fraqueza: ");
    scanf("%f", &entrada[7]);

    printf("\n----> Bolhas na pele: ");
    scanf("%f", &entrada[8]);

    printf("\n----> Coceira: ");
    scanf("%f", &entrada[9]);

    // Passo 02: Produto Escalar
    float v1 = 0.0, v2 = 0.0, v3 = 0.0;
    for(int x = 0; x < 3; x++) {
      for(int i = 0; i < 10; i++) {
        v1 += entrada[i] * pesos1[i];
        v2 += entrada[i] * pesos2[i];
        v3 += entrada[i] * pesos3[i];
      }
    }

    // Zueiras
    int egg = 0;
    egg = easteregg(entrada);

    // Passo 03: Comparação entre a sinapse com conhecimento e a entrada do paciente
    if(egg == 0) {

      printf("\n\n====================================================================================\n\n");
      printf("\n Diagnostico:\n");

      if((v1 > v2) && (v1 > v3)) {
        printf("\n Gripe \n");
      }
      if(((v2 > v1) && v2 > v3)) {
        printf("\n Dengue \n");
      }
      if(((v3 > v1) && v3 > v2)) {
        printf("\n Catapora \n");
      }
    }

    printf("\n FIM \n");
    printf("\n\n====================================================================================\n\n");


  return 0;
}