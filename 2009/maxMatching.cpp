/* 2009
Maciej Szeptuch
XIV LO Wrocław
*/
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

inline bool solve ( void );
inline void clean ( void );

inline int hopcroftKarp ( void );
inline void hopcroftKarpBFS ( void );
bool hopcroftKarpDFS ( int where, int flag );

//int dinitz ( void );

inline int fordFulkerson ( void );
int fordFulkersonDFS ( int where, int end, int push, int flag );

int tests,
	men,
	women,
	contacts,
	man,
	woman,
	visited [ 2004 ],
	weight [ 2004 ] [ 2004 ],
	connected [ 2004 ],
	dist [ 2004 ];

vector < int > graph [ 2004 ];

int main ( void )
{
	scanf ( "%d", & tests );
	for ( int t = 0; t < tests; ++ t )
	{
		clean ( );
		scanf ( "%d %d %d", & men, & women, & contacts );
		for ( int c = 0; c < contacts; ++ c )
		{
			scanf ( "%d %d", & man, & woman );
			-- man;
			-- woman;
			graph [ man ] . push_back ( woman );
			graph [ woman ] . push_back ( man );
			weight [ man ] [ woman ] = 1;
			weight [ woman ] [ man ] = 0;

		}

		printf ( "%s\n", solve ( ) ? "TAK" : "NIE" );
	}
	return 0;
}

inline void clean ( void )
{
	for ( int v = 0; v < 2004; ++ v )
	{
		graph [ v ] . clear ( );
		visited [ v ] = 0;
		connected [ v ] = -1;
		dist [ v ] = -1;
	}
}

inline bool solve ( void )
{
	//return fordFulkerson ( ) == men;
	return hopcroftKarp ( ) == men;
}

inline int fordFulkerson ( void )
{
	int result = 0,
		sum = 0,
		flag = 1;

	for ( int v = 0; v < men; ++ v )
	{
		graph [ men + women ] . push_back ( v );
		graph [ v ] . push_back ( men + women );
		weight [ men + women ] [ v ] = 1;
		weight [ v ] [ men + women ] = 0;
	}

	for ( int v = 0; v < women; ++ v )
	{
		graph [ men + women + 1 ] . push_back ( v + men );
		graph [ v + men ] . push_back ( men + women + 1 );
		weight [ v + men ] [ men + women + 1 ] = 1;
		weight [ men + women + 1 ] [ v + men ] = 0;
	}

	do
	{
		result += sum;
		sum = fordFulkersonDFS ( men + women, men + women + 1, 1, flag ++ );
	}
	while ( sum );

	return result;
}

int fordFulkersonDFS ( int where, int end, int push, int flag )
{
	if ( where == end )
		return push;

	if ( visited [ where ] == flag )
		return 0;

	int tmp = 0;

	visited [ where ] = flag;

	for ( unsigned int v = 0; v < graph [ where ] . size ( ); ++ v )
	{
		if ( visited [ graph [ where ] [ v ] ] == flag ||
			 ! weight [ where ] [ graph [ where ] [ v ] ] )
			continue;

		tmp = fordFulkersonDFS ( graph [ where ] [ v ], end, push > weight [ where ] [ graph [ where ] [ v ] ] ? weight [ where ] [ graph [ where ] [ v ] ] : push, flag );

		if ( tmp )
		{
			weight [ where ] [ graph [ where ] [ v ] ] -= tmp;
			weight [ graph [ where ] [ v ] ] [ where ] += tmp;
			return tmp;
		}
	}

	return 0;
}

inline int hopcroftKarp ( void )
{
	int flag = 0,
		counter = 0;

	bool tmp;

	do
	{
		tmp = false;
		hopcroftKarpBFS ( );

		flag ++;
		for ( int v = 0; v < men; ++ v )
			if ( connected [ v ] == -1 )
				if ( hopcroftKarpDFS ( v, flag ) )
				{
					++ counter;
					tmp = true;
				}

	}
	while ( tmp );

	return counter;
}

inline void hopcroftKarpBFS ( void )
{
	int act;
	queue < int > que;

	for ( int v = 0; v < men; ++ v )
	{
		dist [ v ] = -1;
		if ( connected [ v ] == -1 )
		{
			que . push ( v );
			dist [ v ] = 0;
		}
	}

	while ( ! que . empty ( ) )
	{
		act = que . front ( );
		que . pop ( );
		for ( unsigned int v = 0; v < graph [ act ] . size ( ); ++ v )
		{
			if ( connected [ graph [ act ] [ v ] ] == -1 )
				continue;

			if ( dist [ connected [ graph [ act ] [ v ] ] ] == -1 )
			{
				dist [ connected [ graph [ act ] [ v ] ] ] = dist [ act ] + 1;
				que . push ( connected [ graph [ act ] [ v ] ] );
			}
		}
	}
	return;
}

bool hopcroftKarpDFS ( int where, int flag )
{
	visited [ where ] = flag;
	for ( unsigned int v = 0; v < graph [ where ] . size ( ); ++ v )
	{
		if ( connected [ graph [ where ] [ v ] ] == -1 ||
			 ( visited [ connected [ graph [ where ] [ v ] ] ] != flag &&
			   dist [ connected [ graph [ where ] [ v ] ] ] - 1 == dist [ where ] &&
			   hopcroftKarpDFS ( connected [ graph [ where ] [ v ] ], flag ) )
			 )
		{
			connected [ graph [ where ] [ v ] ] = where;
			connected [ where ] = graph [ where ] [ v ];
			return true;
		}
	}
	return false;
}

