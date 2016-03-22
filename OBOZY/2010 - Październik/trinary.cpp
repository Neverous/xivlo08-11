/* 2010
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
#include<cmath>
//#define DEBUG(args...) fprintf(stderr, args)
#define DEBUG(args...)
#define PRECISION (long double)0.000000000001

long double a,
			b,
			fx,
			fy,
			sx,
			sy,
			result;
unsigned int tests;

inline static long double solve(void);
inline static long double biedaszyb(long double x);
inline static long double distance(long double x, long double y);
inline static long double ABS(long double x);
inline static bool lower(long double first, long double second, bool equal = false);
inline static long double nice(long double x);

int main(void)
{
	scanf("%u", &tests);
	for(unsigned int t = 0; t < tests; ++ t)
	{
		scanf("%Lf %Lf %Lf %Lf %Lf %Lf", &a, &b, &fx, &fy, &sx, &sy);
		result = solve();
		printf("%.5Lf %.5Lf\n", nice(result), nice(biedaszyb(result)));
	}

	return 0;
}

inline static long double solve(void)
{
	long double end = 1000.0,
				start = -1000.0,
				midOne,
				midTwo,
				dS,
				dE,
				dMO,
				dMT;
	while(end - start > PRECISION)
	{
		midOne = start + (end - start) / 3;
		midTwo = midOne + (end - start) / 3;
		dS = distance(start, biedaszyb(start));
		dE = distance(end, biedaszyb(end));
		dMO = distance(midOne, biedaszyb(midOne));
		dMT = distance(midTwo, biedaszyb(midTwo));
		//printf("S: %.10Lf MO: %.10Lf MT: %.10Lf E: %.10Lf\n", start, midOne, midTwo, end);
		//printf("dS: %.10Lf dMO: %.10Lf dMT: %.10Lf dE: %.10Lf\n", dS, dMO, dMT, dE);
		if(lower(dE, dMT) && lower(dMT, dMO) && lower(dMO, dS))
			start = midTwo;

		else if(lower(dMT, dE) && lower(dMO, dMT) && lower(dS, dMO))
			end = midOne;

		else if(lower(dMT, dE, true) && lower(dE, dMO, true) && lower(dE, dS))
			start = midOne;

		else if(lower(dE, dS, true) && lower(dMO, dE, true) && lower(dMT, dMO, true))
			start = midOne;

		else if(lower(dS, dE, true) && lower(dMO, dS) && lower(dMT, dMO, true))
			start = midOne;

		else if(lower(dE, dS, true) && lower(dMT, dE) && lower(dMO, dMT, true))
			end = midTwo;

		else if(lower(dS, dE, true) && lower(dMT, dS, true) && lower(dMO, dMT, true))
			end = midTwo;

		else if(lower(dMT, dE) && lower(dS, dMT, true) && lower(dMO, dS, true))
			end = midTwo;
	}

	//printf("%.10Lf\n", distance(start, biedaszyb(start)));
	return start;
}

inline static long double biedaszyb(long double x)
{
	return x * x * (long double)-1 + a * x + b;
}

inline static long double distance(long double x, long double y)
{
	return sqrt((x - fx) * (x - fx) + (y - fy) * (y - fy)) + sqrt((x - sx) * (x - sx) + (y - sy) * (y - sy));
}

inline static long double ABS(long double x)
{
	return x < 0?-x:x;
}

inline static bool lower(long double first, long double second, bool equal)
{
	if(equal)
		return first - second <= PRECISION;

	return first - second <  PRECISION;
}

inline static long double nice(long double x)
{
	return ABS(x) < PRECISION?0:x;
}
