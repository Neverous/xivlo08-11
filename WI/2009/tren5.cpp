/* Maciej Szeptuch 2008
XIV LO Wrocław
*/
#include <cstdio>
const int SIZE = 524288;
struct iTree // Interval tree
{
	int tree [ 2 * SIZE ];

	iTree ( )
	{
		for ( int t = 0; t < 2 * SIZE; ++ t )
			tree [ t ] = 0;
	}

	void insert ( int v )
	{
		for ( int t = SIZE + v; t > 0; t /= 2 )
			tree [ t ] ++;
	}

	void remove ( int v )
	{
		for ( int t = SIZE + v; t > 0; t /= 2 )
			tree [ t ] --;
	}

	int find ( int elem )
	{
		int t;
		for ( t = 1; t < SIZE; )
		{
			if ( tree [ 2 * t ] < elem )
			{
				elem -= tree [ 2 * t ];
				t = 2 * t + 1;
			}
			else
				t *= 2;
		}
		return t - SIZE + 1;
	}
};

int elem,
	len;

int main ( void )
{
	iTree tree;

	scanf ( "%d", & len );

	for ( int i = 0; i < len; ++ i )
		tree . insert ( i );

	for ( int i = 0; i < len; ++ i )
	{
		scanf ( "%d", & elem );
		elem ++;
		elem = tree . find ( elem );
		tree . remove ( elem - 1 );
		printf ( "%d ",  elem );
	}
	printf ( "\n" );
	return 0;

}

