#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
#define SIZE 524288

int main(void)
{
	preprocess();
	scanf("%d", &tests);
	while(tests--)
	{
		scanf("%d", &job);
		if(job == 1)
		{
			scanf("%d %d", &x, &y);
			insert(x,y+1,1,1);
		}
		if(job == 2)
		{
			scanf("%d %d", &x,&y);
			insert(x,y+1,1,-1);
		}
		if(job == 0)
			printf("%d\n", maks[1]);
	}
	return 0;
}

