/* 2009
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>

int letters;

int main(void)
{
	scanf("%d", &letters);
	printf("%d 2 %d\n", letters, letters);
	for(int s = 0; s < letters; ++ s)
	{
		for(int w = 0; w < letters; ++ w)
			printf("%c", 'A' + w);
		
		puts("");

		for(int w = 0; w < letters; ++ w)
			printf("%c", 'A' + s);

		puts("");
	}

	return 0;
}
