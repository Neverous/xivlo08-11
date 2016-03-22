/* 2009
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
#include<algorithm>
#define min(a, b) ((a) > (b)?(b):(a))

int numbers,
	number[101],
	sum;

char tab[1000001];

int main(void)
{
	scanf("%d", &numbers);
	tab[0] = 1;
	for(int n = 0; n < numbers; ++ n)
	{
		scanf("%d", &number[n]);
		sum += number[n];
	}

	sum = sum>1000000?1000000:sum;
	std::sort(number, number + numbers);
	for(int n = numbers - 1; n >= 0; -- n)
		for(int s = sum; s > 0; -- s)
			if(s - number[n] >= 0 && tab[s - number[n]] && (tab[s - number[n]] + 1 < tab[s] || !tab[s]))
				tab[s] = tab[s - number[n]] + 1;

	scanf("%d", &numbers);
	for(int n = 0; n < numbers; ++ n)
	{
		scanf("%d", &number[0]);
		if(tab[number[0]])
			printf("%d\n", tab[number[0]] - 1);

		else
			printf("NIE\n");
	}

	return 0;
}
