#include <stdio.h>

void so_hoan_hao(int n);
int main()
{
	int n;
	printf("nhap vao n "); scanf("%d", &n);
	so_hoan_hao(n);
}
void so_hoan_hao(int n)
{
	int sum = 0,  i;
	for(i = 1; i < n; i++)
		(n%i == 0) ? sum += i : sum;
	(sum == n) ? printf("%d la so hoan hao", n) : printf("%d khong la so hoan hao", n);
}
