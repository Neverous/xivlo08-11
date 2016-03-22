/* 2009
Maciej Szeptuch
XIV LO Wrocław
*/

#include <cstdio>

struct Node
{
	int value;
	Node * next;

	Node  ( int v = 0, Node * n = 0 )
	{
		value = v;
		next = n;
	}
};

Node * list = 0;
int number;

int main ( void )
{
	while ( scanf ( "%d", & number ) != -1 && number != 0 )
		list = new Node ( number, list );

	while ( list != 0 )
	{
		printf ( "%d ", list -> value );
		list = list -> next;
	}
	printf ( "\n" );

	return 0;
}

