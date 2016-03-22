#include<cstdio>
#include<string>

float a,b,c;

int main(void)
{
	scanf("%f %f %f", &a,&b,&c);
	if(a==0 && b==c)
		printf("NWR\n");
	else if(a==0 && c!=b)
		printf("BR\n");
	else
		printf("%.2f\n", (c-b)/a);
	return 0;
}

