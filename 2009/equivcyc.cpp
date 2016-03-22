/* 2009
 *  * Maciej Szeptuch
 *   * XIV LO Wrocław
 *    */
#include<cstdio>
#include<cstdlib>
#include<cstring>

char word[2000002],
	 pattern[1000001];
int tests,
	pi[2000002],
	wordSize,
	patternSize;

void kmpPrefix(char *word, int *pi)
{
	pi[0] = pi[1] = 0;
	for(int p = 1, l = 0; word[p]; ++ p)
	{
		while(l && word[p] != word[l])
			l = pi[l-1];

		if(word[p] == word[l])
			++ l;

		pi[p] = l;
	}
	return;
} //KNUTH PI

bool kmpFind(char *pattern, char *word)
{
	wordSize = strlen(word);
	patternSize = strlen(pattern);
	if(patternSize != wordSize)
		return false;

	for(int p = 0; p < wordSize; ++ p)
	{
		word[wordSize+p] = word[p];
		word[wordSize+p+1] = 0;
	} //DOUBLE WORD

	kmpPrefix(pattern, pi);

	for(int p = 0, l = 0; word[p]; ++ p)
	{
		while(l && word[p] != pattern[l])
			l = pi[l-1];

		if(word[p] == pattern[l])
			++ l;

		if(l == patternSize)
			return true;
	} 

	return false;
}

int main(void)
{
	scanf("%d", &tests);
	for(int t = 0; t < tests; ++ t)
	{
		word[0] = 0;
		pattern[0] = 0;
		scanf("%s%s", word, pattern);
		printf("%s\n", kmpFind(pattern, word)?"TAK":"NIE");
	}
	return 0;
}

