/* 2010
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
#include<map>
#include<cstring>
//#define DEBUG(args...) fprintf(stderr, args)
#define DEBUG(args...)

int tests,
	p,
	q,
	x,
	y;
long long int var,
			  speedup[4000001];

long long int recurse(long long int v);

int main(void)
{
	scanf("%d\n", &tests);
	for(int t = 0; t < tests; ++ t)
	{
		memset(speedup, 0, sizeof(long long int) * 4000001);
		scanf("%lld %d %d %d %d", &var, &p, &q, &x, &y);
		printf("%lld\n", recurse(var));
	}
	return 0;
}

long long int recurse(long long int v)
{
	if(v <= 0)
		return 1;

	if(v < 4000001)
	{
		if(speedup[v])
			return speedup[v];

		return speedup[v] = recurse(v / p - x) + recurse(v / q - y);
	}

	return recurse(v / p - x) + recurse(v / q - y);
}
