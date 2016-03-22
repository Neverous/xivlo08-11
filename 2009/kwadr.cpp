/* 2009
Maciej Szeptuch
XIV LO Wrocław
*/

#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

inline bool greater ( pair < int, int > a, pair < int, int > b )
{
	return a . first * a . first + a . second * a . second > b . first * b . first + b . second * b . second;
}

struct Heap
{
	pair< int, int > data [ 6000 ];
	int size;

	Heap ( void )
	{
		for ( int i = 0; i < 6000; ++ i )
			data [ i ] . first = data [ i ] . second = 0;
		size = 1;
	}

	bool insert ( pair < int, int > value )
	{
		data [ size ] = value;

		for ( int l = size; l / 2 > 0 && greater ( data [ l / 2 ], data [ l ] ); l /= 2 )
			swap ( data [ l / 2 ], data [ l ] );

		++ size;
		return true;
	}

	inline pair < int, int > top ( void )
	{
		return data [ 1 ];
	}

	bool pop ( void )
	{
		if ( size <= 2 )
		{
			data [ 1 ] . first = 0;
			data [ 1 ] . second = 0;
			size = 1;
			return true;
		}

		data [ 1 ] = data [ -- size ];
		for ( int p = 2; p <= size; p *= 2 )
		{
			if ( p + 1 <= size && greater ( data [ p ], data [ p + 1 ] ) )
				++ p;

			if ( greater ( data [ p / 2 ], data [ p ] ) )
				swap ( data [ p / 2 ], data [ p ] );
			else
				break;

		}
		return true;
	}

	inline bool empty ( void )
	{
		return size == 1;
	}

};

int maks,
	quant,
	maksim,
	act;

Heap heap;

pair < int, int > tmp;

int main ( void )
{
	scanf ( "%d", & maks );
	for ( int m = 1; m * m < maks; ++ m )
		heap . insert ( pair < int, int > ( 1, m ) );

	while ( ! heap . empty ( ) )
	{
		tmp = heap . top ( );
		act = tmp . first * tmp . first + tmp . second * tmp . second;
		heap . pop ( );

		if ( act >= maks )
			break;

		if ( act > maksim )
		{
			++ quant;
			maksim = act;
		}

		++ tmp . first;
		act =  tmp . first * tmp . first + tmp . second * tmp . second;
		if ( act < maks && act > maksim )
			heap . insert ( tmp );
	}
	printf ( "%d %d\n", quant, maksim );
	return 0;
}

