/* 2009
Maciej Szeptuch
XIV LO Wrocław
*/

#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

struct Heap
{
	int data [ 4000000 ],
		size;

	Heap ( void )
	{
		for ( int i = 0; i < 4000000; ++ i )
			data [ i ] = 0;
		size = 1;
	}

	bool insert ( int value )
	{
		data [ size ] = value;
		for ( int l = size; l / 2 > 0 && data [ l / 2 ] > data [ l ]; l /= 2 )
			swap ( data [ l / 2 ], data [ l ] );

		++ size;
		return true;
	}

	int top ( void )
	{
		return data [ 1 ];
	}

	bool pop ( void )
	{
		if ( size <= 2 )
		{
			data [ 1 ] = 0;
			size = 1;
			return true;
		}

		data [ 1 ] = data [ -- size ];
		for ( int p = 2; p <= size; p*= 2 )
		{
			if ( p + 1 <= size && data [ p ] > data [ p + 1 ] )
				++ p;

			if ( data [ p / 2 ] > data [ p ] )
				swap ( data [ p / 2 ], data [ p ] );
			else
				break;

		}
		return true;
	}

};

int action,
	argument;

Heap heap;

int main ( void )
{
	while ( scanf ( "%d %d", & action, & argument ) != -1 && action != 0 )
	{
		if ( action == 1 )
			heap . insert ( argument );
		else
		{
			for ( int a = 0; a < argument; ++ a )
			{
				printf ( "%d ", heap . top ( ) );
				heap . pop ( );
			}

			printf ( "\n" );
		}
	}
	return 0;
}

