#include <stdio.h>

int main(){
FILE *fp;
int c;

fp = fopen("filetext.txt","r");
while(1){
    c = fgetc(fp);
    if (feof(fp)){
    break;
    }
    printf("%c", c);
    }
fclose(fp);

}
