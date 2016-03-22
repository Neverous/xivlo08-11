/* 2009
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
#define min(a, b) ((a) < (b)?(a):(b))

int tests,
	height,
	width,
	tab[1010][1010],
	result;

int main(void)
{
	scanf("%d", &tests);
	for(int t = 0; t < tests; ++ t)
	{
		scanf("%d %d", &height, &width);
		for(int h = 0; h <= height + 1; ++ h)
			for(int w = 1; w <= width + 1; ++ w)
				tab[h][w] = 1000000000;

		result = 1000000000;
		for(int h = 1; h <= height; ++ h)
			for(int w = 1; w <= width; ++ w)
				scanf("%d", &tab[h][w]);

		for(int w = 1; w <= width; ++ w)
			for(int h = 1; h <= height; ++ h)
				tab[h][w] += min(tab[h][w - 1], min(tab[h - 1][w - 1], tab[h + 1][w - 1])); 

		for(int h = 1; h <= height; ++ h)
			result = min(result, tab[h][width]);

		printf("%d\n", result);
	}

	return 0;
}
