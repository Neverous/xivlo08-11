/* 2009
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
#include<cstring>
#define max(a,b) (((a) > (b))?(a):(b))

int lcs[2][1002],
	tests,
	firstSize,
	secondSize;

char first[1002],
	 second[1002];

inline int lenLCS(int &firstSize, char *first, int &secondSize, char *second);

int main(void)
{
	scanf("%d", &tests);
	for(int t = 0; t < tests; ++ t)
	{
		scanf("%d %s", &firstSize, first);
		scanf("%d %s", &secondSize, second);
		printf("%d\n", lenLCS(firstSize, first, secondSize, second));
	}

	return 0;
}

inline int lenLCS(int &firstSize, char *first, int &secondSize, char *second)
{
	for(int s = 0; s < 1002; ++ s)
		lcs[0][s] = lcs[1][s] = 0;

	for(int f = 0; f < firstSize; ++ f)
		for(int s = 0; s < secondSize; ++ s)
			if(first[f] == second[s])
				lcs[(f + 1) % 2][s + 1] = lcs[f % 2][s] + 1;

			else
				lcs[(f + 1) % 2][s + 1] = max(lcs[(f + 1) % 2][s], lcs[f % 2][s + 1]);
	
	return lcs[firstSize % 2][secondSize];
}
