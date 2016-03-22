/* 2011
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
//#define DEBUG(args...) fprintf(stderr, args)
#define DEBUG(args...)

char word[1048576];
int r[1048576],
	length;
long long int result;

void manacher(char *Word, bool even = true);

int main(void)
{
	scanf("%s", word);
	manacher(word);
	while(word[result])
		++ result;

	for(int w = 0; word[w]; ++ w)
	{
		result += r[w];
		r[w] = 0;
	}

	manacher(word, false);
	for(int w = 0; word[w]; ++ w)
	{
		result += r[w];
		r[w] = 0;
	}

	printf("%lld\n", result);
	return 0;
}

void manacher(char *Word, bool even)
{
	for(int w = 0, b = 0; Word[w]; ++ w)
	{
		if(b + r[b] > w)
		{
			if(w + r[2 * b - w] <= b + r[b])
				r[w] = r[2 * b - w];

			else
				r[w] = b + r[b] - w;
		}

		while(w - even - r[w] >= 0 && Word[w + r[w] + 1] && Word[w - even - r[w]] == Word[w + r[w] + 1])
			++ r[w];

		if(w + r[w] > b + r[b])
			b = w;
	}
}
