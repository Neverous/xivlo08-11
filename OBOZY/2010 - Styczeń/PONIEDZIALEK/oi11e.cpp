/* 2010
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int verts,
	edges,
	start,
	end,
	stoe,
	etos,
	cost[10010],
	costT[5005],
	visit,
	color,
	temp,
	last,
	theSame,
	removedVert[5005],
	removedEdge[10010];
bool checked[5005];

vector<pair<int, pair<int, int> > > graph[5005],
						revGraph[5005];
vector<pair<int, int> > costs;
pair<int, int> act,
			   father[10010];

int solve(void);
int dijkstraGlobal(vector<pair<int, pair<int, int> > > *graph, int &verts, int *costTab, pair<int, int> *father, int start);
int dijkstraFind(vector<pair<int, pair<int, int> > > *graph, int &verts, int *costTab, int *costT, int &visit, int *visitVert, int *visitEdge, int actRes, int startCost, int start, int end);

int main(void)
{
	scanf("%d %d", &verts, &edges);
	for(int e = 0; e < edges; ++ e)
	{
		scanf("%d %d %d %d", &start, &end, &stoe, &etos);
		-- start;
		-- end;
		graph[start].push_back(make_pair(end, make_pair(stoe, e)));
		graph[end].push_back(make_pair(start, make_pair(etos, e)));
		revGraph[start].push_back(make_pair(end, make_pair(etos, e)));
		revGraph[end].push_back(make_pair(start, make_pair(stoe, e)));
	}

	printf("%d\n", solve());
	return 0;
}

int solve(void)
{
	int result = 2000000000;
	dijkstraGlobal(graph, verts, cost, father, 0);
	dijkstraGlobal(revGraph, verts, cost + 5005, father + 5005, 0);
	for(int c = 1; c < verts; ++ c)
		costs.push_back(make_pair(cost[c], c));

	for(int c = 1; c < verts; ++ c)
		costs.push_back(make_pair(cost[c + 5005], - (c + 5005)));

	sort(costs.begin(), costs.end());
	for(unsigned int c = 0; c < costs.size(); ++ c)
	{
		if(costs[c].first >= result / 2)
			break;

		last = result;

		if(costs[c].second < 0)
		{
			if(costs[c].first + cost[- costs[c].second - 5005] >= result)
				continue;

			if(checked[- costs[c].second - 5005])
				continue;

			checked[- costs[c].second - 5005] = true;
			visit = - costs[c].second - 5005;
			++ color;
			while(visit)
			{
				removedVert[visit] = color;
				removedEdge[revGraph[father[visit + 5005].first][father[visit + 5005].second].second.second] = color;
				visit = father[visit + 5005].first;
			}

			temp = dijkstraFind(revGraph, verts, costT, cost, color, removedVert, removedEdge, result, costs[c].first, - costs[c].second - 5005, 0);
			if(temp + costs[c].first < result)
				result = temp + costs[c].first;
		}
		else
		{
			if(costs[c].first + cost[costs[c].second] >= result)
				continue;

			if(checked[costs[c].second])
				continue;

			checked[costs[c].second] = true;
			visit = costs[c].second;
			++ color;
			while(visit)
			{
				removedVert[visit] = color;
				removedEdge[graph[father[visit].first][father[visit].second].second.second] = color;
				visit = father[visit].first;
			}

			temp = dijkstraFind(graph, verts, costT, cost + 5005, color, removedVert, removedEdge, result, costs[c].first, costs[c].second, 0);
			if(temp + costs[c].first < result)
				result = temp + costs[c].first;
		}

		if(result == last)
			++ theSame;

		else
			theSame = 0;

		if(theSame > verts / 32) // BRUTAL HACK ;P
			break;
	}

	return result;
}

int dijkstraGlobal(vector<pair<int, pair<int, int> > > *graph, int &verts, int *costTab, pair<int, int> *father, int start)
{
	queue<pair<int, int> > que;
	que.push(make_pair(0, start));
	for(int v = 0; v < verts; ++ v)
		costTab[v] = 1000000000;

	while(!que.empty())
	{
		act = que.front();
		que.pop();

		if(costTab[act.second] < act.first)
			continue;

		costTab[act.second] = act.first;
		for(unsigned int s = 0; s < graph[act.second].size(); ++ s)
			if(costTab[graph[act.second][s].first] > act.first + graph[act.second][s].second.first)
			{
				costTab[graph[act.second][s].first] = act.first + graph[act.second][s].second.first;
				father[graph[act.second][s].first].first = act.second;
				father[graph[act.second][s].first].second = s;
				que.push(make_pair(costTab[graph[act.second][s].first], graph[act.second][s].first));
			}
	}

	return costTab[end];
}

int dijkstraFind(vector<pair<int, pair<int, int> > > *graph, int &verts, int *costTab, int *costT, int &visit, int *visitVert, int *visitEdge, int actRes, int startCost, int start, int end)
{
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > que;
	que.push(make_pair(0, start));
	for(int v = 0; v < verts; ++ v)
		costTab[v] = 1000000000;

	while(!que.empty())
	{
		act = que.top();
		que.pop();

		if(costTab[act.second] < act.first ||
			act.first + startCost >= actRes ||
			act.first + startCost + costT[act.second] >= actRes)
			continue;

		costTab[act.second] = act.first;
		if(act.second == end)
			break;

		for(unsigned int s = 0; s < graph[act.second].size(); ++ s)
		{
			if(visitVert[graph[act.second][s].first] == visit ||
					visitEdge[graph[act.second][s].second.second] == visit ||
					act.first + graph[act.second][s].second.first >= actRes ||
					act.first + graph[act.second][s].second.first + costT[graph[act.second][s].first] >= actRes)
				continue;

			if(costTab[graph[act.second][s].first] > act.first + graph[act.second][s].second.first)
			{
				costTab[graph[act.second][s].first] = act.first + graph[act.second][s].second.first;
				que.push(make_pair(costTab[graph[act.second][s].first], graph[act.second][s].first));
			}
		}
	}

	return costTab[end];
}
