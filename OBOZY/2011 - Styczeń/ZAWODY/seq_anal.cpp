/* 2011
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
//#define DEBUG(args...) fprintf(stderr, args)
#define DEBUG(args...)
#define moveIt(x) ((a * (x) + (x) % b) % c)

unsigned int tests;
long long int A, B, C;

inline static int generate(const long long int &a, const long long int &b, const long long int &c);

int main(void)
{
	scanf("%u", &tests);
	for(unsigned int t = 0; t < tests; ++ t)
	{
		scanf("%lld %lld %lld", &A, &B, &C);
		printf("%d ", generate(A, B, C));
	}

	puts("");
	return 0;
}

inline static int generate(const long long int &a, const long long int &b, const long long int &c)
{
	int pFirst = 0,
		pSecond = 0,
		cycle = 0;
	long long int vFirst = 1,
		 vSecond = 1;
	bool flag = false;

	do
	{
		if(flag){++ pFirst; vFirst = moveIt(vFirst);}
		else{pSecond += 2; vSecond = moveIt(moveIt(vSecond));}
		flag ^= true;
	}
	while(pSecond < 4000000 && vSecond != vFirst);

	if(pSecond == 4000000)
		return -1;

	do
	{
		++ cycle;
		vSecond = moveIt(vSecond);
	}
	while(vSecond != vFirst);

	vFirst = vSecond = 1;
	pFirst = pSecond = 0;
	while(cycle --)
	{
		++ pSecond;
		vSecond = moveIt(vSecond);
	}

	while(pSecond <= 2000000 && vSecond != vFirst)
	{
		++ pFirst;
		++ pSecond;
		vFirst = moveIt(vFirst);
		vSecond = moveIt(vSecond);
	}

	if(pSecond > 2000000)
		return -1;

	return pSecond;
}
