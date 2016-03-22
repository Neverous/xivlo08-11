/* 2010
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
#include<vector>
//#define DEBUG(args...) fprintf(stderr, args)
#define DEBUG(args...)

unsigned int edges,
			 from,
			 to,
			 verts,
			 visited[32],
			 count[32];
bool cycled[32];
std::vector<unsigned int> graph[32];

inline static void clear(void);
inline static int dfs(unsigned int vert, unsigned int end, bool first);

int main(void)
{
	scanf("%u", &edges);
	for(unsigned int e = 0; e < edges; ++ e)
	{
		scanf("%u %u", &from, &to);
		graph[from].push_back(to);
		if(verts < from)
			verts = from;

		if(verts < to)
			verts = to;
	}

	++ verts;
	for(unsigned int f = 0; f < verts; ++ f)
		for(unsigned int t = 0; t < verts; ++ t)
		{
			dfs(f, t, true);
			printf("%d%c", (cycled[f] && count[f])?-1:count[f], t + 1 == verts?'\n':' ');
			clear();
		}

	return 0;
}

inline static void clear(void)
{
	for(unsigned int v = 0; v < verts; ++ v)
		visited[v] = count[v] = cycled[v] = 0;
}

inline static int dfs(unsigned int vert, unsigned int end, bool first = false)
{
	visited[vert] = 1;
	count[vert] = vert == end && !first;
	for(unsigned int n = 0; n < graph[vert].size(); ++ n)
	{
		if(visited[graph[vert][n]] == 1)
		{
			cycled[graph[vert][n]] = true;
			if(graph[vert][n] == end)
				count[vert] += 1;

			continue;
		}

		if(!visited[graph[vert][n]])
			count[vert] += dfs(graph[vert][n], end);

		else
			count[vert] += count[graph[vert][n]];
	}

	visited[vert] = 2;
	return count[vert];

}
