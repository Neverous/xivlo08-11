#include<cstdio>

char x,m;
bool t = 1;
int main(void)
{
	while(scanf("%c", &x)!=-1)
	{
		if(x==' ')
			continue;
		else if(x=='\n')
		{
			t = 1;
			printf("\n");
		}
		else if(t==1)
		{
			m = x;
			t = 0;
		}
		else if(x==m)
			continue;
		else
			printf("%c", x);
	}
	return 0;
}

