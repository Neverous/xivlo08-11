/*		2008
Maciej Szeptuch
XIV LO Wrocław
*/
/*
 *	Napisz program, który dla danych liczb całkowitych a, b oblicza sumę
 *	wszystkich liczb całkowitych z przedziału <a,b>
 */
#include <cstdio>

typedef long long unsigned int llu;

llu a,
	b;

int main ( void )
{
	scanf ( "%llu %llu", & a, & b );
	printf ( "%llu\n", ( a + b ) * ( b - a + 1 ) / 2 );

	#ifndef HELIOS64
	system("pause");
	#endif

	return 0;
}

