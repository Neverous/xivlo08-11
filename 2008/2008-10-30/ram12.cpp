/*		2008
Maciej Szeptuch
XIV LO Wrocław
*/
/*
 *	1.Napisz program,  który dla danej liczb a sprawdzi,
 *	czy jej zapis w systemie dziesiątkowym jest monocyfrowy, tj.
 *	czy do zapisania liczby a w systemie dziesiątkowym wystarczy jedna cyfra.
 */
#include <cstdio>

typedef long long unsigned int llu;

llu a,
	x;

bool check ( llu number )
{
	x = number % 10;
	while ( number > 0 )
	{
		if ( x != number % 10 )
			return 0;
		number /= 10;
	}
	return 1;
}
int main ( void )
{
	scanf ( "%llu", & a );
	printf ( "%d\n", check ( a ) );

	#ifndef HELIOS64
	system("pause");
	#endif

	return 0;
}

