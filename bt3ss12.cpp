#include<stdio.h>
long long tinhGiaiThua(int n);
int main(){
	int n;
	printf("Nhap vao mot so nguyen: ");
	scanf("%d",&n);
	if(n<0){
			printf("Khong tinh duoc giai thua cua so nguyen am.");
		}else{
		printf("Giai thua cua %d la: %lld\n", n, tinhGiaiThua(n));
		}
		return 0;
	}
	long long tinhGiaiThua(int n) {
    if (n==0||n==1){
        return 1;
    }
	long long giaiThua = 1;
    for (int i = 2; i <= n; i++) {
        giaiThua *= i;
    }

    return giaiThua;
}
