/*		2009
Maciej Szeptuch
XIV LO Wrocław
*/
#include <cstdio>
#include <cstdlib>

int points,
	mod,
	pointsTab [ 30000 ];

bool was [ 30000 ];

int solve ( int points )
{
	if ( points <= 2 )
		return 1;

	if ( was [ points ] )
		return pointsTab [ points ];

	for ( int i = 0; points / 2 - i - 2 >= 0; i += 2 )
		pointsTab [ points ] = ( pointsTab [ points ] + ( long ) solve ( i ) * solve ( points - i - 2 ) ) % mod;

	pointsTab [ points ] = ( pointsTab [ points ] * 2 ) % mod;

	if ( ( points / 2 ) % 2 == 1 )
		pointsTab [ points ] = ( pointsTab [ points ] + ( long ) solve ( ( points - 2 ) / 2 ) * solve ( ( points - 2 ) / 2 ) ) % mod;

	was [ points ] = true;

	return pointsTab [ points ];
}

int main ( void )
{
	scanf ( "%d %d", & points, & mod );
	printf ( "%d\n", solve ( 2 * points ) % mod );
	return 0;
}

