/*		2008
Maciej Szeptuch
XIV LO Wrocław
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>

using namespace std;

typedef long long int lld;
vector < lld > primes;
lld tests,
	modulo,
	test,
	tempTab [ 1000010 ];

void sitoGen ( void )
{
	primes . clear ( );
	tempTab [ 0 ] = tempTab [ 1 ] = 1;
	for ( lld i = 2, j = 0; i < 1000010; ++ i )
	{
		if ( tempTab [ i ] )
			continue;

		primes . push_back ( i );

		for ( j = i+i; j < 1000010; j += i )
			tempTab [ j ] = 1;
	}
}

lld fastPower ( lld x, lld n, lld MOD )
{
	lld result = 1;
	for ( int w = 0; w < n; ++ w )
		result *= x;
	return result;
}

lld solve ( lld number )
{
	lld result = 1;
	for ( lld i = 0, size = primes . size ( ), j = 0; i < size && number > 1 && primes [ i ] * primes [ i ] <= number; ++ i )
	{
		j = 0;
		while ( number % primes [ i ] == 0 )
		{
			number /= primes [ i ];
			++ j;
		}
		result = ( result * (lld) ( fastPower ( primes [ i ], j + 1, modulo ) - 1 ) / ( primes [ i ] - 1 ) ) % modulo;
	}
	if ( number > 1 )
		result = ( result * (lld) ( number * number - 1 ) / ( number - 1 ) ) % modulo;
	return result;
}

int main ( void )
{
	sitoGen ( );
	scanf ( "%lld %lld", & tests, & modulo );

	for ( lld t = 0; t < tests; ++ t )
	{
		scanf ( "%lld", & test );
		printf ( "%lld\n", solve ( test ) );
	}

	return 0;
}

