#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

int length[5],
	words,
	len[5],
	logT[2000],
	from, to = 10000;
vector<int> hash[15];
vector<pair<pair<int, int>, int> > sortMe;
char word[10010];

inline void preprocess(void);
inline bool checkEquality(int a, int b, int l);
inline bool check(int length);
inline int log(int n);

int main(void)
{
	for(int n = 0; n < 2000; ++ n)
		logT[n] = -1;

	scanf("%d", &words);
	for(int w = 0; w < words; ++ w)
	{
		scanf("%s", (word + (w?len[w - 1]:0)));
		length[w] = strlen(word + (w?len[w - 1]:0));
		if(to > length[w])
			to = length[w];

		len[w] = length[w];
		if(w)
			len[w] += len[w - 1];

	}

	preprocess();
	from = 0;
	while(from < to)
	{
		if(check((from + to + 1) / 2))
			from = (from + to + 1) / 2;

		else
			to = (from + to + 1) / 2 - 1;
	}

	printf("%d\n", to);
	return 0;
}

inline bool checkEquality(int a, int b, int l)
{
	int power = log(l);
	return hash[power][a] == hash[power][b] && hash[power][a + l - (1 << power)] == hash[power][b + l - (1 << power)];
}

inline void preprocess(void)
{
	hash[0].resize(len[words - 1]);
	for(int w = 0; w < len[words - 1]; ++ w)
		hash[0][w] = word[w];

	for(int h = 1; (1 << h) < len[words - 1]; ++ h)
	{
		hash[h].resize(len[words - 1] - (1 << (h - 1)));
		sortMe.resize(len[words - 1] - (1 << (h - 1)));
		for(int w = 0; w < len[words - 1] - (1 << (h - 1)); ++ w)
			sortMe[w] = pair<pair<int, int>, int>(pair<int, int>(hash[h - 1][w], hash[h - 1][w + (1 << (h - 1))]), w);

		sort(sortMe.begin(), sortMe.end());
		for(int w = 0, k = 0; w < len[words - 1] - (1 << (h - 1)); ++ w)
		{
			if(w && sortMe[w].first != sortMe[w - 1].first)
				++ k;

			hash[h][sortMe[w].second] = k;
		}
	}
}

inline bool check(int leng)
{
	bool best = false;
	for(int m = 0; !best && m <= length[0] - leng; ++ m)
	{
		best = true;
		for(int w = 1; best && w < words; ++ w)
		{
			best = false;
			for(int pos = 0; !best && pos <= length[w] - leng; ++ pos)
				if(checkEquality(m, len[w - 1] + pos, leng))
					best = true;
		}
	}

	return best;
}

inline int log(int n)
{
	if(logT[n] != -1)
		return logT[n];

	logT[n] = 11;
	while((1 << logT[n]) > n)
		-- logT[n];

	return logT[n];
}
