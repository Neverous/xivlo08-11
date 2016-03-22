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

int result [ 2000020 ],
	moneys [ 1000010 ],
	wanted [ 1000010 ],
	money,
	wants,
	maksWant;

void determineIO ( int arg, char * argv [ ] );
void closeIO ( void );
void generateResult ( int value );

int main ( int arg, char * argv [ ] )
{
	determineIO ( arg, argv );

	fscanf ( input, "%d", & money );
	for ( int m = 0; m < money; ++ m )
	{
		fscanf ( input, "%d", & moneys [ m ] );
		result [ moneys [ m ] ] = 1;
	}

	fscanf ( input, "%d\n", & wants );
	for ( int w = 0; w < wants; ++ w )
	{
		fscanf ( input, "%d", & wanted [ w ] );
		maksWant = maksWant < wanted [ w ] ? wanted [ w ] : maksWant;
	}

	generateResult ( maksWant );

	for ( int w = 0; w < wants; ++ w )
	{
		if ( ! result [ wanted [ w ] ] )
			fprintf ( output, "NIE\n" );
		else
			fprintf ( output, "%d\n", result [ wanted [ w ] ] );
	}

	closeIO ( );

	#ifndef HELIOS64
	system ( "pause" );
	#endif

	return 0;
}

void generateResult ( int value )
{
	for ( int i = 1; i < value; ++ i )
	{
		if ( ! result [ i ] )
			continue;

		for ( int m = 0; m < money; ++ m )
			result [ i + moneys [ m ] ] = result [ i + moneys [ m ] ] > result [ i ] + 1 || result [ i + moneys [ m ] ] == 0 ? result [ i ] + 1 : result [ i + moneys [ m ] ];
	}
}

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

