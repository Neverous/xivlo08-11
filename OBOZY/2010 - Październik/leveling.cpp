/* 2010
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
#include<algorithm>
//#define DEBUG(args...) fprintf(stderr, args)
#define DEBUG(args...)

int tab[1000001],
	modulo,
	length;
long long int result;

inline static int ABS(int a);

int main(void)
{
	scanf("%d %d %d", &length, &tab[0], &modulo);
	for(int l = 1, x = tab[l - 1]; l < length; x = tab[l ++])
		tab[l] = (109LL * x * x + 987732LL * x + 65382LL) % 9999971LL;

	for(int l = 0; l < length; ++ l)
		tab[l] %= modulo;

	std::sort(tab, tab + length);
	for(int l = 0; l < length; ++ l)
		result += ABS(tab[l] - tab[length / 2]);

	printf("%lld\n", -result);
	return 0;
}

inline static int ABS(int a)
{
	return a>0?a:-a;
}
