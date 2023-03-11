#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void caso1();
void caso2();

int main (){
    
    int z = 0;
    do{
        printf("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
        printf("\n\n..:: GERADOR E VERIFICADOR DE CODIGO DE HAMMING ::..\n\n");
        printf("Digite a opcao desejada:\n\n");
        printf("1) Enviar um grupo de bits\n\n");
        printf("2) Verificar um grupo de bits recebido\n\n");
        printf("3) Para encerrar o programa\n\n");
        printf("Option: ");
        scanf("%d", &z);
        
        switch (z){

            case 1 :
            caso1();
            break;
            
            case 2 :
            caso2();
            break;

        }
    }while(z != 3);

 printf("\nXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
 return 0;
}

void caso1(){

    int n_bit_dado, n_um=2, n_bit_total;
    float resto;

    printf("\nDigite a quantidade de bits do grupo original (quantidade > 0): ");
    scanf("%d", &n_bit_dado);
    
    int original[n_bit_dado+1];
       
    for(n_bit_total=3; n_um<=n_bit_dado; n_bit_total++){

        n_um++;
        resto=log(n_bit_total+1)/log(2);

        resto = resto - (int)resto;
        
        if(resto==0)
        {
            n_um--;
        }
    }

    resto=log(n_bit_dado+1)/log(2);
    resto = resto - (int)resto;
    int paridade[n_bit_total];
    
    for(int m=0; m<n_bit_dado; m++){

        do{

            printf("\nDigite o dado %d: ", m+1);
            scanf("%d", &original[m]);
        }while(original[m]!=0 && original[m]!=1);
    }
    
    printf("\nDados Originais: ");
    for(int j=0; j<n_bit_dado; j++){

        printf("%d", original[j] );
    }

    int controller = 0;
    
    for(int j=1; j<=n_bit_total; j++){

        resto=log(j)/log(2);
        resto = resto - (int)resto;

        if(resto == 0){

            paridade[j-1]=0;
        }
        else{

            paridade[j-1]=original[controller];
            controller++;
        }            
    }
    
    for(int j=1; j<=n_bit_total; j++){
        
        resto=log(j)/log(2);
       
        if(resto - (int)resto == 0){
            n_um = 0;
            controller=0;
            
            for(int i=j-1; i<n_bit_total; i++){

                if(paridade[i] == 1){

                    n_um++;
                }
                
                if(controller==j-1){

                    controller=0;
                    i=i+j;
                }
                else{
                    controller++;
                }
            }
            
            if(n_um%2!=0){

                paridade[j-1] = 1;
            }
        }
    }

    printf("\n\nDados que serão enviados: ");
    for(int j=0; j<n_bit_total; j++){

        printf("%d", paridade[j]);
    }
    printf("\n\n");
}

void caso2()
{
    int n_um=0, n_bit_total=0, controller=0, bit_erro=0;
    float resto;

    printf("\nDigite a quantidade de bits total (quantidade > 0): ");
    scanf("%d", &n_bit_total);
    
    int original[n_bit_total+1];
    int novo[n_bit_total+1];
    
    for(int m=0; m<n_bit_total; m++){

        do{

            printf("\nDigite o dado %d: ", m+1);
            scanf("%d", &original[m]);
        }while(original[m]!=0 && original[m]!=1);
    }
    
    for(int j=1; j<=n_bit_total; j++){

        resto=log(j)/log(2);
        resto = resto - (int)resto;

        if(resto == 0){

            novo[j-1]=0;
        }
        else{

            novo[j-1]=original[j-1];
        }            
    }
    
    for(int j=1; j<=n_bit_total; j++){

        resto=log(j)/log(2);
       
        if(resto - (int)resto == 0){

            n_um = 0;
            controller=0;
            
            for(int i=j-1; i<n_bit_total; i++){

                if(novo[i] == 1){

                    n_um++;
                }
                
                if(controller==j-1){

                    controller=0;
                    i=i+j;
                }
                else{

                    controller++;
                }
            }
            
            if(n_um%2==0){

                novo[j-1] = 0;
            }
            else{

                novo[j-1] = 1;
            }
            
            if(novo[j-1] != original[j-1]){

                printf("\n%d\n", j);
                bit_erro = bit_erro + j;
            }
        }
    }
    
    if(bit_erro!=0){

        printf("\nFoi detectado um erro no bit nº %d do grupo: ", bit_erro);
        for(int i=0; i<n_bit_total; i++){

           printf("%d", original[i]);
        }
        
        if(original[bit_erro-1]==1){

           original[bit_erro-1]=0; 
        }
        else{

            original[bit_erro-1]=1; 
        }
    }
    
    printf("\n\nGrupo de bits finais com o bit corrigido: ");
        
    for(int i=1; i<=n_bit_total; i++){

        resto=log(i)/log(2);
        
        if(resto - (int)resto != 0){

            printf("%d", original[i-1]);
        }  
    }
    printf("\n\n");
}