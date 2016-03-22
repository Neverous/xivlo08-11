#include<cstdio>
int tests,a,b,tmp;
int main(void)
{
	scanf("%d", &tests);
	for(int i=0;i<tests;i++)
	{
		scanf("%d %d", &a, &b);
		while(b!=0)
		{
			tmp = b;
			b = a%b;
			a = tmp;
		}
		printf("%d\n", 2*a);
	}
	return 0;
}

