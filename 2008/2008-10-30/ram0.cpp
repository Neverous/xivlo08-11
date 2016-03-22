/*		2008
Maciej Szeptuch
XIV LO Wrocław
*/
/*
 *	Znajdź NWD dwóch liczb
 */
#include <cstdio>

typedef long long unsigned int llu;

llu a,
	b;

llu NWD ( llu a, llu b, llu c = 0 )
{
	if ( b > a )
	{
		c = b;
		b = a;
		a = c;
	}
	while ( b > 0 )
	{
		c = b;
		b = a % b;
		a = c;
	}
	return a;
}

int main ( void )
{
	scanf ( "%llu %llu", & a, & b );
	printf ( "%llu\n", NWD ( a, b ) );

	#ifndef HELIOS64
	system("pause");
	#endif

	return 0;
}

