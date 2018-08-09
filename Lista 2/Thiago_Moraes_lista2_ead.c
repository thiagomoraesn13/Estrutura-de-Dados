#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define N 3
//THIAGO MORAES
//LISTA2 AED1
typedef struct{ 
	char nome[20];
	char endereco[40];
	int id;
}tipoDado;

typedef struct tipoNo{
   	tipoDado dado;
   	struct tipoNo *prox;             
} tipoNo;

typedef struct {
  	tipoNo *prim;
  	int numElem;
}tipoLista;

typedef struct {
  	tipoNo *prim;
  	tipoNo *ult;
  	int elem;
}tipoFila;

typedef struct {
  	tipoNo *topo;
}tipoPilha;

typedef struct{
	tipoNo *atual;
	int numelem;
}tipolistac;

typedef struct  tiponoint{
	int dado;
	struct tiponoint *prox;
}tiponoint;

typedef struct {
	tiponoint *prim;
	int elementos;
}tipolistaint;

typedef struct {
	tiponoint *topo;
}tipoPilhaint;

typedef struct {
	char nome[50];
}tipodadochar;

typedef struct tipoNochar {
	tipodadochar dado;
	struct tipoNochar *prox;
}tipoNochar;		

typedef struct {
	tipoNochar *prim;
	tipoNochar *ult;
}filachar;

typedef struct {
	int matricula;
	int turma;
	char CPF[12];
	char nome[20];
}tipoAluno;

typedef struct no {
	tipoAluno al;
	int linha, coluna;
	struct no * prox; 
}tipoNo2;

typedef struct {
  tipoNo2 *prim;
} tipoLista2;
//LISTA2 AED1
//THIAGO MORAES 
//questão 1
void criarpilha(tipoPilha *pilha){
	pilha -> topo = NULL;
}
void inserepilha(tipoPilha *pilha, tipoDado dado){
	tipoNo *aux;
	aux = (tipoNo*)malloc(sizeof(tipoNo));
	aux -> dado = dado;
	aux -> prox = pilha -> topo;
	pilha -> topo =  aux; 
}
void removepilha(tipoPilha *pilha){
	tipoNo *aux;
	aux = pilha -> topo;
	pilha -> topo = aux -> prox;
	free(aux);
}
//questao 2
void criarfila(tipoFila *fila){
	fila -> prim = NULL;
	fila -> ult  = NULL;
	fila -> elem = 0;
}
void inserefila(tipoFila *fila, tipoDado dado){
	tipoNo *aux;
	aux = (tipoNo*)malloc(sizeof(tipoNo));
	aux -> dado = dado;
	aux -> prox = NULL;
	if (fila -> prim == NULL){
		fila -> prim = aux;
	}
	else {
		fila -> ult -> prox = aux;
	}
	fila -> ult = aux;	
}
void removeFila(tipoFila *fila) {
      tipoNo *aux;
      aux = fila->prim;  
      fila->prim = aux->prox;
      free(aux);
      if(fila->prim == NULL) { 
		fila->ult = NULL; 
      }   
 }
