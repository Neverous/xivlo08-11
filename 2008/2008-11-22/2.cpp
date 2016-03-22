/*		2008
Maciej Szeptuch
XIV LO Wrocław
*/
#include <iostream>

using namespace std;

typedef long long int lld;
lld a,
	res = 1,
	tmp;

int main ( void )
{

	scanf ( "%lld", & a );
	for ( lld i = 2; i * i <= a; ++ i )
	{
		tmp = 1;
		while ( a % i == 0 )
		{
			a /= i;
			tmp ++;
		}
		res *= tmp;
	}
	if ( a > 1 )
		res *= 2;
	printf ( "%lld\n", res );

	#ifndef HELIOS64
	system("pause");
	#endif

	return 0;
}

