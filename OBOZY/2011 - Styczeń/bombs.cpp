/* 2011
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
//#define DEBUG(args...) fprintf(stderr, args)
#define DEBUG(args...)
#define __builtin_lastbit(x) (31 - __builtin_clz(x))

unsigned int height,
			 width,
			 result = 1000,
			 level[32],
			 horiz[1 << 25];
char buffer[32];

unsigned int MIN(const unsigned int &A, const unsigned int &B){return A<B?A:B;}
unsigned int MAX(const unsigned int &A, const unsigned int &B){return A>B?A:B;}

int main(void)
{
	scanf("%u %u", &height, &width);
	for(unsigned int h = 0; h < height; ++ h)
	{
		scanf("%s", buffer);
		for(unsigned int w = 0; w < width; ++ w)
			if(buffer[w] == '*')
				level[h] |= (1 << w);
	}

	for(int m = 1, max = (1 << height); m < max; ++ m) // Maska mówi mi których wierszy nie rozwalam ^^
	{
		horiz[m] = horiz[m ^ (1 << __builtin_lastbit(m))] | level[__builtin_lastbit(m)];
		//printf("%d %d %d\n", m, height - __builtin_popcount(m), __builtin_popcount(horiz[m]));
		result = MIN(MAX(__builtin_popcount(horiz[m]), height - __builtin_popcount(m)), result);
	}

	printf("%u\n", result);
	return 0;
}

