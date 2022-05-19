#include <stdio.h>

int giai_thua(int n);
float luy_thua(float x, int n);
float Exp(int n , float x);
int main()
{
	int n;
	float x;
	printf("nhap n "); scanf("%d", &n);
	printf("nhap x "); scanf("%f", &x);
	printf("Exp(n,x)=1 + x/1 + x2/2! + x3/3!+ …+ xn/n!, voi n = %d, x = %f",n, f, Exp(x, n));
	return 0;
}

int giai_thua(int n)
{
	if(n == 1) return 1;
	return n* giai_thua(n-1);
}
float luy_thua(float x, int n)
{
	if(n == 0) return 1;
	return x* luy_thua( x, n-1);
}
float Exp(int n , float x)
{
	float EXP;
	EXP = 1.0;
	int i;
	for(i = 1; i <= n; i++)
	{
		float mau = float(giai_thua(i));
		float tu = luy_thua(x, i);
		EXP += tu/mau;
	}
	return EXP;
}
