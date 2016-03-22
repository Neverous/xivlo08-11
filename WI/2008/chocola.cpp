#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
vector< pair<int,bool> > point;
int tests,
    m,
    n,
    x;
int solve()
{
	sort(point.begin(), point.end());
	int result=0,
	    breakN=1,
	    breakM=1;
	for(int i=point.size()-1;i>=0;i--)
	{
		if(point[i].second==0)
		{
			result += point[i].first*breakN;
			breakM++;
		}
		else
		{
			result += point[i].first*breakM;
			breakN++;
		}
	}
	return result;
}
int main(void)
{
	scanf("%d", &tests);
	for(int i=0;i<tests;i++)
	{
		point.clear();
		scanf("%d %d", &m, &n);
		for(int j=0;j<m-1;j++)
		{
			scanf("%d", &x);
			point.push_back(make_pair(x,0));
		}
		for(int j=0;j<n-1;j++)
		{
			scanf("%d", &x);
			point.push_back(make_pair(x,1));
		}
		printf("%d\n",solve());
	}
	return 0;
}

