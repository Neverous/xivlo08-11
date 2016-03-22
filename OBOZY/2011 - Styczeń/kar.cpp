/* 2011
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
//#define DEBUG(args...) fprintf(stderr, args)
#define DEBUG(args...)

unsigned int numbers,
			 result;
int number[1024];
bool paired[1024];

int main(void)
{
	scanf("%u", &numbers);
	for(unsigned int n = 0; n < numbers; ++ n)
		scanf("%d", &number[n]);

	for(unsigned int n = 0; n < numbers; ++ n)
	{
		if(paired[n])
			continue;

		++ result;
		for(unsigned int s = n + 1; s < numbers; ++ s)
		{
			if(paired[s])
				continue;

			paired[s] = (10000 + number[n] - number[s]) % 100 == 0;
		}
	}

	printf("%u\n", result);
	return 0;
}

