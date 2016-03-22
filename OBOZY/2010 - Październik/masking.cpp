/* 2010
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
//#define DEBUG(args...) fprintf(stderr, args)
#define DEBUG(args...)

unsigned int length,
			 resultS,
			 resultE,
			 parts,
			 middle;
char field[500005];

inline static bool isPossible(unsigned int size);

int main(void)
{
	scanf("%u%s%u", &length, field, &parts);
	resultE = length;
	while(resultS != resultE)
	{
		middle = (resultS + resultE) / 2;
		if(isPossible(middle))
			resultE = middle;

		else
			resultS = middle + 1;

		//printf("%u %u\n", resultS, resultE);
	}

	printf("%u\n", resultS);
	return 0;
}

inline static bool isPossible(unsigned int size)
{
	unsigned int last = 0,
				 partsLeft = parts;
	while(partsLeft && last < length)
	{
		if(field[last] == '+')
		{
			-- partsLeft;
			last += size;
		}

		else
			++ last;
	}

	while(last < length)
		if(field[last ++] == '+')
			return false;

	return true;
}
