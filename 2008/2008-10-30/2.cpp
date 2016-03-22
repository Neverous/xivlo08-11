/*		2008
Maciej Szeptuch
XIV LO Wrocław
*/
#include <iostream>

using namespace std;

int main ( void )
{
	for ( int i = 0, k = 0; i < 10; ++ i )
	{
		for ( int j = 0; j <= i; ++ j, ++k )
			cout << ( ( k % 2 ) ? "+" : "*" );
		cout << endl;
	}

	#ifndef HELIOS64
	system("pause");
	#endif

	return 0;
}

