/* 2009
Maciej Szeptuch
XIV LO Wrocław
*/

#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

bool greater ( pair < int, int > a, pair < int, int > b )
{
	return a . first % 2 > b . first % 2 || ( a . first % 2 == b . first  % 2 && ( a . first < b . first || ( a . first == b . first && a . second > b . second ) ) );
}

struct Heap
{
	pair< int, int > data [ 3000000 ];
	int size;

	Heap ( void )
	{
		for ( int i = 0; i < 3000000; ++ i )
			data [ i ] . first = data [ i ] . second = 0;
		size = 1;
	}

	bool insert ( int id, int value )
	{
		data [ size ] . first = id;
		data [ size ] . second = value;

		for ( int l = size; l / 2 > 0 && greater ( data [ l / 2 ], data [ l ] ); l /= 2 )
			swap ( data [ l / 2 ], data [ l ] );

		++ size;
		return true;
	}

	pair < int, int > top ( void )
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
		for ( int p = 2; p <= size; p*= 2 )
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

};

int action,
	argument,
	money,
	happy;

Heap heap;

pair < int, int > tmp;

int main ( void )
{
	while ( scanf ( "%d", & action ) != -1 && action != -1 )
	{
		scanf ( "%d", & argument );

		if ( action == 0 )
			money += argument;
		else
			heap . insert ( action, argument );

		tmp = heap . top ( );
		while ( tmp . first != 0 && tmp . second <= money )
		{
			happy ++;
			money -= tmp . second;
			heap . pop ( );
			tmp = heap . top ( );
		}
	}
	printf ( "%d %d\n", happy, money );
	return 0;
}

