/* 2009
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int verts,
	ndVerts,
	edges,
	from,
	to,
	color[100010];
vector<int> graph[100010];

bool solve(void);
bool dfs(int vert);

int main(void)
{
	scanf("%d %d", &verts, &edges);
	for(int e = 0; e < edges; ++ e)
	{
		scanf("%d %d", &from, &to);
		-- from;
		-- to;
		graph[from].push_back(to);
		graph[to].push_back(from);
	}

	scanf("%d %d", &ndVerts, &edges);
	if(ndVerts > verts)
		verts = ndVerts;

	for(int e = 0; e < edges; ++ e)
	{
		scanf("%d %d", &from, &to);
		-- from;
		-- to;
		graph[from].push_back(to);
		graph[to].push_back(from);
	}

	if(solve())
		for(int v = 0; v < verts; ++ v)
			printf("%d ", color[v]);

	else
		printf("nie da sie\n");

	return 0;
}

bool solve(void)
{
	for(int v = 0; v < verts; ++ v)
		if(!color[v] && !dfs(v))
			return false;

	return true;
}

bool dfs(int vert)
{
	int colors = 0;
	if(color[vert])
		return true;

	color[vert] = -1;

	for(unsigned int s = 0; s < graph[vert].size(); ++ s)
	{
		if(color[graph[vert][s]] == -1)
			continue;

		if(!color[graph[vert][s]] && !dfs(graph[vert][s]))
			return false;
			
		colors |= 1 << color[graph[vert][s]];
	}

	for(int i = 1; i < 13; ++ i)
		if(~colors & (1 << i))
		{
			color[vert] = i;
			return true;
		}

	return false;
}
