#include<stdio.h>
int numberMax(int arr[],int n);
int main(){
	int n;
	printf("Nhap so luong cac phan tu cua mang: ");
	scanf("%d",&n);
	int arr[n];
	printf("Nhap cac phan tu cua mang:\n");
	for(int i=0;i<n;i++){
		printf("Phan tu thu %d la: ",i+1);
		scanf("%d",&arr[i]);
		}
	printf("Phan tu lon nhat trong mang vua nhap la: %d\n",numberMax(arr,n));	
	return 0;
	}
	int numberMax(int arr[],int n){
		int max=arr[0];
		for(int i=1;i<n;i++){
			if(arr[i]>max){
				max=arr[i];
			}
		}
	return max;
}
