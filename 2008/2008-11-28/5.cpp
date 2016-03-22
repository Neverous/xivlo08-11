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

int a,
	b,
	c,
	rX,
	rY;

void determineIO ( int arg, char * argv [ ] );
void closeIO ( void );
bool extendedEuklides ( int a, int b, int c, int & rX, int & rY );

int main ( int arg, char * argv [ ] )
{
	determineIO ( arg, argv );

	fscanf ( input, "%d %d %d", & a, & b, & c );
	if ( extendedEuklides ( a, b, c, rX, rY ) )
		fprintf ( output, "%d %d\n", rX, rY );
	else
		fprintf ( output, "NIE\n" );

	closeIO ( );

	#ifndef HELIOS64
	system ( "pause" );
	#endif

	return 0;
}

bool extendedEuklides ( int a, int b, int c, int & rX, int & rY )
{
	int d = 0,
		x = 0,
		lastX = 1,
		y = 1,
		lastY = 0,
		div = a / b;

	bool swapped = false;

	if ( a < b )
	{
		swap ( a, b );
		swapped = true;
	}

	while ( b > 0 )
	{
		d = b;
		div = a / b;
		b = a % b;
		a = d;

		d = x;
		x = lastX - div * x;
		lastX = d;

		d = y;
		y = lastY - div * y;
		lastY = d;

		if ( b > 0 && c % b == 0 )
		{
			rX = x * c / b;
			rY = y * c / b;
			if ( swapped )
				swap ( rX, rY );

			return 1;
		}
	}

	if ( c % a == 0 )
	{
		rX = lastX * c / a;
		rY = lastY * c / a;
		if ( swapped )
			swap ( rX, rY );
		return 1;
	}

	return 0;
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

