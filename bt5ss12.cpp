#include<stdio.h>
int checkSoNguyenTo(int n);
int main(){
	int a,b;
	printf("Nhap vao hai so nguyen:\n");
	printf("Nhap vao so thu nhat: ");
	scanf("%d",&a);
	printf("Nhap cao so nguyen thu hai: ");
	scanf("%d",&b);
	if(checkSoNguyenTo(a)){
		printf("%d la so nguyen to\n",a);
	}else{
		printf("%d khong phai la so nguyen to.\n",a);
	}
	if(checkSoNguyenTo(b)){
		printf("%d la so nguyen to.\n",b);
		}else{
			printf("%d khong phai la so nguyen to.\n",b);
		}
	return 0;	
}

checkSoNguyenTo(int n){
	if(n<=1){
		return 0;
		}
	for(int i=2;i*i<=n;i++){
		if(n%2==0){
			return 0;
	}
}
return 1;
}

