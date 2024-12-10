#include<stdio.h>
#include<stdlib.h>
int** taoMaTran(int soHang, int soCot);
void inMaTran(int** maTran, int soHang, int soCot);
void giaiPhongMaTran(int** maTran, int soHang);
int main() {
    int soHang, soCot;
    printf("Nhap so hang: ");
    scanf("%d", &soHang);
    printf("Nhap so cot: ");
    scanf("%d", &soCot);
    int** maTran = taoMaTran(soHang, soCot);
    inMaTran(maTran, soHang, soCot);
    giaiPhongMaTran(maTran, soHang);
    return 0;
}
int** taoMaTran(int soHang, int soCot){
    int** maTran = (int**)malloc(soHang * sizeof(int*));
    for (int i = 0; i < soHang; i++) {
        maTran[i] = (int*)malloc(soCot * sizeof(int));
    }
    printf("Nhap gia tri cho ma tran (%dx%d):\n", soHang, soCot);
    for (int i = 0; i < soHang; i++) {
        for (int j = 0; j<soCot; j++) {
            printf("Nhap phan tu [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &maTran[i][j]);
        }
    }
    return maTran;
}
void inMaTran(int** maTran, int soHang, int soCot){
    printf("Ma tran la:\n");
    for (int i = 0; i < soHang; i++) {
        for (int j = 0; j < soCot; j++) {
            printf("%d\t", maTran[i][j]);
        }
        printf("\n");
    }
}
void giaiPhongMaTran(int** maTran, int soHang){
    for (int i = 0; i < soHang; i++) {
        free(maTran[i]);
    }
    free(maTran);
}
