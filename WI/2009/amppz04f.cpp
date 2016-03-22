/* 2009
Maciej Szeptuch
XIV LO Wrocław
*/
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

double center [ 2 ];
pair < int, int > point [ 100001 ];
int points,
	tests;

bool solve ( void )
{
	if ( points < 3 )
		return true;

	sort ( point, point + points );

	for ( int p = 0; p < points; ++ p )
	{
		if ( ! binary_search ( point,
							   point + points,
							   pair < int, int > ( ( int ) ( center [ 0 ] - point [ p ] . first ),
							   					   ( int ) ( center [ 1 ] - point [ p ] . second )
							   					 )
							 )
		   )
			return false;
	}

	return true;
}

int main ( void )
{
	scanf ( "%d", & tests );
	for ( int t = 0; t < tests; ++ t )
	{
		center [ 0 ] = center [ 1 ] = 0;
		scanf ( "%d", & points );
		for ( int p = 0; p < points; ++ p )
		{
			scanf ( "%d %d", & point [ p ] . first, & point [ p ] . second );
			center [ 0 ] += point [ p ] . first;
			center [ 1 ] += point [ p ] . second;
		}

		center [ 0 ] /= points;
		center [ 1 ] /= points;
		center [ 0 ] *= 2;
		center [ 1 ] *= 2;

		printf ( "%s\n", solve ( ) ? "tak" : "nie" );
	}
	return 0;
}

