/* 2009
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int verts,
	edges,
	from,
	to,
	order[1010],
	ordering,
	vert[1010],
	result;
bool visited[1010];
vector<int> graph[1010],
			revGraph[1010];

inline bool postOrdering(const int &v1, const int &v2);
void postOrder(int &vert);
void revDfs(int &vert);

int main(void)
{
	scanf("%d %d", &verts, &edges);
	for(int e = 0; e < edges; ++ e)
	{
		scanf("%d %d", &from, &to);
		-- from;
		-- to;
		graph[from].push_back(to);
		revGraph[to].push_back(from);
	}

	for(int v = 0; v < verts; ++ v)
		if(!visited[v])
			postOrder(v);

	for(int v = 0; v < verts; ++ v)
	{
		visited[v] = false;
		vert[v] = v;
	}

	sort(vert, vert + verts, postOrdering);
	for(int v = 0; v < verts; ++ v)
		if(!visited[vert[v]])
		{
			revDfs(vert[v]);
			++ result;
		}

	printf("%d\n", result);
	return 0;
}

inline bool postOrdering(const int &v1, const int &v2)
{
	return order[v1] > order[v2];
}

void postOrder(int &v)
{
	visited[v] = true;
	for(unsigned int s = 0; s < graph[v].size(); ++ s)
		if(!visited[graph[v][s]])
			postOrder(graph[v][s]);

	order[v] = ordering ++;
	return;
}

void revDfs(int &v)
{
	visited[v] = true;
	for(unsigned int s = 0; s < revGraph[v].size(); ++ s)
		if(!visited[revGraph[v][s]])
			revDfs(revGraph[v][s]);

	return;
}