//questão 3
void criarlistaencadeada(tipolistac *circular){
	circular -> atual = NULL;
	circular ->numelem = 0;
}
void atualiz_atual(tipolistac *circular){
	circular -> atual = circular -> atual -> prox;
}
void inserelistaencadeada(tipolistac *circular, tipoDado d){
	tipoNo *aux, *tmp;
	aux = (tipoNo*) malloc (sizeof(tipoNo));
	aux -> dado = d;
	if(circular -> atual){
		tmp = circular -> atual;
		while (tmp -> prox != circular -> atual){
			tmp = tmp -> prox;
		}
		tmp -> prox = aux;
		aux -> prox = circular -> atual;		
		circular -> atual = aux;		
	}
	else{
		circular -> atual = aux;
		aux -> prox = circular -> atual;				
	}
		circular->numelem++;		
}
void removelistac (tipolistac *circular){
	tipoNo *aux;
	if(circular->atual){
		aux = circular -> atual;
		if(aux -> prox == NULL){
			free(aux);
			circular->atual = NULL;		
		}
		else {
			aux = aux -> prox;
			circular -> atual -> prox = aux -> prox;
			free(aux);
			}

	}
}
//questao 4
int retornaElemDaLista (tipolistac lista, int k){
	tipoNo *aux;
	int cont = 0;
		if(lista.atual != NULL){
			if(lista.atual->dado.id == k){
					cont++;
			}	
		aux = lista.atual->prox;	
			while(aux != lista.atual) { 
				if(aux->dado.id == k){
					cont++;
			}	
			aux = aux -> prox;
			}
		}
			
			return cont;
}
//questão 5
void inserevetorpilha (tipoPilhaint *pilha, int vet[], int n){
	tiponoint *aux;
	int i;	
	for(i=0;i<n; i++){
		aux =(tiponoint*)malloc(sizeof(tiponoint));
		aux -> dado = vet[i];
		aux -> prox = pilha -> topo;
		pilha -> topo = aux; 
	} 
}
//questao 6
void removekelemento (tipolistac *lista, int k){
	tipoNo *tmp, *aux;
	aux = lista->atual;	
	if(lista->numelem >= k){
		k--;
			while(k!=0){
				aux = aux -> prox;
				k--;
			}
		if(aux->prox == lista->atual){
			lista -> atual = lista -> atual -> prox;
		}
		tmp = aux -> prox;
		aux -> prox = tmp -> prox;
		free(tmp);
	}
}
int  verificaSimetrico (tipolistaint lista){
	tiponoint *inicio, *meio, *depois;
	int i;
	int tamanho;
	
	if(lista.elementos){
		meio = lista.prim;
		tamanho = (lista.elementos/2);
		i=0;
		while(i<tamanho){
			meio = meio -> prox;
			i++;
		}
		if(lista.elementos%2==1){
			meio = meio -> prox;
		}
		depois = meio;
		inicio = lista.prim;
		while(i){
			while(depois){
				if(inicio->dado == depois->dado){
					break;
				}
				else {
					if(depois->prox == NULL){
						return 0;
					}
				}
				depois = depois -> prox;
			}
			i--;	
			depois = meio;
			inicio = inicio-> prox; 
		}
		return 1;
	}
	else{
	return 0;
	}
}
//questao 8
void inserelista_vet(tipolistac *lista, tipoDado vet[], int n){
	tipoNo *aux, *tmp;
	aux = lista -> atual;
	int i;
	for(i=0; i< n; i++){
		vet[i] = aux->dado;
		tmp=aux;
		aux = aux -> prox; 
		free(tmp);
		}
		lista->atual =NULL;
}
//questao 9
void imprimir_filachar_inversa (filachar fila){
	tipoNochar *aux;
	if(fila.prim){
		aux = fila.prim;
		fila.prim = fila.prim->prox;
		imprimir_filachar_inversa(fila);
		printf("%s\n", aux->dado.nome);	
	}
}
//questao 10, fiz a função insertion para vetores com tamanho menor que 10, e dentro do quicksorte chamo ela caso,
//o vetor seja menor que 10, e caso seja maior chamo o quicksort.
void insercaonome(tipoDado v[], int tamanho) {
    int i, j;
    tipoDado pivot;
    for(j = 1; j < tamanho; j++ ) {
      i = j -1;
      pivot = v[j];
    while(i>=0) {
      if(v[i].id>pivot.id) {
	v[i+1] = v[i];
      }
      else {
	break;
      }
      i--;
    }
    v[i+1] = pivot;
    }
  }
  void qSort(tipoDado v[], int inicio, int fim) {
  tipoDado pivot;
  tipoDado temp;
  int i,j;
  i = inicio;
  j = fim;
  pivot = v[(i+j)/2];  
  do {
    while(strcasecmp(v[i].nome,pivot.nome)<0)i++;
    while(strcasecmp(v[j].nome,pivot.nome)>0)j--;
    if(i<= j) {
      temp = v[i];
      v[i] = v[j];
      v[j] = temp;
      i++; j--;
    }
  } while (i<=j);
  if(inicio < j) qSort(v,inicio, j);
  if(i < fim) qSort(v, i,fim);
}
void quickSort(tipoDado v[], int n) {
	if(n<10){
		insercaonome(v,n);
	}
	else {
  	qSort(v, 0, n-1);
	}
}
//questão 11
void merge(tipoDado v1[], int n1, tipoDado v2[], int n2, tipoDado v3[]){
  int i= 0, j= 0;
  while((i < n1) && (j < n2) ) {
    if(strcasecmp(v1[i].nome, v2[j].nome) < 0) {
      v3[i+j] = v1[i];
      i++;
    }
    else {
      v3[i+j] = v2[j];
      j++;
    }
  }
  while(j < n2) { v3[i+j] = v2[j];  j++;  }
  while( i < n1) { v3[i+j] = v1[i]; i++; }
}
void mergesort(tipoDado v1[], int i, int f, tipoDado aux[]){
	int meio;
	if(i<f){
		meio = (i+f) / 2;
		mergesort(v1,aux,i,meio);
		mergesort(v1,aux,meio+1,f);
		merge(v1,aux,i,meio,f);
	}
}
//questao12
void qsortid(tipoDado v[], int inicio, int fim) {
  tipoDado pivot;
  tipoDado temp;
  int i,j;
  i = inicio;
  j = fim;
  pivot = v[(i+j)/2];
   do {
    while(v[i].id < pivot.id)i++;
    while(v[j].id > pivot.id)j--;
    if(i<= j) {
      temp = v[i];
      v[i] = v[j];
      v[j] = temp;
      i++; j--;
    }
  }while (i<=j);
  
  if(inicio < j) qsortk(v,inicio, j);
  if(i < fim) qsortk(v, i,fim);
}
void quickSortid( tipoDado v[], int n){
	qsortid(v,0,n-1);
}
//questao 13
void Quick(tipoDado v[], int inicio, int fim, int k) {
  tipoDado pivot;
  tipoDado temp;
  int i,j;
  i = inicio;
  j = fim;
  pivot = v[(i+j)/2];
  do {
    while(pivot > v[i]){
    	i++;
    }
	while(pivot < v[j]){
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
  if(inicio < j ){
		Quick(v,inicio, j,k);
  }
  if(i < k) {
  		Quick(v,i, k,k);
  }
}
void QuickSork(tipoDado v[], int n, int k) {
  Quick(v, 0, n-1, k);
}
//questao 14
void imprimealuno (tipoLista2 *lista, tipoAluno d){
	tipoNo2 *aux;
	aux = lista -> prim;
	while(aux){
		if(aux->al.turma == d.turma){
			printf("%s\n", aux->al.nome);
		}
		aux = aux -> prox;
	}
}
//questao 15:-)
void transfere_ultimo(tipoLista2 *lista){
	tipoNo2 *aux, *tmp;
	aux = lista->prim;
	while(aux->prox->prox){
		aux = aux -> prox;
	}
	tmp = aux;
	aux = aux->prox;
	tmp -> prox = NULL;
	aux -> prox = lista->prim;
	lista->prim = aux;
}
//questao 16
 tipoLista2 listamatriz(tipoAluno matriz[N][N], tipoAluno k){
	tipoLista2 *lista;
	tipoNo2 *aux, *tmp;
	int i;
	int j;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			if(matriz[i][j].turma == k.turma){
			aux =(tipoNo2*)malloc(sizeof(tipoNo2));
			aux -> al = k;
			lista -> prim = aux;
			lista -> prim -> linha = i;
			lista -> prim -> coluna = j;
			}
		}
	}
	tmp = lista -> prim;
	while(tmp){
		printf("%d, %d, %s, %s, \n", tmp -> al.matricula, tmp->al.turma, tmp->al.CPF, tmp->al.nome);
		tmp = tmp -> prox;
	}
}
//questao 17
void transferirElemento(tipoLista2 *lista, tipoAluno M[N][N]){
	tipoNo2 *aux, *tmp;
	int i, j;
	aux = lista -> prim;
	i=aux->linha;
	j=aux->coluna;
	while(aux){
		i=aux->linha;
		j=aux->coluna;
		M[i][j] = aux->al;
		tmp = aux;
		aux = aux -> prox;
		free(tmp);
	}
	lista->prim = NULL;	
}

