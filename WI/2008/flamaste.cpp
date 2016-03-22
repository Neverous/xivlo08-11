#include<cstdio>
int x,last,num,tests;
int main(void)
{
	scanf("%d ", &tests);
	for(int i=0;i<tests;i++)
	{
		num = 0;
		last = 0;
		while(scanf("%c", &x) && x!='\n')
		{
			if(x==last)
				num++;
			else
			{
				if(num>2)
					printf("%c%d", last, num);
				else if(num==2)
					printf("%c%c", last, last);
				else
					printf("%c", last);
				num = 1;
				last = x;
			}
		}
		if(num>2)
			printf("%c%d\n", last, num);
		else if(num==2)
			printf("%c%c\n", last, last);
		else
			printf("%c\n", last);
	}
	return 0;
}

