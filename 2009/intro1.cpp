/* Maciej Szeptuch 2009
XIV LO Wrocław
*/
#include <cstdio>

int uniTab [ 100001 ],
	operationsTab [ 200002 ],
	edgesTab [ 200002 ] [ 2 ],
	operations,
	edges,
	operation,
	result;

bool removeEdge [ 200002 ];

int findUnion ( int a )
{
	if ( a != uniTab [ a ] )
		uniTab [ a ] = findUnion ( uniTab [ a ] );

	return uniTab [ a ];
}

inline bool unionUnion ( int a, int b )
{
	int A = findUnion ( a ),
		B = findUnion ( b );

	if ( A == B )
		return false;

	uniTab [ A ] = B;

	return true;
}

inline void genUnion ( void )
{
	for ( int i = 0; i < 100001; ++ i )
		uniTab [ i ] = i;

	for ( int e = 0; e < edges; ++ e )
		if ( ! removeEdge [ e ] && unionUnion ( edgesTab [ e ] [ 0 ], edgesTab [ e ] [ 1 ] ) )
			-- result;
}

inline void solve ( )
{
	genUnion ( );

	for ( int o = operations - 1; o >= 0; -- o )
		if ( unionUnion ( edgesTab [ operationsTab [ o ] ] [ 0 ], edgesTab [ operationsTab [ o ] ] [ 1 ] ) )
			operationsTab [ o ] = result --;
		else
			operationsTab [ o ] = result;

	for ( int r = 0; r < operations; ++ r )
		printf ( "%d\n", operationsTab [ r ] );
}

int main ( void )
{
	scanf ( "%d %d %d", & result, & edges, & operations );
	for ( int e = 0; e < edges; ++ e )
	{
		scanf ( "%d %d", & edgesTab [ e ] [ 0 ], & edgesTab [ e ] [ 1 ] );
		-- edgesTab [ e ] [ 0 ];
		-- edgesTab [ e ] [ 1 ];
	}

	for ( int o = 0; o < operations; ++ o )
	{
		scanf ( "%d", & operation );
		-- operation;
		operationsTab [ o ] = operation;
		removeEdge [ operation ] = true;
	}

	solve ( );
}

