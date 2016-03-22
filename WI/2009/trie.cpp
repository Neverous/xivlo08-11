/* TRIE
Drzewo Trie
Maciej Szeptuch 2008
*/
#include <cstdio>

struct TreeNode
{
	TreeNode * todds [ 30 ]; // Dzieci.

	TreeNode ( void ) // "zerowanie" wszystkiego.
	{
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
		}

		now = now -> todds [ ltn ( word [ i ] ) ]; // Zmieniam aktualnego.
	}

}

void addSpecialWord ( TreeNode * root, char * word ) // "specjalne" dodawanie: wyraz i jego "podsłowa".
{
	for ( int i = 0; word [ i ] != NULL; i++ ) // Dla każdego "podsłowa"
		addWord ( root, word + i ); // uruchom normalne dodawanie.

}

bool searchWord ( TreeNode * now, char * word ) // Znajdź słowo ^^.
{
	for ( int i = 0; word [ i ] != NULL; i++ ) // Sprawdzaj każdą literę.
	{
		if ( now -> todds [ ltn ( word [ i ] ) ] == NULL ) // Jeśli nie ma takiego dziecka nie ma takiego słowa ^^.
			return 0;

		now = now -> todds [ ltn ( word [ i ] ) ]; // Idziemy do syna.
	}
	return 1;
}

int main ( void )
{
	TreeNode * root = new TreeNode;
	int wordsToCheck;
	char word [ 1010 ];

	scanf ( "%s", word ); // Wyraz.
	addSpecialWord ( root, word ); // Dodaj.

	scanf ( "%d", &wordsToCheck ); // Ilość wyrazów do sprawdzenia.

	for ( int i = 0; i < wordsToCheck; i++ ) // Wyrazy.
	{
		scanf ( "%s", word );
		printf ( "%s\n", ( searchWord ( root, word ) ) ? "TAK" : "NIE" );
	}

	return 0; // Zwracam 0.
}

