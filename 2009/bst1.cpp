/* 2009
Maciej Szeptuch
XIV LO Wrocław
*/

#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

template < typename type >
struct Node
{
	Node * left,
		 * right,
		 * parent;

	type value;

	Node ( type nValue = 0, Node < type > * nParent = 0 )
	{
		value = nValue;
		parent = nParent;
		left = 0;
		right = 0;
	}

	Node < type > * insert ( Node < type > * child )
	{
		Node * act = this;

		while ( act )
		{
			if ( act -> value > child -> value )
			{
				if ( ! act -> left )
				{
					act -> left = child;
					child -> parent = act;
					break;
				}
				act = act -> left;
			}

			else
			{
				if ( ! act -> right )
				{
					act -> right = child;
					child -> parent = act;
					break;
				}
				act = act -> right;
			}
		}

		return child;
	}

	Node < type > * getMinimum ( )
	{
		Node * act = this;
		while ( act -> left )
			act = act -> left;

		return act;
	}

	Node * getMaximum ( )
	{
		Node * act = this;
		while ( act -> right )
			act = act -> right;

		return act;
	}

	Node < type > * search ( type sValue )
	{
		Node * act = this;

		while ( act )
		{
			if ( act -> value > sValue )
				act = act -> left;

			else if ( act -> value < sValue )
				act = act -> right;

			else
				return act;
		}

		return act;
	}

	Node < type > * getSuccessor ( type sValue )
	{
		Node * act = search ( sValue ),
			 * tmp;

		if ( ! act )
			return act;

		if ( act -> right )
			return act -> right -> getMinimum ( );

		tmp = act -> parent;

		while ( tmp && act == tmp -> right )
		{
			act = tmp;
			tmp = tmp -> parent;
		}

		return tmp;
	}

	Node < type > *  getPredecessor ( type sValue )
	{
		Node * act = search ( sValue ),
			 * tmp;

		if ( ! act )
			return act;

		if ( act -> left )
			return act -> left -> getMaximum ( );

		tmp = act -> parent;

		while ( tmp && act == tmp -> left )
		{
			act = tmp;
			tmp = tmp -> parent;
		}

		return tmp;
	}

	Node < type > * remove ( type rValue )
	{
		Node * act = search ( rValue ),
			 * suc = 0,
			 * tmp = 0;

		if ( ! act )
			return act;

		if ( ! act -> left || ! act -> right )
			suc = act;

		else
			suc = act -> getSuccessor ( act -> value );

		if ( suc -> left )
			tmp = suc -> left;

		else
			tmp = suc -> right;

		if ( tmp )
			tmp -> parent = suc -> parent;

		if ( suc == suc -> parent -> left )
			suc -> parent -> left = tmp;

		else
			suc -> parent -> right = tmp;

		if ( suc != act )
			swap ( act -> value, suc -> value );

		return suc;
	}
};

Node < int > * placeholder = new Node < int > ( -1 ),
			 * tmp;
int a,
	b;

int main ( void )
{
	while ( scanf ( "%d %d", & a, & b ) != -1 && a != 0 )
	{
		switch ( a )
		{
			case 1 :
				placeholder -> insert ( new Node < int > ( b ) );
				break;

			case 2 :
				printf ( "%d\n", placeholder -> right -> getMinimum ( ) -> value );
				break;

			case 3 :
				printf ( "%d\n", placeholder -> right -> getMaximum ( ) -> value );
				break;

			case 4 :
				printf ( "%s\n", placeholder -> right -> search ( b ) ? "TAK" : "NIE" );
				break;

			case 5 :
				delete placeholder -> right -> remove ( b );
				break;

			case 6 :
				if ( ! placeholder -> right -> search ( b ) )
					printf ( "NIE\n" );

				else
				{
					tmp = placeholder -> right -> getPredecessor ( b );
					printf ( "%d ",  tmp ? tmp -> value : -1 );
					tmp = placeholder -> right -> getSuccessor ( b );
					printf ( "%d\n",  tmp ? tmp -> value : -1 );
				}
				break;

			default :
				break;
		}
	}
	return 0;
}

