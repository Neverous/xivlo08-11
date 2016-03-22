/* 2009
Maciej Szeptuch
XIV LO Wrocław
*/
/* Zadanie na 6 ze sprawdzianu - PO CZASIE */
/*
	To chyba działa poprawnie
	Tak jak to co wysłałem na sprawdzianie +
		* każdy wierzchołek trzyma jescze pozycje początku i końca przedziału ( w innym przypadku operacje zamiany kosztowałyby (log^2(n)) a nie tak jak napisałem w opisie na sprawdzianie czyli log(n) - co teraz działa
		* w efekcie złożoność pamięciowa jest trochę większa ( 11n zamiast 7n czyli dla 1048576 elementów ~ 50MB )
		* dodane odpowiedznie porównanie aby idąc coraz wyżej w drzewie wartości były odpowiednie...( nie chce mi się tego opisywać ;) )
*/
#include <cstdio>
#define max4(a,b,c,d) max2(max2(a,b),max2(c,d))
#define max2(a,b) ((a)>(b)?(a):(b))

struct TreeElement
{
	int prefixPosition,
		prefixLength,
		suffixPosition,
		suffixLength,
		maxLength;

	TreeElement ( void )
	{
		prefixPosition = suffixPosition = \
		prefixLength = suffixLength = maxLength = 0;
	}
};

template < typename Type, typename Type2 >
struct IntervalTree
{
	static const int SIZE = 131072;
	Type data [ SIZE * 2 ];
	Type2 values [ SIZE ];

	IntervalTree ( void )
	{
		for ( int s = 0; s < SIZE * 2; ++ s )
		{
			values [ s / 2 ] = data [ s ] . prefixPosition = \
			data [ s ] . suffixPosition = data [ s ] . maxLength = \
			data [ s ] . prefixLength = data [ s ] . suffixLength = 0;
		}
	}

	Type top ( void )
	{
		return data [ 1 ];
	}

	void buildTree ( void )
	{
		for ( int pos = SIZE - 1; pos > 0; -- pos )
		{
			data [ pos ] . prefixPosition = data [ pos * 2 ] . prefixPosition;
			data [ pos ] . suffixPosition = data [ pos * 2 + 1 ] . suffixPosition;
			data [ pos ] . prefixLength = data [ pos * 2 ] . prefixLength;
			data [ pos ] . suffixLength = data [ pos * 2 + 1 ] . suffixLength;

			if ( data [ pos * 2 ] . maxLength &&
				 data [ pos * 2 + 1 ] . maxLength &&
				 values [ data [ pos * 2 ] . suffixPosition ] > values [ data [ pos * 2 + 1 ] . prefixPosition ] )
			{
				if ( data [ pos * 2 ] . prefixLength == data [ pos * 2 ] . suffixPosition - data [ pos * 2 ] . prefixPosition + 1 &&
					 data [ pos ] . prefixLength < data [ pos * 2 ] . prefixLength + data [ pos * 2 + 1 ] . prefixLength )
					data [ pos ] . prefixLength = data [ pos * 2 ] . prefixLength + data [ pos * 2 + 1 ] . prefixLength;

				if ( data [ pos * 2 + 1 ] . suffixLength == data [ pos * 2 + 1 ] . suffixPosition - data [ pos * 2 + 1 ] . prefixPosition + 1 &&
					 data [ pos ] . suffixLength < data [ pos * 2 ] . suffixLength + data [ pos * 2 + 1 ] . prefixLength )
					data [ pos ] . suffixLength = data [ pos * 2 ] . suffixLength + data [ pos * 2 + 1 ] . prefixLength;

				if ( data [ pos ] . maxLength < data [ pos * 2 ] . suffixLength + data [ pos * 2 + 1 ] . prefixLength )
					data [ pos ] . maxLength = data [ pos * 2 ] . suffixLength + data [ pos * 2 + 1 ] . prefixLength;
			}

			data [ pos ] . maxLength = max4 ( max2 ( data [ pos ] . prefixLength, data [ pos ] . maxLength ), data [ pos ] . suffixLength, data [ pos * 2 ] . maxLength, data [ pos * 2 + 1 ] . maxLength );

		}
	}

