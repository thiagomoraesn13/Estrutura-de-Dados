#include <stdio.h>
//questao 1
int fatorial(int n)
{
int fat=1;
	if (n<=0){
 	return 1;
	}
	while (n>1){
        fat = (fat * n);
	n = n - 1;	
	}
	return fat;
}
//questao 2
void modificavetor ( int vet[], int n)
{
	int i;

	for(i=0; i<=n; i++)
	{
	if (vet[i] <=0){
	vet[i] = -2;
	}
	else if((vet[i] >= 1) && (vet[i] <= 5))
	{
	vet[i] = -1;
	}	
	else 
	{
	vet[i] = 0;
	}
	
	}
	
}
//questao 3
void inverte (int vet[], int tamanho)
{
	int i=0
	int j= tamanho - 1;
	int aux;
	
		while(i < j)
		{
			aux    = vet[i];
			vet[i] = vet[j];
			vet[j] = aux;
			i++;
			j--;
		}
}
			

//questao 4
int buscastring(char vet [40], char chave[4])
{	
	int x;
		for(x=0; x<40-4; x++)
		{
		if((chave[0]==vet[x]) && (chave[1]==vet[x+1]) 
		&& (chave[2] == vet[x+2]) && (chave[3]==vet[x+3]))
		{		
		printf("verdadeiro\n");
					return 1;
		}
		}
		 
		printf("falso\n");
		return 0;
	
}
//questao 5

int checaordena(int v[], int n)
{
	int i;
	for(i=0;i<=n-2;i++)
	{
		if(v[i] > v[i+1])
			{
				return 0;
			}
	}
	return 1;
}
//questao 6

QUESTAO 6;

void ordena_insercao (int vet[], int n)
 {
	 int i,j,aux;
	 i=1;
	 while(i<n)
	{
		aux=vet[i];
		j=i-1;
		i=i+1;
		while((j>=0) && (aux <vet[j]))
		{
			vet[j+1]=vet[j];
			j--;
		}
		vet[j+1]=aux;
	}
	
//questao 7
int quadrado (int n)
{
	int soma=0;
	while(n>0)
	{
	soma = soma + (n*n);
	n--;
    }
    return soma;
}
// questao 8    

int verifica_letra(char nome[], int n, char chave)
{
	int x, cont;
	for(x=o;x<n;x++)
	{
		if((nome[i]==chave)||(((nome[i])-32)==chave)
		||(nome[i]==((chave)-32))){
			cont++;
		}
	}
	return cont;
}
// questao 9
int palindrome (char str[], int n)
{
	
	int i=0;
	int j = n-1;
	while(i<j)
	{ 
		if(str[i] != str[j])
		
		{
			return 0;
		}
			i++;
			j--;	
		
	}
	return 1;
}

//questao 10

int buscabinaria (int vet[], int n, int  chave)
{
	int cont=0;
	int inicio;
	int meio;
	int fim;
	inicio = 0;
	fim = n-1;
	while(inicio<=fim)
	{
		meio = (inicio +fim) / 2;
		if(vet[medio] == chave)
		{
			cont = cont+1;
			return cont;
		}
			else if (vet[meio]< chave)
			{
				cont = cont +1;
				fim = meio -1;
				return con;t 
			}
		  return 1;
	  }
}

//questao 11
int substituir(int vet[], int n, int delta)
{	
	int x, aux;
	for(x=o; x<n; x++)
	{
		vet[x]= vet[x] - delta;
	}
}
//questao 12
void substitui(int vet[], int n)
{
	int i;
	for(i=0; i<n; i++)
	{
	    vet[i+1] = vet[i+2] - vet[+1];
	}
}
//questao 13
void desubstituir(int vet[], int n)
{
	int i;
	for(i=0; i<n; i++)
	{
		
	    vet[i+1] = vet[i+2] - vet[+1];
	}
}
// questao 14
QUESTAO 14;

int busca(int vet[0,3,12,25,20,25,40,50,55,90,95,99], int n, int chave)
{
	int i;
	int meio;
	int fim;
	int inicio;
	inicio = 0;
	fim = n-1;
	while(e <= fim)
	{
	meio= (inicio + fim)/2;
	
		if(vet[meio] == chave){
			
			
		return meio;
	
	}
	if (vet[meio] < chave){
		inicio = meio + 1;
		{
			else {
				fim= meio -1;
			}
			return 1
		}
/*Seriam comparados os elementos  de posicão vet[i] e vet[i+1] para a chave 4
e para chave 55 seriam os elementos de posição 0 até a posição 6.*/

// questao 15
#define N 3
int matriz (int vet[N][N], int k)
{
	int cont =0;
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(vet[i][j] == k){
				cont++;
			}
		}
		}
		
		if(cont==4){
			return 1;
		}
		return 0;
	}


//questao 16

#define N 
int matriz(int vet[N][N])
{
int i;
	int maior= vet[0][0];
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			if(vet[i][j] > maior){
				maior = vet[i][j];
			}
		}
	}
	return maior;
}
  	 
//questao 17

int somadiagonal(int vetor[N][N]){
	
	int i,j;
	int soma = 0;
	
	for(i = 0,j = N-1; i < N; i++,j--){
			soma = soma + vetor[i][j];		
			
	}
	
	return soma;
}
	
//questao 18

#include <math.h>

 float desvio (int vet[], int n)
{
	float media = 0.0;
	float desviop=0.0;
	int i;
	for(i=0; i<n;i++){
	media = media + vet[i];
	}
	media = (media) / n;
	for(i=0;i<n;i++){
	desviop = desviop + (vet[i]- media)*(vet[i]- media);
	}
	desviop = (desviop/n);
	desviop = sqrt(desviop);

	return desviop;
}
int main()
{
	int n;
	scanf("%d", &n);
	int v[n];
	desvio(v,n);
	}



/*void ler_matriz(int matriz[N][N]){
	int i,j;
	for(i=0;i<N;i++){
		scanf("%d",&matriz[i][j]);
		for(j=0;j<N;j++){
			scanf("%d",&matriz[i][j]);
		}
		printf("%d", matriz[i][j]);
	}
	printf("\n");
	
	
}


void mostrar_matriz(int matriz[N][N]){
	int i, j;
	for(i=0;i<N;i++){
		printf("%d", matriz[i][0]);
		for(j=0;j<N;j++){
			printf("%d", matriz[0][j]);
			printf("\t");
		}
		printf("\n");
	}
	printf("\n");
}
*/



 
	





























		 
	

	
		


 

