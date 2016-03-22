/* 2010
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
//#define DEBUG(args...) fprintf(stderr, args)
#define DEBUG(args...)

int number,
	primes = 1,
	result = 1;

int main(void)
{
	scanf("%d", &number);
	for(int p = 2, c = 0; p * p <= number; ++ p)
	{
		c = 0;
		while(number % p == 0)
		{
			++ c;
			number /= p;
		}

		if(c)
			++ primes;

		result *= (c + 1);
	}

	if(number != 1)
	{
		result *= 2;
		++ primes;
	}

	printf("%d\n", result - primes);
	return 0;
}

