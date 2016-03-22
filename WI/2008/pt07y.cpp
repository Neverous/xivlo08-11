#include<cstdio>
#include<cstdlib>
#include<vector>

using namespace std;

vector< vector< int > > graph;
vector< int > colors;

int nodes, edges, tmpA, tmpB;

bool check(int a)
{
	if(colors[a]==2)
		return 0;
	colors[a] = 1;
	for(int i=0;i<graph[a].size();i++)
	{
		if(colors[graph[a][i]] == 1)
			continue;
		if(colors[graph[a][i]] != 0)
			return 0;
		if(!check(graph[a][i]))
			return 0;
	}
	colors[a] = 2;
	return 1;
}

bool checkIt(void)
{
	if(!check(0))
		return 0;
	for(int i=0;i<colors.size();i++)
		if(colors[i] != 2) return 0;
	return 1;
}

int main(void)
{
	scanf("%d %d", &nodes, &edges);
	graph.resize(nodes);
	colors.resize(nodes);
	for(int i=0;i<edges;i++)
	{
		scanf("%d %d", &tmpA, &tmpB);
		graph[tmpA-1].push_back(tmpB-1);
		graph[tmpB-1].push_back(tmpA-1);
	}
	printf("%s\n", ((checkIt())?"YES":"NO"));
	return 0;
}

