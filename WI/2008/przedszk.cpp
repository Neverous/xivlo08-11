#include<cstdio>
int tests,a,b,tmp;
int main(void)
{
	scanf("%d", &tests);
	for(int i=0;i<tests;i++)
	{
		scanf("%d %d", &a, &b);
		if(a>b)
		{
			tmp = b;
			b = a;
			a = tmp;
		}
		tmp = a;
		while(a<b || a%b!=0)
			a+=tmp;
		printf("%d\n", a);
	}
	return 0;
}