	void change ( int position, int value )
	{
		values [ position ] = value;
		data [ position + SIZE ] . prefixPosition = \
		data [ position + SIZE ] . suffixPosition = position;

		data [ position + SIZE ] . maxLength = \
		data [ position + SIZE ] . prefixLength = \
		data [ position + SIZE ] . suffixLength = 1;

		for ( int pos = ( position + SIZE ) / 2; pos > 0; pos /= 2 )
		{
			data [ pos ] . prefixPosition = data [ pos * 2 ] . prefixPosition;
			data [ pos ] . suffixPosition = data [ pos * 2 + 1 ] . suffixPosition;
			data [ pos ] . prefixLength = data [ pos * 2 ] . prefixLength;
			data [ pos ] . suffixLength = data [ pos * 2 + 1 ] . suffixLength;

			if ( data [ pos * 2 ] . maxLength &&
				 data [ pos * 2 + 1 ] . maxLength &&
				 values [ data [ pos * 2 ] . suffixPosition ] > values [ data [ pos * 2 + 1 ] . prefixPosition ] )
			{
				if ( data [ pos * 2 ] . prefixLength == data [ pos * 2 ] . suffixPosition - data [ pos * 2 ] . prefixPosition + 1 &&
					 data [ pos ] . prefixLength < data [ pos * 2 ] . prefixLength + data [ pos * 2 + 1 ] . prefixLength )
					data [ pos ] . prefixLength = data [ pos * 2 ] . prefixLength + data [ pos * 2 + 1 ] . prefixLength;

				if ( data [ pos * 2 + 1 ] . suffixLength == data [ pos * 2 + 1 ] . suffixPosition - data [ pos * 2 + 1 ] . prefixPosition + 1 &&
					 data [ pos ] . suffixLength < data [ pos * 2 ] . suffixLength + data [ pos * 2 + 1 ] . prefixLength )
					data [ pos ] . suffixLength = data [ pos * 2 ] . suffixLength + data [ pos * 2 + 1 ] . prefixLength;
			}

			data [ pos ] . maxLength = max4 ( data [ pos ] . prefixLength, data [ pos ] . suffixLength, data [ pos * 2 ] . maxLength, data [ pos * 2 + 1 ] . maxLength );

			if ( data [ pos * 2 ] . maxLength &&
				 data [ pos * 2 + 1 ] . maxLength &&
				 values [ data [ pos * 2 ] . suffixPosition ] > values [ data [ pos * 2 + 1 ] . prefixPosition ] &&
				 data [ pos ] . maxLength < data [ pos * 2 ] . suffixLength + data [ pos * 2 + 1 ] . prefixLength )
				data [ pos ] . maxLength = data [ pos * 2 ] . suffixLength + data [ pos * 2 + 1 ] . prefixLength;

		}
	}
};

IntervalTree < TreeElement, int > tree;
int elements,
	actions,
	value,
	act;

char action [ 100 ];

int main ( void )
{
	scanf ( "%d", & elements );
	for ( int e = 0; e < elements; ++ e )
	{
		scanf ( "%d", & tree . values [ e ] );
		tree . data [ e + tree . SIZE ] . prefixPosition = \
		tree . data [ e + tree . SIZE ] . suffixPosition = e;

		tree . data [ e + tree . SIZE ] . maxLength = \
		tree . data [ e + tree . SIZE ] . prefixLength = \
		tree . data [ e + tree . SIZE ] . suffixLength = 1;

	}
	tree . buildTree ( );

	printf ( "Cookies!\n" );
	while ( scanf ( "%s", action ) != -1 && action [ 0 ] != 'E' )
	{
		if ( action [ 0 ] == 'P' )
			printf ( "%d\n", tree . top ( ) . maxLength );

		else if ( action [ 0 ] == 'Z' )
		{
			scanf ( "%d %d", & act, & value );
			tree . change ( act - 1, value );
		}

		else
			break;
	}
	printf ( "Cookies!\n" );
	return 0;
}

