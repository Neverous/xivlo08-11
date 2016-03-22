/* 2010
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
//#define DEBUG(args...) fprintf(stderr, args)
#define DEBUG(args...)

int numbers,
	Ax, Ay,
	Bx, By,
	x, y,
	data[3];

static inline int mulsign(const long long int &a, const long long int &b, const long long int &c, const long long int &d, const long long int &e, const long long int &f);

int main(void)
{
	scanf("%d", &numbers);
	scanf("%d %d %d %d", &Bx, &By, &Ax, &Ay);
	for(int n = 0; n < numbers; ++ n)
	{
		scanf("%d %d", &x, &y);
		++ data[1 + mulsign(Ax, Ay, Bx, By, x, y)];
	}

	printf("na prostej %d\nna prawo %d\nna lewo %d\n", data[1], data[2], data[0]);
	return 0;
}

static inline int mulsign(const long long int &a, const long long int &b, const long long int &c, const long long int &d, const long long int &e, const long long int &f)
{
	long long int R = (c - a) * (f - b) - (e - a) * (d - b);
	return ((R == 0)?0:((R < 0)?-1:1));
}
