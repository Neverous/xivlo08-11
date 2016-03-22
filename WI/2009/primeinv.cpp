/* Maciej Szeptuch 2008
XIV LO Wrocław
*/
#include <cstdio>

int notPrime [ 8000 ];

void sito ( void )
{
	notPrime [ 0 ] = notPrime [ 1 ] = 1;
	for ( int i = 2; i < 8000; ++ i )
	{
		if ( notPrime [ i ] )
			continue;
		for ( int j = i + i; j < 8000; j += i )
			notPrime [ j ] = 1;
	}
}

int n;

int main ( void )
{
	sito ( );
	scanf ( "%d", & n );
	for ( int i = 2, j = 0, k = 0; i > 0; )
	{
		if ( ! notPrime [ i ] )
			++ j;

		if ( !k && j >= n )
			k = 1;

		if ( k && ! notPrime [ i ] )
			printf ( "%d ", i );

		if ( !k ) ++ i;
		else -- i;
	}
	printf ( "\n" );
	return 0;
}

