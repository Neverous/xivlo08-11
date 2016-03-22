/* 2009
Maciej Szeptuch
XIV LO Wrocław
*/

#include <cstdio>

int numbers [ 1000010 ],
	size,
	quant,
	tmp;

int bsearch ( int v, int start, int end )
{
	int middle;

	while ( start + 1 < end )
	{
		middle = ( start + end ) / 2;
		if ( numbers [ middle ] < v )
			start = middle;

		else
			end = middle;
	}

	return numbers [ start ] < v ? start + 1 : start;
}

int main ( void )
{
	scanf ( "%d", & size );
	for ( int s = 0; s < size; ++ s )
		scanf ( "%d", & numbers [ s ] );

	scanf ( "%d", & quant );
	for ( int q = 0; q < quant; ++ q )
	{
		scanf ( "%d", & tmp );
		printf ( "%d ", size - bsearch ( tmp, 0, size ) );
	}
	return 0;
}

