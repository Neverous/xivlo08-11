/*		2008
Maciej Szeptuch
XIV LO Wrocław
*/
/*
 *	1.Napisz program, który wczytuje liczby naturalne a i b,
 *	a następnie znajduje najmniejszą liczbę k, taką, że:
 *	k jest nie mniejsza od a,
 *	k dzieli się przez b.
 */
#include <cstdio>

typedef long long unsigned int llu;

llu a,
	k;

int main ( void )
{
	scanf ( "%llu %llu", & a, & k );
	printf ( "%llu\n", ( ( a + k - 1 ) / k ) * k  );

	#ifndef HELIOS64
	system("pause");
	#endif

	return 0;
}

