#include <stdio.h>
//this programm print ASCII code and symbol
int main () {
    for (int i = 32; i<=126; i++) {
        printf("[ASCII] %3d [SYM] %3c\n", i, i);
    }
}