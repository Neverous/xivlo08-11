/* 2009
Maciej Szeptuch
XIV LO Wrocław
*/
#include <cstdio>

int cars,
	act = 1,
	place,
	car,
	road [ 1010 ];

int main ( void )
{
	scanf ( "%d", & cars );
	for ( int c = 0; c < cars; ++ c )
	{
		scanf ( "%d", & car );
		if ( car == act )
			++ act;
		else
		{
			while ( place > 0 && road [ place - 1 ] == act )
			{
				++ act;
				-- place;
			}
			road [ place ++ ] = car;
		}
	}

	while ( place > 0 && road [ place - 1 ] == act )
	{
		++ act;
		-- place;
	}

	printf ( "%s\n", ! place ? "yes" : "no" );
	return 0;
}

