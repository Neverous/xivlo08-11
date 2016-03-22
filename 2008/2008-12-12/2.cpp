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

void determineIO ( int arg, char * argv [ ] );
void closeIO ( void );

/******************************************************************************/
typedef long long int lld;
vector < int > primes;
int tests,
	modulo,
	test,
	tempTab [ 1000000 ];

void sitoGen ( void )
{
	primes . clear ( );
	tempTab [ 0 ] = tempTab [ 1 ] = 1;
	for ( int i = 2, j = 0; i < 1000000; ++ i )
	{
		if ( tempTab [ i ] )
			continue;

		primes . push_back ( i );

		for ( j = i+i; j < 1000000; j += i )
			tempTab [ j ] = 1;
	}
}

lld fastPower ( int x, int n, int MOD )
{
	lld result = 1,
		temp = x;
	while ( n > 0 )
	{
		if ( n % 2 )
			result *= temp;
		n /= 2;
		temp = ( temp * x ) % MOD;
	}
	return result;
}

lld solve ( int number )
{
	lld result = 1;
	for ( int i = 0, size = primes . size ( ), j = 0; number > 1 && primes [ i ] * primes [ i ] <= number && i < size; ++ i )
	{
		j = 0;
		while ( number % primes [ i ] == 0 )
		{
			number /= primes [ i ];
			++ j;
		}
		result *= (lld) ( fastPower ( primes [ i ], j + 1, modulo ) - 1 ) / ( primes [ i ] - 1 );
		result %= modulo;
	}
	if ( number > 1 )
		result *= (lld) ( number * number - 1 ) / ( number - 1 );
	return result % modulo;
}

int main ( int arg, char * argv [ ] )
{
	determineIO ( arg, argv );

	sitoGen ( );
	fscanf ( input, "%d %d\n", & tests, & modulo );

	for ( int t = 0; t < tests; ++ t )
	{
		fscanf ( input, "%d", & test );
		fprintf ( output, "%lld\n", solve ( test ) );
	}
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

