/* 2011
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
#include<queue>
#include<vector>
//#define DEBUG(args...) fprintf(stderr, args)
#define DEBUG(args...)

unsigned int tests,
			 verts;
int dist[2048],
	connected[2048],
	visited[2048];
char buffer[1024];
std::vector<unsigned int> graph[2048];

inline static unsigned int hopcroftKarp(void);
inline static void hopcroftKarpBFS(void);
inline static bool hopcroftKarpDFS(int v, int flag);

int main(void)
{
	scanf("%u", &tests);
	for(unsigned int t = 0; t < tests; ++ t)
	{
		for(unsigned int v = 0; v < 2048; ++ v)
		{
			dist[v] = connected[v] = -1;
			visited[v] = 0;
			graph[v].clear();
		}

		scanf("%u", &verts);
		for(unsigned int h = 0; h < verts; ++ h)
		{
			scanf("%s", buffer);
			for(unsigned int w = 0; w < verts; ++ w)
				if(buffer[w] == '1')
					graph[h].push_back(verts + w);
		}

		printf("%d\n", hopcroftKarp());
	}

	return 0;
}

inline static unsigned int hopcroftKarp(void)
{
	unsigned int flag = 0,
				 counter = 0;
	bool done;

	do
	{
		done = false;
		hopcroftKarpBFS();

		++ flag;
		for(unsigned int v = 0; v < verts; ++ v)
			if(connected[v] == -1 && hopcroftKarpDFS(v, flag))
			{
				++ counter;
				done = true;
			}

	}
	while(done);

	return counter;
}

inline static void hopcroftKarpBFS(void)
{
	unsigned int act;
	std::queue<unsigned int> que;
	for(unsigned int v = 0; v < verts; ++ v)
	{
		dist[v] = -1;
		if(connected[v] == -1)
		{
			dist[v] = 0;
			que.push(v);
		}
	}

	while(!que.empty())
	{
		act = que.front();
		que.pop();
		for(unsigned int n = 0; n < graph[act].size(); ++ n)
		{
			if(connected[graph[act][n]] == -1)
				continue;

			if(dist[connected[graph[act][n]]] == -1)
			{
				dist[connected[graph[act][n]]] = dist[act] + 1;
				que.push(connected[graph[act][n]]);
			}
		}
	}

	return;
}

inline static bool hopcroftKarpDFS(int v, int flag)
{
	visited[v] = flag;
	for(unsigned int n = 0; n < graph[v].size(); ++ n)
	{
		if(connected[graph[v][n]] == -1 ||
		   (visited[connected[graph[v][n]]] != flag &&
			dist[connected[graph[v][n]]] - 1 == dist[v] &&
			hopcroftKarpDFS(connected[graph[v][n]], flag)))
		{
			connected[graph[v][n]] = v;
			connected[v] = graph[v][n];
			return true;
		}
	}

	return false;
}
