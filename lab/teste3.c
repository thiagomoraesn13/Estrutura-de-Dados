#include <stdio.h>

int main() {
	int cont=0;
	char str;
	char vetor[15];
	vetor [14] = 0;
	FILE *fp;



	fp =fopen("arqteste", "r");

	if(fp == NULL){
		printf("erro ao abrir arquivo\n");
	}
	else{
		while(!feof(fp)){
			while((str =fgetc(fp)) && (cont !=2) && (!feof(fp))){
				while((str !=':') && (!feof(fp))){
				str = fgetc(fp);
			}
			cont ++;
			}	
			cont = 0;
			if(!feof(fp)){
				fseek(fp, -1, SEEK_CUR);
				fgets(vetor,15,fp);
				printf("%s\n",vetor);

			}
		}	
	}
	
	fclose(fp);
}