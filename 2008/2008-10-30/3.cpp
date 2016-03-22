/*		2008
Maciej Szeptuch
XIV LO Wrocław
*/
#include <cstdio>

int rows,
	columns;

int main ( void )
{
	scanf ( "%d %d", & rows, & columns );

	for ( int i = 0, k = 0; i < rows; ++ i, k = i % 10 )
	{
		for ( int j = 0; j < columns; ++ j, k = ( k + 1) % 10 )
			printf ( "%d", k );

		printf ( "\n");
	}

	#ifndef HELIOS64
	system("pause");
	#endif

	return 0;
}

