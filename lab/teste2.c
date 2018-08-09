#include <stdio.h>

int main(){
	FILE *endereco, *procura;
	int pos,posseguinte,x;
	char buf[500];

	endereco = fopen("arqteste", "r");
	procura = fopen("arqidx", "r");

	printf("digite um número de registro:\n");
	scanf("%d", &x);
	fseek(procura, x*sizeof(int), SEEK_SET);
	fread(&pos,sizeof(int),1,procura);
	fread(&posseguinte,sizeof(int),1,procura); 

	fseek(endereco,pos,SEEK_SET);

	fread(buf,sizeof(int),posseguinte-pos,endereco);

	buf[posseguinte-pos] = 0;

	printf("%s", buf);

	printf("\n");

	fclose(endereco);
	fclose(procura);
}