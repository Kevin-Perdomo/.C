#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

//Lógica do teste
int teste_primo(int n){

    int auxiliar = 0;

    for(int i = 1; i <= n; i++){
        if(n % i == 0){
            auxiliar ++;
        }
    }

    if(auxiliar == 2)
    return 1;
    else
    return 0;

}

int main (){

    //Comando de Regionalização
    setlocale(LC_ALL,"Portuguese_Brazil");

    int resultado = 0, numero = 0;

    printf("\n\n Insira um número inteiro positivo \n\n");
    scanf("%d", &numero);
    resultado = teste_primo(numero);

    if(resultado == 1)
    printf("\n O número %d é primo \n\n", numero);
    if(resultado == 0) //Poderia ser 'else' apenas
    printf("\n O número %d não é primo \n\n", numero);

    system("pause");
    return 0;
}