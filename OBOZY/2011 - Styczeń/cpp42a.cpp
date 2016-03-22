/* 2011
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
//#define DEBUG(args...) fprintf(stderr, args)
#define DEBUG(args...)
#define LETTER(x) (((x) >= 'A' && (x) <= 'Z')?(x)-'A'+'a':(x))

unsigned int letters,
			 count[256],
			 max;
char word[131072];

int main(void)
{
	scanf("%u", &letters);
	scanf("%s", word);
	for(unsigned int l = 0; l < letters; ++ l)
		++ count[LETTER(word[l])];

	for(unsigned int l = 0; l < 256; ++ l)
		max = count[max] < count[l]?l:max;

	printf("%u %c\n", count[max], (char) max);
	return 0;
}

