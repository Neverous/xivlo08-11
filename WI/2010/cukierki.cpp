/* 2010
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
//#define DEBUG(args...) fprintf(stderr, args)
#define DEBUG(args...)

int sweets,
	count,
	result;

int NWD(int a, int b);

int main(void)
{
	scanf("%d %d", &sweets, &result);
	for(int s = 1; s < sweets; ++ s)
	{
		scanf("%d", &count);
		result = NWD(result, count);
	}

	printf("%d\n", result);
	return 0;
}

int NWD(int a, int b)
{
	if(!a)
		return b;

	if(a > b)
		return NWD(b, a);

	return NWD(b % a, a);
}
