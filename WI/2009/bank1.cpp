/* 2009
Maciej Szeptuch
XIV LO Wrocław
*/

#include <cstdio>
#include <algorithm>
#include <functional>

int money,
	cash [ 202 ],
	got [ 20020 ],
	wanted;

int solve ( void )
{
	std :: sort ( cash, cash + money, std :: greater < int > () );

	for ( int pointer = 0;! got [ wanted ] && pointer < money; ++ pointer )
	{
		for ( int now = wanted; now >= cash [ pointer ]; -- now )
		{
			if ( got [ now - cash [ pointer ] ] > 0 && got [ now ] < got [ now - cash [ pointer ] ] + 1 )
				got [ now ] = got [ now - cash [ pointer ] ] + 1;

		}

		got [ cash [ pointer ] ] = 1;
	}

	return got [ wanted ] ? got [ wanted ] : -1;
}

int main ( void )
{
	scanf ( "%d", & money );
	for ( int m = 0; m < money; ++ m )
		scanf ( "%d", & cash [ m ] );

	scanf ( "%d", & wanted );
	printf ( "%d\n", solve ( ) );
	return 0;
}

