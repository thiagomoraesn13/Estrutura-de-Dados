#include <stdio.h>
#include <string.h>

typedef struct {
  char nome[20];
  char endereco[30];
} tipoDadosDeCadastro;



int buscaSequencial(FILE *fp, char chave[], tipoDadosDeCadastro *r) {
  tipoDadosDeCadastro x;
 
  fseek(fp, 0, SEEK_SET); // move o cursor para o inicio do arquivo
  while(fread(&x,sizeof(tipoDadosDeCadastro),1,fp)) {
    if(strcmp(chave,x.nome) == 0) {
      *r = x;
      return 1;
    }
  }
  return 0;
}



int buscaBinaria(FILE *fp, char chave[], tipoDadosDeCadastro *r) {
  tipoDadosDeCadastro x; 
  int inicio = 0;
  int fim;
   int meio;
  fseek(fp,0, SEEK_END);
  fim = ftell(fp)/sizeof(tipoDadosDeCadastro);
 
  while(inicio <=fim) {

    meio = (inicio+fim)/2;
    fseek(fp, meio*sizeof(tipoDadosDeCadastro), SEEK_SET);
    fread(&x,sizeof(tipoDadosDeCadastro),1,fp);
    if(strcmp(chave,x.nome)> 0) {
      inicio = meio+1;
    }
    else if(strcmp(chave,x.nome)< 0) {
      fim = meio-1;
    }
    else {
      *r = x;
      return 1;
    }
  }
  return 0;
}




int main() {
  FILE *qualquerNome;
  tipoDadosDeCadastro x;
  char nome[20];


  qualquerNome = fopen("dados.dat","r");
 
  printf("Entre com um nome a ser buscado:\n");
  scanf("%s",nome);
  if(buscaBinaria(qualquerNome,nome,&x)) {
      printf("Encontrei!!!!:)\n");
      printf("Nome: %s\n",x.nome);
      printf("Endereco %s\n", x.endereco);
  }
  else {
    printf("pessoa nao encontrada\n");
  }

 fclose(qualquerNome);
}
  
