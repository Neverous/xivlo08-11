#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
vector< char > result;
int being,
    tests,
    x,
    sum,
    tab[10];
void solve()
{
	char lastElem;
	int x = 0,sum = 0;
	if(tab[0]==0  && tab[5]==0)
	{
		printf("impossible\n");
		return;
	}
	if(tab[0]>0)
		tab[lastElem = 0]--;
	else
		tab[x = lastElem = 5]--;
	for(int i=0,j=0;i<10;i++)
	{
		if(tab[i]>0 && (i+x)%3==0)
		{
			result.push_back(i);
			tab[i]--;
			x = 0;
		}
		else if(tab[i]>1 && (i+i+x)%3==0)
		{
			result.push_back(i);
			result.push_back(i);
			tab[i]-=2;
			x = 0;
		}
		if(i%3==0)
			while(tab[i]--)
				result.push_back(i);
		else
			for(;tab[i]>=3;tab[i]-=3)
			{
				result.push_back(i);
				result.push_back(i);
				result.push_back(i);
			}
	}
	for(int i=8;i>=0;i--)
	{

		for(int j=i-1;j>=0 && tab[i]>0;j--)
		{
			if(tab[j]==0)
				continue;
			if((i+j+x)%3 == 0)
			{
				while(tab[i]>0 && tab[j]>0)
				{
					tab[i]--;
					tab[j]--;
					result.push_back(i);
					result.push_back(j);
				}
				x = 0;
			}
			else if(tab[i]>0 && tab[j]>1 && (i+j+j+x)%3 == 0)
			{
				tab[i]--;
				tab[j]-=2;
				result.push_back(i);
				result.push_back(j);
				result.push_back(j);
				x = 0;
			}
			else if(tab[j]>0 && tab[i]>1 && (i+i+j+x)%3 == 0)
			{
				tab[i]-=2;
				tab[j]--;
				result.push_back(i);
				result.push_back(i);
				result.push_back(j);
				x = 0;
			}
		}
	}
	sort(result.begin(),result.end());
	for(int i=result.size()-1;i>=0;i--)
		sum += result[i];
	sum += lastElem;
	if(result.size()==0 || sum == 0 || sum%3 != 0)
	{
		printf("impossible\n");
		return;
	}
	for(int i=result.size()-1;i>=0;i--)
		printf("%d", result[i]);
	printf("%d\n", lastElem);
}
int main(void)
{
	scanf("%d ", &tests);
	for(int i=0;i<tests;i++)
	{
		for(int j=0;j<10;tab[j++]=0);
		while(scanf("%c", &x)>0 && x!='\n')
			tab[x-'0']++;
		solve();
		result.clear();
	}
	return 0;
}

