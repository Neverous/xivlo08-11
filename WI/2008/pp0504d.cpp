#include<cstdio>

long long int sumGlob,sum,tmp;

int main(void)
{
	while(true)
	{
		scanf("%lld", &tmp);
		sum += tmp;
		sumGlob += tmp;
		if(tmp == 0)
			printf("%lld\n", sum);
		if(tmp == 0 && sum == 0)
			break;
		if(tmp == 0)
			sum = 0;
	}
	printf("%lld\n", sumGlob);
	return 0;
}

