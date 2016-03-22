/* 2010
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
//#define DEBUG(args...) fprintf(stderr, args)
#define DEBUG(args...)
const int BUFFER = 4096;
int p = BUFFER - 1;
char buffer[BUFFER];

long long unsigned int getNumber(void);

long long unsigned int tests,
					   elements,
					   best,
					   count,
					   numbers[8000000];

int main(void)
{
	tests = getNumber();
	for(long long unsigned int t = 0; t < tests; ++ t)
	{
		elements = getNumber();
		count = 0;
		for(long long unsigned int e = 0; e < elements; ++ e)
		{
			numbers[e] = getNumber();
			if(!count)
				best = numbers[e];

			if(best == numbers[e])
				++ count;

			else
				-- count;
		}

		count = 0;
		for(long long unsigned int e = 0; e < elements; ++ e)
			if(numbers[e] == best)
				++ count;

		if(count > elements / 2)
			printf("%llu\n", best);

		else
			printf("-1\n");
	}

	return 0;
}

long long unsigned int getNumber(void)
{
	long long unsigned int number = 0;
	while((buffer[p] < '0' || buffer[p] > '9') && ++ p)
		if(p == BUFFER)
		{
			fread(buffer, sizeof(char), BUFFER, stdin);
			p = 0;
		}

	while(buffer[p] >= '0' && buffer[p] <= '9')
	{
		number = number * 10 + buffer[p] - '0';
		++ p;

		if(p == BUFFER)
		{
			fread(buffer, sizeof(char), BUFFER, stdin);
			p = 0;
		}
	}

	return number;
}
