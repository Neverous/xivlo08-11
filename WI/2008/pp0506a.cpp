#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int tests,x,y,points;
pair<pair<int,int>, int> point[1005];
char name[1005][15];
bool cmp(const pair<pair<int,int>, int>& A,const pair<pair<int,int>, int>& B)
{
	return (abs(A.first.first)<abs(B.first.first)) || (abs(A.first.first)==abs(B.first.first) && abs(A.first.second)<abs(B.first.second));
}

int main(void)
{
	scanf("%d", &tests);
	for(int i=0;i<tests;i++)
	{
		scanf("%d", &points);
		for(int j=0;j<points;j++)
		{
			scanf("%s %d %d", name[j], &x, &y);
			point[j] = make_pair(make_pair(x,y),j);
		}
		sort(point,point +points, cmp);
		for(int j=0;j<points;j++)
			printf("%s %d %d\n", name[point[j].second], point[j].first.first, point[j].first.second);
	}
	return 0;
}

