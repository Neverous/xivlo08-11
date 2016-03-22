/* 2010
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>

int test,
	grundy[808][2][2],
	tests;

inline void preprocess(void)
{
	for(int s = 0; s < 808; ++ s)
		for(int l = 0; l < 2; ++ l)
			for(int r = 0; r < 2; ++ r)
				grundy[s][l][r] = -1;

	for(int i = 0; i < 2; ++ i)
		for(int l = 0; l < 2; ++ l)
			for(int r = 0; r < 2; ++ r)
				grundy[i][l][r] = 0;

	grundy[2][0][0] = grundy[2][1][0] = grundy[2][0][1] = 1;
}

int winner(int size, bool left = false, bool right = false);

int main(void)
{
	preprocess();
	scanf("%d", &tests);
	for(int t = 0; t < tests; ++ t)
	{
		scanf("%d", &test);
		printf("%c\n", winner(test)?'X':'Y');
	}

	return 0;
}

int winner(int size, bool left, bool right)
{
	if(size <= 1)
		return 0;

	if(grundy[size][left][right] != -1)
		return grundy[size][left][right];

	grundy[size][left][right] = 0;
	bool results[100];
	for(int r = 0; r < 100; ++ r)
		results[r] = false;

	for(int s = 0; s < size - 1; ++ s)
	{
		if(!left || s != 0)
			results[winner(s, left, false) ^ winner(size - s - 1, true, right)] = true;

		if(!right || s != size - 2)
			results[winner(s + 1, left, true) ^ winner(size - s - 2, false, right)] = true;
	}

	while(results[grundy[size][left][right]])
		++ grundy[size][left][right];

	return grundy[size][left][right];
}
