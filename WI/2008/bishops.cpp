#include<cstdio>
#include<string>

int tests;
char number[102];

void solve(void)
{
	char result[102]={0};
	int rest=0,toDiff=1, size = strlen(number)-1,j,i;
	if(size==0 && number[0]=='1')
	{
		printf("1\n");
		return;
	}

	for(j=0,i=size;i>=0;i--,j++)
	{
		if(toDiff!=0)
			if(number[i]-'0'==0)
				number[i] = '9';
			else
			{
				number[i] -= 1;
				toDiff =  0;
			}
		result[j] = (number[i]-'0')*2 + rest;
		rest = result[j]/10;
		result[j] %= 10;
		result[j] += '0';
	}
	if(rest!=0) result[j] = rest+'0';
	for(int i=(result[size+1]!=0)?size+1:size;i>=0;i--)
		printf("%c", result[i]);
	printf("\n");
}

int main(void)
{
	while(scanf("%s", number)!=-1)
		solve();
	return 0;
}

