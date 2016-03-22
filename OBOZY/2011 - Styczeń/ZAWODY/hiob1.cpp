/* 2011
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
//#define DEBUG(args...) fprintf(stderr, args)
#define DEBUG(args...)

int indirect;

int main(void)
{
	scanf("%*d %*d %d", &indirect);
	puts(indirect & 1?"Bob":"Alice");
	return 0;
}

