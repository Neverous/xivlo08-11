/* 2009
Maciej Szeptuch
XIV LO Wrocław
*/
#include <cstdio>
#include <string>

template < typename Type >
struct ListElem
{
	Type value;
	ListElem < Type > * next;

	ListElem ( Type nValue = 0, ListElem < Type > * nNext = 0 )
	{
		value = nValue;
		next = nNext;
	}

	void del ( void )
	{
		if ( next )
		{
			next -> del ( );
			delete next;
		}

		next = 0;
	}
};

template < typename Type >
struct List
{
	unsigned int _size;
	ListElem < Type > * first;
	ListElem < Type > * last;

	List ( void )
	{
		_size = 0;
		first = 0;
		last = 0;
	}

	void push_back ( Type value )
	{
		++ _size;
		if ( ! last )
			first = last = new ListElem < Type > ( value );
		else
		{
			last -> next = new ListElem < Type > ( value );
			last = last -> next;
		}
	}

	unsigned int size ( void )
	{
		return _size;
	}

	void clear ( void )
	{
		if ( first )
		{
			first -> del ( );
			delete first;
		}

		last = 0;
		first = 0;
		_size = 0;
	}
};

char action,
	 word [ 1000 ];

List < std :: string > tab [ 30 ];
ListElem < std :: string > * now;

int main ( void )
{
	while ( action != 'K' )
	{
		scanf ( "%c", & action );

		if ( action == '\n' )
			scanf ( "%c", &action );

		if ( action == 'K' )
			break;

		scanf ( "%*s%s", word );
		switch ( action )
		{
			case 'D' :
				tab [ word [ 0 ] - 'a' ] . push_back ( std :: string ( word ) );
				break;

			case 'W' :
				printf ( "%d ", tab [ word [ 0 ] - 'a' ] . size ( ) );
				now = tab [ word [ 0 ] - 'a' ] . first;
				while ( now )
				{
					printf ( "%s ", now -> value . c_str ( ) );
					now = now -> next;
				}
				printf ( "\n" );
				break;

			case 'C' :
				tab [ word [ 0 ] - 'a' ] . clear ( );
				break;
		}
	}
	return 0;
}

