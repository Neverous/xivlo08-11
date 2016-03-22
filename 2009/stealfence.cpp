/* 2009
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
//#define DEBUG(args...) fprintf(stderr, args)
#define DEBUG(args...) 
#define INFTY 6000

short int boards,
	count,
	board[51],
	fence[51][INFTY][2],
	posF,
	posB,
	min,
	sum,
	perimeter,
	temp;

int main(void)
{
	scanf("%hd", &boards);
	count = boards;
	for(int b = 1; b <= boards; ++ b)
	{
		scanf("%hd", &board[b]);
		sum += board[b];
		perimeter += 2 * (board[b] > board[b - 1]?board[b] - board[b - 1] + 1:1);
	}

	for(int b = 0; b <= boards; ++ b)
		for(int f = 0; f <= perimeter; ++ f)
			fence[b][f][0] = fence[b][f][1] = INFTY;

	/* SOLVE */
	fence[0][0][0] = 0;
	for(int b = 1; b <= boards; ++ b)
		for(int f = 1; f <= perimeter; ++ f)
			for(int c = 0, pos; c < b; ++ c)
			{
				pos = 2 * (board[b] > board[c]?(board[b] - board[c] + 1):1);
				if(f - pos >= 0 && 
				   fence[c][f - pos][0] + board[b] < fence[b][f][0])
				{
					fence[b][f][0] = fence[c][f - pos][0] + board[b];
					fence[b][f][1] = c;
				}
			}

	min = INFTY;
	for(int f = perimeter / 2; f <= perimeter; ++ f)
		for(int b = 0; b <= boards; ++ b)
			if(min > fence[b][f][0])
			{
				posB = b;
				posF = f;
				min = fence[b][f][0];
			}
	
	printf("%hd\n", sum - min);
	while(fence[posB][posF][1] != INFTY)
	{
		-- count;
		temp = posB;
		posB = fence[posB][posF][1];
		posF = posF - 2 * (board[temp] > board[posB]?(board[temp] - board[posB] + 1):1);
		board[temp] = -1;
	}
	
	/* RESULT */
	printf("%hd\n", count);
	for(int c = 1; c <= boards; ++ c)
		if(board[c] != -1)
			printf("%hd%c", c, c == boards?'\n':' ');

	return 0;
}


