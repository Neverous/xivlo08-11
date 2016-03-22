/* 2010
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
//#define DEBUG(args...) fprintf(stderr, args)
#define DEBUG(args...)

int tests,
	length,
	tab[101],
	result = 1;

inline static int NWD(int a, int b);

int main(void)
{
	scanf("%d", &tests);
	for(int t = 0; t < tests; ++ t)
	{
		result = 1;
		scanf("%d", &length);
		for(int l = 0; l < length; ++ l)
		{
			scanf("%d", &tab[l]);
			-- tab[l];
		}

		for(int l = 0, m = 0, n = 0, cost = 0; l < length; m = ++ l, cost = 0)
		{
			while(tab[m] != -1)
			{
				++ cost;
				n = tab[m];
				tab[m] = -1;
				m = n;
			}

			if(cost)
				result = cost * result / NWD(cost, result);
		}

		printf("%d\n", result);
	}

	return 0;
}

inline static int NWD(int a, int b)
{
	if(a < b)
		return NWD(b, a);

	if(b == 0)
		return a;

	return NWD(b, a % b);
}
