/* 2010
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
#define INFTY 32766

int cities,
	weight[20][20],
	dp[(1 << 19)][19],
	result = INFTY,
	s;

int main(void)
{
	scanf("%d", &cities);
	for(int f = 0; f < cities; ++ f)
		for(int t = 0; t < cities; ++ t)
			scanf("%d", &weight[f][t]);

	-- cities;
	s = (1 << cities);
	for(int d = 0; d < s; ++ d)
		for(int p = 0; p < cities; ++ p)
			dp[d][p] = INFTY;

	for(int c = 0; c < cities; ++ c)
		dp[1 << c][c] = weight[0][c + 1];

	for(int d = 3; d < s; ++ d)
		for(int e = 0, r = 1; e < cities; ++ e, r = (1 << e))
			if(d & r)
				for(int v = 0, t = 1; v < cities; ++ v, t = (1 << v))
					if(d & t && dp[d][e] > dp[d ^ r][v] + weight[v + 1][e + 1])
						dp[d][e] = dp[d ^ r][v] + weight[v + 1][e + 1];

	for(int c = 0; c < cities; ++ c)
		if(result > dp[s - 1][c] + weight[c + 1][0])
			result = dp[s - 1][c] + weight[c + 1][0];

	printf("%d\n", result);

	return 0;
}

