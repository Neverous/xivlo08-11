/*		2008
Maciej Szeptuch
XIV LO Wrocław
*/
#include <iostream>

using namespace std;

typedef long long int lld;
lld a;

int main ( void )
{

	scanf ( "%lld", & a );
	for ( lld i = 2; i * i <= a; ++ i )
	{
		while ( a % i == 0 )
		{
			printf ( "%lld ", i );
			a /= i;
		}
	}
	if ( a > 1 )
		printf ( "%lld ", a );
	printf ( "\n" );

	#ifndef HELIOS64
	system("pause");
	#endif

	return 0;
}

