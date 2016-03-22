#include<cstdio>
typedef long long unsigned int num;
num newton(num n, num k)
{
	if(n==k)return 1;
	num result=1;
	for(num i=n-k+1;i<=n;i++)
		result *=i;
	while(k>1)
		result /=k--;
	return result;
}
num tests,a,b;
int main()
{
	scanf("%llu",&tests);
	for(num i=0;i<tests;i++)
	{
		scanf("%llu %llu",&a,&b);
		printf("%llu\n",newton(a,b));
	}
	return 0;
}

