/* 2010
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
#define DEBUG(args...) fprintf(stderr, args)
//#define DEBUG(args...)

int bestWin(int r, int b, int c);

int red,
	black,
	coins,
	speedup[32768][11][11],
	power[16];

int main(void)
{
	power[0] = 1;
	for(int p = 1; p < 16; ++ p)
		power[p] = power[p - 1] * 2;

	for(int c = 0; c < power[15]; ++ c)
		for(int r = 0; r < 11; ++ r)
			for(int b = 0; b < 11; ++ b)
				speedup[c][r][b] = -1;

	scanf("%d %d %d", &red, &black, &coins);
	printf("%d\n", bestWin(red, black, coins));
	return 0;
}

int bestWin(int r, int b, int c)
{
	if(speedup[c][r][b] != -1)
		return speedup[c][r][b];

	if(!r || !b)
		return speedup[c][r][b] = power[r + b] * c; //If i know i have to win ;]

	for(int bet = 0; bet <= c; ++ bet)
	{
		/* albo czerw albo czarne albo wygra albo przegra .. // No shit sherlock ^^ */
		temp = bestWin(r - 1, b, c - bet);
		temp2 = bestWin(r - 1, b, c + bet);
		if(temp2 < temp)
			temp = temp2;

		if(temp > temp3)
			temp3 = temp;
	}

	return speedup[c][r][b];
}
