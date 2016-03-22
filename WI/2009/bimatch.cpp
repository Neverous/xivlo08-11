/* 2009
Maciej Szeptuch
XIV LO Wrocław
*/
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

inline int hopcroftKarp ( void );
inline void hopcroftKarpBFS ( void );
bool hopcroftKarpDFS ( int where, int flag );

int men,
	doves,
	quant,
	dove,
	visited [ 20002 ],
	connected [ 20002 ],
	dist [ 20002 ];

vector < int > graph [ 20002 ];

int main ( void )
{
	scanf ( "%d %d", & men, & doves );

	for ( int v = 0; v < 20002; ++ v )
		dist [ v ] = connected [ v ] = -1;

	for ( int m = 0; m < men; ++ m )
	{
		scanf ( "%d", & quant );
		for ( int q = 0 ; q < quant; ++ q )
		{
			scanf ( "%d", & dove );
			-- dove;
			graph [ m ] . push_back ( men + dove );
		}
	}

	printf ( "%d\n", hopcroftKarp ( ) );

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

