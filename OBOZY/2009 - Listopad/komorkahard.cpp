/* 2009
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
#include<vector>

using namespace std;

int verts,
	edges,
	from,
	to,
	best,
	questions,
	parent[200020],
	result[200020],
	question;
vector<int> graph[200020];
void dfs(int vert, int set);

int main(void)
{
	scanf("%d %d", &verts, &edges);
	for(int e = 0; e < edges; ++ e)
	{
		scanf("%d %d", &from, &to);
		graph[from].push_back(to);
		parent[to] = from;
	}

	scanf("%d %d", &best, &questions);
	dfs(best, best);
	for(int q = 0; q < questions; ++ q)
	{
		scanf("%d", &question);
		printf("%d\n", result[question]);
	}

	return 0;
}

void dfs(int vert, int set)
{
	if(result[vert])
		return;

	result[vert] = set;
	for(unsigned int s = 0; s < graph[vert].size(); ++ s)
		if(!result[graph[vert][s]])
			dfs(graph[vert][s], set);

	if(parent[vert])
		dfs(parent[vert], parent[vert]);	
}
