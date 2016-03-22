/* 2010
 * Maciej Szeptuch
 * XIV LO Wrocław
 * ----------
 *  Wykręcanie każdej setnej sekundy ;P
 *		i każdego bajtu...
 */
#include<cstdio>
#include<string>
#include<algorithm>
//#define DEBUG(args...) fprintf(stderr, args)
#define DEBUG(args...)

char temp[1024];
unsigned int words;
std::string word[1600];

inline static bool removeSuffixes(void);
inline static void removeDuplicates(void);

int main(void)
{
	scanf("%u", &words);
	for(unsigned int w = 0; w < words; ++ w)
	{
		scanf("%s", temp);
		word[w] = std::string(temp);
	}

	std::sort(word, word + words);
	do
		removeDuplicates();
	while(removeSuffixes());

	printf("%s\n", (words == 2 && word[0].size() == 1 && word[1].size() == 1)?"NIE":"TAK");
	return 0;
}

inline static void removeDuplicates(void)
{
	int nw = 1;
	for(unsigned int w = 1; w < words; ++ w)
		if(word[w] != word[w - 1])
			word[nw ++] = word[w];

	words = nw;
	return;
}

inline static bool removeSuffixes(void)
{
	bool worked = false,
		 suffix;
	for(unsigned int w = 0, ws = word[0].size(), wS = *word[w].rbegin(); w < words; ws = word[++ w].size(), wS = *word[w].rbegin())
	{
		if(ws < 2)
			continue;

		suffix = false;
		for(unsigned int d = 0, ds = word[0].size(); !suffix && d < words; ds = word[++ d].size())
			if(w != d && ws >= ds && wS != *word[d].rbegin())
			{
				suffix = true;
				for(unsigned int a = ws - ds, b = 0, c = ds - 1; suffix && b < c; ++ a, ++ b)
					suffix = word[w][a] == word[d][b];
			}

		if(suffix)
		{
			word[w].erase(ws - 1);
			worked = true;
		}
	}

	return worked;
}

