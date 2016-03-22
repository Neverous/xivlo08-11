/* 2010
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
//#define DEBUG(args...) fprintf(stderr, args)
#define DEBUG(args...)

unsigned int tests,
			 number,
			 magic[21] = { 1,
				 1, 2, 6, 4, 2,
				 2, 4, 2, 8, 4,
				 4, 8, 4, 6, 8,
				 8, 6, 8, 2, 6,
			 };

inline unsigned int factorial(unsigned int num);

int main(void)
{
	scanf("%u", &tests);
	for(unsigned int t = 0; t < tests; ++ t)
	{
		scanf("%u", &number);
		printf("%u\n", factorial(number));
	}

	return 0;
}

inline unsigned int factorial(unsigned int num)
{
	unsigned int result = 1;
	while(num)
	{
		result = (result * magic[num % 20]) % 10;
		num /= 5;
	}

	return result;
}
