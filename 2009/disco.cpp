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

int tests,
	men,
	women,
	contacts,
	man,
	woman,
	visited [ 2004 ],
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
	return hopcroftKarp ( ) == men;
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

