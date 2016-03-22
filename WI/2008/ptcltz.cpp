#include<cstdio>

int tests,x;

int solve(int x)
{
	if(x==1)
		return 0;
	for(int i=1;true;i++)
	{
		if(x%2==1)
			x = 3*x+1;
		else
			x /= 2;
		if(x==1)
			return i;
	}
}

int main(void)
{
	scanf("%d", &tests);
	for(int i=0;i<tests;i++)
	{
		scanf("%d", &x);
		printf("%d\n", solve(x));
	}
	return 0;
}

