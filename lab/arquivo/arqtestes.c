#include <stdio.h>
#include <string.h>

void main() {
FILE *arquivo;
int i=0, cont=0;
char c;

arquivo = fopen("arqteste", "r");

do {
    c = fgetc(arquivo);
    if (c == ':'){
        i++;
        if (i == 2) {
            while (cont < 14){
            c = fgetc(arquivo);
            printf("%c", c);
            cont++;
            }
        printf("\n");
        cont = 0;
        i = 0;
        }
    }
}
while (c != EOF);
}


