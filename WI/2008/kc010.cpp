#include<cstdio>
#include<string>

int x, y;
bool t=1;
char c;

int main(void)
{
	while(scanf("%c", &c)!=-1)
	{
		if(t)
		{
			if(c>='0' && c<='9')
				x++;
			else
				y++;
			t = 0;
		}
		else if(c==' ')
			t = 1;
		else if(c=='\n')
		{
			printf("%d %d\n", x, y);
			t = 1;
			x = 0;
			y = 0;
		}
	}
	return 0;
}

