/* FFFFFFFFFFFFFFUUUUUUUUUUUUUUUUUUUUCCCCCCCCCCCCCCCCCCCKKKKKKKKKKKKKKKKKK */
/* 2009
Maciej Szeptuch
XIV LO Wrocław
*/

#include <cstdio>
#include <list>

using namespace std;

list < int > que;

int cows,
    width,
    questions,
    act,
    tab [ 1000010 ],
    result [ 1000010 ];

int main ( void )
{
	scanf ( "%d %d %d", & cows, & width, & questions );
	for ( int c = 0; c < cows; ++ c )
	{
	    scanf ( "%d", & tab [ c ] );

	    while ( ! que . empty ( ) && tab [ * ( -- que . end ( ) ) ] >= tab [ c ] )
	        que . pop_back ( );

	    que . push_back ( c );

	    if ( c >= width - 1 )
	    {
	        result [ c - width + 1 ] = tab [ * que . begin ( ) ];
	        if ( * que . begin ( ) == c - width + 1 )
	            que . pop_front ( );
	    }
	}
    result [ cows - width + 1 ] = tab [ * que . begin ( ) ];

	for ( int q = 0; q < questions; ++ q )
	{
	    scanf ( "%d", & act );
	    printf ( "%d\n", result [ act ] );
	}
	return 0;
}

