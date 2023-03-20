#include <stdio.h>

// Função de busca binária recursiva
int busca_binaria(int array[], int esquerda, int direita, int elemento)
{

    if (direita >= esquerda)
    {
        int meio = esquerda + (direita - esquerda) / 2;

        // Se o elemento estiver no meio, retorna o índice
        if (array[meio] == elemento)
            return meio;

        // Se o elemento for menor que o meio, busca na metade esquerda do array
        if (array[meio] > elemento)
            return busca_binaria(array, esquerda, meio - 1, elemento);

        // Se o elemento for maior que o meio, busca na metade direita do array
        return busca_binaria(array, meio + 1, direita, elemento);
    }

    // Se o elemento não estiver no array, retorna -1
    return -1;
}

// Função principal
int main(void)
{

    int array[] = {1, 2, 4, 4, 5, 6, 7, 7, 8, 9};
    int n = sizeof(array) / sizeof(array[0]);
    int elemento;

    printf("\n\nDigite o valor que deseja burcar no array: ");
    scanf("%d", &elemento);

    int resultado = busca_binaria(array, 0, n - 1, elemento);

    if (resultado == -1)
    {
        printf("\n\nElemento nao encontrado no array.\n\n\n");
    }
    else
    {
        printf("\n\nElemento encontrado no indice %d do array.\n\n\n", resultado);
    }

    return 0;
}
