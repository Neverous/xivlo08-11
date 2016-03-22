/* 2011
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
#include<algorithm>
#include<cmath>
//#define DEBUG(args...) fprintf(stderr, args)
#define DEBUG(args...)

int objects,
	range,
	x, y,
	result = 1;
long double last;
std::pair<long double, long double> object[1024];

int main(void)
{
	scanf("%d %d", &objects, &range);
	for(int o = 0; o < objects; ++ o)
	{
		scanf("%d %d", &x, &y);
		if(y > range || y < -range)
		{
			puts("-1");
			return 0;
		}

		object[o].second = (long double) x - sqrt(range * range - y * y);
		object[o].first = (long double) x + sqrt(range * range - y * y);
	}

	std::sort(object, object + objects);
	last = object[0].first;
	for(int o = 1; o < objects; ++ o)
	{
		if(object[o].second <= last && object[o].first >= last)
			continue;

		++ result;
		last = object[o].first;
	}

	printf("%d\n", result);
	return 0;
}

