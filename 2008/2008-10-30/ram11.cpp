/*		2008
Maciej Szeptuch
XIV LO Wrocław
*/
/*
 *	1.Napisz program, który dla danej liczby a oblicza , ile podzielników ma liczba a.
 */
#include <cstdio>

typedef long long unsigned int llu;

llu a;

llu divisors ( llu number )
{
	llu result = 1;
	for ( llu i = 2, tmp = 1; i * i <= number; ++ i, tmp = 1 )
	{
		while ( number % i == 0 && number > 0 )
		{
			number /= i;
			++ tmp;
		}

		result *= tmp;
	}
	if ( number > 1 )
		result *= 2;
	return result;
}

int main ( void )
{
	scanf ( "%llu", & a );
	printf ( "%llu\n", divisors ( a ) );

	#ifndef HELIOS64
	system("pause");
	#endif

	return 0;
}

