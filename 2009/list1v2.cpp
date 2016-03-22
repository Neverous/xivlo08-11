/* 2009
Maciej Szeptuch
XIV LO Wrocław
PRO VERSION ^^
*/
#include <cstdio>

struct List
{
	int value;
	List * next;

	List ( int nValue = 0, List * nNext = 0 )
	{
		value = nValue;
		next = nNext;
	}
};

List * first = new List,
	 * last = first,
	 * ph = new List,
	 * act,
	 * act2,
	 * act3;

int size,
	actions,
	tmp,
	what,
	where;

int main ( void )
{

	scanf ( "%d %d", & size, & actions );

	for ( int s = 0; s < size; ++ s )
	{
		scanf ( "%d", & tmp );
		act = new List ( tmp, ph );
		if ( ! first )
		{
			first = act;
			last = act;
			continue;
		}

		last -> next = act;
		last = act;
	}

	for ( int a = 0; a < actions; ++ a )
	{
		scanf ( "%d %d", & what, & where );

		if ( where == 0 && what == 0 )
		{
			act = first;
			while ( act )
			{
				if ( act -> value )
					printf ( "%d ", act -> value );

				act = act -> next;
			}
			printf ( "\n" );
			continue;
		}

		act3 = act2 = 0;
		act = first;
		while ( act )
		{
			if ( act -> value == where )
				act3 = act;

			if ( act -> next && act -> next -> value == what )
				act2 = act;

			act = act -> next;
		}

		act = act2 -> next;

		act2 -> next = act2 -> next -> next;
		act -> next = act3 -> next;
		act3 -> next = act;
	}
	return 0;
}

