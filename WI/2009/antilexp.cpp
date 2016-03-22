/* 2009
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
#include<algorithm>

using namespace std;

int numbers,
	tab[1001];

int main(void)
{
	scanf("%d", &numbers);
	for(int n = 0; n < numbers; ++ n)
		tab[n] = numbers - n;

	for(int p = 0; p < 1000; ++ p)
	{
		for(int n = numbers - 1; n >= 0; -- n)
			printf("%d ", tab[n]);

		puts("");
		if(!prev_permutation(tab, tab + numbers))
			break;
	}
}
