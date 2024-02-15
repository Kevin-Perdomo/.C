// Programa 01 - Treinamento;
// Rede neural artificial (RNA) Perceptron para diagnóstico de doenças;
// Desenvolvida por: Kevin Siqueira Perdomo;
// Matrícula: 201911250205;
// Curso: Bacharelado em Engenharia De Computação;

#include <stdio.h>
#include <math.h>

// Coeficiente de Aprendizagem
#define PHI 0.5

// Vetores de entrada (em forma de uma matriz), sendo a primeira posição o BIAS
float entradas[][10] = {{1, 1, 1, 1, 1, 0, 0, 1, 0, 0},
                        {1, 0, 0, 1, 1, 1, 1, 1, 0, 0},
                        {1, 0, 0, 1, 0, 1, 0, 1, 1, 1}};

// Valores esperados
float yDesejado[][3] = {{1, 0, 0}, // Gripe
                        {0, 1, 0}, // Dengue
                        {0, 0, 1}};// Catapora

// Passo 01: vetores aleatorios
float pesos1[10] = {0, 0, 1, 1, 1, 0, 0, 0, 0, 0};
float pesos2[10] = {1, 1, 1, 1, 1, 0, 0, 0, 0, 0};
float pesos3[10] = {0, 0, 0, 0, 0, 1, 1, 1, 1, 1};

// Vetor de erros da época
float errosEpoca[3] = {0, 0, 0};

// Passo 03: Função de ativação (Degrau Simples)
float funcaoAtivacao(float valor) {
  if(valor > 0)
    return 1;
  else
    return 0;
}

// Mostra as sinapses que adquiriram conhecimento
void printaSinpses(float pesos[], int indice) {

  printf("Sinapse 0%d:", indice);
  printf("|");
  for(int i = 0; i < 10; i++) {
    printf("%.2f|", pesos[i]);
  }
  printf("\n\n");
}

int main()
{
  float erroGlobal = 0;

  do{

    //  x == lINHA;
    //  i == Coluna;
    for(int x = 0; x < 3; x++) {

      // Passo 02: Treinar o proximo vetor de entrada
      float v1 = 0.0, v2 = 0.0, v3 = 0.0;
      for(int i = 0; i < 10; i++) {
        v1 += entradas[x][i] * pesos1[i];
        v2 += entradas[x][i] * pesos2[i];
        v3 += entradas[x][i] * pesos3[i];
      }

      float y1 = funcaoAtivacao(v1);
      float y2 = funcaoAtivacao(v2);
      float y3 = funcaoAtivacao(v3);
      
      // Passo 04: Calcular os erros de cada neurônio
      float e1 = yDesejado[x][0] - y1;
      float e2 = yDesejado[x][1] - y2;
      float e3 = yDesejado[x][2] - y3;

      // Passo 05: Atualizar as sinapses
      float deltaW1[10], deltaW2[10], deltaW3[10];
        for(int i = 0; i < 10; i++) {
          deltaW1[i] = PHI * e1 * entradas[x][i];
          deltaW2[i] = PHI * e2 * entradas[x][i];
          deltaW3[i] = PHI * e3 * entradas[x][i];

          pesos1[i] = pesos1[i] + deltaW1[i];
          pesos2[i] = pesos2[i] + deltaW2[i];
          pesos3[i] = pesos3[i] + deltaW3[i];
      }

      // Passo 06: Calculo do erro Médio Local
      errosEpoca[x] = ((e1*e1)+(e2*e2)+(e3*e3))/3;
    }

    // Passo 07: Calculo do erro Médio global (Criterio de Parada)
    erroGlobal = (errosEpoca[1] + errosEpoca[2] + errosEpoca[3])/3;

    printf("\n\n====================================================================================\n\n");
    printf("\nErros Globais: ");
    printf(" |%.4f|\n", erroGlobal);

  }while(erroGlobal > 0.00001);

  printf("\n\n====================================================================================\n\n");
  printf("\nSinapses Com Conhecimento\n\n\n");
  
  printaSinpses(pesos1, 1); // Gripe
  printaSinpses(pesos2, 2); // Dengue
  printaSinpses(pesos3, 3); // Catapora

  printf("\nFIM\n");
  printf("\n\n====================================================================================\n\n");

  return 0;
}