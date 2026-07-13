#include <stdio.h>
#include <string.h>

int convert(int* a, int len_a, int k);
int sum(int* a, size_t len_a, int* b, size_t len_b, int k);

int main() {
    int a[5]={1};
    int b[5]={1};
    int summary=sum(a,1,b,1,2);
    printf("%d",summary);
    return 0;
}

int sum(int* a, size_t len_a, int* b, size_t len_b, int k) {
    int new_a = convert(a,len_a,k);
    int new_b = convert(b,len_b,k);
    int result = new_a + new_b;
    return result;  
}

int convert(int* a, int len_a, int k) {
    int result = 0;
    int degree = 1;
    for (size_t i=1; i<=len_a; i++) {
        result+=a[len_a-i]*degree;
        degree=degree*k;
    }
    return result;
}