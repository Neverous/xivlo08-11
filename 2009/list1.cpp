/* 2009
Maciej Szeptuch
XIV LO Wrocław
*/
#include <cstdio>

int prev [ 10010 ],
	next [ 10010 ],
	size,
	actions,
	where,
	what,
	last;

int main ( void )
{
	for ( int i = 0; i < 10010; ++ i )
		prev [ i ] = next [ i ] = 10010;

	scanf ( "%d %d", & size, & actions );

	for ( int s = 0; s < size; ++ s )
	{
		scanf ( "%d", & next [ last ] );
		prev [ next [ last ] ] = last;
		last = next [ last ];
	}

	for ( int a = 0; a < actions; ++ a )
	{
		scanf ( "%d %d", & what, & where );

		if ( where == 0 && what == 0 )
		{
			while ( where <= size )
			{
				if ( where )
					printf ( "%d ", where );

				where = next [ where ];
			}
			printf ( "\n" );
			continue;
		}

		next [ prev [ what ] ] = next [ what ];
		prev [ next [ what ] ] = prev [ what ];
		next [ what ] = next [ where ];
		prev [ what ] = where;
		prev [ next [ where ] ] = what;
		next [ where ] = what;

	}
	return 0;
}

