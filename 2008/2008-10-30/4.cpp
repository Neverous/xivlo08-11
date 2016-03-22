/*		2008
Maciej Szeptuch
XIV LO Wrocław
*/
#include <cstdio>

typedef long long unsigned int llu;

const llu MODULO = 10000;

llu base,
	exponent;

llu fastPower ( llu base, llu exponent )
{
	llu result = 1, actual = base;
	while ( exponent > 0)
	{
		if ( exponent % 2 )
			result = ( result * actual ) % MODULO;

		actual = ( actual * actual ) % MODULO;
		exponent /= 2;
	}
	return result;
}

int main ( void )
{
	scanf ( "%llu %llu", & base, & exponent );
	printf ( "%llu\n", fastPower( base % MODULO, exponent ) );

	#ifndef HELIOS64
	system("pause");
	#endif

	return 0;
}

