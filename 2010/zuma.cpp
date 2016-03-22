/* 2010
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
#include<vector>
//#define DEBUG(args...) fprintf(stderr, args)
#define DEBUG(args...) {}

int marbles,
	vanish,
	color,
	colors,
	vanishingSpeed[100][100][5];

std::pair<int, int> marble[100];

int vanishing(int start, int end, int supply);
static inline int MIN(int a, int b);
static inline int MAX(int a, int b);

int main(void)
{
	for(int s = 0; s < 100; ++ s)
		for(int e = 0; e < 100; ++ e)
			for(int p = 0; p < 5; ++ p)
				vanishingSpeed[s][e][p] = -1;

	scanf("%d %d", &marbles, &vanish);
	for(int m = 0; m < marbles; ++ m)
	{
		scanf("%d", &color);

		if(colors && marble[colors - 1].first == color)
			++ marble[colors- 1].second;

		else
			marble[colors ++] = std::pair<int, int>(color, 1);
	}

	printf("%d\n", vanishing(0, colors, 0));
	return 0;
}

int vanishing(int start, int end, int supply)
{
	if(start >= end)
		return 0;

	if(vanishingSpeed[start][end][supply] != -1)
		return vanishingSpeed[start][end][supply];

	vanishingSpeed[start][end][supply] = MAX(0, vanish - marble[start].second - supply);
	if(start == end - 1)
		return vanishingSpeed[start][end][supply];

	vanishingSpeed[start][end][supply] += vanishing(start + 1, end, 0);
	for(int m = start + 1; m < end; ++ m)
	{
		if(marble[start].first != marble[m].first)
			continue;

		vanishingSpeed[start][end][supply] = MIN(vanishingSpeed[start][end][supply],
			vanishing(start + 1, m, 0) +
			vanishing(m, end, MIN(vanish - 1, marble[start].second + supply))
		);
	}

	return vanishingSpeed[start][end][supply];
}

static inline int MIN(int a, int b)
{
	return (a < b)?a:b;
}

static inline int MAX(int a, int b)
{
	return (a > b)?a:b;
}
