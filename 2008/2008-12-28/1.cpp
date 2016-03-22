/*		2008
Maciej Szeptuch
XIV LO Wrocław
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <list>
#define HELP_MSG "usage: %s [options]\nWhere [options] could be:\n   * input output - names of input.txt and output.txt files ( could be stdin or stdout for standard input / output )\n\nexample: %s dane.txt stdout\nWill read data from dane.txt and write output to screen\n\n(C) Maciej Szeptuch 2008\n", argv [ 0 ], argv [ 0 ]

using namespace std;

FILE * input,
	* output;

void determineIO ( int arg, char * argv [ ] );
void closeIO ( void );

/******************************************************************************/

int size,
	tab [ 1010 ] [ 1010 ],
	result,
	act,
	maks;

list< int > queue;

int bfs ( int h, int w )
{
	result = 0;
	queue . push_back ( h * 10000 + w );

	while ( ! queue . empty ( ) )
	{
		w = queue . front ( );
		h = w / 10000;
		w %= 10000;
		queue . pop_front ( );

		if ( ! tab [ h ] [ w ] )
			continue;

		result ++;

		if ( tab [ h - 1 ] [ w ] == tab [ h ] [ w ] )
			queue . push_back ( ( h - 1 ) * 10000 + w );

		if ( tab [ h + 1 ] [ w ] == tab [ h ] [ w ] )
			queue . push_back ( ( h + 1 ) * 10000 + w );

		if ( tab [ h ] [ w - 1 ] == tab [ h ] [ w ] )
			queue . push_back ( h * 10000 + w - 1 );

		if ( tab [ h ] [ w + 1 ] == tab [ h ] [ w ] )
			queue . push_back ( h * 10000 + w + 1 );

		tab [ h ] [ w ] = 0;
	}
	return result;
}

int solve ( void )
{
	for ( int h = 1; h <= size; ++ h )
		for ( int w = 1; w <= size; ++ w )
		{
			if ( tab [ h ] [ w ] )
			{
				act = bfs ( h, w );
				maks = maks > act ? maks : act;
			}
		}

	return maks;
}

int main ( int arg, char * argv [ ] )
{
	determineIO ( arg, argv );

	fscanf ( input, "%d", & size );

	for ( int h = 1; h <= size; ++ h )
		for ( int w = 1; w <= size; ++ w )
			fscanf ( input, "%d", & tab [ h ] [ w ] );

	fprintf ( output, "%d\n", solve ( ) );

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

