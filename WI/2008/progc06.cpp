#include<cstdio>

char x;
bool tab[30];
bool t = 1;
int main(void)
{
	while(scanf("%c", &x)!=-1)
	{
		if(x==' ')
		{
			t = 0;
		}
		else if(x=='\n')
		{
			t = 1;
			printf("\n");
			for(int i=0;i<30;tab[i++]=0);
		}
		else if(t==1)
		{
			tab[x-'a'] = 1;
		}
		else if(tab[x-'a'])
			continue;
		else
			printf("%c", x);
	}
	return 0;
}

