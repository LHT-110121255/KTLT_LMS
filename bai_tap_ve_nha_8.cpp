#include <stdio.h>
#include <windows.h>
#include <math.h>
#define cot 1000

void inMaTrix(int arr[][cot], int n);  					void outMaTrix(int arr[][cot], int n);                       
void minMaTrix(int arr[][cot], int n);          		void findElementMaTrix(int arr[][cot], int n);
void sumMaTrix_DCC(int arr[][cot], int n);				void coutElement(int arr[][cot], int n);          
void findElementOfDCP_max(int arr[][cot], int n);   	void diem_yen_ngua(int arr[][cot], int n); 
int KT_dong(int arr[][cot], int , int , int ); 	int KT_cot(int arr[][cot], int , int , int );

int main() {
    system("cls");
    int size, m;
    printf("nhap kich thuoc matran "); scanf("%d", &size);
    int arr[size][1000];
    inMaTrix(arr, size);
    while(1) {
        printf("\n======================================================\n");
        printf("|| 0. thoat chuong trinh -> exit                    	||\n");
        printf("|| 1. tim phan tu nho nhat trong ma tran            	||\n");
        printf("|| 2. tinh tong cac phan tu nam tren duong cheo chinh   ||\n");
        printf("|| 3. tim phan tu lon nhat tren duong cheo phu        	||\n");
        printf("|| 4. so phan tu chan nam trong tam giac tren cua DCC  	||\n");
        printf("|| (khong ke duong cheo chinh )			    	||\n");
        printf("|| 5. tim va in ra cac so le  trong tam giac duoi DCP  	||\n");
        printf("|| (tinh luon duong cheo phu )				||\n");
        printf("|| 6. tim cac diem yen ngua trong ma tran			  	||\n");
        printf("\n => Chon yeu cau: ");
        scanf("%d", &m);
        if (m == 0) {
            printf("Thoat chuong trinh!");
            break;  
        }
        switch (m)
        {
        case 1:
        	minMaTrix(arr, size);
        	break;
        case 2:
        	sumMaTrix_DCC(arr, size);
        	break;
        case 3:
        	findElementOfDCP_max(arr, size);
        	break;
        case 4:
        	coutElement(arr, size);
        	break;
        case 5:
        	findElementMaTrix(arr, size);
        	break;
        case 6:
        	diem_yen_ngua(arr, size);
        	break;
        default:
            printf("yeu cau khong co !");
            printf("\n");
            break;
        }
    }
    
    return 0;
}    
    
void inMaTrix(int arr[][cot], int n) 
{
    int i, j;
    for (i = 0; i < n; i++) 
        for(j = 0; j < n; j++) {
            printf("Nhap phan tu arr[%d][%d]", i, j);
            scanf("%d", &arr[i][j]);
        }    
    outMaTrix(arr, n);
}

void outMaTrix(int arr[][cot], int n) 
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++) {

            printf("|%d| \t", arr[i][j]);
        }   
        printf("\n"); 
    }

}

void minMaTrix(int arr[][cot], int n)
{
    int i, j, min = arr[0][0];
    for (i = 1; i < n; i++) 
        for(j = 1; j < n; j++) {
            (min > arr[i][j]) ? min = arr[i][j] : min;
        }
    printf("min = %d", min);
}
void sumMaTrix_DCC(int arr[][cot], int n) 
{
    int i,  sum = 0;
        for(i = 0; i < n; i++) {
           sum += arr[i][i]; 
        }
    printf("\nTong cac phan tu tren duong cheo chinh = %d", sum);
}
void findElementOfDCP_max(int arr[][cot], int size)
{
    int i, max = arr[0][size-1];
    for(i = 0; i < size; i++) 
        if(max < arr[i][size-i-1])
        	max = arr[i][size-i-1];
    printf("phan tu lon nhat tren duong cheo phu = %d", max);
}
void coutElement(int arr[][cot], int n) 
{
    int i, j, dem=0;
    for (i = 0; i < n; i++) 
        for(j = i+1; j < n; j++) {
            (arr[i][j]%2 == 0) ? dem++ : dem;
        }
    printf("\nso phan tu chan nam trong tam giac tren DCC la: %d", dem);
}
void findElementMaTrix(int arr[][cot], int size) 
{
    int i, j;
    for(i = 0; i < size; i++)
    	for(j = size-i; j < size; j++)
			(arr[i][j]%2 != 0) ? printf("%d\t", arr[i][j]) : i;
}

int KT_cot(int arr[][cot], int pt, int c, int n)
{
	int i;
	for(i = 0; i < n; i++)
		if (pt < arr[i][c])
			return 0;
	return 1;
}
int KT_dong(int arr[][cot], int pt, int n, int dong)
{
	int i;
	for(i = 0; i < n; i++)
	{
		if(pt > arr[dong][i])
			return 0;
	}
	return 1;
}
void diem_yen_ngua(int arr[][cot], int size)
{
	int i, j;
	for(i = 0; i < size; i++)
		for(j = 0; j < size; j++)
		{
			if( KT_cot(arr, arr[i][j], j, size) == 1 && KT_dong(arr,arr[i][j], size, i))
				printf("%d\t", arr[i][j]);
		}
					
}

