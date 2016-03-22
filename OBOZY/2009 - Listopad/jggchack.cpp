/* 2009
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>

char code[32];

int main(void)
{
	while(scanf("%s", code) != -1)
	{
		for(int c = 0; code[c + 1] > 0; c += 2)
			printf("%c", (code[c + 1] - 'A') * 16 + code[c] - 'A');

		puts("");
	}
	return 0;
}
