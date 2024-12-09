#include<stdio.h>
#include<math.h>
int sumNumber(int number1,int number2){
	return number1+number2;
}
int main(){
	int number1, number2;
		printf("Tinh tong hai so.\n");
		printf("Nhap so thu nhat: ");
	    scanf("%d", &number1);
	    printf("Nhap so thu hai: ");
	    scanf("%d", &number2);
		printf("Tong cua 2 so la: %d",sumNumber(number1,number2));
	return 0;
}
