/* 2011
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
#include<cmath>
//#define DEBUG(args...) fprintf(stderr, args)
#define DEBUG(args...)

unsigned int number;

bool isSquare(unsigned int num);

int main(void)
{
	scanf("%u", &number);
	if(isSquare(number))
	{
		puts("1");
		return 0;
	}

	for(unsigned int n = 1, w = 1; w <= number; w = (++ n) * n)
		for(unsigned int n2 = 1, w2 = 1; w2 <= number; w2 = (++ n2) * n2)
			if(w + w2 == number)
			{
				puts("2");
				return 0;
			}

	for(unsigned int n = 1, w = 1; w <= number; w = (++ n) * n)
		for(unsigned int n2 = 1, w2 = 1; w2 <= number; w2 = (++ n2) * n2)
			if(w + w2 < number && isSquare(number - w - w2))
			{
				puts("3");
				return 0;
			}

	puts("4");
	return 0;
}

bool isSquare(unsigned int num)
{
	unsigned int sqr = sqrt(num);
	return sqr * sqr == num;
}
