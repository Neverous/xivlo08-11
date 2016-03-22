#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
#define SIZE 10010
int verts[SIZE],
    vertsIle[SIZE],
    tests,
    cities,
    neighbours,
    cost,
    address;
vector<pair<int,pair<int,int> > > edges;
int find(int a)
{
	if(verts[a]==a)
		return a;
	verts[a] = find(verts[a]);
	return verts[a];
}
bool Union(int a, int b)
{
	int va = find(a),
	    vb = find(b);

	if(va==vb) return false;
	if(vertsIle[va]<=vertsIle[vb])
	{
		vertsIle[vb] += vertsIle[va];
		verts[va] = vb;
	}
	else
	{
		vertsIle[va] += vertsIle[vb];
		verts[vb] = va;
	}
	return true;
}
int solve()
{
	int result = 0;
	sort(edges.begin(),edges.end());
	for(int i=0;i<edges.size();i++)
	{
		if(Union(edges[i].second.first,edges[i].second.second))
			result += edges[i].first;
	}
	return result;
}
void preprocess()
{
	for(int i=0;i<SIZE;i++)
	{
		verts[i] = i;
		vertsIle[i] = 0;
	}
	edges.clear();
}

int main(void)
{
	scanf("%d", &tests);
	while(tests--)
	{
		preprocess();
		scanf("%d", &cities);
		for(int i=0;i<cities;i++)
		{
			scanf("%*s %d", &neighbours);
			for(int j=0;j<neighbours;j++)
			{
				scanf("%d %d", &address, &cost);
				edges.push_back(make_pair(cost,make_pair(i,address-1)));
			}
		}
		printf("%d\n", solve());
	}
	return 0;
}

