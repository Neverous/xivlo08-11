/* 2010
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
#include<vector>
//#define DEBUG(args...) fprintf(stderr, args)
#define DEBUG(args...)

int size,
	a,
	b,
	need;
long long unsigned int number,
					   remember[4001][35];

long long unsigned int count(int open, int close);

int main(void)
{
	scanf("%d %llu", &size, &number);
	a = size;
	b = size;
	for(int s = 0; s < 2 * size; ++ s)
	{
		if(count(a - 1, b) >= number)
		{
			printf("(");
			-- a;
		}

		else
		{
			printf(")");
			number -= count(a - 1, b);
			-- b;
		}
	}

	puts("");
	return 0;
}

long long unsigned int count(int open, int close)
{
	if(open < 0 || open > close)
		return 0;

	if(!open)
		return 1;

	if(open >= 35)
		return 3116285494907301262LLU;

	if(remember[close][open])
		return remember[close][open];

	remember[close][open] = count(open - 1, close) + ((close > open)?count(open, close - 1):0);
	if(remember[close][open] > count(35, 35))
		remember[close][open] = count(35, 35);

	return remember[close][open];
}
