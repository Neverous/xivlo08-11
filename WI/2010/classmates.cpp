#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

int first,
	second,
	length,
	firstLength,
	logT[400040],
	secondLength;
vector<int> hash[20];
vector<pair<pair<int, int>, int> > sortMe;
char word[400040];

inline void preprocess(void);
inline bool checkEquality(int a, int b, int l);
inline int log(int n);

int main(void)
{
	for(int n = 0; n < 400040; ++ n)
		logT[n] = -1;

	scanf("%s%n ", word, &firstLength);
	scanf("%s%n", word + firstLength, &secondLength);
	preprocess();
	while(scanf("%d %d %d", &first, &second, &length) != -1 && first && second && length)
		printf("%s\n", checkEquality(first - 1, second + firstLength - 1, length)?"TAK":"NIE");

	return 0;
}

inline void preprocess(void)
{
	hash[0].resize(firstLength + secondLength);
	for(int w = 0; w < firstLength + secondLength; ++ w)
		hash[0][w] = word[w];

	for(int h = 1; (1 << h) < firstLength + secondLength; ++ h)
	{
		hash[h].resize(firstLength + secondLength - (1 << (h - 1)));
		sortMe.resize(firstLength + secondLength - (1 << (h - 1)));
		for(int w = 0; w < firstLength + secondLength - (1 << (h - 1)); ++ w)
			sortMe[w] = pair<pair<int, int>, int>(pair<int, int>(hash[h - 1][w], hash[h - 1][w + (1 << (h - 1))]), w);

		sort(sortMe.begin(), sortMe.end());
		for(int w = 0, k = 0; w < firstLength + secondLength - (1 << (h - 1)); ++ w)
		{
			if(w && sortMe[w].first != sortMe[w - 1].first)
				++ k;

			hash[h][sortMe[w].second] = k;
		}
	}
}

inline bool checkEquality(int a, int b, int l)
{
	int power = log(l);
	return hash[power][a] == hash[power][b] && hash[power][a + l - (1 << power)] == hash[power][b + l - (1 << power)];
}

inline int log(int n)
{
	if(logT[n] != -1)
		return logT[n];

	logT[n] = 20;
	while((1 << logT[n]) > n)
		-- logT[n];

	return logT[n];
}
