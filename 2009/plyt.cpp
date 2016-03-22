/* 2010
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
//#define DEBUG(args...) fprintf(stderr, args)
#define DEBUG(args...)
#define MAX(a, b) ((a) > (b)?(a):(b))

int height,
	width,
	result[2][17][1 << 16],
	map[17][17];

int main(void)
{
	scanf("%d %d", &height, &width);
	for(int h = 0; h < height; ++ h)
		for(int w = 0; w < width; ++ w)
			scanf("%d", &map[h][w]);

	for(int w = 0; w < width; ++ w)
	{
		for(int h = 0; h < height; ++ h)
			for(int mask = 0; mask < (1 << height); ++ mask)
			{
				if(h == 0)
				{
					result[w % 2][h][mask] = result[(w + 1) % 2][height - 1][mask | 1] + (!map[h][w] && (mask & (1 << h)));
					continue;
				}

				result[w % 2][h][mask] = result[w % 2][h - 1][mask | (1 << h)] + (!map[h][w] && (mask & (1 << h)));
				if(w > 0 && h > 0 &&
					!map[h - 1][w - 1] && !map[h - 1][w] &&
					!map[h][w - 1] && !map[h][w] &&
					(mask & (3 << (h - 1))) == (3 << (h - 1)))
				{
					if(h < 2)
						result[w % 2][h][mask] = MAX(result[w % 2][h][mask], 16 + result[(w + 1) % 2][height - 1][mask ^ (3 << (h - 1))]);

					else
						result[w % 2][h][mask] = MAX(result[w % 2][h][mask], 16 + result[w % 2][h - 2][mask ^ (3 << (h - 1))]);
				}
			}
	}

	//for(int h = 0; h < height; ++ h)
	//for(int mask = 0; mask < (1 << height); ++ mask)
	//printf("[%d, %d]: %d\n", h, mask, result[w % 2][h][mask]);

	//puts("");
	//}
	//
	printf("%d\n", result[(width + 1) % 2][height - 1][(1 << height) - 1]);

	return 0;
}

