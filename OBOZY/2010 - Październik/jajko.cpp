/* 2010
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
//#define DEBUG(args...) fprintf(stderr, args)
#define DEBUG(args...)

int a,
			 b,
			 floors,
			 ans[1000010];

inline int MAX(int a, int b);
inline int MIN(int a, int b);

int main(void)
{
	scanf("%d %d %d", &a, &b, &floors);
	ans[0] = 0;
	ans[1] = a;
	for(int f = 2, s = 1, e = 1, mid = 0; f <= floors; s = 1, e = f ++)
	{
		while(s != e)
		{
			mid = (s + e + 1) / 2;
			if(ans[f - mid] - b * mid > 0)
				s = mid;

			else
				e = mid - 1;
		}

		ans[f] = MAX(ans[f], a + MIN(b * s, ans[f - s]));
		if(s < f)
			ans[f] = MAX(ans[f], a + MIN(b * (s + 1), ans[f - s - 1]));

		if(s)
			ans[f] = MAX(ans[f], a + MIN(b * (s - 1), ans[f - s + 1]));
	}

	printf("%d\n", ans[floors]);
	return 0;
}

inline int MAX(int A, int B)
{
	return A>B?A:B;
}

inline int MIN(int A, int B)
{
	return A<B?A:B;
}
