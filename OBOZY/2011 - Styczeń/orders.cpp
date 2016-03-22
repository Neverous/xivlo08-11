/* 2011
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>
#define source (tasks + machines)
#define sink (tasks + machines + 1)

int tasks,
	machines,
	gain,
	need,
	machine,
	cost,
	profit;
short int visited[2402],
		  weight[2402][2402];
std::vector<short int> graph[2402];

inline static int MIN(const int &A, const int &B){return A<B?A:B;}

/* Dinic algorithm - I suppose */
std::queue<short int> que;
short int qAct,
	  latest[2402];
bool impossible[2402];
inline static int dinic(const int &start, const int &end);
inline static int dinicBFS(const int &start, const int &end);
inline static int dinicDFS(const int &v, const int &end, int push);

int main(void)
{
	scanf("%d %d", &tasks, &machines);
	for(int t = 0; t < tasks; ++ t)
	{
		scanf("%d %d", &gain, &need);
		profit += gain;
		graph[source].push_back(t);
		graph[t].push_back(source);
		weight[source][t] = gain;
		for(int n = 0; n < need; ++ n)
		{
			scanf("%d %d", &machine, &cost);
			-- machine;
			graph[t].push_back(tasks + machine);
			graph[tasks + machine].push_back(t);
			weight[t][tasks + machine] = cost;
		}
	}

	for(int m = 0; m < machines; ++ m)
	{
		scanf("%d", &cost);
		graph[tasks + m].push_back(sink);
		graph[sink].push_back(tasks + m);
		weight[tasks + m][sink] = cost;
	}

	/* TO AVOID BAD CASES */
	for(int v = 0; v < tasks + machines + 2; ++ v)
		std::random_shuffle(graph[v].begin(), graph[v].end());

	printf("%d\n", profit - dinic(source, sink));
	return 0;
}

/* Dinic algorithm - I suppose */
inline static int dinic(const int &start, const int &end)
{
	int flow = 0,
		act = 0;

	while(dinicBFS(start, end))
	{
		do
		{
			flow += act = dinicDFS(start, end, (1 << 30));
		}
		while(act);
	}

	return flow;
}

inline static int dinicBFS(const int &start, const int &end)
{
	que = std::queue<short int>();
	bzero(visited, sizeof(visited));
	bzero(latest, sizeof(latest));
	bzero(impossible, sizeof(impossible));
	visited[end] = 1;
	que.push(end);
	while(!que.empty() && !visited[start])
	{
		qAct = que.front();
		que.pop();
		for(unsigned int n = 0, g = graph[qAct][n]; n < graph[qAct].size(); g = graph[qAct][++ n])
			if(!visited[g] && weight[g][qAct] > 0)
			{
				visited[g] = visited[qAct] + 1;
				que.push(g);
			}
	}

	return visited[start];

}

inline static int dinicDFS(const int &v, const int &end, int push)
{
	if(v == end)
		return push;

	if(!push || impossible[v])
		return 0;

	int flow = 0,
		act = 0;
	for(unsigned int n = latest[v], g = graph[v][n]; push && n < graph[v].size(); g = graph[v][n = ++ latest[v]])
		if(visited[g] + 1 == visited[v] && weight[v][g] > 0 &&
			(act = dinicDFS(g, end, MIN(push, weight[v][g]))))
		{
			weight[v][g] -= act;
			weight[g][v] += act;
			flow += act;
			push -= act;
		}

	latest[v] -= !push;
	impossible[v] = !flow;
	return flow;
}
