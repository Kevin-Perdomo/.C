#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char crip[128];

void maiusculas(char *texto){

    int i;
    int k = strlen(texto);

    for(i=0; i < k; i++) // Pega todos os caracteres do vetor string(texto ou chave)
	{
        texto[i] = toupper(texto[i]); // Transforma todas as letras minusculas em maiusculas
    }
}

void somente_letras(char *texto){ // Remove numeros e caracteres especiais

    int i , j = 0;
    int k = strlen(texto);
    char texto_novo[128];

    for(i=0; i < k; i++){ // Pega todos os caracteres do vetor string(texto ou chave)
        if(texto[i]>='A' && texto[i]<='Z'){ // Se o caractere atual não estiver intervalo A-Z
            texto_novo[j] = texto[i]; // Adiciona a letra maiuscula a um novo vetor
            j++;
        }
    }

    for(i=0; i < j; i++){ // Substitue o texto antigo pelo novo(que contem somente letras)
        texto[i] = texto_novo[i];
    }
    texto[i] = '\0'; // Adiciona um valor nulo ao final do texto
}

void cifrar(char *texto, char *chave, int option_cifra){

    int i;
    int k = strlen(texto);

    maiusculas(texto);
    maiusculas(chave);
    somente_letras(texto);
    somente_letras(chave);

    for(i = 0; i < k; i++){ // Pega todos os caracteres do vetor string(texto ou chave)
        if(option_cifra == 1){
            crip[i] = ((texto[i] - 'A') + (chave[i % strlen(chave)] - 'A')) % 26 + 'A'; // Criptografa o caractere
        }
        else{
            crip[i] = (texto[i] - chave[i % strlen(chave)] + 26) % 26 + 'A'; // Descriptografa o caractere
        }
    }
}

int main()
{
   
    char texto[128], chave[128], m1[128], m2[128];
    int option = 0, auxiliar, option_cifra;

    printf("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
    printf("\n\n..:: PROGRAMA DE CRIPTOGRAFIA - CIFRA DE VIGENERE ::..\n\n");

    printf("\nObservacoes, tanto para o texto quanto para a cifra:");
    printf("\n1 - No maximo 128 caracteres;");
    printf("\n2 - Somente e permitida a utilizacao de letras;");
    printf("\n3 - Os acentos, espaco 'tecla Space', e a letra 'c cedilha' nao sao aceitos;");

    printf("\n\nEscolha uma opcao:\n\n");
    printf("1) Criptografar\n\n");
    printf("2) Descriptografar\n\n");
    printf("3) Para encerrar o programa");

    do{
        printf("\n\nDigite o numero da opcao escolhida: ");
        scanf("%d",&option);
        fflush(stdin); //__fpurge(stdin); //somente no linux

        auxiliar = 1;

        if(option!=1 && option!=2 && option!=3){
            printf("\n\nOpcao invalida!\n");
            auxiliar = 0;
        }
    }
    while(auxiliar == 0); // Verifica se foi digitado algum texto

    switch(option){
       
        case 1:
            printf("\n\nOpcao escolhida: CRIPTOGRAFAR\n\n");
            option_cifra = 1;
            strcpy(m1, "Texto original");
            strcpy(m2, "Texto criptografado");
            break;

        case 2:
            printf("\n\nOpcao escolhida: DESCRIPTOGRAFAR\n\n");
            option_cifra = 2;
            strcpy(m1, "Texto criptografado");
            strcpy(m2, "Texto original");
            break;

        case 3:
            printf("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
            return 0;

    }

    //Tratamento do texto
    do{
        printf("\nDigite o texto: ");
        fgets(texto,128,stdin);

        fflush(stdin);//__fpurge(stdin); //somente no linux

        if(texto[strlen(texto)-1]=='\n'){
            texto[strlen(texto)-1]='\0';
        }
        
        auxiliar = 1;

        if(!strlen(texto)){
            printf("\nNao foi digitado nenhum texto!\n");
            auxiliar = 0;
        }
        else if(strlen(texto) < 4){
            printf("\nO texto deve ter no minimo 4 caracteres!\n");
            auxiliar = 0;
        }
    }
    while(auxiliar == 0);

    //Tratamento da chave
    do{
        printf("\nDigite a chave: ");
        fgets(chave,128,stdin);

        fflush(stdin);//__fpurge(stdin);  //somente no linux

         if(texto[strlen(texto)-1]=='\n'){
            texto[strlen(texto)-1]='\0';
        }

        auxiliar = 1;

        if(!strlen(chave)){
            printf("\nNao foi digitada nenhuma chave!\n");
            auxiliar = 0;
        }
        else if(strlen(chave) < 4){
            printf("\nA chave deve ter no minimo 4 caracteres!\n");
            auxiliar = 0;
        }
    }
    while(auxiliar == 0);
        
        //Cifrar
        cifrar(texto,chave,option_cifra);
        printf("\n\n\n%s: \t%s \n",m1,texto);
        printf("\nChave: \t\t\t%s \n",chave);
        printf("\n%s: \t%s \n",m2,crip);
        printf("\n\n\n");
        getchar();
        printf("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");

    return 0;
}
