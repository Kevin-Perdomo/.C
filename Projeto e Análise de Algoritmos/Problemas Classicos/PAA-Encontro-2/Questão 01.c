#include <stdio.h>
#define N 2

void somatoria1(int matriz[N][N]){
	int s=0;
	for(int i=0; i < N; i++){
		for(int j=0; j < N; j++){
			s = s + matriz[i][j];
			printf("%d\n", s);
		}
	}	
	printf("O resultado final é: %d\n", s);
}

void somatoria2(int matriz[N][N]){
	int s=0;
	for(int i=0; i < N; i++){
		for(int j=0; j < N; j++){
			s = s + matriz[j][i];
			printf("%d\n", s);
		}
	}
	printf("O resultado final é: %d\n", s);	
}

void somatoria3(int matriz[N][N]){
	int s=0;
	for(int i=0; i < N; i++){
		for(int j=0; j < N; j++){
			if(i != j){
				s = s + matriz[i][j];	
			}
			printf("%d\n", s);
		}
	}
	printf("O resultado final é: %d\n", s);	
}

void somatoria4(int matriz[N][N]){
	int s=0;
	for(int i=0; i < N; i++){
		for(int j=0; j < N; j++){
			if(i == j){
				s = s + matriz[j][i];	
			}
			printf("%d\n", s);
		}
	}
	printf("O resultado final é: %d\n", s);	
}

void somatoria5(int matriz[N][N]){
	int s=0;
	for(int i=0; i < N; i++){
		for(int j=0; j < N; j++){
			if(i < j){
				s = s + matriz[i][j];	
			}
			printf("%d\n", s);
		}
	}
	printf("O resultado final é: %d\n", s);	
}

void somatoria6(int matriz[N][N]){
	int s=0;
	for(int i=0; i < N; i++){
		for(int j=0; j < N; j++){
			if(i > j){
				s = s + matriz[i][j];	
			}
			printf("%d\n", s);
		}
	}
	printf("O resultado final é: %d\n", s);	
}

void somatoria7(int matriz[N][N]){
	int s=0;
	for(int i=0; i < N; i++){
		for(int j=0; j < N; j++){
			if(i < j){
				s = s + (matriz[i][j] * matriz[j][i]);	
			}
			printf("%d\n", s);
		}
	}
	printf("O resultado final é: %d\n", s);	
}

void somatoria8(int matriz[N][N], int x){
	int s=0;
	for(int i=0; i < N; i++){
		for(int j=0; j < N; j++){
			s = s + matriz[i][j];
			printf("%d\n", s);
		}
	}
	s= s * x;	
	printf("O resultado final é: %d\n", s);
}


int main(){

	int matriz[N][N], i, j, x;

	for(i=0; i < N; i++){
		for(j=0; j < N; j++){
			printf("Digite um numero: ");
			scanf("%d",&matriz[i][j]);
		}
	}
	printf("\nDigite um numero para X: ");
	scanf("%d",&x);

	somatoria8(matriz,x);	

}