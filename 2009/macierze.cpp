/* 2009
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
//#define DEBUG(args...) fprintf(stderr, args)
#define DEBUG(args...) 

int recurse(int start, int end);

int tests,
	matrices,
	matrix[256],
	speed[256][256];

int main(void)
{
	scanf("%d", &tests);
	for(int t = 0; t < tests; ++ t)
	{
		scanf("%d", &matrices);
		for(int m = 0; m <= matrices; ++ m)
		{
			for(int n = 0; n <= matrices; ++ n)
				speed[n][m] = -1;

			scanf("%d", &matrix[m]);
		}

		if(matrices > 1)
			printf("%d\n", recurse(0, matrices));

		else
			printf("0\n");
	}
	return 0;
}

int recurse(int start, int end)
{
	if(speed[start][end] != -1)
		return speed[start][end];

	int temp;

	if(end - start == 2)
	{
		speed[start][end] = 1;
		for(int s = start; s <= end; ++ s)
			speed[start][end] *= matrix[s];

		return speed[start][end];
	}

	if(end - start < 2)
	{
		speed[start][end] = 0;
		return 0;
	}

	speed[start][end] = 1000000000;
	for(int p = start + 1; p < end; ++ p)
	{
		temp = recurse(start, p) + recurse(p, end) + matrix[start] * matrix[p] * matrix[end];
		speed[start][end] = speed[start][end] < temp?speed[start][end]:temp;
	}

	return speed[start][end];
}
