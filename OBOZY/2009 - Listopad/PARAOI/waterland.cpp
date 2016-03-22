/* 2009
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>

int height,
	width,
	land[1010][1010],
	field,
	max,
	min = 1000000000,
	bestresult;

int main(void)
{
	scanf("%d %d", &height, &width);
	for(int h = 1; h <= height; ++ h)
		for(int w = 1; w <= width; ++ w)
			scanf("%d", &land[h][w]);

	for(int h = 0; h <= height; ++ h)
		for(int w = 0; w <= width; ++ w)
		{
			if(w)
				land[h][w] += land[h][w - 1];

			if(h)
				land[h][w] += land[h - 1][w];

			if(h && w)
				land[h][w] -= land[h - 1][w - 1];
		}

	for(int s = 1; s <= height && s <= width; ++ s)
	{
		max = 0;
		min = 1000000000;
		for(int h = s; h <= height; h += s)
			for(int w = s; w <= width; w += s)
			{
				field = land[h][w] - land[h - s][w] - land[h][w - s] + land[h - s][w - s];
				if(field > max)
					max = field;

				if(field < min)
					min = field;
			}

		if(max - min > bestresult)
			bestresult = max - min;
	}

	printf("%d\n", bestresult);
	return 0;
}
