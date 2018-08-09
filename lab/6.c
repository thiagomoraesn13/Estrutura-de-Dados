#include <stdio.h>

void diminuir_nota (FILE *fo, int k){
tipoAluno tmp;

//FUNCAO PRA DIMINUUIR NOTA DO K-ÉZIMO//

fseek(fo,k*sizeof(tipoAluno, SEEK_SET);

	if(fread(&tmp,sizeof(tipoAluno),1,fo)){
		tmp.nota = tmp.nota -2.0; 
		fseek(fo, -sizeof(tipoAluno), SEEK_CUR);
		fwrite(&tmp, sizeof(tipoAluno), 1,fo);
	}
}


int aprovado (FILE *fo){
//funcao pra retornar nota dos aprovados//

fseek(fo,0, SEEK_SET);//garantir que estou no inicio//

	while(fread(&tmp,sizeof(tipoAluno),1,fo)==1){
		if(tmp.nota>=7.0){
		cont++;
		}
	return cont;
}


//faca uma questao que atualize a note de um aluno//

