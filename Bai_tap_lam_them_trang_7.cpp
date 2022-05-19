#include <stdio.h>
#include <windows.h>

void inArray(float *arr, int n);
void outArray(float *arr, int n);
void swap(float &a, float &b);
void tim_so_duong(float *arr, int n);
void quickSort_T(float *arr, int left, int right);
void quickSort_G(float *arr, int left, int right);
void sap_xep(float *arr, int n, int left, int right);
void mang_con_tang_dan(float *arr, int n);
int KT_mang_con(float *arr, int i, int &dem);
void menu(float *arr, int n);

int main()
{
	int n; 
	printf("nhap kich thuoc n "); 
	scanf("%d", &n);
	float arr[n];
	menu(arr, n);
}
void menu(float *arr, int n)
{
	int KT = true;
	while (KT)
	{
		printf("\n 1. Nhap mang va xuat mang");
		printf("\n 2. tim so duong nho nhat");
		printf("\n 3. sap xep mang so chan tang dan o dau va so le giam dan o cuoi");
		printf("\n 4. dem so mang con trong mang");
		printf("\n 5. lam sach cua so");
		printf("\n 0. thoat");
		printf("\n  moi nhap yeu cau ? ");
	int lc; scanf("%d", &lc);
		switch (lc)
		{
			case 1:
				inArray(arr, n);
				printf("\n");
				break;
			case 2: 
				tim_so_duong(arr, n);
				printf("\n");
				break;
			case 3: 
				sap_xep(arr, n, 1, n);
				printf("\n");
				break;
			case 4: 
				mang_con_tang_dan(arr, n);
				printf("\n");
				break;
			case 5:
				system("cls");
				break;
			case 0:
				KT = false;
				break;
			 default:
			 	printf("nhap sai !! chon lai !!");
				printf("\n");
			 	break;
		}
	}
}
void swap(float &a, float &b) 
{
    float t = a;  a = b;   b = t;
}
void inArray(float *arr, int n)
{
	int i;
	for(i = 1; i <= n; i++)
	{
		printf("nhap A[%d]", i);
		scanf("%f", &arr[i]);
	}
	outArray(arr, n);
}
void outArray(float *arr, int n)
{
	int i;
	for(i = 1; i <= n; i++)
	{
		printf("%.3f\t", arr[i]);
	}
}
void tim_so_duong(float *arr, int n)
{
	int i, j = 1;
	float brr[100];
	for(i = 1; i <= n; i++)
		if (arr[i] > 0.0)
		{
			brr[j] = arr[i];
			j++;	
		}
	float min = brr[1];
	for(i = 2; i < j; i++)
	{
		if(min > brr[i])
			min = brr[i];
	}
	printf("so duong nho nhat trong mang la %.3f", min);
}
void quickSort_T(float *arr, int left, int right) {
    int i, j , x;
    if(left >= right) return;
    x = arr[(left+right)/2];
    i = left; j = right;
    while(i <= j) {
        while(arr[i] < x) i++;
        while(arr[j] > x) j--;
            if(i <= j)
            {
                swap(arr[i], arr[j]);
                i++;    j--;
            }
    }
    quickSort_T(arr, left, j);
    quickSort_T(arr, i, right);
}
void quickSort_G(float *arr, int left, int right)
{
    int i, j , x;
    if(left >= right) return;
    x = arr[(left+right)/2];
    i = left; j = right;
    while(i <= j) {
        while(arr[i] > x) i++;
        while(arr[j] < x) j--;
            if(i <= j)
            {
                swap(arr[i], arr[j]);
                i++;    j--;
            }
    }
    quickSort_G(arr, left, j);
    quickSort_G(arr, i, right);
}
void sap_xep(float *arr, int n, int left, int right)
{
	int i, j = 1 , k = 1 ;
	float brr[100], crr[100];
	for(i = 1; i <= n; i++) {
		if (int(arr[i])%2 == 0)
		{
			crr[j] = arr[i];
			j++;	
		}	
	}
	quickSort_T(crr, 1, j-1);
	printf("\n");
	outArray(crr, j-1);
	for(i = 1; i <= n; i++) {
		if (int(arr[i])%2 != 0)
		{
			brr[k] = arr[i];
			k++;	
		}	
	}
	quickSort_G(brr, 1, k-1);
	outArray(brr, k-1);
}
int KT_mang_con(float *arr, int i, int &dem)
{
	if (arr[i] < arr[i+1])
	{
		dem++;
		KT_mang_con(arr, ++i, dem);
	}
	return dem;
}
void mang_con_tang_dan(float *arr, int n)
{
	int dem = 0;
	int i;
	for(i = 1; i <= n; i++) 
		KT_mang_con(arr, i, dem);
	printf("so mang con tang dan trong mang = %d", dem);
}
