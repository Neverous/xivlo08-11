/*		2008
Maciej Szeptuch
XIV LO Wrocław
*/
/*
 *	Napisz program, który wczytuje  liczby naturalne a i b, a następnie
 *	oblicza resztę dzielenia a przez b.
 */
#include <cstdio>

typedef long long unsigned int llu;

llu number,
	modulo;

int main ( void )
{
	scanf ( "%llu %llu", & number, & modulo );
	printf ( "%llu\n", number % modulo );

	#ifndef HELIOS64
	system("pause");
	#endif

	return 0;
}

