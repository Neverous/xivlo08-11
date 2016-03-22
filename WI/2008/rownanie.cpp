#include<cstdio>
#include<string>

float a,b,c;

int main(void)
{
	while(scanf("%f %f %f", &a,&b,&c)!=-1)
	{
		b*=b;
		a *= 4*c;
		if(b>a)
			printf("2\n");
		else if(b<a)
			printf("0\n");
		else
			printf("1\n");
	}
	return 0;
}

