/*		2008
Maciej Szeptuch
XIV LO Wrocław
*/
#include <iostream>

typedef long long int lld;
int tab [ 30 ];
char x;
int max;

int main ( void )
{
	while ( scanf ( "%c", &x ) != -1 && x != '\n' )
	{
		tab [ x - 'a' ] ++;
		if ( tab [ x - 'a' ] > tab [ max ] )
			max = x - 'a';
	}

	printf ( "%c\n", max + 'a' );

	#ifndef HELIOS64
	system("pause");
	#endif

	return 0;
}

