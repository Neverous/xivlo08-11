/* 2009
Maciej Szeptuch
XIV LO Wrocław
*/
#include <cstdio>

int vertexes,
	cost [ 202 ] [ 202 ],
	speedUp [ 202 ] [ 202 ];

int triangulate ( int start, int end );

int main ( void )
{
	scanf ( "%d", & vertexes );
	for ( int v = 0; v < vertexes; ++ v )
		for ( int e = v + 1; e < vertexes; ++ e )
		{
			scanf ( "%d", & cost [ v ] [ e ] );
			cost [ e ] [ v ] = cost [ v ] [ e ];
		}

	printf ( "%d\n", triangulate ( 0, 1 ) );
	return 0;
}

int triangulate ( int start, int end )
{
	if ( speedUp [ start ] [ end ] )
		return speedUp [ start ] [ end ];

	int result = cost [ start ] [ end ],
		act,
		res = 1000000;

	if ( ( end + 1 ) % vertexes == start )
		return result;

	for ( int i = ( end + 1 ) % vertexes; i != start; i = ( i + 1 ) % vertexes )
	{
		act = triangulate ( start, i ) + triangulate ( i, end );
		res = res > act ? act : res;
	}

	speedUp [ start ] [ end ] = result + res;

	return speedUp [ start ] [ end ];
}

