/* 2009
Maciej Szeptuch
XIV LO Wrocław
*/

#include <cstdio>

inline void dijkstra ( void )
{
    for ( int = 0; s < cities; ++ s )
        cost [ s ] = 1000000000;

    priority_queue < int, operate > que;

    que . push_back ( 0 );

    while ( ! que . empty ( ) )
    {
        act = que . top ( );
        que . pop ( );

        for ( int s = 0; s < graph [ act ] . size ( ); ++ s )
        {
            if ( cost [ graph [ act ] [ i ] . first ] > getNewCost ( cost [ act ], graph [ act ] [ i ] . first ) + graph [ act ] [ i ] . second )
            {
                cost [ graph [ act ] [ i ] . first ] = getNewCost ( cost [ act ], graph [ act ] [ i ] . first ) + graph [ act ] [ i ] . second;
                que . push ( graph [ act ] [ i ] . first );
            }
        }
    }
}

int main ( void )
{
    scanf ( "%d", & tests );

    for ( int t = 0; t < tests; ++ t )
    {
        scanf ( "%d %d", & cities, & roads );
        for ( r = 0; r < roads; ++ r )
        {
            scanf ( "%d %d %d %d %d %d", & from, & to, & cost, & cycle, & start, & time );
            graph [ from ] . push_back ( pair < int, int > ( to, cost ) );
        }
    }
}

