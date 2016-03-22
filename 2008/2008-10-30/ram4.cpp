/*		2008
Maciej Szeptuch
XIV LO Wrocław
*/
/*
 *	1.Napisz program, który wczytuje liczby naturalne a, b i c,
 *	a następnie oblicza, ile wielokrotności liczby c należy do przedziału <a,b>.
 */
#include <cstdio>

typedef long long unsigned int llu;

llu a,
	b,
	c;

int main ( void )
{
	scanf ( "%llu %llu %llu", & a, & b, & c );
	printf ( "%llu\n", ( b / c ) - ( a - 1 ) / c  );

	#ifndef HELIOS64
	system("pause");
	#endif

	return 0;
}

