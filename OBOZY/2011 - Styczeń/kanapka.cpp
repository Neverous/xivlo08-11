/* 2011
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
#include<cmath>
//#define DEBUG(args...) fprintf(stderr, args)
#define DEBUG(args...)
#define P_G 981

unsigned int tests;
double length,
	velocity,
	height;
double obr;

int main(void)
{
	scanf("%u", &tests);
	for(unsigned int t = 0; t < tests; ++ t)
	{
		scanf("%lf %lf %lf", &length, &velocity, &height);
		obr = (double)velocity * sqrt((height - length) / P_G * 2);
		obr -= (int)obr;
		if(obr >= 0.25 && obr <= 0.75)
			puts("butter");

		else
			puts("bread");
	}

	return 0;
}

