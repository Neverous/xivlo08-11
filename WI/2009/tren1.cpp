#include <cstdio>

char text[1000010],last;
int sizeOfTree,
	sum,
	minCost;
int tree [ 100010 ];

int calculate ( int node = 1 )
{
	if ( node >= sizeOfTree )
		return 1;

	int costA = calculate ( node * 2 ),
		costB = calculate ( node * 2 + 1);

	return tree [ node ] ? costA + costB : ( costA > costB ) ? costB : costA;
}

int main ( void )
{
	scanf ( "%d ", & sizeOfTree );

	last = '0';
	scanf ( "%s",  text );
	for ( int i = 0; text [ i ] != NULL; i++ )
	{
		if ( text [ i ] != last )
			sum ++;

		last = text [ i ];
	}

	for ( int i = 1; i < sizeOfTree; i++ )
		scanf ( "%d", & tree [ i ] );

	minCost = calculate ( );
	printf ( "%d\n", ( sum > 0 ) ? minCost-1+sum : 0 );

	return 0;
}

