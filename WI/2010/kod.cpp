/* 2010
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
//#define DEBUG(args...) fprintf(stderr, args)
#define DEBUG(args...)

int position,
	size,
	possible[20];

void preprocess(void);
void solve(int length, int place, char starting = 'a');

int main(void)
{
	preprocess();
	scanf("%d %d", &position, &size);
	solve(size, position);
	return 0;
}

void preprocess(void)
{
	possible[0] = 1;
	for(int c = 1; c < 20; ++ c)
		for(int k = 0; k < c; ++ k)
			possible[c] += possible[k] * possible[c - k - 1];
}

void solve(int length, int place, char starting)
{
	if(!length)
		return;

	int pos = 0,
		sum = 0;

	while(sum < place)
	{
		sum += possible[pos] * possible[length - pos - 1];
		++ pos;
	}

	-- pos;

	putchar(starting + pos);
	solve(pos, (place - sum + possible[pos] * possible[length - pos - 1] - 1) / possible[length - pos - 1] + 1, starting);
	solve(length - pos - 1, (place - sum + possible[pos] * possible[length - pos - 1] - 1) % possible[length - pos - 1] + 1, starting + pos + 1);
}
