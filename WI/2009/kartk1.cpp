#include <cstdio>
int a,
	m,
	k,
	ksor;

int main ( void )
{
	scanf ( "%d %d %d ", & a, & m, & k );
	m %= 1<<16;
	for ( int i = 0; i < m + 1; i++ )
	{
		ksor ^= a;
		a = ( a + k ) % ( 1<<16 );
	}

	printf ( "%d\n", ksor );

	return 0;
}

