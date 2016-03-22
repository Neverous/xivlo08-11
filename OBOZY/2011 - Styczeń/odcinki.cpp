/* 2010
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
//#define DEBUG(args...) fprintf(stderr, args)
#define DEBUG(args...)

int tests;
long long int Ax, Ay,
			  Bx, By,
			  Cx, Cy,
			  Dx, Dy;

static inline int mulsign(const long long int &a, const long long int &b, const long long int &c, const long long int &d, const long long int &e, const long long int &f);
static inline long long int MAX(const long long int &a, const long long int &b){return a>b?a:b;}
static inline long long int MIN(const long long int &a, const long long int &b){return a<b?a:b;}
static inline bool BETWEEN(const long long int &a, const long long int &b, const long long int &c){return a <= b && b <= c;}
static inline bool checkIt(void);

int main(void)
{
	scanf("%d", &tests);
	for(int t = 0; t < tests; ++ t)
	{
		scanf("%lld %lld %lld %lld %lld %lld %lld %lld", &Ax, &Ay, &Bx, &By, &Cx, &Cy, &Dx, &Dy);
		puts(checkIt()?"TAK":"NIE");
	}
	return 0;
}

static inline bool checkIt(void)
{
	int A = mulsign(Ax, Ay, Bx, By, Dx, Dy),
		B = mulsign(Ax, Ay, Bx, By, Cx, Cy),
		C = mulsign(Cx, Cy, Dx, Dy, Bx, By),
		D = mulsign(Cx, Cy, Dx, Dy, Ax, Ay);

	if(A * B < 0 && C * D < 0)
		return true; // -|-

	if(A * B > 0 || C * D > 0)
		return false; // |/

	if(!A && BETWEEN(MIN(Ax, Bx), Dx, MAX(Ax, Bx)))
		return true;

	if(!B && BETWEEN(MIN(Ax, Bx), Cx, MAX(Ax, Bx)))
		return true;

	if(!C && BETWEEN(MIN(Cx, Dx), Bx, MAX(Cx, Dx)))
		return true;

	if(!D && BETWEEN(MIN(Cx, Dx), Ax, MAX(Cx, Dx)))
		return true;

	return false;
}

static inline int mulsign(const long long int &a, const long long int &b, const long long int &c, const long long int &d, const long long int &e, const long long int &f)
{
	long long int R = (c - a) * (f - b) - (e - a) * (d - b);
	return ((R == 0)?0:((R < 0)?-1:1));
}
