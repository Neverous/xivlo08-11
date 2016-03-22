/*		2008
Maciej Szeptuch
XIV LO Wrocław
*/
/*
 *	1.Napisz program, który wczytuje liczby naturalne a, b i c,
 *	a następnie (a < b oraz  b-a<100),  a następnie
 *	wypisuje wszystkie wielokrotności liczby c, które należą do przedziału <a,b>
 */
#include <cstdio>

typedef long long unsigned int llu;

llu a,
	b,
	c;

int main ( void )
{
	scanf ( "%llu %llu %llu", & a, & b, & c );

	for ( llu i = ( ( a + c - 1 ) / c ) * c; i <= b; i += c )
		printf ( "%llu ", i );

	printf ( "\n" );
	#ifndef HELIOS64
	system("pause");
	#endif

	return 0;
}

