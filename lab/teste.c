#include <stdio.h>

void main(){
FILE *ender,*procura;
int c;
int pos, poseguinte;
char buf[500];

ender = fopen("arqteste","r");
procura = fopen("arqidx","r");

printf("Entre com o número do registro: \n");
scanf("%d",&c);
fseek(procura,c*sizeof(int),SEEK_SET);
fread(&pos,sizeof(int),1,procura);
fread(&poseguinte,sizeof(int),1,procura);
fseek(ender,pos,SEEK_SET);
fread(buf,sizeof(int),poseguinte-pos,ender);
buf[poseguinte-pos] = 0;
printf("%s", buf);
printf("\n");

fclose(ender);
fclose(procura);
}
