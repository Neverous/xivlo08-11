/* 2010
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
//#define DEBUG(args...) fprintf(stderr, args)
#define DEBUG(args...)

int tests,
	size,
	speedup[51][51];

inline static int gimmeh(int parts, int left);
inline static int permutations(int num);
inline static int NWD(int a, int b);
inline static int MAX(int a, int b);

int main(void)
{
	scanf("%d", &tests);
	for(int t = 0; t < tests; ++ t)
	{
		scanf("%d", &size);
		printf("%d\n", permutations(size));
	}

	return 0;
}

inline static int permutations(int num)
{
	int result = 1;
	for(int i = 1; i <= num; ++ i)
		result = MAX(result, gimmeh(i, num));

	return result;
}

inline static int NWD(int a, int b)
{
	if(a < b)
		return NWD(b, a);

	if(b == 0)
		return a;

	return NWD(b, a % b);
}

inline static int MAX(int a, int b)
{
	return a>b?a:b;
}

inline static int gimmeh(int parts, int left)
{
	if(speedup[parts][left])
		return speedup[parts][left];

	int gh;
	speedup[parts][left] = left;
	if(parts == 1)
		return speedup[parts][left];

	for(int l = 1; l < left; ++ l)
	{
		gh = gimmeh(parts - 1, left - l);
		speedup[parts][left] = MAX(speedup[parts][left], l * gh / NWD(l, gh));
	}

	return speedup[parts][left];
}

