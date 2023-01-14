#include <stdio.h>
#include <stdlib.h>

int fatorial (int n)
{
	if ((n == 0) || (n == 1))
	return(1);
	else
	return (n * fatorial (n - 1));
}

int main()
{
	int numero, resultado;
	printf("\n\t Digite o numero que deseja calcular e comfirme com Enter : ");
	scanf("%d",&numero);
	resultado = fatorial(numero);
	printf("\n\t %d \n\n", resultado);
    return 0;
}
