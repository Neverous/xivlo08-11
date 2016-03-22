/*		2008
Maciej Szeptuch
XIV LO Wrocław
*/
/*
 *	1.Napisz program, który dla danej liczby naturalnej a
 *	oblicza sufit z pierwiastka kwadratowego liczby a.
 *	Na przykład dla a= 16 program powinien wypisać wartość 4,
 *	a dla a=17 – wartość 5.
 */
#include <cstdio>

typedef long long unsigned int llu;

llu a,
	i,
	j,
	center;

int main ( void )
{
	scanf ( "%llu", & a );

	for ( i = 1, j = a; i + 1 != j; )
	{
		center = ( i + j ) / 2;
		if ( center * center > a )
			j = center;
		else if ( center * center < a )
			i = center;
		else
		{
			j = center;
			break;
		}
	}

	printf ( "%llu\n", j );

	#ifndef HELIOS64
	system("pause");
	#endif

	return 0;
}

