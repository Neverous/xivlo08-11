/* 2010
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
#define FUNC(a, b) (((a) * (b) + 1) / 2)

int tests,
	width,
	height;

int main(void)
{
	scanf("%d", &tests);
	for(int t = 0; t < tests; ++ t)
	{
		scanf("%d %d", &width, &height);
		printf("%d\n", FUNC(width / 2, height / 2) +
				FUNC((width + 1) / 2, height / 2) +
				FUNC((height + 1) / 2, width / 2) +
				FUNC((height + 1) / 2, (width + 1) / 2));
	}
	return 0;
}

