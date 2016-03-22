/* 2009
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
//#define DEBUG(args...) fprintf(stderr, args)
#define DEBUG(args...) 

int days,
	money,
	cost,
	best,
	profit;

int main(void)
{
	while(scanf("%d %d", &days, &money) != -1 && days)
	{
		profit = 0;
		best = 50000;
		for(int d = 0; d < days; ++ d)
		{
			scanf("%d", &cost);
			if(profit < (cost - best) * (money / best))
				profit = (cost - best) * (money / best);

			if(best > cost)
				best = cost;
		}

		printf("%d\n", profit);
	}

	return 0;
}

