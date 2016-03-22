/* 2010
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
#include<vector>
#include<cstring>

unsigned int tests,
			 cities,
			 roads,
			 homeland,
			 from,
			 to,
			 cost,
			 jobs,
			 packages,
			 pack,
			 result,
			 matrix[128][128],
			 dp[4096][16];
std::pair<unsigned int, unsigned int> package[16];

inline static void floydWarshall(void);
inline static unsigned int MIN(unsigned int a, unsigned int b);

int main(void)
{
	scanf("%u", &tests);
	for(unsigned int t = 0; t < tests; ++ t)
	{
		pack = 0;
		result = (1 << 30);
		scanf("%u %u %u", &cities, &roads, &homeland);
		 -- homeland;
		for(unsigned int s = 0; s < 128; ++ s)
			for(unsigned int e = 0; e < 128; ++ e)
				matrix[s][e] = (s != e)?100000:0;

		for(unsigned int r = 0; r < roads; ++ r)
		{
			scanf("%u %u %u", &from, &to, &cost);
			-- from;
			-- to;
			matrix[from][to] = matrix[to][from] = MIN(matrix[to][from], cost);
		}

		floydWarshall();
		scanf("%u", &jobs);
		for(unsigned int j = 0; j < jobs; ++ j)
		{
			scanf("%u %u %u", &from, &to, &packages);
			-- from;
			-- to;
			for(unsigned int p = 0; p < packages; ++ p)
				package[pack ++] = std::make_pair(from, to);
		}

		for(unsigned int p = 0; p < 12; ++ p)
			dp[0][p] = (1 << 30);

		for(unsigned int m = 1; m < (1 << 12); ++ m)
			memcpy(dp[m], dp[0], sizeof(unsigned int) * 12);

		for(unsigned int p = 0; p < pack; ++ p)
			dp[1 << p][p] = matrix[homeland][package[p].first] + matrix[package[p].first][package[p].second];

		for(unsigned int m = 1; m < (1 << pack); ++ m)
			for(unsigned int l = 0; l < pack; ++ l)
				if(m & (1 << l))
					for(unsigned int p = 0; p < pack; ++ p)
						if(m & (1 << p) && dp[m][l] > dp[m ^ (1 << l)][p] + matrix[package[p].second][package[l].first] + matrix[package[l].first][package[l].second])
							dp[m][l] = dp[m ^ (1 << l)][p] + matrix[package[p].second][package[l].first] + matrix[package[l].first][package[l].second];

		for(unsigned int p = 0; p < pack; ++ p)
			if(result > dp[(1 << pack) - 1][p] + matrix[package[p].second][homeland])
				result = dp[(1 << pack) - 1][p] + matrix[package[p].second][homeland];

		printf("%u\n", result);
	}

	return 0;
}

inline static unsigned int MIN(unsigned int a, unsigned int b)
{
	return a<b?a:b;
}

inline static void floydWarshall(void)
{
	for(unsigned int b = 0; b < cities; ++ b)
		for(unsigned int f =  0; f < cities; ++ f)
			for(unsigned int t = 0; t < cities; ++ t)
				matrix[f][t] = MIN(matrix[f][t], matrix[f][b] + matrix[b][t]);
}


