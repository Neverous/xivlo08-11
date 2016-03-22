/* 2010
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
#include<algorithm>
#define DEBUG(args...) fprintf(stderr, args)
//#define DEBUG(args...)

int communes,
	colors,
	commune[3030],
	count[3030][3030],
	shareSpeed[10][3030];

static inline int MIN(int a, int b);
static inline int ABS(int a);
inline void prepareCount(int end);

int main(void)
{
	scanf("%d %d", &communes, &colors);
	for(int c = 0; c < communes; ++ c)
		scanf("%d", &commune[c]);

	std::sort(commune, commune + communes);
	prepareCount(communes);
	for(int commun = communes - 1; commun >= 0; -- commun)
	{
		shareSpeed[0][commun] = count[commun][communes - 1];
		for(int cuts = 1; cuts < colors; ++ cuts)
		{
			shareSpeed[cuts][commun] = count[commun][communes - 1];
			for(int c = commun; c < communes; ++ c)
				shareSpeed[cuts][commun] = MIN(shareSpeed[cuts][commun], count[commun][c] + shareSpeed[cuts - 1][c + 1]);
		}
	}

	printf("%d\n", shareSpeed[colors - 1][0]);
	return 0;
}


static inline int MIN(int a, int b)
{
	return (a > b)?b:a;
}

static inline int ABS(int a)
{
	return (a > 0)?a:-a;
}

inline void prepareCount(int end)
{
	for(int s = 0; s < end; ++ s)
		for(int c = 1; c < end - s; ++ c)
			count[s][s + c] = count[s][s + c - 1] + ABS(commune[s + c] - commune[s + c / 2]);
}
