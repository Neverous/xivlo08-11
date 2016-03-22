#include<cstdio>
int x,n;
int main(void)
{
	while(scanf("%c", &x)!=-1)
		if(x=='\n')
			n++;
	printf("%d\n", n);
	return 0;
}

