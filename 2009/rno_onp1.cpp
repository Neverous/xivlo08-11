/* 2009
Maciej Szeptuch
XIV LO Wrocław
*/

#include <cstdio>
#define INT_MAX 2147483647

int tests,
	len,
	stack [ 505 ],
	pointer,
	result;

char act;
bool bad;

inline int solve ( void )
{
	pointer = bad = 0;
	for ( int l = 0; l < len; ++ l )
	{
		scanf ( "%c", & act );

		if ( bad )
			continue;

		if ( act <= '9' && act >= '0' )
			stack [ pointer ++ ] = act - '0';

		else if ( pointer < 2 || pointer > 501 )
			bad = true;

		else if ( act == '+' )
		{
			stack [ pointer - 2 ] += stack [ pointer - 1 ];
			pointer --;
		}

		else if ( act == '-' )
		{
			stack [ pointer - 2 ] -= stack [ pointer - 1 ];
			pointer --;
		}

		else if ( act == '*' )
		{
			stack [ pointer - 2 ] *= stack [ pointer - 1 ];
			pointer --;
		}

		else if ( act == '/' && stack [ pointer - 1 ] )
		{
			stack [ pointer - 2 ] /= stack [ pointer - 1 ];
			pointer --;
		}

		else
			bad = true;
	}

	if ( bad || pointer < 1 )
		return INT_MAX;

	return stack [ 0 ];
}

int main ( void )
{
	scanf ( "%d", & tests );
	for ( int t = 0; t < tests; ++ t )
	{
		scanf ( "%d\n", & len );
		result = solve ( );
		if ( result == INT_MAX )
			printf ( "BRAK\n" );

		else
			printf ( "%d\n", result );
	}
	return 0;
}

