/* 2010
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
#include<vector>
//#define DEBUG(args...) fprintf(stderr, args)
#define DEBUG(args...)

long long int prime,
	tab[200002],
	res = 1;

std::pair<long long int, long long int> extendedEuclides(long long int first, long long int second);
inline static long long int NWD(long long int a, long long int b);

int main(void)
{
	while(scanf("%lld", &prime) != -1)
	{
		tab[0] = 1;
		res = 1;
		for(long long int p = 1; p < prime; ++ p)
			//{
			tab[p] = (prime + extendedEuclides(prime, p).second + 1) % prime;
		//printf("%lld ", tab[p]);
		//}

		//puts("");

		for(long long int l = 0, m = 0, n = 0, cost = 0; l < prime; m = ++ l, cost = 0)
		{
			while(tab[m] != -1)
			{
				++ cost;
				n = tab[m];
				tab[m] = -1;
				m = n;
			}

			if(cost)
				res = cost * res / NWD(cost, res);
		}

		printf("%lld\n", res);
	}
	return 0;
}

std::pair<long long int, long long int> extendedEuclides(long long int first, long long int second)
{
	std::pair<long long int, long long int> result(0, 1);
	long long int tmp;
	if(first % second == 0)
		return result;

	result = extendedEuclides(second, first % second);
	tmp = result.first;
	result.first = result.second;
	result.second = tmp - result.second * (first / second);
	return result;
}

inline static long long int NWD(long long int a, long long int b)
{
	if(a < b)
		return NWD(b, a);

	if(b == 0)
		return a;

	return NWD(b, a % b);
}
