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
		got [ cash [ pointer ] ] = 1;
		for ( int now = 0; now <= wanted - cash [ pointer ]; ++ now )
		{
			if ( got [ now ] > 0 && got [ now + cash [ pointer ] ] < got [ now ] + 1 )
				got [ now  + cash [ pointer ] ] = got [ now ] + 1;

		}
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

