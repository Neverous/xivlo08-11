#include<cstdio>
int tab[300],x;
int main(void)
{
	while(scanf("%c", &x)!=-1)
		tab[x]++;
	for(int i=0;i<300;i++)
		if(tab[i]==0)
			continue;
		else
			printf("%d %d\n", i,tab[i]);
	return 0;
}

