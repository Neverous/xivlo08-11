#include<cstdio>
#include<string>

char A[1005],
     B[1005],
     x;
int z,y;
int solve()
{
	z = strlen(A);
	y = strlen(B);
	if(z>y)
	{
		if(x=='>' || x=='!')
			return 1;
		return 0;
	}
	if(z<y)
	{
		if(x=='<' || x=='!')
			return 1;
		return 0;
	}
	for(int i=0;A[i]!=0 && B[i]!=0;i++)
	{
		if(A[i]==B[i])
			continue;
		if(A[i]>B[i])
		{
			if(x=='!' || x=='>')
				return 1;
			return 0;
		}
		if(x=='<' || x=='!')
			return 1;
		return 0;
	}
	if(x=='=')
		return 1;
	return 0;
}
int main(void)
{
	while(scanf("%s %c%*c %s", &A, &x,&B)!=-1)
	{
		printf("%d\n", solve());
	}
	return 0;
}

