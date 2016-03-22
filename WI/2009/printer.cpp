/* PRINTER
Drzewo Trie
Maciej Szeptuch 2008
*/
#include <cstdio>

struct TreeNode
{
	int weight; // Ile liter maksymalnie podemną.
	TreeNode * daddy; // Ojciec.
	TreeNode * todds [ 30 ]; // Dzieci.
	char whoAmI; // Jak się nazywam.
	char numberOfTodds; // Ile mam dzieci.
	bool writeMe; // Jestem sobie końcem wyrazu?

	TreeNode ( void ) // "zerowanie" wszystkiego.
	{
		weight = 0;
		daddy = NULL;
		whoAmI = 0;
		numberOfTodds = 0;
		writeMe = false;

		for ( int i = 0; i < 30; i++ )
			todds [ i ] = NULL;

	}

};

char ltn ( char letter ) // Letter To Number
{
	return letter - 'a';
}

void addWord ( TreeNode * root, char * word ) // "normalne" dodawanie wyrazu do drzewa.
{
	TreeNode * now = root;

	for ( int i = 0; word [ i ] != NULL; i++ ) // Dla każdego elementu wyrazu,
	{
		if ( now -> todds [ ltn ( word [ i ] ) ] == NULL ) // jeśli aktualny nie ma takiego dziecka,
		{
			now -> todds [ ltn ( word [ i ] ) ] = new TreeNode; // to je dodaje ;).
			now -> todds [ ltn ( word [ i ] ) ] -> daddy = now; // Żeby wiedziało kto jest ojcem
			now -> todds [ ltn ( word [ i ] ) ] -> whoAmI = word [ i ]; // i jak się nazywa.
			now -> numberOfTodds++; // Ojciec ma dziecko więcej ^^.
		}

		now = now -> todds [ ltn ( word [ i ] ) ]; // Zmieniam aktualnego.
	}

	now -> writeMe = true; // Jestem końcem wyrazu!!! JUPII!

	for ( int i = 0; now != NULL; i++ ) // Uzupełnianie wag.
	{
		if ( now -> weight < i ) // Jeśli waży za mało,
			now -> weight = i; // to powinien przytyć ^^.

		now = now -> daddy; // Teraz sprawdzamy ojca.
	}

}

void addSpecialWord ( TreeNode * root, char * word ) // "specjalne" dodawanie: wyraz i jego "podsłowa".
{
	for ( int i = 0; word [ i ] != NULL; i++ ) // Dla każdego "podsłowa"
		addWord ( root, word + i ); // uruchom normalne dodawanie.

}

int movesToPrint ( TreeNode * now ) // Określanie minimalnej ilości ruchów dla zadania TYPE PRINTER.
{
	int numberOfMoves = 2;	// Ilość ruchów.
	if ( now -> writeMe ) // Jeśli jestem końcem,
		numberOfMoves++; // to wykonam ruch więcej.

	for ( int i = 0; i < 30; i++ ) // Sprawdzenie dzieci.
	{
		if ( now -> todds [ i ] != NULL ) // Jeśli ma dziecko,
			 numberOfMoves += movesToPrint ( now -> todds [ i ] ); // To dodaje jego ilość ruchów.

	}
	return numberOfMoves; // Zwracam ilość ruchów.
}

int main ( void )
{
	TreeNode * root = new TreeNode;
	int wordsToAdd;
	char word [ 30 ];

	scanf ( "%d", & wordsToAdd ); // Ile wyrazów.

	for ( int i = 0; i < wordsToAdd; i++ )
	{
		scanf ( "%s", word );  // Wczytuje te wyrazy

		addWord ( root, word ); // i dodaję.
	}

	printf ( "%d", movesToPrint ( root ) - 2 - root -> weight ); // Wypisuję wynik. [ odejmuje 2 bo to od korzenia i odejmuje największy wyraz ]

	return 0; // Zwracam 0.
}

