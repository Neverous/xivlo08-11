/* 2010
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
//#define DEBUG(args...) fprintf(stderr, args)
#define DEBUG(args...)

unsigned int tests,
			 rest,
			 coins,
			 coin;

unsigned int used[1024];

inline static unsigned int MIN(unsigned int a, unsigned int b);

int main(void)
{
	scanf("%u", &tests);
	for(unsigned int t = 0; t < tests; ++ t)
	{
		scanf("%u %u", &rest, &coins);
		for(unsigned int r = 0; r <= rest; ++ r)
			used[r] = (1 << 30);

		used[0] = 0;
		for(unsigned int c = 0; c < coins; ++ c)
		{
			scanf("%u", &coin);
			for(unsigned int r = coin; r <= rest; ++ r)
				used[r] = MIN(used[r - coin] + 1, used[r]);
		}

		printf("%u\n", used[rest] <= rest?used[rest]:0);
	}

	return 0;
}


inline static unsigned int MIN(unsigned int a, unsigned int b)
{
	return a<b?a:b;
}
