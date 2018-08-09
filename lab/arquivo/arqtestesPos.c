#include <stdio.h>
#include <string.h>

void main() {
FILE *arquivo, *enderecos;
int i=0, cont=0;
char c;
int x=0;


arquivo = fopen("arqteste", "r");
enderecos = fopen("endRegistro", "w");

fwrite(&x,sizeof(int),1,enderecos);
do {
    c = fgetc(arquivo);
    if (c == ':'){
        i++;
        if (i == 2) {
            while (cont < 14){
            c = fgetc(arquivo);
            cont++;
            }
        x = ftell(arquivo);
        fwrite(&x,sizeof(int),1,enderecos);
        cont = 0;
        i = 0;
        }
    }
}
while (c != EOF);
fclose(arquivo);
fclose(enderecos);
}


