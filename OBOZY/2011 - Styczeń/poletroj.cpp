/* 2010
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
//#define DEBUG(args...) fprintf(stderr, args)
#define DEBUG(args...)

int Ax, Ay,
	Bx, By,
	Cx, Cy;

static inline int ABS(const int &a){return a<0?-a:a;}

int main(void)
{
	scanf("%d %d %d %d %d %d", &Ax, &Ay, &Bx, &By, &Cx, &Cy);
	printf("%.1lf\n", (double)ABS((Bx - Ax) * (Cy - Ay) - (Cx - Ax) * (By - Ay)) / 2.0);
	return 0;
}

