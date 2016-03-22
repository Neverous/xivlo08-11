/* 2009
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
#define max(a, b) ((a) > (b)?(a):(b))

int f,
	s,
	lcs[102][102];
char first[102],
	 second[102];

int main(void)
{
	scanf("%s", first);
	scanf("%s", second);

	for(f = 0; first[f]; ++ f)
		for(s = 0; second[s]; ++ s)
		{
			lcs[f + 1][s + 1] = max(lcs[f + 1][s], lcs[f][s + 1]);
			if(first[f] == second[s])
				lcs[f + 1][s + 1] = max(lcs[f][s] + 1, lcs[f + 1][s + 1]);
		}

	printf("%d\n", lcs[f][s]);
	return 0;
}
