#include<cstdio>

int tests,
    a,
    b;

int main(void)
{
	scanf("%d", &tests);
	for(int i=0;i<tests;i++)
	{
		scanf("%d %d", &a, &b);
		a--;
		printf("%s\n", (a==0 || a>b || (b>a && b%a>0))?"TAK":"NIE");
	}
	return 0;
}

