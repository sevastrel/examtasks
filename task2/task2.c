#include <stdio.h>

void cezar(int n, FILE* in,FILE* out);

int main() {
    printf("%d\n",-107%26);
    FILE* in = fopen("in.txt","r");
    FILE* out = fopen("out1.txt","w+");
    char a[50];
    char b[50];
    // fscanf(in,"%s", a);
    cezar(3,in,out);
    fseek(out,0,SEEK_SET);
    fscanf(out,"%s", b);
    // fclose(out);
    // printf("%s",a);
    printf("%s",b);
}

void cezar(int n, FILE* in, FILE* out) {
    int sym;
    while((sym=fgetc(in))!=EOF) {
        if (sym>='A' && sym<='Z') {
            sym=((sym-'A'+(n%26+26))%26)+'A';
        }
        else if (sym>='a' && sym<='z') {
            sym=((sym-'a'+(n%26+26))%26)+'a';
        }
        fputc(sym,out);
        // printf("%c",sym);
    }
}