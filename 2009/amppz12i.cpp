/* 2010
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>

int tests,
	numbers,
	nth,
	temp,
	count[100010];

int main(void)
{
	scanf("%d", &tests);
	for(int t = 0; t < tests; ++ t)
	{
		for(int n = 0; n < 100010 ; ++ n)
			count[n] = 0;

		scanf("%d %d", &numbers, &nth);
		for(int n = 0; n < numbers; ++ n)
		{
			scanf("%d", &temp);
			++ count[temp];
		}

		for(int n = 0; n < 100010 ; ++ n)
			if(count[n] < nth)
				nth -= count[n];

			else
			{
				printf("%d\n", n);
				break;
			}
	}

	return 0;
}

