/* 2010
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
#include<cmath>
//#define DEBUG(args...) fprintf(stderr, args)
#define DEBUG(args...)

unsigned int tests,
			 start,
			 end,
			 eratostenes[1048576];

inline static void preprocess(void);

int main(void)
{
	preprocess();
	scanf("%u", &tests);
	for(unsigned int t = 0; t < tests; ++ t)
	{
		scanf("%u %u", &start, &end);
		printf("%u\n", eratostenes[end] - eratostenes[start - 1]);
	}

	return 0;
}

inline static void preprocess(void)
{
	for(unsigned int e = 0; e < 1048576; ++ e)
		eratostenes[e] = 1;

	for(unsigned int e = 2; e * e < 1048576; ++ e)
	{
		if(!eratostenes[e])
			continue;

		for(unsigned int j = e * e; j < 1048576; j += e)
			eratostenes[j] = 0;
	}

	for(unsigned int e = 1; e < 1048576; ++ e)
		eratostenes[e] += eratostenes[e - 1];
}
