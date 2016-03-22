/* 2011
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
//#define DEBUG(args...) fprintf(stderr, args)
#define DEBUG(args...)

unsigned int length,
			 pi[1048576];
long long unsigned int result;
char word[1048576];

inline static void KMP(char *Word, unsigned int Length);

int main(void)
{
	scanf("%u %s", &length, word);
	KMP(word, length);
	for(unsigned int l = 0; l < length; ++ l)
	{
		while(pi[l] && pi[pi[l] - 1])
			pi[l] = pi[pi[l] - 1];

		result += pi[l]?l + 1 - pi[l]:0;
	}

	printf("%llu\n", result);
	return 0;
}

inline static void KMP(char *Word, unsigned int Length)
{
	for(unsigned int l = 1, p = 0; l < Length; ++ l)
	{
		while(p && Word[p] != Word[l])
			p = pi[p - 1];

		if(Word[p] == Word[l])
			pi[l] = ++ p;
	}

	return;
}
