/* 2009
Maciej Szeptuch
XIV LO Wrocław
*/
#include <cstdio>
int length,
	start = 0,
	left = 0,
	count = 1,
	right = 1,
	end = 1;

char word [ 1000010 ];
bool first = true;

int main ( void )
{
	scanf ( "%d", & length );
	scanf ( "%s",  word );
	printf ( "%s=", word );
	while ( right < length )
	{
		while ( word [ left ] == word [ right ] && right < length )
		{
			++ left;
			++ right;
			if ( left > end && ( left % ( end - start ) ) == 0 )
				++ count;
		}

		if ( word [ right ] > word [ left ] )
		{
			end = right + 1;
			left = start;
			count = 1;
		}

		else
		{
			for ( int c = 0; c < count; ++ c )
			{
				if ( ! first )
					printf ( "+" );

				for ( int i = 0; i < end - start; ++ i )
					printf ( "%c", word [ start + i ] );

				first = false;
			}
			start = start + ( end - start ) * count;
			left = start;
			right = start;
			end = start + 1;
			count = 1;
		}
		++ right;
	}

	while ( count -- && end <= length )
	{
		if ( ! first )
			printf ( "+" );

		for ( int i = 0; i < end - start; ++ i )
			printf ( "%c", word [ start + i ] );

		first = false;
	}
	printf ( "\n" );
	return 0;
}

