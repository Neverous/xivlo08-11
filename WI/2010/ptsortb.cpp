/* 2010
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
#include<algorithm>
//#define DEBUG(args...) fprintf(stderr, args)
#define DEBUG(args...)

unsigned int points;
std::pair<int, int> point[131072];

int main(void)
{
	scanf("%u", &points);
	for(unsigned int p = 0; p < points; ++ p)
		scanf("%d %d", &point[p].second, &point[p].first);

	std::sort(point, point + points);
	for(unsigned int p = 0; p < points; ++ p)
		printf("%d %d\n", point[p].second, point[p].first);

	return 0;
}

