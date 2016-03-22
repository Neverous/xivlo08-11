/*		2008
Maciej Szeptuch
XIV LO Wrocław
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>

#define HELP_MSG "usage: %s [options]\nWhere [options] could be:\n   * input output - names of input.txt and output.txt files ( could be stdin or stdout for standard input / output )\n\nexample: %s dane.txt stdout\nWill read data from dane.txt and write output to screen\n\n(C) Maciej Szeptuch 2008\n", argv [ 0 ], argv [ 0 ]

using namespace std;

FILE * input,
	* output;

int numbers [ 1000010 ],
	num,
	len,
	maksLen,
	n;

vector < pair < int, int > >  need;

void determineIO ( int arg, char * argv [ ] );
void closeIO ( void );

int main ( int arg, char * argv [ ] )
{
	determineIO ( arg, argv );

	for ( n = 0; fscanf ( input, "%d", & num ) != -1; ++ n )
	{
		numbers [ n ] = num;
		if ( n > 0 && num <= numbers [ n - 1 ] )
		{
			need . push_back ( make_pair ( n, len ) );
			maksLen = maksLen < len ? len : maksLen;
			len = 0;
		}
		++ len;
	}

	maksLen = maksLen < len ? len : maksLen;
	need . push_back ( make_pair ( n, len ) );

	for ( n = 0; n < need . size ( ) - 1; ++ n )
	{
		if ( need [ n ] . first - 2 >= 0 &&
			( (
				numbers [ need [ n ] . first ] < numbers [ need [ n ] . first - 2 ]	&&
				numbers [ need [ n ] . first - 1 ] < numbers [ need [ n ] . first + 1 ]
			  ) ||
			  (
			  	numbers [ need [ n ] . first ] > numbers [ need [ n ] . first - 2 ]
			  )
			 )
			)
			maksLen = maksLen > need [ n ] . second + need [ n + 1 ] . second - 1 ? maksLen : need [ n ] . second + need [ n + 1 ] . second - 1;
	}

	fprintf ( output, "%d\n", maksLen );

	closeIO ( );

	#ifndef HELIOS64
	system ( "pause" );
	#endif

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

