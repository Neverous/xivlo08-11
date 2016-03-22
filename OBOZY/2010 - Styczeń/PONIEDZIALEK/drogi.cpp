/* 2010
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
#include<vector>
#include<list>
//#define DEBUG(args...) fprintf(stderr, args)
#define DEBUG(args...)

using namespace std;

int verts,
	edges,
	start,
	end;
bool visited[1000010];
vector<int> graph[1000010];

int check(int start);

int main(void)
{
	scanf("%d %d", &verts, &edges);
	for(int e = 0; e < edges; ++ e)
	{
		scanf("%d %d", &start, &end);
		graph[start].push_back(end);
		graph[end].push_back(start);
	}

	printf("%d\n", check(0));
	return 0;
}

int check(int v)
{
	list<int> que;
	int res = 0,
		act;
	que.push_back(v);
	visited[v] = true;

	while(!que.empty())
	{
		act = que.front();
		que.pop_front();
		res ++;
		for(unsigned int s = 0; s < graph[act].size(); ++ s)
			if(!visited[graph[act][s]])
			{
				visited[graph[act][s]] = true;
				que.push_back(graph[act][s]);
			}
	}

	return res;
}
