/* 2010
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
#define MIN(a, b) ((a) > (b)?(b):(a))

int lcs[1010][10010],
	min;
char pattern[1010],
	 word[10010];

int main(void)
{
	for(int w = 0; w < 10010; ++ w)
		lcs[0][w] = 0;

	for(int p = 1; p < 1010; ++ p)
		lcs[p][0] = 100000000;

	while(scanf("%s %s", pattern, word) != -1)
	{
		min = 100000000;
		for(int p = 0; pattern[p]; ++ p)
			for(int w = 0; word[w]; ++ w)
			{
				if(pattern[p] == word[w] || pattern[p] == '?')
					lcs[p + 1][w + 1] = lcs[p][w] + word[w] - 'a' + 1;

				else if(pattern[p] == '*')
					lcs[p + 1][w + 1] = MIN(lcs[p + 1][w] + word[w] - 'a' + 1, lcs[p][w + 1]);

				else
					lcs[p + 1][w + 1] = 100000000;

				if(!pattern[p + 1])
					if(min > lcs[p + 1][w + 1])
						min = lcs[p + 1][w + 1];
			}

		printf("%d\n", min == 100000000?-1:min);
	}
	return 0;
}

