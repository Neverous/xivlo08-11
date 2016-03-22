/*	2008
Maciej Szeptuch
XIV LO Wrocław
*/
#include<cstdio>

int numbers [ 1010 ], // zbiór
	numOfNumbers, // ilość elementów zbioru
	position [ 1010 ], // gdzie powinien znajdować się i-ty element
	visited [ 1010 ], // odwiedzony
	min, // minimum w cyklu
	sum, // suma w cyklu
	length, // długość cyklu
	minElement, // minimalnt element całego zbioru
	result; // wynik

int dfs ( int i )
{
	if ( visited [ i ] ) // Jeśli wcześniej odwiedzony
		return 0;

	visited [ i ] = true; // odwiedzony
	sum += numbers [ i ]; // suma się zwiększa
	min = ( min < numbers [ i ] ) ? min : numbers [ i ]; // minimum może się zmniejszyć
	length ++; // długość cyklu się zwiększa
	return length + dfs ( position [ numbers [ i ] ] - 1 );	 // następny element cyklu
}

void csort ( )
{
	for ( int i = 0; i < 1010; i ++ )
	{
		position [ i ] = 0;
		visited [ i ] = 0;
	} // Czyszczenie tablic
	for ( int i = 0; i < numOfNumbers; i ++ )
		position [ numbers [ i ] ] ++;  // ile mnie jest
	for ( int i = 1; i < 1010; i ++ )
		position [ i ] += position [ i - 1 ]; // ile mniejszych bądź równych mnie
}

int solve ( )
{
	csort ( ); //*sort*
	result = 0; // zerowanie
	for ( int i = 0; i < numOfNumbers; i ++ )
	{
		min = 1010; // maksimum
		sum = length = 0; // zerowanie
		if ( ! visited [ i ] ) // jeśli nie odwiedzony
			if ( dfs ( i )  &&  length > 1) // to odwiedź, i jeśli długość cyklu > 1 dodaj koszt
				result += ( minElement * ( length + 1 ) + sum + min < min * ( length - 2 ) + sum ) ? minElement * ( length + 1 ) + sum + min : min * ( length - 2 ) + sum; // z tym że można go nieco ulepszyć jeśli koszt zamiany minimum z cyklu i minimum ogólnego i z powrotem będzie dawał jakiś zysk
	}
	return result; //wynik
}

int main ( void )
{
	int cas = 0; // testy
	while ( scanf ( "%d", & numOfNumbers ) != -1 && numOfNumbers != 0 && ++ cas )
	{
		minElement = 1010; // Zerowanie
		for ( int i = 0; i < numOfNumbers; i ++ )
		{
			scanf ( "%d", & numbers [ i ] );
			minElement = ( minElement > numbers [ i ] ) ? numbers [ i ] : minElement; // szukanie minimum w całym zbiorze
		}
		printf ( "Case %d: %d\n", cas, solve ( ) ); // wynik
	}
}

