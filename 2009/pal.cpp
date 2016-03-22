/* 2010
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
#include<string>
#include<algorithm>

int tests,
	letters;
std::string sWord,
			rWord;
char word[64];
int KMP(std::string &pattern);

int main(void)
{
	scanf("%d", &tests);
	for(int t = 0; t < tests; ++ t)
	{
		scanf("%s", word);
		rWord = std::string(word);
		std::reverse(rWord.begin(), rWord.end());
		sWord = rWord + "$" + std::string(word);
		letters = KMP(sWord);
		printf("%s%s\n", word, rWord.c_str() + letters);
	}

	return 0;
}

int KMP(std::string &pattern)
{
	int p[128];
	for(int i = 0; i < 128; ++ i)
		p[i] = 0;

	for(int i = 1, j = 0; pattern[i]; ++ i)
	{
		while(j > 0 && pattern[i] != pattern[j])
			j = p[j - 1];

		if(pattern[i] == pattern[j])
			p[i] = ++ j;

	}

	return p[pattern.length() - 1];
}
