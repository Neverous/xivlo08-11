/* 2010
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
#include<cmath>
#define SIZE 32768

unsigned int tests,
			 from,
			 to,
			 primes[SIZE + 1];

inline static void preprocess(void);

int main(void)
{
	preprocess();
	scanf("%u", &tests);
	for(unsigned int t = 0; t < tests; ++ t)
	{
		scanf("%u %u", &from, &to);
		printf("%u\n", primes[(unsigned int)sqrt(to)] - primes[(unsigned int)sqrt(from - 1)]);
	}

	return 0;
}


inline static void preprocess(void)
{
	for(unsigned int p = 2; p <= SIZE; ++ p)
		primes[p] = 1;

	for(unsigned int p = 2; p * p <= SIZE; ++ p)
	{
		if(!primes[p])
			continue;

		for(unsigned int n = p * p; n <= SIZE; n += p)
			primes[n] = 0;
	}

	for(unsigned int p = 1; p <= SIZE; ++ p)
		primes[p] += primes[p - 1];
}
