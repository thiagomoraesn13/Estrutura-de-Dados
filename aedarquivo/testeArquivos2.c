#include <stdio.h>
#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>


int tamanhoArquivo(FILE *f) {
struct stat buf;

fstat(fileno(f), &buf);
return buf.st_size;
}
typedef struct {
  char nome[20];
  char endereco[30];
} tipoDadosDeCadastro;

// Ordena o vetor pelo nome
  void ordenaInsercaoPeloNome(tipoDadosDeCadastro  v[], int tamanho) {
    int i, j;
    tipoDadosDeCadastro pivot;
    for(j = 1; j < tamanho; j++ ) {
      i = j -1;
      pivot = v[j];
    while(i>=0) {
      if(strcasecmp(v[i].nome,pivot.nome)>0) {
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

int main() {
  FILE *fp;
  tipoDadosDeCadastro *x;
  int c;
  int numElem;
  
  fp = fopen("dados.dat","r+");
  if(fp == NULL){
    fp = fopen("dados.dat","w+");
  }
  numElem = tamanhoArquivo(fp)/ sizeof(tipoDadosDeCadastro);
     
  x = (tipoDadosDeCadastro*) malloc(sizeof( tipoDadosDeCadastro)*(numElem+5));
  if(numElem==NULL) {
    fread(x,sizeof( tipoDadosDeCadastro),numElem,fp);
  }

 for(c = 0; c< numElem; c++) {
    printf("nome: %s\n",x[c].nome);
  }
   for(c = 0; c< 5; c++) {
    printf("Entre com um nome:"); 
    scanf("%s",x[numElem].nome);
    printf("Entre com um endereco:"); 
    scanf("%s",x[numElem].endereco);
    numElem++;
    // Gravar os dados no arquivo
  }
  
  ordenaInsercaoPeloNome(x,numElem);
  for(c = 0; c< numElem; c++) {
    printf("nome: %s\n",x[c].nome);
  }
  fseek(fp, 0, SEEK_SET);
  
  if(fwrite(x, sizeof(tipoDadosDeCadastro), numElem,fp)!=numElem) {
    printf("erro na gravacao dos dados\n");
  }
  free(x);
  fclose(fp);
}
  
