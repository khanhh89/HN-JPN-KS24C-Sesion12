#include<stdio.h>
void nhapMang(int arr[], int *n);
void inMang(int arr[], int n);
void themPhanTu(int arr[], int *n);
void suaPhanTu(int arr[], int n);
void xoaPhanTu(int arr[], int *n);
void sapXepMang(int arr[], int n, int tangDan);
void timKiemTuyenTinh(int arr[], int n);
void timKiemNhiPhan(int arr[], int n);

int main() {
    int arr[MAX], n = 0, choice, subChoice;
    do {
        printf("\n1.Nhap gia tri\n2.In gia tri\n3.Them phan tu\n4.Sua phan tu\n5.Xoa phan tu\n6.Sap xep\n7.Tim kiem\n8.Thoat\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1: nhapMang(arr, &n); break;
            case 2: inMang(arr, n); break;
            case 3: themPhanTu(arr, &n); break;
            case 4: suaPhanTu(arr, n); break;
            case 5: xoaPhanTu(arr, &n); break;
            case 6:
                printf("1.Tang dan\n2.Giam dan\n");
                scanf("%d", &subChoice);
                sapXepMang(arr, n, subChoice == 1);
                break;
            case 7:
                printf("1.Tuyen tinh\n2.Nhi phan\n");
                scanf("%d", &subChoice);
                if (subChoice == 1) timKiemTuyenTinh(arr, n);
                else if (subChoice == 2) {
                    sapXepMang(arr, n, 1);
                    timKiemNhiPhan(arr, n);
                }
                break;
            case 8: break;
            default: printf("Lua chon khong hop le\n");
        }
    } while (choice != 8);
    return 0;
}
void nhapMang(int arr[], int *n) {
    printf("Nhap so phan tu can nhap (toi da %d): ", MAX);
    scanf("%d", n);
    if (*n > MAX) *n = MAX;
    for (int i = 0; i < *n; i++) {
        printf("Nhap phan tu arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }
}
void inMang(int arr[], int n) {
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}
void themPhanTu(int arr[], int *n) {
    int viTri, giaTri;
    if (*n >= MAX) return;
    printf("Nhap vi tri can them (0-%d): ", *n);
    scanf("%d", &viTri);
    if (viTri < 0 || viTri > *n) return;
    printf("Nhap gia tri can them: ");
    scanf("%d", &giaTri);
    for (int i = *n; i > viTri; i--) arr[i] = arr[i - 1];
    arr[viTri] = giaTri;
    (*n)++;
}
void suaPhanTu(int arr[], int n) {
    int viTri, giaTri;
    printf("Nhap vi tri can sua (0-%d): ", n - 1);
    scanf("%d", &viTri);
    if (viTri < 0 || viTri >= n) return;
    printf("Nhap gia tri moi: ");
    scanf("%d", &giaTri);
    arr[viTri] = giaTri;
}
void xoaPhanTu(int arr[], int *n) {
    int viTri;
    printf("Nhap vi tri can xoa (0-%d): ", *n - 1);
    scanf("%d", &viTri);
    if (viTri < 0 || viTri >= *n) return;
    for (int i = viTri; i < *n - 1; i++) arr[i] = arr[i + 1];
    (*n)--;
}
void sapXepMang(int arr[], int n, int tangDan) {
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if ((tangDan && arr[i] > arr[j]) || (!tangDan && arr[i] < arr[j])) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
}
void timKiemTuyenTinh(int arr[], int n) {
    int giaTri, found = 0;
    printf("Nhap gia tri can tim: ");
    scanf("%d", &giaTri);
    for (int i = 0; i < n; i++) {
        if (arr[i] == giaTri) {
            printf("Gia tri %d o vi tri %d\n", giaTri, i);
            found = 1;
        }
    }
    if (!found) printf("Khong tim thay %d\n", giaTri);
}
void timKiemNhiPhan(int arr[], int n) {
    int giaTri, left = 0, right = n - 1, mid;
    printf("Nhap gia tri can tim: ");
    scanf("%d", &giaTri);
    while (left <= right) {
        mid = (left + right) / 2;
        if (arr[mid] == giaTri) {
            printf("Gia tri %d o vi tri %d\n", giaTri, mid);
            return;
        } else if (arr[mid] < giaTri) left = mid + 1;
        else right = mid - 1;
    }
    printf("Khong tim thay %d\n", giaTri);
}
