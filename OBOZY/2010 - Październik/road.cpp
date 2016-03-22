/* 2010
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
#include<vector>
//#define DEBUG(args...) fprintf(stderr, args)
#define DEBUG(args...)

unsigned int verts,
			 edges,
			 niceness[20002],
			 component[1001],
			 components,
			 postorder[1001],
			 componentSize[1001],
			 best,
			 count,
			 order;
bool visited[1001];
std::pair<unsigned int, unsigned int> edge[20002];
std::vector<unsigned int> graph[1001],
						  revGraph[1001];

inline static void findSCC(void);
inline static void postOrder(unsigned int &v);
inline static unsigned int markSCC(unsigned int &v, unsigned int &comp);

int main(void)
{
	scanf("%u %u", &verts, &edges);
	for(unsigned int e = 0; e < edges; ++ e)
	{
		scanf("%u %u", &edge[e].first, &edge[e].second);
		-- edge[e].first;
		-- edge[e].second;
		niceness[e] = 0;
	}

	findSCC();
	for(unsigned int e = 0, f = component[edge[0].first], t = component[edge[0].second]; e < edges; f = component[edge[++ e].first], t = component[edge[e].second])
	{
		if(f == t)
			continue;

		niceness[e] = componentSize[f] + componentSize[t];
		if(niceness[e] > niceness[best])
		{
			best = e;
			count = 0;
		}
		else if(niceness[e] == niceness[best])
			++ count;
	}

	printf("%u\n%u\n", niceness[best], count);
	for(unsigned int e = 0; e < edges; ++ e)
		if(niceness[e] == niceness[best])
			printf("%u\n", e + 1);

	return 0;
}

inline static void findSCC(void)
{
	/* BUILD GRAPHS */
	for(unsigned int  e = 0, f = edge[0].first, t = edge[0].second; e < edges; f = edge[++ e].first, t = edge[e].second)
	{
		graph[f].push_back(t);
		revGraph[t].push_back(f);
	}

	order = verts;
	for(unsigned int v = 0; v < verts; ++ v)
		if(!visited[v])
			postOrder(v);

	printf("POSTORDER!!!\n");
	for(unsigned int v = 0; v < verts; ++ v)
		printf("%u: %u\n", v, postorder[v]);

	for(unsigned int v = 0; v < verts; ++ v)
		visited[v] = false;

	for(unsigned int p = 0, v = postorder[p]; p < verts; v = postorder[++ p])
	{
		if(visited[v])
			continue;

		componentSize[components] = markSCC(v, components);
		++ components;
	}

	printf("COMPONENTS!!!\n");
	for(unsigned int v = 0; v < verts; ++ v)
		printf("%u: %u\n", v, component[v]);

	return;
}

inline static void postOrder(unsigned int &v)
{
	visited[v] = true;
	for(unsigned int n = 0; n < graph[v].size(); ++ n)
		if(!visited[graph[v][n]])
			postOrder(graph[v][n]);

	postorder[-- order] = v;
	return;
}

inline static unsigned int markSCC(unsigned int &v, unsigned int &comp)
{
	unsigned int vCount = 1;
	visited[v] = true;
	component[v] = comp;
	for(unsigned int n = 0; n < revGraph[v].size(); ++ n)
		if(!visited[revGraph[v][n]])
			vCount += markSCC(revGraph[v][n], comp);

	return vCount;
}
