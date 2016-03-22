/* 2009
Maciej Szeptuch
XIV LO Wrocław
*/
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

bool bfs ( void );
bool bfsProcedure ( void );

int tests,
	verts,
	edges,
	start,
	end,
	color [ 1000001 ],
	level [ 1000001 ];

vector < int > graph [ 1000001 ];
queue < pair < int, int > > que;
queue < pair < int, int > > empty;
pair <int, int > act;

int main ( void )
{
	scanf ( "%d", & tests );
	for ( int t = 0; t < tests; ++ t )
	{
		for ( int v = 0; v < verts; ++ v )
		{
			graph [ v ] . clear ( );
			color [ v ] = 0;
			level [ v ] = 0;
		}

		scanf ( "%d %d", & verts, & edges );
		for ( int e = 0; e < edges; ++ e )
		{
			scanf ( "%d %d", & start, & end );
			-- start;
			-- end;
			++ level [ start ];
			++ level [ end ];
			graph [ start ] . push_back ( end );
			graph [ end ] . push_back ( start );
		}

		printf ( "%s\n", bfs ( ) ? "TAK" : "NIE" );
	}
	return 0;
}

bool bfs ( void )
{
	for ( int v = 0; v < verts; ++ v )
		if ( ! color [ v ] )
		{
			que . push ( make_pair ( v, 2 ) );
			if ( ! bfsProcedure ( ) )
				return false;
		}

	return true;
}

bool bfsProcedure ( void )
{
	while ( ! que . empty ( ) )
	{
		act = que . front ( );
		que . pop ( );

		if ( color [ act . first ] && color [ act . first ] != act . second )
			return false;

		if ( color [ act . first ] )
			continue;

		color [ act . first ] = act . second;

		for ( unsigned int v = 0; v < graph [ act . first ] . size ( ); ++ v )
			if ( ! color [ graph [ act . first ] [ v ] ] )
				que . push ( make_pair ( graph [ act . first ] [ v ], 1 + act . second % 2 ) );
			else if ( color [ graph [ act . first ] [ v ] ] != 1 + act . second % 2 )
				return false;
	}

	return true;
}

