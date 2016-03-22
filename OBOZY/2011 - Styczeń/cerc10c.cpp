/* 2011
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
#include<cstring>
//#define DEBUG(args...) fprintf(stderr, args)
#define DEBUG(args...)

int tests,
	result,
	r[524288];
char spell[524288];

void manacher(char *Word);

int main(void)
{
	scanf("%d", &tests);
	for(int t = 0; t < tests; ++ t)
	{
		bzero(r, sizeof(int) * 524288);
		result = 0;
		scanf("%s", spell);
		manacher(spell);
		for(int s = 0, temp; spell[s]; ++ s)
		{
			temp = r[s] & ~1;
			while(result / 2 < temp)
			{
				if(r[s - temp / 2] >= temp / 2 && r[s + temp / 2] >= temp / 2)
				{
					result = temp * 2;
					break;
				}

				temp -= 4;
			}
		}

		printf("%d\n", result);
	}

	return 0;
}

void manacher(char *Word)
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

		while(w - r[w] >= 0 && Word[w + r[w] + 1] && Word[w - r[w]] == Word[w + r[w] + 1])
			++ r[w];

		if(w + r[w] > b + r[b])
			b = w;
	}
}
