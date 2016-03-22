/*		2008
Maciej Szeptuch
XIV LO Wrocław
*/
/*
 *	Napisz program, który wczytuje liczbę i wypisuje jej cyfrę jedności.
 */
#include <cstdio>

typedef long long unsigned int llu;

llu number;

int main ( void )
{
	scanf ( "%llu", & number );
	printf ( "%llu\n", number % 10 );

	#ifndef HELIOS64
	system("pause");
	#endif

	return 0;
}

