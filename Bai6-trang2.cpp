#include <stdio.h>
#include <math.h>
float S_tam_giac(int a, int b, int c);
float chieu_cao(int S, int a);

int main() 
{
	float a, b, c;
	printf("nhap a = "); scanf("%f", &a);
	printf("nhap b = "); scanf("%f", &b);
	printf("nhap c = "); scanf("%f", &c);
	(a+b>c && a+c>b && b+c>a) ? 
	(printf("\na,b,c la 3 canh cua 1 tam giac !!"), 
	printf("\ndien tich cua tam giac ABC = %.3f", S_tam_giac(a,b,c)),
	printf("\nchieu dai duong cao AH = %.2f", chieu_cao(S_tam_giac(a,b,c), a)),
	printf("\nchieu dai duong cao BH = %.2f", chieu_cao(S_tam_giac(a,b,c), b)),
	printf("\nchieu dai duong cao CH = %.2f", chieu_cao(S_tam_giac(a,b,c), b))
	): printf("\na,b,c khong phai la 3 canh cua 1 tam giac");

	return 0; 
}

float S_tam_giac(int a, int b, int c)
{
	float p; p = (a+b+c)/2.0;
	float S; S = sqrt(p*(p-a)*(p-b)*(p-c));
	return p;
}
float chieu_cao(int S, int a)
{
	float h; h = 2*S/a;
	return h;
}
	
