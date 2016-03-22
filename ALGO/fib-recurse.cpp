/* 2010
 * Maciej Szeptuch
 * XIV LO Wrocław
 * --------------------------
 * Fibonacci rekurencyjnie
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
	if(which < 3)
		return 1;

	return (fibonacci(which - 1, mod) + fibonacci(which - 2, mod)) % mod;
}
