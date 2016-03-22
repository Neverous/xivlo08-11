/* 2011
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
#include<vector>
//#define DEBUG(args...) fprintf(stderr, args)
#define DEBUG(args...)

int verts,
	questions,
	first,
	second,
	height[1048576],
	path[1048576],
	revpath[1048576],
	start[1048576],
	end[1048576],
	father[1048576][20],
	Time = 0,
	lca;
std::vector<int> graph[1048576];

static inline int MAX(const int &a, const int &b){return a>b?a:b;}
static inline void dfs(int v, int f = -1);
static inline int findLCA(int a, int b);
static inline bool inInterval(int v, int i);

int main(void)
{
	scanf("%d %d", &verts, &questions);
	for(int v = 0; v < verts; ++ v)
		scanf("%d", &height[v]);

	for(int e = 0; e < verts - 1; ++ e)
	{
		scanf("%d %d", &first, &second);
		-- first;
		-- second;
		graph[first].push_back(second);
		graph[second].push_back(first);
	}

	dfs(0, 0);
	for(int q = 0; q < questions; ++ q)
	{
		scanf("%d %d", &first, &second);
		-- first;
		-- second;
		lca = findLCA(first, second);
		printf("%d\n", path[first] + revpath[second] - path[lca] - revpath[lca]);
	}

	return 0;
}

static inline void dfs(int v, int f)
{
	father[v][0] = f;
	path[v] = path[f] + MAX(height[f] - height[v], 0);
	revpath[v] = revpath[f] + MAX(height[v] - height[f], 0);
	for(int l = 1; l < 20; ++ l)
	   father[v][l] = father[father[v][l - 1]][l - 1];

	start[v] = Time ++;
	for(unsigned int n = 0; n < graph[v].size(); ++ n)
		if(graph[v][n] != f)
			dfs(graph[v][n], v);

	end[v] = Time ++;

}

static inline int findLCA(int a, int b)
{
	if(inInterval(a, b))
		return b;

	if(inInterval(b, a))
		return a;

	int l = 0;
	while(!inInterval(a, b))
	{
		l = 0;
		while(!inInterval(a, father[b][++ l]));
		b = father[b][l - 1];
	}

	return b;
}

static inline bool inInterval(int v, int i)
{
	return start[i] <= start[v] && start[v] <= end[i];
}
