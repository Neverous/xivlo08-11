/*		2008
Maciej Szeptuch
XIV LO Wrocław
*/
/*	COLLATZ2
 *	1.Napisz program, który dla liczb a, b (a<b i b-a<100) znajdzie liczbę, k taką, że:
 *	k należy do przedziału <a,b>
 *	c(k)>=c(x) dla każdego x z przedziału <a,b>.
 */
#include <cstdio>

typedef long long unsigned int llu;

llu a,
	b,
	result,
	max,
	tmp;

llu collatz ( llu first )
{
	llu result = 1;
	for ( ; first > 1; ++ result )
	{
		if ( first % 2 )
		{
			first = ( first * 3 ) + 1;
			++ result;
		}
		first /= 2;
	}
	return result;
}

int main ( void )
{
	scanf ( "%llu %llu", & a, & b );

	if ( a < b / 2 )
		a = b / 2;

	for ( llu i = a; i <= b; ++ i )
	{
		tmp = collatz ( i );
		if ( tmp > max )
		{
			max = tmp;
			result = i;
		}
	}

	printf ( "%llu\n", result );

	#ifndef HELIOS64
	system("pause");
	#endif

	return 0;
}

