/* 2009
Maciej Szeptuch
XIV LO Wrocław
*/

#include <cstdio>
#include <string.h>

struct Tree
{
	static const int SIZE = 2097152;
	long long int data [ SIZE ];

	Tree ( void )
	{
		bzero ( data, SIZE * sizeof ( long long int ) );
	}

	inline void insert ( int position, int quantity )
	{
		position += SIZE / 2 - 1;

		while ( position > 0 )
		{
			data [ position ] += quantity;
			position /= 2;
		}
	}

	long long int sum ( int start, int end, int rootStart = 1, int rootEnd = SIZE / 2, int index = 1 )
	{
		if ( start == rootStart && end == rootEnd )
			return data [ index ];

		int half = ( rootStart + rootEnd ) / 2;
		long long int res = 0;

		if ( end <= half )
			res += sum ( start, end, rootStart, half, index * 2 );
		else if ( start > half )
			res += sum ( start, end, half + 1, rootEnd, index * 2 + 1 );
		else if ( start <= half && end > half )
		{
			res += sum ( start, half, rootStart, half, index * 2 );
			res += sum ( half + 1, end, half + 1, rootEnd, index * 2 + 1 );
		}

		return res;
	}
};

int tests,
	a,
	b;

char action;

Tree * tree;

int main ( void )
{
	scanf ( "%d", & tests );
	for ( int t = 0; t < tests; ++ t )
	{
		tree = new Tree;
		while ( true )
		{
			scanf ( " %c %d %d", & action, & a, & b );
			++ a;

			if ( action == 'A' )
				tree -> insert ( a, b );

			else if ( action == 'S' )
				printf ( "%lld\n", tree -> sum ( a, b + 1 ) );

			else
				break;
		}
		delete tree;
	}
	return 0;
}

