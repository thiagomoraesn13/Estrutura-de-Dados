#include <stdio.h>

int main(int argc, char *argv[]){
FILE * fd, *fo;
char str;
char vet[15];
vet[14]=0;
int cont = 0;
int pos =0;

fo = fopen("arqidx", "w");
fd = fopen("arqteste", "r");
if (fd==NULL){
	printf("Erro ao abrir o arquivo");
}
 else{
  fwrite(&pos,sizeof(int), 1, fo);
   while(!feof(fd)){
     while ((str = fgetc(fd)) && (cont != 2) && (!feof(fd))) {
       while ((str != ':') && (!feof(fd))) {
	 str = fgetc(fd);
       }
       cont++;
     }     
     cont = 0;
     if(!feof(fd)) {  // so mostra o CPF se nao acabou o arquivo!
       fseek(fd,-1, SEEK_CUR);
       fgets(vet, 15, fd);
       pos=ftell(fd);
	     fwrite(&pos,sizeof(int), 1, fo);
	   }
   }
 }
 fclose(fd);
 fclose(fo);
}










