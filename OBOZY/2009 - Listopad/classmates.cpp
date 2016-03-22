/* 2009
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int firstLength,
	secondLength,
	first,
	second,
	letters;
char word[400004];
vector<int> hash[20];
vector<pair<pair<int, int>, int> > temp;

inline void preprocess(void);
inline bool checkHash(int firstPos, int secondPos, int count);

int main(void)
{
	scanf("%s%n ", word, &firstLength);
	scanf("%s%n ", word + firstLength, &secondLength);
	preprocess();
	while(scanf("%d %d %d", &first, &second, &letters) != -1 && letters > 0)
		printf("%s\n", checkHash(first - 1, second + firstLength - 1, letters)?"TAK":"NIE");

	return 0;
}

inline void preprocess(void)
{
	hash[0].resize(firstLength + secondLength);
	for(int h = 0; h < firstLength + secondLength; ++ h)
		hash[0][h] = (int)word[h]; // wszystkie podsłowa jednoliterowe

	for(int h = 1; (1 << h) < firstLength + secondLength; ++ h) // podsłowa o rozmiarze 2**h, h > 0
	{
		hash[h].resize(firstLength + secondLength - (1 << (h - 1)));
		temp.resize(firstLength + secondLength - (1 << (h - 1)));
		for(int p = 0; p < firstLength + secondLength - (1 << (h - 1)); ++ p)
			temp[p] = make_pair(make_pair(hash[h - 1][p], hash[h - 1][p + (1 << (h - 1))]), p);

		sort(temp.begin(), temp.end());
		for(int p = 0, k = 0; p < firstLength + secondLength - (1 << (h - 1)); ++ p)
		{
			if(p && temp[p].first != temp[p - 1].first)
				++ k;

			hash[h][temp[p].second] = k;
		}
	}
}

inline bool checkHash(int firstPos, int secondPos, int count)
{
	int log;
	for(log = 0; (1 << log) < count / 2; ++ log);

	return hash[log][firstPos] == hash[log][secondPos] && hash[log][firstPos + count - (1 << log)] == hash[log][secondPos + count - (1 << log)];
}
