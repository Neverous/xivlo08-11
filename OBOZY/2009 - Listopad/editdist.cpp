/* 2009
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
#include<cstring>
#define abs(a) ((a) > 0?(a):-(a))

char first[1010],
	 second[1010];
int lcs[1010][1010];

int main(void)
{
	scanf("%*d %s %*d %s", first, second);
	for(int f = 0; first[f]; ++ f)
		for(int s = 0; second[s]; ++ s)
		{
			lcs[f + 1][s + 1] = lcs[f + 1][s];
			lcs[f + 1][s + 1] = lcs[f + 1][s] < lcs[f][s + 1]?lcs[f][s + 1]:lcs[f + 1][s];

			if(first[f] == second[s])
				lcs[f + 1][s + 1] = lcs[f][s] + 1;
		}

	printf("%d\n", (int)(strlen(first) + strlen(second) - 2 * lcs[strlen(first)][strlen(second)]));

}

