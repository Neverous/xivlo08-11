/* 2011
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
#include<algorithm>
//#define DEBUG(args...) fprintf(stderr, args)
#define DEBUG(args...)

int villages,
	posts,
	village[1024],
	cost[1024][1024],
	dp[64][1024],
	res[64][1024],
	result[64];

int main(void)
{
	scanf("%d %d", &villages, &posts);
	for(int v = 0; v < villages; ++ v)
		scanf("%d", &village[v]);

	/* PREPROCESS */
	for(int s = 0; s < villages; ++ s)
		for(int c = 1; c < villages - s; ++ c)
			cost[s + c][s] = cost[s + c - 1][s] + village[s + c] - village[s + c / 2];

	/* MAIN ALGO */
	for(int v = 0; v < villages; ++ v)
	{
		dp[0][v] = cost[v][0];
		res[0][v] = 0;
	}

	for(int p = 1, *x = dp[p], *y = dp[p - 1], *z = res[p]; p < posts; y = x, x = dp[++ p], z = res[p])
	{
		for(int v = p, *w = cost[v]; v < villages; w = cost[++ v])
		{
			x[v] = w[0];
			z[v] = 0;
			for(int v2 = p; v2 < v; ++ v2)
				if(x[v] > y[v2] + w[v2 + 1])
				{
					x[v] = y[v2] + w[v2 + 1];
					z[v] = v2;
				}
		}
	}

	printf("%d\n", dp[posts - 1][villages - 1]);
	for(int p = posts - 1, v = villages - 1; p >= 0; -- p)
	{
		printf("%d%c", village[(v + res[p][v] + 1) / 2], p == 0?'\n':' ');
		v = res[p][v];
	}

	return 0;
}

