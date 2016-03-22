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

int a,
	b;

int magicFunction ( int n, int k )
{
	if ( k == 0 || k == n )
		return 1;

	return ( magicFunction ( n - 1, k ) + magicFunction ( n - 1, k - 1 ) ) % 1000000;
}

int main ( int arg, char * argv [ ] )
{
	determineIO ( arg, argv );

	fscanf ( input, "%d %d", & a, & b );
	fprintf ( output, "%d\n", magicFunction ( a, b ) );

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

