#include <stdio.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	char nome [30];
	float salario;
	int setor;
}tipoFuncionario;

int tamanhoarquivo(FILE *f){
	struct stat buf;
	fstat(fileno(f), &buf);
	return buf.st_size; 
}

void sort(tipoFuncionario v[], int inicio, int fim){
  tipoFuncionario pivot;
  tipoFuncionario temp;
  int i,j;
  i = inicio;
  j = fim;
  pivot = v[(i+j)/2];   
  do{
    	while(strcasecmp(v[i].nome,pivot.nome)<0){
    	i++;
		}
    	while(strcasecmp(v[j].nome,pivot.nome)>0){
    	j--;
    	}
    		if(i<= j) {
      			temp = v[i];
      			v[i] = v[j];
      			v[j] = temp;
      			i++; 
      			j--;
    }

  }while (i<=j);
  		if(inicio < j){
  			sort(v,inicio,j);
  		}
  		if(i < fim){
  		sort(v, i,fim);
  		}
}

void quicksort(tipoFuncionario v[], int n){
	sort(v, 0, n-1);
}

void mostrar (tipoFuncionario vet[], int n){
	int i;
	
	for(i=0; i<n; i++){
		printf("[%s]\n[%2.10f]\n[%d]\n", vet[i].nome, vet[i].salario, vet[i].setor);
	}
	printf("\n");
}


int main() {
	FILE *fo;
	int numelemento;
	tipoFuncionario *x;	

	fo = fopen("arqTeste", "r");
	
	if(fo == NULL){
		printf("erro ao abrir arquivo");	
	}

	else{

	numelemento = tamanhoarquivo(fo)/sizeof(tipoFuncionario);
	
	x = (tipoFuncionario*) malloc(sizeof(tipoFuncionario)*numelemento);

	fread(x,sizeof(tipoFuncionario),numelemento,fo);

	quicksort(x,numelemento);
	
	mostrar(x,numelemento);
	
	}
	
	fclose(fo);
}	
	
	
	 
