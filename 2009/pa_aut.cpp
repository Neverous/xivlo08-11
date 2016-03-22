/* 2010
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
#include<algorithm>
#include<vector>
#define MIN(a, b) ((a) < (b)?(a):(b))

int start,
	end,
	stations,
	busFrom,
	busTo,
	best;
bool done;
std::vector<int> from[3],
				 to[3];

bool compareFrom(const int &A, const int &B);
bool compareTo(const int &A, const int &B);

int main(void)
{
	scanf("%d %d %d %d %d", &start, &end, &stations, &busFrom, &busTo);
	from[0].resize(busFrom);
	from[1].resize(busFrom);
	from[2].resize(busFrom);
	to[0].resize(busTo);
	to[1].resize(busTo);
	to[2].resize(busTo);
	best = end - start;
	for(int b = 0; b < busFrom; ++ b)
		scanf("%d", &from[0][b]);

	for(int b = 0; b < busTo; ++ b)
		scanf("%d", &to[0][b]);

	for(int s = 1; s < stations; ++ s)
	{
		for(int b = 0; b < busFrom; ++ b)
		{
			scanf("%d", &from[1][b]);
			from[2][b] = b;
		}

		for(int b = 0; b < busTo; ++ b)
		{
			scanf("%d", &to[1][b]);
			to[2][b] = b;
		}

		std::sort(from[2].begin(), from[2].end(), compareFrom);
		std::sort(to[2].begin(), to[2].end(), compareTo);
		for(int fs = 0, f = from[2][0], ts = 0, t = to[2][0]; fs < busFrom && ts < busTo; f = from[2][++ fs])
		{
			if(from[0][f] < start)
				continue;

			while(ts < busTo && (to[0][t] > end || to[1][t] < from[1][f]))
				t = to[2][++ ts];

			if(ts < busTo && best >= end - to[0][t] + to[1][t] - from[1][f] + from[0][f] - start)
				best = end - to[0][t] + to[1][t] - from[1][f] + from[0][f] - start;
		}
	}

	printf("%d\n", best);
	return 0;
}

bool compareFrom(const int &A, const int &B)
{
	return from[1][A] < from[1][B];
}

bool compareTo(const int &A, const int &B)
{
	return to[1][A] < to[1][B];
}
