#include<cstdio>
#include<algorithm>
using namespace std;
bool graph[1000][1000];
int n,
    m,
    tests,
    temp;
   //TODO: BFS DO NAJDALSZEGO PUNKTU!!!
int DFS(int x, int y)
{
	int result=0;
	graph[x][y] = 0;
	if(x-1>=0 && graph[x-1][y]==1)
		result += DFS(x-1,y);
	if(x+1<=n && graph[x+1][y]==1)
		result += DFS(x+1,y);
	if(y-1>=0 && graph[x][y-1]==1)
		result += DFS(x,y-1);
	if(y+1<=m && graph[x][y+1]==1)
		result += DFS(x,y+1);
	return result+1;
}
int solve()
{
	int result = 0,tmp = 0;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			if(graph[i][j]!=1)
				continue;
			tmp = DFS(i,j)-1;
			result = (result>tmp)?result:tmp;
		}
	return result;
}

int main(void)
{
	scanf("%d", &tests);
	for(int i=0;i<tests;i++)
	{
		scanf("%d %d ", &m, &n);
		for(int k=0;k<n;k++)
			for(int l=0;l<m;graph[k][l++]=0);
		for(int j=0;j<n;j++)
		{
			for(int k=0;k<m;k++)
			{
				scanf("%c", &temp);
				if(temp == '\n')
					scanf("%c", &temp);
				if(temp=='.')
					graph[j][k] = 1;
			}
		}
		printf("Maximum rope length is %d.\n", solve());
	}
	return 0;
}

