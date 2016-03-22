#include<cstdio>
#include<cmath>

double a,b;

int main(void)
{
	scanf("%lf %lf", &a,&b);
	printf("%.2lf\n", ((a*a)-((b*b)/4))*3.141592654);
	return 0;
}

