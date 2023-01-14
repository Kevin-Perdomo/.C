#include <stdio.h>
#include <stdlib.h>

long int fatorial (int n)
{
	if ((n == 0) || (n == 1))
	return(1);
	else
	return (n * fatorial (n - 1));
}

int main()
{
	int numero;
	long int resultado;

	printf("\n\t Digite um numero natural positivo e comfirme com Enter : ");
	scanf("%d",&numero);

	if (numero >= 0)
	{	
		resultado = fatorial(numero);
		printf("\n\t %ld \n\n", resultado);
	} else
	     {
		 	printf("\n\t Nao existe fatorial de numero negativo \n\n");
		 }

    return 0;
}
