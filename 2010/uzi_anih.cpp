/* 2010
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
//#define DEBUG(args...) fprintf(stderr, args)
#define DEBUG(args...)

int tests,
	number,
	prime[1000001],
	supermemo[1000001],
	phiT[1000001];

inline void preprocess(void);
int solve(int num);
int phi(int num);

int main(void)
{
	preprocess();
	scanf("%d", &tests);
	for(int t = 0; t < tests; ++ t)
	{
		scanf("%d", &number);
		printf("%d\n", solve(number));
	}
}

int solve(int num)
{
	if(supermemo[num] != -1)
		return supermemo[num];

	return supermemo[num] = solve(phi(num)) + 1;
}

inline void preprocess(void)
{
	for(int p = 2; p < 1000001; ++ p)
		supermemo[p] = phiT[p] = -1;

	prime[1] = 1;
	for(int p = 2; p * p <= 1000001; ++ p)
	{
		if(prime[p])
			continue;

		prime[p] = p;
		for(int p2 = p * p; p2 < 1000001; p2 += p)
			prime[p2] = p;
	}

	for(int p = 0; p < 1000001; ++ p)
		if(!prime[p])
			prime[p] = p;
}

int phi(int num)
{
	if(phiT[num] != -1)
		return phiT[num];

	long long int P = prime[num];
	while(num % P == 0)
		P *= prime[num];

	P /= prime[num];
	if(P == num)
		return phiT[num] = (P - P / prime[num]);

	return phiT[num] = (P - P / prime[num]) * phi(num / P);
}

