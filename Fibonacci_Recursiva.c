#include<stdio.h>
#include<stdlib.h>

int fibonacci(int position)
{
	if (position == 1 || position == 2)
	{
		return 1; 
	}
	else
	{
		return fibonacci(position - 1) + fibonacci(position - 2);
	}
}

int main()
{

	int posicao, resultado;
	printf("\n Escolha uma posiçao da sequencia de Fibonacci: ");
	scanf("%d", &posicao);

	if (posicao > 0)
	{
		resultado = fibonacci(posicao);
		printf("\n\n Resultado: %d \n\n", resultado);
	}
	else
	{
		return printf("\n\n Esta posiçao nao existe na sequencia de Fibonacci \n\n");
	}

	system("pause");
	return 0;
}
