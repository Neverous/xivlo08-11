/* 2009
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
#define cti(a) ((a) - 'a')

struct TrieNode
{
	TrieNode *todds[30];
	int fertility;
	char whoAmI;

	TrieNode(char me = NULL)
	{
		whoAmI = me;
		fertility = 0;
	}

	void add(char *word)
	{
		TrieNode *act = this;
		for(int pos = 0; word[pos]; ++ pos)
		{
			if(!act->todds[cti(word[pos])])
				act->todds[cti(word[pos])] = new TrieNode(word[pos]);
			
			++ act->fertility;
			act = act->todds[cti(word[pos])];
		}

		++ act->fertility;
	}

	int find(char *word)
	{
		TrieNode *act = this;
		for(int w = 0; word[w]; ++ w)
		{
			if(!act->todds[cti(word[w])])
				return 0;

			act = act->todds[cti(word[w])];
		}

		return act->fertility;
	}
};

int words,
	questions;
char word[1000010];
TrieNode tree;

int main(void)
{
	scanf("%d", &words);
	for(int w = 0; w < words; ++ w)
	{
		scanf("%*d %s", word);
		tree.add(word);
	}
	
	scanf("%d", &questions);
	for(int q = 0; q < questions; ++ q)
	{
		scanf("%*d %s", word);
		printf("%d\n", tree.find(word));
	}

	return 0;
}
