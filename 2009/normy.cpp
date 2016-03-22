/* 2009
Maciej Szeptuch
XIV LO Wrocław
*/

#include <cstdio>

template < typename type >
struct Heap
{
	int index;
	static const int SIZE = 110010;

	type data [ SIZE ],
		 temp;

	Heap ( void )
	{
		clear ( );
	}

	inline void clear ( void )
	{
		index = 1;
	}

	inline void insert ( type value )
	{
		data [ index ] = value;

		for ( int position = index; position / 2 > 0 && data [ position / 2 ] > data [ position ]; position /= 2 )
		{
			temp = data [ position / 2 ];
			data [ position / 2 ] = data [ position ];
			data [ position ] = temp;
		}

		++ index;
	}

	inline type top ( void )
	{
		return data [ 1 ];
	}

	inline void pop ( void )
	{
		if ( index == 1 )
			return;

		data [ 1 ] = data [ -- index ];
		for ( int position = 2; position <= index; position *= 2 )
		{
			if ( position + 1 <= index && data [ position ] > data [ position + 1 ] )
				++ position;

			if ( data [ position / 2 ] > data [ position ] )
			{
				temp = data [ position / 2 ];
				data [ position / 2 ] = data [ position ];
				data [ position ] = temp;
			}
			else
				break;

		}
	}

	inline bool empty ( void )
	{
		return index == 1;
	}

};

struct Container
{
	int number,
		type,
		additional;

	Container ( void )
	{
		clear ( );
	}

	Container ( int nNumber, int nType, int nAdditional )
	{
		number = nNumber;
		type = nType;
		additional = nAdditional;
	}

	inline void clear ( void )
	{
		number = type = additional = 0;
	}

	inline bool operator> ( const Container &elem )
	{
		if ( number != elem . number )
			return number > elem . number;

		if ( type != elem . type )
			return type > elem . type;

		if ( additional != elem . additional )
			return additional > elem . additional;

		return false;
	}
};

Heap < Container > heap;
int tests,
	probes,
	probe,
	standards,
	from,
	to,
	numbers,
	standard [ 5005 ];

Container temp;

int main ( void )
{
	scanf ( "%d", & tests );
	for ( int t = 0; t < tests; ++ t )
	{
		scanf ( "%d", & probes );
		for ( int p = 0; p < probes; ++ p )
		{
			scanf ( "%d", & probe );
			heap . insert ( Container ( probe, 1, 0 ) );
		}

		scanf ( "%d", & standards );
		for ( int s = 0; s < standards; ++ s )
		{
			scanf ( "%d %d", & from, & to );
			heap . insert ( Container ( from, 0, s ) );
			heap . insert ( Container ( to, 2, s ) );
		}

		while ( ! heap . empty ( ) )
		{
			temp = heap . top ( );
			heap . pop ( );

			if ( temp . type == 1 )
			{
				numbers ++;
				continue;
			}

			if ( temp . type == 0 )
				standard [ temp . additional ] -= numbers;

			else
				standard [ temp . additional ] += numbers;
		}

		for ( int s = 0; s < standards; ++ s )
		{
			printf ( "%d\n", standard [ s ] );
			standard [ s ] = 0;
		}

		heap . clear ( );
		numbers = 0;
	}
	return 0;
}

