/* 2009
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
#define sgn(a) ((a)==0?0:((a)>0?1:-1))
#define max(a,b) ((a) > (b)?(a):(b))
#define min(a,b) ((a) < (b)?(a):(b))

int tests,
	x1, y1,
	x2, y2,
	x3, y3,
	x4, y4;

inline bool checkCut(int &x1, int &y1, int &x2, int &y2, int &x3, int &y3, int &x4, int &y4); // Czy odcinki 1-2 i 3-4 się przecinają

int main(void)
{
	scanf("%d", &tests);
	for(int t = 0; t < tests; ++ t)
	{
		scanf("%d %d %d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);
		printf("%s\n", checkCut(x1, y1, x2, y2, x3, y3, x4, y4)?"TAK":"NIE");
	}

	return 0;
}

inline bool checkCut(int &x1, int &y1, int &x2, int &y2, int &x3, int &y3, int &x4, int &y4)
{
	int x124 = sgn((long long int)(x1 - x2) * (y4 - y2) - (long long int)(x4 - x2) * (y1 - y2)), // iloczyn skalarny pkt 1 2 4
		x123 = sgn((long long int)(x1 - x2) * (y3 - y2) - (long long int)(x3 - x2) * (y1 - y2)), // ... 1 2 3
		x342 = sgn((long long int)(x3 - x4) * (y2 - y4) - (long long int)(x2 - x4) * (y3 - y4)), // ... 3 4 2
		x341 = sgn((long long int)(x3 - x4) * (y1 - y4) - (long long int)(x1 - x4) * (y3 - y4)); // ... 3 4 1
	
	if(x124 * x123 < 0 && x342 * x341 < 0) // mają przeciwne znaki czyli leżą po przeciwnych stronach
		return true; 

	if(x124 * x123 > 0 || x342 * x341 > 0) // mają takie same znaki
		return false;

	if(x124 == 0 && min(x1,x2) <= x4 && x4 <= max(x1, x2)) // 4 jest współliniowy z 1-2 i zawiera się w 1-2
		return true;

	if(x123 == 0 && min(x1,x2) <= x3 && x3 <= max(x1, x2)) // 3 (...)
		return true;

	if(x342 == 0 && min(x3,x4) <= x2 && x2 <= max(x3, x4)) // 2 (...) z 3-4 i zawiera się w 3-4
		return true;

	if(x341 == 0 && min(x3,x4) <= x1 && x1 <= max(x4, x3)) // 1 (...)
		return true;

	return false;
}

