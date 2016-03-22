/*		2008
Maciej Szeptuch
XIV LO Wrocław
*/
#include <iostream>

typedef long long int lld;
lld tab [ 30 ],
	sum,
	tab1 [ 1010 ],
	tab2 [ 1010 ],
	first [ 1010 ];
char x;

void sito ( )
{
	first [ 0 ] = first [ 1 ] = 1;
	for ( int i = 2; i < 1010; ++i )
	{
		if ( first [ i ] )
			continue;
		for ( int j = i*i; j < 1010; j+=i )
		{
			first [ j ] = 1;
		}
	}
}

void specialSil ( lld n, lld *result )
{
	for ( lld i = 2,j; i <= n;  ++ i )
	{
		if ( first [ i ] )
			continue;
		j = i;
		while ( n / j > 0 )
		{
			result [ i ] += n/j;
			j*=i;
		}
	}
}

int main ( void )
{
	sito ( );
	while ( scanf ( "%c", &x ) != -1 && x != '\n' )
	{
		tab [ x - 'a' ] ++;
		sum ++;
	}

	specialSil ( sum, tab1 );

	for ( lld i = 0; i < 30; ++i )
	{
		specialSil ( tab [ i ], tab2 );
		for ( lld j = 0; j < 1010; ++j )
		{
			tab1 [ j ] -= tab2 [ j ];
			tab2 [ j ] = 0;
		}
	}
	sum = 1;
	for ( lld i = 1; i < 1010;++ i )
		while ( tab1 [ i ] -- > 0 )
			sum *= i;

	printf ( "%lld\n", sum );

	#ifndef HELIOS64
	system("pause");
	#endif

	return 0;
}

