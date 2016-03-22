/* 2009
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
#include<vector>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> data[1002];
int tastes,
	sizes,
	maxTastes,
	number;

const bool compare(const vector<int> &A, const vector<int> &B)
{
	for(int i = 1100; i >= 0; -- i)
		if(A[i] != B[i])
			return A[i] > B[i];

	return false;
}

int main(void)
{
	scanf("%d %d %d", &tastes, &sizes, &maxTastes);
	for(int t = 0; t < tastes; ++ t)
	{
		data[t].resize(1101, 0);
		for(int s = 0; s < sizes; ++ s)
		{
			scanf("%d", &number);
			data[t][s] += number;
			if(data[t][s] >= 8)
			{
				data[t][s + 1] = data[t][s] / 8;
				data[t][s] %= 8;
			}
		}
	}

	sort(data, data + tastes, compare);
	data[tastes].resize(1101, 0);

	for(int t = 0; t < maxTastes; ++ t)
		for(int s = 0; s < 1101; ++ s)
		{
			data[tastes][s] += data[t][s];
			if(data[tastes][s] >= 8)
			{
				data[tastes][s + 1] += data[tastes][s] / 8;
				data[tastes][s] %= 8;
			}
		}

	for(int i = 1100; i >= 0; -- i)
		if(data[tastes][i] > 0)
		{
			printf("%d\n%d\n", data[tastes][i], i);
			break;
		}

	return 0;
}
