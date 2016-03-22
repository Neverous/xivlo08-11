/* 2010
 * Maciej Szeptuch
 * XIV LO Wrocław
 * --------------------------
 * Fibonacci liniowo
 */
#include<cstdio>

int tests;
long long unsigned int number,
					   modulo;

long long unsigned int fibonacci(long long unsigned int which, long long unsigned int mod);

int main(void)
{
	scanf("%d\n", &tests);
	for(int t = 0; t < tests; ++ t)
	{
		scanf("%llu %llu", &number, &modulo);
		printf("%llu\n", fibonacci(number, modulo));
	}

	return 0;
}

long long unsigned int fibonacci(long long unsigned int which, long long unsigned int mod)
{
	long long unsigned int a = 1,
						   b = 1,
						   c = 0;

	for(long long unsigned int w = 2; w < which; ++ w)
	{
		c = (a + b) % mod;
		a = b;
		b = c;
	}

	return b;
}
