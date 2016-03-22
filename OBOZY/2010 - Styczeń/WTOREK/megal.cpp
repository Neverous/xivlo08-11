/* 2010
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
#include<vector>
//#define DEBUG(args...) fprintf(stderr, args)
#define DEBUG(args...)

using namespace std;

struct iTree
{
	static const int SIZE = 262144;
	int data[2 * SIZE];

	iTree(void)
	{
		for(int d = 0; d < 2 * SIZE; ++ d)
			data[d] = 0;
	}

	int getSum(int vert, int pos = 1, int rootStart = 0, int rootEnd = SIZE - 1)
	{
		int result = 0,
			middle;
		while(rootStart != vert || rootEnd != vert)
		{
			result += data[pos];
			middle = (rootStart + rootEnd) / 2;
			if(vert > middle)
			{
				rootStart = middle + 1;
				pos = pos * 2 + 1;
			}

			else
			{
				rootEnd = middle;
				pos *= 2;
			}
		}

		result += data[pos];
		return result;
	}

	void setInterval(int start, int end, int value, int pos = 1, int rootStart = 0, int rootEnd = SIZE - 1)
	{
		if(start == rootStart && end == rootEnd)
		{
			data[pos] += value;
			return;
		}

		int middle = (rootStart + rootEnd) / 2;
		if(end <= middle)
		{
			setInterval(start, end, value, pos * 2, rootStart, middle);
			return;
		}

		if(start > middle)
		{
			setInterval(start, end, value, pos * 2 + 1, middle + 1, rootEnd);
			return;
		}

		setInterval(start, middle, value, pos * 2, rootStart, middle);
		setInterval(middle + 1, end, value, pos * 2 + 1, middle + 1, rootEnd);
		return;
	}
};

int cities,
	start,
	end,
	questions,
	level[262144],
	iStart[262144],
	iEnd[262144],
	iColor;
char action[2];
vector<int> graph[262144];
iTree tree;

void processGraph(int vert, int lev = 0);

int main(void)
{
	scanf("%d", &cities);
	for(int c = 0; c < cities - 1; ++ c)
	{
		scanf("%d %d", &start, &end);
		graph[start].push_back(end);
	}

	processGraph(1);
	scanf("%d", &questions);
	for(int q = 0; q < questions + cities - 1; ++ q)
	{
		scanf("%s", action);
		if(action[0] == 'W')
		{
			scanf("%d", &start);
			printf("%d\n", level[start] - tree.getSum(iStart[start]));
			continue;
		}

		scanf("%d %d", &start, &end);
		tree.setInterval(iStart[end], iEnd[end], 1);
	}
	return 0;
}

void processGraph(int vert, int lev)
{
	level[vert] = lev;
	iStart[vert] = ++ iColor;
	for(unsigned int s = 0; s < graph[vert].size(); ++ s)
		if(!iStart[graph[vert][s]])
			processGraph(graph[vert][s], lev + 1);

	iEnd[vert] = iColor;
}
