/*		2008
Maciej Szeptuch
XIV LO Wrocław
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#define HELP_MSG "usage: %s [options]\nWhere [options] could be:\n   * input output - names of input.txt and output.txt files ( could be stdin or stdout for standard input / output )\n\nexample: %s dane.txt stdout\nWill read data from dane.txt and write output to screen\n\n(C) Maciej Szeptuch 2008\n", argv [ 0 ], argv [ 0 ]

using namespace std;

FILE * input,
	* output;

void determineIO ( int arg, char * argv [ ] );
void closeIO ( void );

/******************************************************************************/

typedef long long int lld;

lld tab [ 100 ],
	n,
	k,
	j = 2;

int size;

int binarySearch ( lld element, int start, int end )
{
	while ( start < end )
	{
		if ( tab [ ( start + end ) / 2 ] > element )
			end = ( start + end ) / 2;
		else
			start = ( start + end ) / 2 + 1;
	}
	return start<=0?1:start - 1;
}

void generate ( void )
{
	for ( size = 0; j < (lld) 1000000000000000000; j *= 2, ++ size )
		tab [ size ] = j;
	-- size;
}

int solve ( void )
{
	generate ( );
	while ( n > 2 )
	{
		size = binarySearch  ( n, 0, size );

		if ( n % tab [ size ] == 0 && k <= n )
			return 1;

		n %= tab [ size ];
		k %= tab [ size ];
	}
	if ( ( n == 1 && k == 1 ) || ( n == 2 && k == 1 ) || ( n == 2 && k == 2 ) )
		return 1;
	return 0;
}

int main ( int arg, char * argv [ ] )
{
	determineIO ( arg, argv );

	fscanf ( input, "%lld %lld", & n, & k );
	++k; ++n;
	printf ( "%d\n", solve ( ) );
	closeIO ( );

	#ifndef HELIOS64
	system ( "pause" );
	#endif

	return 0;
}

/******************************************************************************/

void determineIO ( int arg, char * argv [ ] )
{
	switch ( arg )
	{
		case 3 :
			if ( ! strcmp ( argv [ 1 ], "stdin" ) )
				input = stdin;
			else
				input = fopen ( argv [ 1 ], "r" );

			if ( input == NULL )
				break;

			if ( ! strcmp ( argv [ 2 ], "stdout" ) )
				output = stdout;
			else
				output = fopen ( argv [ 2 ], "w" );
			break;

		default :
			printf ( HELP_MSG );
			exit ( 0 );
			break;
	}
	if ( input == NULL ||
		 output == NULL )
	{
		printf ( "Cannot open input or output file!\nIf you dont know how to use this program type: %s help.\n", argv [ 0 ] );

		exit ( 1 );
	}
}

void closeIO ( void )
{
	if ( input != stdin )
		fclose ( input );

	if ( output != stdout )
		fclose ( output );

}

