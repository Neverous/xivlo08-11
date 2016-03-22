/* 2010
 * Maciej Szeptuch
 * XIV LO Wrocław
 * --------------------------
 * Fibonacci rekurencyjne z lekkim przyspieszaczem
 */
#include<cstdio>

int tests;
long long int number,
			  modulo;
long long int speedup[2048][2048];

long long int fibonacci(long long int which, long long int mod);

int main(void)
{
	for(int w = 0; w < 2048; ++ w)
		for(int m = 0; m < 2048; ++ m)
			speedup[w][m] = -1;

	scanf("%d\n", &tests);
	for(int t = 0; t < tests; ++ t)
	{
		scanf("%lld %lld", &number, &modulo);
		printf("%lld\n", fibonacci(number, modulo));
	}

	return 0;
}

long long int fibonacci(long long int which, long long int mod)
{
	if(which < 3)
		return 1;

	if(which < 2048 && mod < 2048)
	{
		if(speedup[which][mod] == -1)
			speedup[which][mod] = (fibonacci(which - 1, mod) + fibonacci(which - 2, mod)) % mod;

		return speedup[which][mod];
	}

	return (fibonacci(which - 1, mod) + fibonacci(which - 2, mod)) % mod;
}
