#include<cstdio>
#include<string>
char A[1005];

int main()
{
	while(scanf("%s", A)!=-1)
	{
		for(int i=strlen(A)-1;i>=0;i--)
			printf("%c", A[i]);
		printf("\n");
	}
	return 0;
}

