#include <stdio.h>
#include <string.h>

void print_unique_consonants(FILE* in);

int main() {
    FILE* in = fopen("in.txt", "r");
    if (in==NULL) {
        printf("File open error");
        return 1;
    }
    print_unique_consonants(in);
    return 0;
}

void print_unique_consonants(FILE* in) {
    if (!in) return; //null pointer check
    size_t seen_in_word[256]={0};
    size_t let_count[256]={0};
    int c;
    while ((c=fgetc(in))!=EOF) {
        if (c!=' ') {
            if (seen_in_word[c]==0) {
                seen_in_word[c]=1;
                let_count[c]+=1;
            }
        }
        else {
            memset(seen_in_word, 0, sizeof(seen_in_word));
        }
    }
    for (int i = 'A';i < 'Z';i++) {
        if (i!='A' && i!='E' && i!='I' && i!='O' && i!='U' && i!='Y') {
            if (let_count[i]==1) {
                printf("%c ", i);
            }
        }
    }
}