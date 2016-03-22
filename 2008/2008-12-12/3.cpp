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
const int BIGNUM = 10000;
int size,
	tab [ 1005 ] [ 1005 ] [ 3 ],
	min,
	place;

int main ( int arg, char * argv [ ] )
{
	determineIO ( arg, argv );

	fscanf ( input, "%d", & size );

	for ( int i = 0; i <= size; ++ i )
		tab [ 0 ] [ i ] [ 1 ] = tab [ size + 1 ] [ i ] [ 1 ] = BIGNUM;

	for ( int i = 1; i <= size; ++ i )
		for ( int j = 1; j <= size; ++ j )
			fscanf ( input, "%d", & tab [ i ] [ j ] [ 0 ] );

	for ( int j = 1; j <= size; ++ j )
		for ( int i = 1; i <= size; ++ i )
		{
			tab [ i ] [ j ] [ 1 ] = BIGNUM;
			for ( int k = -1; k <= 1; ++ k )
			{
				if ( tab [ i ] [ j ] [ 0 ] + tab [ i + k ] [ j - 1 ] [ 1 ] < tab [ i ] [ j ] [ 1 ] )
				{
					tab [ i ] [ j ] [ 1 ] = tab [ i ] [ j ] [ 0 ] + tab [ i + k ] [ j - 1 ] [ 1 ];
					tab [ i ] [ j ] [ 2 ] = k;
				}
			}
		}

	min = BIGNUM;

	for ( int i = 1; i <= size; ++ i )
		if ( min > tab [ i ] [ size ] [ 1 ] )
		{
			min = tab [ i ] [ size ] [ 1 ];
			place = i;
		}

	for ( int j = place, i = size; i > 0; j += tab [ j ] [ i ] [ 2 ], -- i )
		tab [ 0 ] [ i - 1 ] [ 0 ]  = tab [ j ] [ i ] [ 0 ];

	for ( int i = 0; i < size; ++ i )
		fprintf ( output, "%d ", tab [ 0 ] [ i ] [ 0 ] );
	fprintf ( output, "\n%d\n", min );

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

