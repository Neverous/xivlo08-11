/* 2011
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
#include<algorithm>
#include<vector>
//#define DEBUG(args...) fprintf(stderr, args)
#define DEBUG(args...)

unsigned int tests,
			 points;
std::vector<std::pair<unsigned int, unsigned int> > point[2];

static inline std::pair<unsigned int, unsigned int> operator+(const std::pair<unsigned int, unsigned int> &A, const std::pair<unsigned int, unsigned int> &B);
static inline std::pair<unsigned int, unsigned int> operator/(const std::pair<unsigned int, unsigned int> &A, const int &D);
inline static int solve(void);

int main(void)
{
	scanf("%u", &tests);
	for(unsigned int t = 0; t < tests; ++ t)
	{
		scanf("%u", &points);
		point[0].clear();
		point[0].resize(points);
		point[1].clear();
		for(unsigned int p = 0; p < points; ++ p)
		{
			scanf("%u %u", &point[0][p].first, &point[0][p].second);
			point[0][p].first *= 2;
			point[0][p].second *= 2;
		}

		if(points < 4)
			puts("-1");

		else
			printf("%d\n", solve());
	}

	return 0;
}

inline static int solve(void)
{
	for(unsigned int p = 0; p < point[0].size(); ++ p)
		for(unsigned int p2 = p + 1; p2 < point[0].size(); ++ p2)
			point[1].push_back((point[0][p] + point[0][p2]) / 2);

	std::sort(point[1].begin(), point[1].end());
	for(unsigned int p = 1; p < point[1].size(); ++ p)
		if(point[1][p] == point[1][p - 1])
			return 1;

	return 2;
}

static inline std::pair<unsigned int, unsigned int> operator+(const std::pair<unsigned int, unsigned int> &A, const std::pair<unsigned int, unsigned int> &B)
{
	return std::pair<unsigned int, unsigned int> (A.first + B.first, A.second + B.second);
}

static inline std::pair<unsigned int, unsigned int> operator/(const std::pair<unsigned int, unsigned int> &A, const int &D)
{
	return std::pair<unsigned int, unsigned int> (A.first / D, A.second / D);
}

