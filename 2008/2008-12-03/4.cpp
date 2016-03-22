/*		2008
Maciej Szeptuch
XIV LO Wrocław
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

#define HELP_MSG "usage: %s [options]\nWhere [options] could be:\n   * input output - names of input.txt and output.txt files ( could be stdin or stdout for standard input / output )\n\nexample: %s dane.txt stdout\nWill read data from dane.txt and write output to screen\n\n(C) Maciej Szeptuch 2008\n", argv [ 0 ], argv [ 0 ]

using namespace std;

FILE * input,
	* output;

void determineIO ( int arg, char * argv [ ] );
void closeIO ( void );

/******************************************************************************/
int elem,
	maks,
	tab [ 1000010 ],
	tmp;

int binarySearch ( int element )
{
	int start = 0,
		end = maks + 1;

	while ( start < end )
	{
		if ( tab [ ( start + end ) / 2 ] > element )
			end = ( start + end ) / 2;
		else
			start = ( start + end ) / 2 + 1;
	}
	return start<=0?1:start;
}

int main ( int arg, char * argv [ ] )
{
	determineIO ( arg, argv );

	for ( int i = 1; i < 1000010; ++ i )
		tab [ i ] = 1000000;

	while ( fscanf ( input, "%d", & elem ) != -1 )
	{
		tmp = binarySearch ( elem );
		if ( tab [ tmp ] > elem )
			tab [ tmp ] = elem;
		maks = maks > tmp ? maks : tmp;
	}

	fprintf ( output, "%d\n", maks );

	closeIO ( );

	#ifndef HELIOS64
	system ( "pause" );
	#endif

	return 0;
}

/******************************************************************************/

void determineIO ( int arg, char * argv [ ] )
{
	/*input = fopen ( "Dane6seq.txt", "r" );
	output = fopen ( "Out6seq.txt", "w" );
	*/
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

