/*		2008
Maciej Szeptuch
XIV LO Wrocław
*/
/*	COLLATZ
 *	1.Dla danej liczby naturalnej b rozważamy następujący ciąg c(b):
 *	Pierwszym elementem ciągu jest liczba b;
 *	Kolejne elementy ciągu tworzymy na podstawie poprzedniego g następującej zasady:
 *		a.	Jeśli poprzedni  element jest liczbą parzystą,
 *			to kolejny otrzymujemy dzieląc poprzedni przez 2
 *
 *		b.	Jeśli poprzedni element jest liczbą nieparzystą,
 *			to kolejny otrzymujemy mnożąc poprzedni przez 3 i dodając do wyniku 1.
 *
 *	Budowanie ciągu kończymy, gdy otrzymamy liczbę 1.
 *	Przykład: dla liczby 7
 *	zbudujemy ciąg c(b) =7, 22, 11, 34, 17, 52, 26, 13, 40, 20, 10, 5, 16, 8, 4, 2, 1.
 *	Napisz program, który dla danej liczby b obliczy długość ciągu c(b).
 */
#include <cstdio>

typedef long long unsigned int llu;

llu a,
	result = 1;

int main ( void )
{
	scanf ( "%llu", & a );

	for ( ; a > 1; ++ result )
	{
		if ( a % 2 )
		{
			a = ( a * 3 ) + 1;
			++ result;
		}
		a /= 2;
	}

	printf ( "%llu\n", result );

	#ifndef HELIOS64
	system("pause");
	#endif

	return 0;
}

