/* 2009
Maciej Szeptuch
XIV LO Wrocław
*/
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

int tests;
char first [ 50050 ],
	 second [ 50050 ];

char * nwdBinary ( char * A, char * B )
{
	int lenA = strlen ( A ),
		lenB = strlen ( B ),
		r = 50000;

	char tmp [ 50050 ];
	char * result = new char [ 50050 ];

	for ( int a = lenA - 1, b = lenB - 1; a > 0 && b > 0; -- b, -- a )
	{
		if ( A [ a ] != B [ b ] )
		{
			tmp = sumBinary ( A, B, lenA, lenB );
			if ( strcmp ( tmp, A ) == 0 )
				break;
			A = tmp;
		}

		if ( A [ a ] == '0' )
		{
			result [ r ] = '0';
			-- r;
		}
	}
	return A;
}

int main ( void )
{
	scanf ( "%d", & tests );

	for ( int  i = 0; i < 10; ++ i )
		first [ i ] = second [ i ] = '0';

	for ( int t = 0; t < tests; ++ t )
	{
		scanf ( "%s\n%s", first + 10, second + 10 );
		printf ( "%s\n", nwdBinary ( first, second ) );
	}
	return 0;
}

