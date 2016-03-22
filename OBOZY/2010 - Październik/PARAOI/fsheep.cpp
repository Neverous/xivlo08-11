/* 2010
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
#include<vector>
//#define DEBUG(args...) fprintf(stderr, args)
#define DEBUG(args...)

unsigned int tests,
			 verts,
			 sheeps,
			 result;
long long int x, y;
std::pair<long long int, long long int> fence[100000];

inline static bool check(long long int &sx, long long int &sy);
inline static long long int side(std::pair<long long int, long long int> A, std::pair<long long int, long long int> B, std::pair<long long int, long long int> C);

int main(void)
{
	scanf("%u", &tests);
	for(unsigned int t = 0; t < tests; ++ t)
	{
		scanf("%u %u", &verts, &sheeps);
		result = 0;
		for(unsigned int v = 0; v < verts; ++ v)
			scanf("%lld %lld", &fence[v].first, &fence[v].second);

		for(unsigned int s = 0; s < sheeps; ++ s)
		{
			scanf("%lld %lld", &x, &y);
			result += check(x, y);
		}

		printf("%u\n", result);
	}

	return 0;
}

inline static bool check(long long int &sx, long long int &sy)
{
	printf("P: %lld %lld\n", sx, sy);
	unsigned int f = 0, size = verts - 2, mid;
	while(size > 2)
	{
		mid = (f + size / 2) % verts;
		if(side(std::make_pair(0, 0), fence[f], std::make_pair(sx, sy)) <= 0 &&
			side(std::make_pair(0, 0), fence[(f + size) % verts], std::make_pair(sx, sy)) >= 0)
		{
			f = (f + size) % verts;
			size = verts - size;
			continue;
		}

		if(side(std::make_pair(0, 0), fence[mid], std::make_pair(sx, sy)) < 0)
			f = mid;

		size /= 2;
	}

	printf(">>%u %u\n", f, (f + size)  % verts);
	return side(fence[f], fence[(f + size) % verts], std::make_pair(sx, sy)) >= 0;
}

inline static long long int side(std::pair<long long int, long long int> A, std::pair<long long int, long long int> B, std::pair<long long int, long long int> C)
{
	long long int value = (B.first - A.first) * (C.second - A.second) - (C.first - A.first) * (B.second - A.second);
	if(value < 0)
		return -1;

	if(value > 0)
		return 1;

	return 0;
}
