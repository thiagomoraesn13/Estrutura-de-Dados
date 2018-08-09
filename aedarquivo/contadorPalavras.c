#include <stdio.h>



int eDelimitador(char ch) {
  
  if((ch >= 'A') && (ch <= 'Z')) {
    return 0;
  } 
  else  if((ch >= 'a') && (ch <= 'z')) {
    return 0;
  } 
  else if(ch == 0) { 
    return 0;
  }
  else if((ch >= '0') && (ch <= '9')) {
    return 0;
  }
  return 1;
}

/* Versao para contar palavras igual ao comando wc do linux. Aqui apenas os três simbolos abaixo são considerados separadores.*/

/*
int eDelimitador(char ch) {

  if((ch == ' ') || (ch == '\t') || (ch == '\n')) return 1;
  return 0;
}
*/

int contaPalavras( char *str) {
  int cont = 0;
  
  while(*str) {
    while(eDelimitador(*str)) str++;
    if(*str) {
      cont++;
      while(!eDelimitador(*str) && *str) {
	str++;
      }
    }
  }
  return cont;
}


int main(int argc, char *argv[]) {
  FILE *f;
  char linha[1000];
  int cont = 0;
  int contP = 0;
  
  f = fopen(argv[1],"r");

  if (f) {
    while(fgets(linha,1000, f)) {
      cont++;
      printf("%03d: %s",cont, linha);
      contP= contP+ contaPalavras(linha);
      
    }
  }
  printf("O numero de palavras é %d\n",contP);
}
