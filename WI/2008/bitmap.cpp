#include<cstdio>
#include<queue>
#include<vector>
using namespace std;
int tests,
	h,
	w,
	bitmap[185][185];
queue< pair<short int,short int> > que;
pair<short int,short int> u;
void solve()
{
	while(!que.empty())
	{
		u = que.front();
		que.pop();
		if(u.first>0 && bitmap[u.first-1][u.second]>bitmap[u.first][u.second]+1)
		{
			que.push(make_pair(u.first-1, u.second));
			bitmap[u.first-1][u.second] = bitmap[u.first][u.second]+1;
		}
		if(u.first<182 && bitmap[u.first+1][u.second]>bitmap[u.first][u.second]+1)
		{
			que.push(make_pair(u.first+1, u.second));
			bitmap[u.first+1][u.second] = bitmap[u.first][u.second]+1;
		}
		if(u.second>0 && bitmap[u.first][u.second-1]>bitmap[u.first][u.second]+1)
		{
			que.push(make_pair(u.first, u.second-1));
			bitmap[u.first][u.second-1] = bitmap[u.first][u.second]+1;
		}
		if(u.second<182 && bitmap[u.first][u.second+1]>bitmap[u.first][u.second]+1)
		{
			que.push(make_pair(u.first, u.second+1));
			bitmap[u.first][u.second+1] = bitmap[u.first][u.second]+1;
		}
	}
}
int main(void)
{
	scanf("%d", &tests);
	for(int i=0;i<tests;i++)
	{
		for(int j=0;j<h;j++)
			for(int k=0;k<w;k++)
				bitmap[j][k] = 0;
		scanf("%d %d", &h, &w);
		for(int j=0;j<h;j++)
			for(int k=0;k<w;k++)
			{
				scanf(" %c", &bitmap[j][k]);
				bitmap[j][k] -= '0';
				if(bitmap[j][k]==0)
					bitmap[j][k] = 10000;
				else
					bitmap[j][k] = 0;
				que.push(make_pair(j,k));
			}
		solve();
		for(int j=0;j<h;j++)
		{
			for(int k=0;k<w;k++)
				printf("%d ", bitmap[j][k]);
			printf("\n");
		}
	}
	return 0;
}

