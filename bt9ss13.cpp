#include<stdio.h>
#include<math.h>
void nhapMang(int hang, int cot, int mang[hang][cot]);
void inMang(int hang, int cot, int mang[hang][cot]);
void inGoc(int hang, int cot, int mang[hang][cot]);
void inBien(int hang, int cot, int mang[hang][cot]);
void inCheo(int hang, int cot, int mang[hang][cot]);
void soNguyenTo(int hang, int cot, int mang[hang][cot]);
int laNguyenTo(int so);
int main(){
	int hang, cot, choice;
	printf("Nhap so hang: ");
	scanf("%d", &hang);
	printf("Nhap so cot: ");
    scanf("%d", &cot);
    int mang[hang][cot];
do {
	printf("\n************MENU************\n");
	printf("1.Nhap gia tri cac phan tu cua mang.\n");
	printf("2.In gia tri cac phan tu cua mang theo ma tran.\n");
	printf("3.In ra cac phan tu o goc theo ma tran.\n");
	printf("4.In ra cac phan tu nam tren duong bien theo ma tran.\n");
	printf("5.In ra cac phan tu nam tren duong cheo chinh va cheo phu theo ma tran.\n");
	printf("6.In ra cac phan tu la so nguyen to theo ma tran.\n");
	printf("7.Thoat.\n");
	scanf("%d",&choice);
	switch(choice){
		case 1: 
		 	nhapMang(hang, cot, mang); 
			break;
		case 2: 
			inMang(hang, cot, mang);
			break;
		case 3:
			inGoc(hang, cot, mang); 
			break;
		case 4: 
			inBien(hang, cot, mang);
			break;
		case 5: 
			inCheo(hang, cot, mang);
			break;
		case 6: 
			soNguyenTo(hang, cot, mang);
			break;
		case 7: 
			printf("Thoat chuong trinh.\n");
			break;
		default:
			printf("Lua chon khong hop le, vui long lua chon lai.\n")
	}while(choice!=7);
	return 0;
	}
void nhapMang(int hang, int cot,int mang[hang][cot]){
	for(int i=0;i<hang;i++){
		for(int j=0;i<cot;j++){
			printf("Phan tu[%d][%d]: ",i+1,j+1);
			scanf("%d",&mang[i][j]);
			}
		
		}		
	}
void inMang(int hang,int cot,int mang[hang][cot]){
	for(int i=0;i<hang;i++){
		for(int j=0;i<cot;j++){
			printf("%d\t",mang[i][j]);
			}
			printf("\n");
		}
	}
void inGoc(int hang,int cot,int mang[hang][cot]){
	int ketQua[hang][cot];
	for(int i=0;i<hang;i++){
		for(int j=0;i<cot;j++){
			ketQua[i][j]=0;
			}
		}
		ketQua[0][0]=mang[0][0];
		 ketQua[0][cot-1]=mang[0][cot-1];
	    ketQua[hang-1][0]=mang[hang-1][0];
	    ketQua[hang-1][cot-1] =mang[hang-1][cot-1];
	    inMang(hang,cot,ketQua);
	}
void inBien(int hang,int cot,int mang[hang][cot]){
	int ketQua[hang][cot];
	for(int i=0;i<hang;i++){
		for(int j=0;i<cot;j++){
			if(i==0||i==hang-1||j==0||j==cot)
				  ketQua[i][j] = mang[i][j];
				else
				ketQua[i][j] = 0;	
			}
			inMang(hang,cot,ketQua);
		}
	}
void inCheo(int hang,int cot,int mang[hang][cot]){
	int ketQua[hang][cot];
    for (int i = 0; i < hang; i++) {
        for (int j = 0; j < cot; j++) {
            if (laNguyenTo(mang[i][j]))
                ketQua[i][j] = mang[i][j];
            else
                ketQua[i][j] = 0;
        }
    }
    inMang(hang, cot, ketQua);
	}
void soNguyenTo(int so){
	if (so < 2) return 0;
    for (int i = 2; i <= sqrt(so); i++) {
        if (so % i == 0) return 0;
    }
    return 1;
	}
