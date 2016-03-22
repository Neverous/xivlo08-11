/* 2009
Maciej Szeptuch
XIV LO Wrocław
*/

#include <cstdio>

struct Gcd
{
	int gcd,
		x,
		y;

	Gcd ( void )
	{
		gcd = 1;
		x = 0;
		y = 1;
	}
}; // Strukturka dla wyniku...

Gcd extendedEuclides ( int first, int second );
Gcd result;
int first,
	second;

int main ( void )
{
	scanf ( "%d %d", & first, & second );
	result = extendedEuclides ( first, second ); // Zakładam, że first > second
	printf ( "%d %d %d\n", result . x, result . y, result . gcd );
	return 0;
}

Gcd extendedEuclides ( int first, int second )
{
	Gcd result;
	int tmp;
	result . gcd = second;
	if ( first % second == 0 )
		return result;

	result = extendedEuclides ( second, first % second );
	tmp = result . x;
	result . x = result . y;
	result . y = tmp - result . y * ( first / second );

	return result;
}
