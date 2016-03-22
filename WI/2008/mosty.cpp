#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

int numOfVerts,
	numOfEdges,
	from,
	to,
	stage[100000],
	stg;

bool color[100000];

vector< int > graph[100000];
vector< pair< int, int > > result;

void DFS(int start, int father);

int main(void)
{
	scanf("%d %d", &numOfVerts, &numOfEdges);
	for(int i=0;i<numOfEdges;i++)
	{
		scanf("%d %d", &from, &to);
		from--;
		to--;
		graph[from].push_back(to);
		graph[to].push_back(from);
	}
	for(int i=0;i<numOfVerts;i++)
		if(color[i]==0)
			DFS(i,-1);
	sort(result.begin(),result.end());
	for(int i=0,size=result.size();i<size;i++)
		printf("%d %d\n", result[i].first, result[i].second);
	return 0;
}

void DFS(int start, int father)
{
	int tmp,
		tmpStage = stg;
	color[start] = 1;
	stage[start] = stg++;
	for(int i=0,size=graph[start].size();i<size;i++)
	{
		if(color[graph[start][i]]==0)
		{
			DFS(graph[start][i],start);
			if(stage[graph[start][i]]>tmpStage)
			{
				if(graph[start][i]<start)
					result.push_back(make_pair(graph[start][i]+1,start+1));
				else
					result.push_back(make_pair(start+1,graph[start][i]+1));
			}
		}
		if(graph[start][i]!=father)
			stage[start] = (stage[start]<stage[graph[start][i]])?stage[start]:stage[graph[start][i]];
	}
}

