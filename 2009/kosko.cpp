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
	map[1024][1024],
	result[1024][1024][2],
	best;

int main(void)
{
	scanf("%d %d", &height, &width);
	for(int h = 0; h < height; ++ h)
		for(int w = 0; w < width; ++ w)
			scanf("%d", &map[h][w]);

	for(int w = 0; w < width; ++ w)
		result[0][w][0] = map[0][w];

	for(int h = 0; h < height; h ++)
	{
		if(h - 1 >= 0) // 2. typ skoku
			for(int w = 0; w < width; ++ w)
			{
				if(w - 1 >= 0)
					result[h - 1][w - 1][1] = MAX(result[h - 1][w - 1][1],
						result[h][w][0] + map[h - 1][w - 1]);

				if(w + 1 < width)
					result[h - 1][w + 1][1] = MAX(result[h - 1][w + 1][1],
						result[h][w][0] + map[h - 1][w + 1]);
			}

		if(h + 2 < height) //1. typ skoku
			for(int w = 0; w < width; ++ w)
			{
				if(w - 1 >= 0)
					result[h + 2][w - 1][0] = MAX(result[h + 2][w - 1][0],
						MAX(result[h][w][1], result[h][w][0]) + map[h + 2][w - 1]);

				if(w + 1 < width)
					result[h + 2][w + 1][0] = MAX(result[h + 2][w + 1][0],
						MAX(result[h][w][1], result[h][w][0]) + map[h + 2][w + 1]);
			}

		if(h + 1 < height && h - 1 >= 0) // 2. typ skoku po 1.
		{
			for(int w = 0; w < width; ++ w) // 2. typ skoku
			{
				if(w - 1 >= 0)
					result[h + 1][w - 1][0] = MAX(result[h + 1][w - 1][0],
						MAX(result[h - 1][w][1], result[h - 1][w][0]) + map[h + 1][w - 1]);

				if(w + 1 < width)
					result[h + 1][w + 1][0] = MAX(result[h + 1][w + 1][0],
						MAX(result[h - 1][w][1], result[h - 1][w][0]) + map[h + 1][w + 1]);
			}

			for(int w = 0; w < width; ++ w) // i jeszcze raz 1.
			{
				if(w - 1 >= 0)
					result[h][w - 1][1] = MAX(result[h][w - 1][1],
						result[h + 1][w][0] + map[h][w - 1]);

				if(w + 1 < width)
					result[h][w + 1][1] = MAX(result[h][w + 1][1],
						result[h + 1][w][0] + map[h][w + 1]);
			}
		}
	}

	//DEBUG("\n");
	//for(int h = 0; h < height; ++ h)
	//for(int w = 0; w < width; ++ w)
	//DEBUG("%3d%c", result[h][w][0], w == width - 1?'\n':' ');

	//DEBUG("\n");
	//for(int h = 0; h < height; ++ h)
	//for(int w = 0; w < width; ++ w)
	//DEBUG("%3d%c", result[h][w][1], w == width - 1?'\n':' ');

	//DEBUG("\n");
	for(int w = 0; w < width; ++ w)
		best = MAX(best, result[height - 1][w][0]);

	printf("%d\n", best);
	return 0;
}

