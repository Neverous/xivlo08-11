/* 2009
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
#define abs(a) ((a) > 0?(a):-(a))

struct Gcd
{
	long long int x,
				  y,
				  gcd;

	Gcd(long long int X = 0, long long int Y = 1, long long int G = 1)
	{
		x = X;
		y = Y;
		gcd = G;
	}
};

Gcd extGcd(long long int A, long long int B);

int tests;
long long int a,
			  b,
			  c;
Gcd result;

int main(void)
{
	scanf("%d", &tests);
	for(int t = 0; t < tests; ++ t)
	{
		scanf("%lld %lld", &a, &b);
		if(a < b)
		{
			c = b;
			b = a;
			a = c;
		} //SWAP

		result = extGcd(a, b);
		if(result.gcd != 1)
			printf("He will starve\n");

		else
			printf("%lld\n", abs(result.x) + abs(result.y));
	}

	return 0;
}

Gcd extGcd(long long int A, long long int B)
{
	Gcd res;
	long long int T;
	res.gcd = B;
	if(!B)
	{
		res.gcd = A;
		res.y = 0;
		res.x = 1;
		return res;
	}

	if(A % B == 0)
		return res;

	res = extGcd(B, A % B);
	T = res.x;
	res.x = res.y;
	res.y = T - res.y * (A / B);

	return res;
}
