/* 2009
Maciej Szeptuch
XIV LO Wrocław
*/

#include <cstdio>
#include <vector>
#include <queue>
#define MAX_INT 2147483647

using namespace std;

vector < pair < int, int > > graph [ 500050 ];
priority_queue < pair < int, int > > que;
pair < int , int > act;

int cost [ 500050 ];

int	verts,
	edges,
	start,
	end,
	from,
	to;

void dijkstra ( int start );

int main ( void )
{
	scanf ( "%d %d %d %d", & verts, & edges, & start, & end );
	-- start;
	-- end;
	cost [ start ] = cost [ end ] = MAX_INT;
	for ( int e = 0; e < edges; ++ e )
	{
		scanf ( "%d %d", & from, & to );
		-- from;
		-- to;
		graph [ from ] . push_back ( pair < int, int > ( to, 0 ) );
		graph [ to ] . push_back ( pair < int, int > ( from, 1 ) );
		cost [ from ] = cost [ to ] = MAX_INT;
	}

	dijkstra ( start );
	if ( cost [ end ] != MAX_INT )
		printf ( "%d\n", cost [ end ] );

	else
		printf ( "-1\n" );

	return 0;
}

void dijkstra ( int start )
{
	que . push ( pair < int, int > ( 0, start ) );

	while ( ! que . empty ( ) )
	{
		act = que . top ( );
		que . pop ( );

		if ( cost [ act . second ] <= - act . first )
			continue;

		cost [ act . second ] = - act . first;

		for ( unsigned int s = 0; s < graph [ act . second ] . size ( ); ++ s )
		{
			if ( cost [ graph [ act . second ] [ s ] . first ] > cost [ act . second ] + graph [ act . second ] [ s ] . second )
				que . push ( pair < int, int > ( - ( cost [ act . second ] + graph [ act . second ] [ s ] . second ), graph [ act . second ] [ s ] . first ) );
		}

	}
}

