/* 2010
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
#include<cstdlib>
//#define DEBUG(args...) fprintf(stderr, args)
#define DEBUG(args...)
#define ABS(a) ((a) < 0?-(a):(a))

int a,
	b,
	c,
	res;

int main(void)
{
	scanf("%d %d %d", &a, &b, &c);
	res = ABS(a - b) + ABS(a - c);
	res = res > ABS(b - a) + ABS(b - c)?ABS(b - a) + ABS(b - c):res;
	res = res > ABS(c - a) + ABS(b - c)?ABS(c - a) + ABS(b - c):res;
	printf("%d\n", res);
	return 0;
}

