/* 2009
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
#include<vector>
#define inInterval(what, interval) (what >= interval.first && what <= interval.second)

using namespace std;

int verts,
	edges,
	from,
	to,
	tab[86000][20],
	root,
	logVerts,
	questions,
	color;
bool isRoot[86000];
vector<int> graph[86000];
pair<int, int> interval[86000];
int order[86000];

inline int log(int number);
int dfs(int vert);
inline int lca(int a, int b);

int main(void)
{
	scanf("%d %d", &verts, &edges);
	for(int v = 0; v < verts; ++ v)
		isRoot[v] = true;

	logVerts = log(verts) + 1;
	for(int e = 0; e < edges; ++ e)
	{
		scanf("%d %d", &from, &to);
		-- from;
		-- to;
		tab[to][0] = from;
		graph[from].push_back(to);
		isRoot[to] = false;
	}

	for(int v = 0; v < verts; ++ v)
		if(isRoot[v])
		{
			root = v;
			break;
		}

	for(int s = 0; s <= logVerts; ++ s)
		tab[root][s] = root;

	for(int s = 1; s <= logVerts; ++ s)
		for(int v = 0; v < verts; ++ v)
			if(v != root)
				tab[v][s] = tab[tab[v][s - 1]][s - 1];

	dfs(root);
	scanf("%d", &questions);
	for(int q = 0; q < questions; ++ q)
	{
		scanf("%d %d", &from, &to);
		-- from;
		-- to;
		printf("%d\n", lca(from, to));
	}

	return 0;
}

inline int log(int number)
{
	int result = 1;
	while(number)
	{
		number /= 2;
		++ result;
	}

	return result;
}

inline int lca(int a, int b)
{
	int pos = logVerts;
	while(!inInterval(order[a], interval[b]))
	{
		while(pos > 0 && inInterval(order[a], interval[tab[b][pos]]))
			-- pos;

		b = tab[b][pos];
	}

	return b + 1;
	
}

int dfs(int vert)
{
	int min = 86000;
	for(unsigned int s = 0; s < graph[vert].size(); ++ s)
	{
		dfs(graph[vert][s]);
		if(interval[graph[vert][s]].first < min)
			min = interval[graph[vert][s]].first;
	}

	if(min == 86000)
		min = color + 1;

	order[vert] = ++ color;
	interval[vert] = make_pair(min, color);
	return color;
}
