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
	best;
bool visited[1010];
vector<int> graph[1010],
			revGraph[1010],
			resultVerts,
			tempResult;
pair<int, int> result,
			   temp;

inline bool postOrdering(const int &v1, const int &v2);
void postOrder(int &vert);
void getResultVerts(int &v);
pair<int, int> revDfs(int &vert);

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
			temp = revDfs(vert[v]);
			if(temp.first > result.first || 
					(temp.first == result.first && temp.second < result.second))
			{
				result = temp;
				best = vert[v];
				resultVerts = tempResult;
			}

			tempResult.clear();
		}

	sort(resultVerts.begin(), resultVerts.end());
	printf("%d\n", result.first);
	for(unsigned int r = 0; r < resultVerts.size(); ++ r)
		printf("%d\n", resultVerts[r] + 1);

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

pair<int, int> revDfs(int &v)
{
	pair<int, int> tmp;
	pair<int, int> res(1, v);
	visited[v] = true;
	tempResult.push_back(v);
	for(unsigned int s = 0; s < revGraph[v].size(); ++ s)
		if(!visited[revGraph[v][s]])
		{
			tmp = revDfs(revGraph[v][s]);
			res.first += tmp.first;
			res.second = res.second > tmp.second?tmp.second:res.second;
		}

	return res;
}
