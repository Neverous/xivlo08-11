/* 2010
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>

int students,
	can[20][20],
	s,
	m,
	mask,
	w;
long long int dp[1 << 20][2];

int main(void)
{
	scanf("%d", &students);
	for(s = 0; s < students; ++ s)
		for(w = 0; w < students; ++ w)
			scanf("%d", &can[s][w]);

	for(m = 1, w = 0; w < students; m *= 2, ++ w)
		dp[m][0] += can[0][w];

	for(s = 1; s < students; ++ s)
		for(m = 1 << (s - 1), mask = 1 << (s - 1); m < (1 << students); ++ m, w = 0, mask = m)
			if(__builtin_popcount(mask) > s)
			while(mask && w < students)
			{
				w = __builtin_ctz(mask);
				if(can[s][w])
					dp[m][s % 2] += dp[m ^ (1 << w)][(s + 1) % 2];

				mask ^= (1 << w);
			}

	printf("%lld\n", dp[(1 << students) - 1][(students + 1) % 2]);
	return 0;
}
