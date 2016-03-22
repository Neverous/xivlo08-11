/* 2009
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
#include<cstdlib>
#include<cstring>

char word[1000001];
int tests,
	pi[1000001],
	pi2[1000001];

void kmpPrefix2(char *word, int *pi2)
{
	pi[0] = pi[1] = pi2[0] = pi2[1] = 0;
	for(int p = 0, l = 0, k = 0; word[p]; ++ p)
	{

		if(p)
		{
			while(k && word[p] != word[k])
				k = pi[k-1];

			l = k;
			if(word[p] == word[k])
				++ k;

			pi[p] = k;
		} //KNUTH PI

		while(l && (word[p] != word[l] || word[p+1] == word[l+1]))
		{
			l = pi[l-1];
			if(pi2[l] <= 0 && word[p+1] == word[l+1])
			{
				l = 0;
				break;
			}
		}

		if(word[p] == word[l] && word[p+1] != word[l+1])
			++ l;

		pi2[p] = l;
		if(l!=0)
			continue;

		if(word[0] != word[p+1])
			pi2[p] = 0;

		else
			pi2[p] = -1;
	}
	return;
} //KNUTH PI2

int main(void)
{
	scanf("%d", &tests);
	for(int t = 0; t < tests; ++ t)
	{
		scanf("%s", word);
		kmpPrefix2(word, pi2);
		for(int p = 0; word[p]; ++ p)
			printf("%d ", pi2[p]);

		puts("");
	}
	return 0;
}

