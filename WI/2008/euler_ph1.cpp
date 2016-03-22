#include<cstdio>
#include<vector>
typedef long long unsigned int llu;
using namespace std;
int tests;
llu result,
    number,
    tmpNumber;
llu solve()
{
	tmpNumber = result = number;
	for(llu i=2;i<=number && i*i<=tmpNumber;i++)
	{
		if(!(number%i))
		{
			while(!(number%i)) number /= i;
			result /= i;
			result *= i-1;
		}
	}
	if(number>1)
	{
		result *= number-1;
		result /= number;
	}
	return result;
}
int main(void)
{
	scanf("%d", &tests);
	for(int i=0;i<tests;i++)
	{
		scanf("%llu", &number);
		printf("%llu\n", solve());
	}
	return 0;
}

