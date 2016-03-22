/* 2009
Maciej Szeptuch
XIV LO Wrocław
*/

#include <cstdio>
#include <vector>

int cities,
	connections,
	start,
	end,
	question;

std :: vector < int > graph [ 10000 ],
					  reverseGraph [ 10000 ];

int sort [ 10000 ],
	visited [ 10000 ],
	componentSize [ 10000 ],
	component [ 10000 ];

void dfs ( int city );
inline void findSCC ( void );
int dfsSCC ( int city, int color );

int main ( void )
{
	scanf ( "%d %d", & cities, & connections );
	for ( int c = 0; c < connections; ++ c )
	{
		scanf ( "%d %d", & start, & end );
		-- start;
		-- end;
		graph [ start ] . push_back ( end );
		reverseGraph [ end ] . push_back ( start );
	}

	for ( int c = 0; c < cities; ++ c )
		if ( ! visited [ c ] )
			dfs ( c );

	findSCC ( );

	while ( scanf ( "%d", & question ) != -1 && question != 0 )
		printf ( "%d\n", componentSize [ component [ question - 1 ] ] );

	return 0;
}

void dfs ( int city )
{
	static int colorize = 1;

	visited [ city ] = -1;

	for ( unsigned int s = 0; s < graph [ city ] . size ( ); ++ s )
		if ( ! visited [ graph [ city  ] [ s ] ] )
			dfs ( graph [ city ] [ s ] );

	visited [ city ] = colorize ++;
}

inline void findSCC ( void )
{
	for ( int c = 0; c < cities; ++ c )
		sort [ visited [ c ] ] = c;

	for ( int s = cities, color = 1; s > 0; -- s )
	{
		if ( component [ sort [ s ] ] )
			continue;

		componentSize [ color ] = dfsSCC ( sort [ s ], color );
		++ color;
	}
}

int dfsSCC ( int city, int color )
{
	int result = 1;
	component [ city ] = color;

	for ( unsigned int s = 0; s < reverseGraph [ city ] . size ( ); ++ s )
		if ( ! component [ reverseGraph [ city ] [ s ] ] )
			result += dfsSCC ( reverseGraph [ city ] [ s ], color );

	return result;
}

