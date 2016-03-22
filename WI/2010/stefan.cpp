/* 2010
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
//#define DEBUG(args...) fprintf(stderr, args)
#define DEBUG(args...)

long long int numbers,
			  sum,
			  min,
			  best;

inline static long long int MIN(const long long int &A, const long long int &B);
inline static long long int MAX(const long long int &A, const long long int &B);

const int BUFFER = 4096;
int p = BUFFER - 1;
char buffer[BUFFER];

long long int getNumber(void)
{
	long long int number = 0;
	bool under = false;
	while((buffer[p] < '0' || buffer[p] > '9') && buffer[p] != '-')
		if(++ p == BUFFER)
		{
			fread(buffer, sizeof(char), BUFFER, stdin);
			p = 0;
		}

	while(buffer[p] == '-' || (buffer[p] >= '0' && buffer[p] <= '9'))
	{
		if(buffer[p] == '-')
			under = true;

		else
			number = number * 10 + buffer[p] - '0';

		if(++ p == BUFFER)
		{
			fread(buffer, sizeof(char), BUFFER, stdin);
			p = 0;
		}
	}

	return under?-number:number;
}

int main(void)
{
	numbers = getNumber();
	for(unsigned int n = 0; n < numbers; ++ n)
	{
		sum += getNumber();
		min = MIN(sum, min);
		best = MAX(sum - min, best);
	}

	printf("%lld\n", best);
	return 0;
}


inline static long long int MIN(const long long int &A, const long long int &B)
{
	return A<B?A:B;
}

inline static long long int MAX(const long long int &A, const long long int &B)
{
	return A>B?A:B;
}
