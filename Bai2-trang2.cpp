#include <stdio.h>

int main()
{
	int x; 
	printf("nhap vao so nguyen x"); scanf("%d", &x);
	float S = 1.0 + x + x*x*x/3.0 + x*x*x*x*x/5.0;
	printf ("S=1 + x + x3/3 + x5/5 = %.2f", S);
	return 0;
}
