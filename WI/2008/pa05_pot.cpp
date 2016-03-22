#include<cstdio>
int a,b,tests;
int main(void)
{
	scanf("%d ", &tests);
	for(int i=0;i<tests;i++)
	{
		scanf("%d %d", &a, &b);
		a %= 10;
		for(int i=1,x=a;i<b;i++)
			a = (a*x)%10;
		printf("%d\n", a);
	}
	return 0;
}

