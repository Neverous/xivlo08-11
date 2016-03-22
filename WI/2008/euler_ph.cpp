#include<cstdio>
#include<vector>
typedef long long unsigned int llu;
using namespace std;
int tests;
llu number,
    tmpNumber,
    result,
    k;

llu solve()
{
	if(number<2)
		return 0;

	tmpNumber = number;
	result = 1;
	for(llu i=2; i*i<=tmpNumber && i <= number; i++)
	{
		for(k=0;!(number%i);k++)
			number /= i;
		if(k)
		{
			result *= i-1;
			while(--k)
				result *= i;
		}
	}

	if(number>1)
		result *= number -1;

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

