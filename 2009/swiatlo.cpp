/* 2009
Maciej Szeptuch
XIV LO Wrocław
*/
#include <cstdio>

template < typename Type >
struct Heap
{
	Type data [ 1000000 ];
	int _size;

	Heap ( void )
	{
		_size = 0;
	}

	void insert ( Type nValue )
	{
		data [ _size + 1 ] = nValue;

		for ( int position = _size + 1; position / 2 > 0 && data [ position ] > data [ position / 2 ]; position /= 2 )
		{
			data [ _size + 2 ] = data [ position / 2 ];
			data [ position / 2 ] = data [ position ];
			data [ position ] = data [ _size + 2 ];
		}

		++ _size;
	}

	Type pop ( void )
	{
		if ( _size == 0 )
			return Type ( 0 );

		Type ret = data [ 1 ];

		if ( _size == 1 )
			data [ 1 ] = 0;

		else
			data [ 1 ] = data [ _size ];

		for ( int position = 2; position < _size; position *= 2 )
		{
			if ( position + 1 < _size && data [ position + 1 ] > data [ position ] )
				++ position;

			if ( data [ position ] > data [ position / 2 ] )
			{
				data [ _size + 2 ] = data [ position / 2 ];
				data [ position / 2 ] = data [ position ];
				data [ position ] = data [ _size + 2 ];
			}
			else
				break;
		}

		-- _size;
		return ret;
	}

	inline Type top ( void )
	{
		return data [ 1 ];
	}
};

struct Max
{
	int value;

	Max ( int nValue = 0 )
	{
		value = nValue;
	}

	inline bool operator > ( const Max & a ) const
	{
		return value > a . value;
	}
};

struct Min
{
	int value;

	Min ( int nValue = 0 )
	{
		value = nValue;
	}

	inline bool operator > ( const Min & a ) const
	{
		return value < a . value;
	}
};

struct Test
{
	int _size;
	Heap < Max > base;
	Heap < Min > extension;

	Test ( void )
	{
	}

	void insert ( int value )
	{
		if ( base . _size >= _size && base . top ( ) . value < value )
			extension . insert ( Min ( value ) );

		else
			base . insert ( Max ( value ) );

		if ( base . _size >= _size )
			extension . insert ( Min ( base . pop ( ) . value ) );

	}

	inline int top ( void )
	{
		return extension . top ( ) . value;
	}

	inline void pop ( void )
	{
		extension . pop ( );
	}
};

Test tab;

int action,
	add;

int main ( void )
{
	scanf ( "%d", & tab . _size );
	while ( scanf ( "%d", & action ) && action )
		if ( action == 2 )
		{
			scanf ( "%d", & add );
			tab . insert ( add );
		}

		else if ( action == 1 )
			printf ( "%d\n", tab . top ( ) );

		else
			tab . pop ( );

	return 0;
}

