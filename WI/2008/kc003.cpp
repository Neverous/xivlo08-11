#include<cstdio>
float a,b,c;

int main(void)
{
	while(scanf("%f %f %f", &a,&b,&c)!=-1)
	{
		printf("%d\n", (a+b>=c && a+c>=b && c+b>=a));
	}
	return 0;
}

