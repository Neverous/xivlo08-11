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

int len,
	tab [ 10010 ],
	maks = 1,
	series;

int gcd ( int a, int b )
{
	int c;
	if ( b > a )
		swap ( a, b );

	while ( b )
	{
		c = b;
		b = a % b;
		a = c;
	}

	return a;
}

int lcm ( int a, int b )
{
	return ( a * b ) /  gcd ( a, b );
}

int dfs ( void )
{
	for ( int l = 0, k = 0; l < len; ++ l )
	{
		series = 0;
		while ( tab [ l ] && ++ series )
		{
			k = l;
			l = tab [ l ] - 1;
			tab [ k ] = 0;
		}
		if ( series > 0 )
			maks = lcm ( maks, series );
	}
	return maks;
}

int main ( int arg, char * argv [ ] )
{
	determineIO ( arg, argv );

	fscanf ( input, "%d", & len );
	for ( int l = 0; l < len; ++ l )
		fscanf ( input, "%d", & tab [ l ] );

	fprintf ( output, "%d\n", dfs ( ) );

	closeIO ( );

	#ifndef HELIOS64
	system ( "pause" );
	#endif

	return 0;
}

/******************************************************************************/

void determineIO ( int arg, char * argv [ ] )
{
	input = fopen ( "Dane6perm.txt", "r" );
	output = fopen ( "Out6perm.txt", "w" );
	/*
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
	}*/
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

