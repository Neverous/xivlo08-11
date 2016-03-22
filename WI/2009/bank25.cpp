/* 2009
Maciej Szeptuch
XIV LO Wrocław
*/

#include <cstdio>

int size,
    width,
    act,
    tab [ 1000010 ],
    que [ 1000010 ],
    quePos = -1,
    queMove;

int main ( void )
{
	scanf ( "%d %d", & size, & width );
	for ( int s = 0; s < size; ++ s )
	{
	    scanf ( "%d", & tab [ s ] );

	    while ( quePos >= 0 && tab [ que [ ( queMove + quePos ) % 1000010 ] ] >= tab [ s ] )
	        -- quePos;

	    ++ quePos;
	    que [ ( queMove + quePos ) % 1000010 ] = s;

	    printf ( "%d\n", tab [ que [ queMove ] ] );

	    if ( que [ queMove ] == s - width + 1 )
	    {
	    	++ queMove;
	    	if ( queMove >= 1000010 )
	    		queMove %= 10000010;
	    	-- quePos;
	    }
	}
	return 0;
}

