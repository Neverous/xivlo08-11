/* 2009
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
#include<set>
#include<vector>

using namespace std;

int data[3505][3505],
	broken,
	questions,
	MOD,
	row,
	col,
	number;
set<pair<pair<int, int>, int> > secik;
set<pair<pair<int, int>, int> >::iterator pos;

int solve(int Row, int Col);

int main(void)
{

	scanf("%d %d %d", &broken, &questions, &MOD);
	data[0][0] = 1;
	for(int i = 1; i < 3502; ++ i)
		for(int j = 0; j <= i; ++ j)
			data[i][j] = -1;

	for(int b = 0; b < broken; ++ b)
	{
		scanf("%d %d %d", &row, &col, &number);
		if(row > 3500)
			secik.insert(make_pair(make_pair(row, col), number));

		else
			data[row][col] = number;
	}

	for(int q = 0; q < questions; ++ q)
	{
		scanf("%d %d", &row, &col);
		printf("%d\n", solve(row, col));
	}

	return 0;
}

int solve(int Row, int Col)
{

	if(Row <= 3500)
	{
		if(data[Row][Col] == -1)
			data[Row][Col] = (solve(Row - 1, Col) + (Col?solve(Row - 1, Col - 1):0)) % MOD;
		
		return data[Row][Col];
	}

	pos = secik.lower_bound(make_pair(make_pair(Row, Col), 0));
	if(pos != secik.end())
		return pos->second;

	return (solve(Row - 1, Col) + (Col?solve(Row- 1, Col - 1):0)) % MOD;
}
