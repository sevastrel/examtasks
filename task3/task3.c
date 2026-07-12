#include <stdio.h>

void printf_matrix(int i,int j, double A[i][j]);
void mul(int x_degA, int y_degA, int x_degB, int y_degB, double A[x_degA][y_degA], double B[x_degB][y_degB], double C[x_degA+x_degB][y_degA+y_degB]);
int main() {
    double A[4][4]={1,3,5,0};
    double B[4][4]={0,2,11,1};
    double C[4][4]={0};
    mul(2,2,2,2,A,B,C);
    printf_matrix( 2, 2, A);
    printf_matrix( 2, 2, B);
    printf_matrix( 4, 4, C);


}
void mul(int x_degA, int y_degA, int x_degB, int y_degB, double A[x_degA][y_degA], double B[x_degB][y_degB], double C[x_degA+x_degB][y_degA+y_degB]) {
    for (int i=0; i<x_degA;i++) {
        for (int j=0; j<y_degA;j++) {
            if (A[i][j]==0.0) continue;
              for (int k=0; k<x_degB;k++) {
                for (int m=0; m<y_degB;m++) {
                    C[i+k][j+m]+=(A[i][j])*(B[k][m]);
                }
            }
        }
    }
}

void printf_matrix(int i,int j, double A[i][j]) {
    printf("\n");
    for (int k=0; k<i;k++) {
        printf("\n");
        for (int m=0; m<j; m++) {
            printf("%.0f ", A[k][m]);
        }
    }
    printf("\n");
}