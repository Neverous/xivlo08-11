/* 2011
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
//#define DEBUG(args...) fprintf(stderr, args)
#define DEBUG(args...)

int a,
	b,
	c,
	d,
	e,
	f,
	T,
	B,
	N;

static inline int nwd(int a, int b);

int main(void)
{
	scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);
	T = a * c * e;
	B = b * d * f;
	N = nwd(T, B);
	T /= N;
	B /= N;
	printf("%d/%d\n", T, B);
	return 0;
}

static inline int nwd(int a, int b)
{
	int c;
	if(a < b)
	{
		c = a;
		a = b;
		b = c;
	}

	while(b)
	{
		c = b;
		b = a % b;
		a = c;
	}

	return a;
}
