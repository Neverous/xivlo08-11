/* 2010
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
#include<string>
//#define DEBUG(args...) fprintf(stderr, args)
#define DEBUG(args...)

unsigned int tests,
			 words = 15,
			 cost[15][15],
			 minLength[1 << 15][15],
			 result,
			 bestW,
			 bestP;
char temp[101];
std::string word[15];

inline unsigned int count(std::string &from, std::string &to);
inline static unsigned int MIN(unsigned int A, unsigned int B);

int main(void)
{
	scanf("%u", &tests);
	for(unsigned int t = 0; t < tests; ++ t)
	{
		for(unsigned int f = 0; f < (1 << words); ++ f)
			for(unsigned int s = 0; s < words; ++ s)
				minLength[f][s] = (1 << 11);

		scanf("%u", &words);
		for(unsigned int w = 0; w < words; ++ w)
		{
			scanf("%s", temp);
			word[w] = std::string(temp);
		}

		/* SOLVE */
		for(unsigned int f = 0; f < words; ++ f)
			for(unsigned int s = 0; s < words; ++ s)
				if(f != s && count(word[f], word[s]) == word[f].length())
					word[f --] = word[-- words];

		for(unsigned int f = 0; f < words; ++ f)
			for(unsigned int s = 0; s < words; ++ s)
				cost[f][s] = count(word[f], word[s]);

		for(unsigned int f = 0; f < (1 << words); ++ f)
		{
			for(unsigned int w = 0; w < words; ++ w)
			{
				if(!(f & (1 << w)))
					continue;

				if(!(f ^ (1 << w)))
				{
					minLength[f][w] = word[w].length();
					continue;
				}

				for(unsigned int n = 0; n < words; ++ n)
				{
					if(!(f & (1 << n)) || w == n)
						continue;

					minLength[f][w] = MIN(minLength[f][w], minLength[f ^ (1 << w)][n] + word[w].length() - cost[w][n]);
				}
			}
		}

		result = (1 << words) - 1;
		for(unsigned int l = 0; l < words; ++ l)
		{
			bestP = bestW;
			bestW = (1 << 11);
			for(unsigned int w = 0; w < words; ++ w)
			{
				if(!(result & (1 << w)))
					continue;

				if(!l)
				{
					if(bestW == (1 << 11) || minLength[result][w] < minLength[result][bestW] || (minLength[result][w] == minLength[result][bestW] && word[w] < word[bestW]))
						bestW = w;
				}

				else
				{
					if(bestW == (1 << 11) || minLength[result][w] - cost[bestP][w] < minLength[result][bestW] - cost[bestP][bestW] || (minLength[result][w] - cost[bestP][w] == minLength[result][bestW] - cost[bestP][bestW] && word[w].substr(cost[bestP][w]) < word[bestW].substr(cost[bestP][bestW])))
						bestW = w;
				}
			}

			printf("%s", (l?word[bestW].substr(cost[bestP][bestW]):word[bestW]).c_str());
			result ^= (1 << bestW);
		}

		puts("");
	}

	return 0;
}

inline unsigned int count(std::string &from, std::string &to)
{
	unsigned int best = 0,
				 pi[202];
	std::string Word = to + '#' + from;
	for(int p = 0; p < 202; ++ p)
		pi[p] = 0;

	for(unsigned int w = 1, s = 0; w < Word.length(); ++ w)
	{
		while(s > 0 && Word[w] != Word[s])
			s = pi[s - 1];

		if(Word[w] == Word[s])
		{
			pi[w] = ++ s;
			if(s > best)
				best = s;
		}
	}

	return best == from.length()?best:pi[Word.length() - 1];
}

inline static unsigned int MIN(unsigned int A, unsigned int B)
{
	return A < B?A:B;
}
