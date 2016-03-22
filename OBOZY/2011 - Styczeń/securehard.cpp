/* 2011
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
#include<vector>
#include<algorithm>
//#define DEBUG(args...) fprintf(stderr, args)
#define DEBUG(args...)

long long int numbers,
	number,
	MOD,
	a;
std::vector<std::pair<long long int, long long int> > data;

int main(void)
{
	scanf("%lld %lld %lld", &numbers, &MOD, &a);
	for(long long int l = 0; l < 256; ++ l)
		data.push_back(std::make_pair((l * a) % MOD, l));

	std::sort(data.begin(), data.end());
	for(long long int n = 0; n < numbers; ++ n)
	{
		scanf("%lld", &number);
		printf("%lld%c", std::lower_bound(data.begin(), data.end(), std::pair<long long int, long long int>(number, 0))->second, n + 1 == numbers?'\n':' ');
	}

	return 0;
}

