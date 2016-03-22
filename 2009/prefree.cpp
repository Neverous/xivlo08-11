/* 2009
 * Maciej Szeptuch
 * XIV LO
 */
#include<cstdio>
#define ord(a) ((a)-'a') // Litera na numer

struct TrieNode // Struktura wierzchołka
{
	char id; // Jaką literką jestem
	TrieNode *todds[32]; // Moje dzieci
	char fertility; // Ile mam dzieci

	TrieNode(char _id = 0) // Wyzeruj wszystko i ustaw czym jestem
	{
		id = _id;
		fertility = 0;
		for(int t = 0; t < 32; ++ t)
			todds[t] = NULL;
	}
};

struct Trie
{
	TrieNode *root, // Korzeń
			 *guard; // Wartownik
	/*
	 * 27 - korzeń
	 * 28 - wartownik
	 */

	Trie(void)
	{
		root = new TrieNode(27);
		guard = new TrieNode(28);
	}

	void insert(char *word) // Wrzuć nowy wyraz do drzewa
	{
		TrieNode *act = root; // Aktualne miejsce w drzewie
		for(int w = 0; word[w]; ++ w)
		{
			if(!act->todds[ord(word[w])]) // Nie mam takiego syna (word[w])
			{
				// Trzeba go "stworzyć"...
				++ act->fertility; // Jeden więcej
				act->todds[ord(word[w])] = new TrieNode(word[w]); // I powstał ;P
			}

			act = act->todds[ord(word[w])]; // Przechodzimy dalej
		}

		act->todds[28] = guard; // Koniec wyrazu
		return;
	}

	long long unsigned int subsets(TrieNode *act = NULL) // Wyznacz ilość podzbiorów bezprefiksowych
	{
		if(!act)
			act = root; // Takie brzydkie coś bo root nie jest static...

		if(!act->fertility) // Nie mam żadnych dzieci (tylko wartownika)
			return 2; // znaczy że jestem końcem i nic więcej nie ma - wtedy są dwa podzbiory (ze mną i beze mnie ^^)

		long long unsigned int result = 1;
		for(int t = 0; t < 27; ++ t) // dla każdego dziecka
			if(act->todds[t]) // Jeśli jest
				result *= subsets(act->todds[t]); // to dolicz jego wynik
		/* Mnoże wyniki moich dzieci bo każdy z ich podzbiorów mogę połączyć ze sobą (w sensie pomiędzy synami) */

		if(act->todds[28]) // Jestem końcem
			++ result; // Sam też tworzę zbiór
		
		return result;
	}
};

int words; // Ilość słów
char word[64]; // Słowo
Trie tree;

int main(void)
{
	scanf("%d", &words); // Ilość słów
	for(int w = 0; w < words; ++ w)
	{
		scanf("%s", word); // Słowo
		tree.insert(word); // Dodaj słowo do drzewa
	}

	printf("%llu\n", tree.subsets()); // Wypisz ilość bezprefiksowych podzbiorów
}
