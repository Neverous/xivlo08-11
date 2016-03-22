/* 2009
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>

long long int number,
	max = 0,
	nextmax = 0;

int main(void)
{
	for(int i = 0; i < 10; ++ i)
	{
		scanf("%lld", &number);
		if(number >= max)
		{
			nextmax = max;
			max = number;
		}

		else if(number >= nextmax)
			nextmax = number;

	}
	printf("%lld\n", nextmax);
}
