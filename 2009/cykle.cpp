/* 2009
Maciej Szeptuch
XIV LO Wrocław
*/

#include <cstdio>
#include <vector>

std :: vector < int > graph [ 100010 ];

bool visited [ 100010 ];

int	tests,
	verts,
	edges,
	from,
	to;

bool dfs ( int vert, int father );

bool solve ( void );

int main ( void )
{
	scanf ( "%d", & tests );
	for ( int t = 0; t < tests; ++ t )
	{
		scanf ( "%d %d", & verts, & edges );
		for ( int e = 0; e < edges; ++ e )
		{
			scanf ( "%d %d", & from, & to );
			-- from;
			-- to;
			graph [ from ] . push_back ( to );
			graph [ to ] . push_back ( from );
		}

		printf ( "%s\n", solve ( ) ? "TAK" : "NIE" );
		//CLEAR
		for ( int v = 0; v < 100010; ++ v )
		{
			graph [ v ] . clear ( );
			visited [ v ] = false;
		}
	}

	return 0;
}

bool dfs ( int vert, int father )
{
	visited [ vert ] = true;
	for ( unsigned int s = 0; s < graph [ vert ] . size ( ); ++ s )
	{
		if ( father == graph [ vert ] [ s ] )
			continue;

		if ( visited [ graph [ vert ] [ s ] ] || dfs ( graph [ vert ] [ s ], vert ) )
			return true;
	}

	return false;
}

bool solve ( void )
{
	for ( int v = 0; v < verts; ++ v )
	{
		if ( ! visited [ v ] && dfs ( v, -1 ) )
			return true;
	}

	return false;
}

