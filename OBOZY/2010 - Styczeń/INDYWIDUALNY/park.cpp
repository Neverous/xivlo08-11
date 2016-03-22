/* 2010
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
#include<vector>

using namespace std;

int tests,
	verts,
	edges,
	start,
	end,
	visited[4444];

vector<int> graph[4444];

int dfs(int v, int f, int l);

int main(void)
{
	scanf("%d", &tests);
	for(int t = 0; t < tests; ++ t)
	{
		for(int v = 0; v < 4444; ++ v)
		{
			graph[v].clear();
			visited[v] = 0;
		}

		scanf("%d %d", &verts, &edges);
		for(int e = 0; e < edges; ++ e)
		{
			scanf("%d %d", &start, &end);
			-- start;
			-- end;
			graph[start].push_back(end);
			graph[end].push_back(start);
		}

		printf("%d\n", dfs(0, -1, 1));
	}
	return 0;
}

int dfs(int v, int f, int l)
{
	int best = 0,
		temp;
	visited[v] = l;

	for(unsigned int s = 0; s < graph[v].size(); ++ s)
	{
		if(graph[v][s] == f)
			continue;

		if(visited[graph[v][s]])
		{
			if(best < l - visited[graph[v][s]] + 1)
				best = l - visited[graph[v][s]] + 1;

			continue;
		}

		temp = dfs(graph[v][s], v, l + 1);
		if(temp > best)
			best = temp;
	}

	return best;
}
