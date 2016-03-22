/* 2009
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
#include<vector>
#include<queue>

using namespace std;

int jumps,
	jump[202],
	maks,
	pos,
	side = 1,
	act;
pair<int, int> data[500000];
queue<int> que;

void bfs(void);

int main(void)
{
	scanf("%d", &jumps);
	for(int j = 0; j < jumps; ++ j)
	{
		scanf("%d", &jump[j]);
		if(maks < jump[j])
			maks = jump[j];
	}
	
	bfs();
	pos = maks + 1;
	if(data[pos].first == 0)
	{
		printf("0\n");
		return 0;
	}

	printf("%d\n", data[pos].first);
	while(pos != maks)
	{
		printf("%d ", pos - data[pos].second);
		pos = data[pos].second;
	}

	puts("");
	return 0;
}

inline void bfs(void)
{
	que.push(maks);
	while(!que.empty())
	{
		act = que.front();
		que.pop();
		if(act == maks + 1)
			return;

		side = act > maks?-1:1;
		for(int j = 0; j < jumps; ++ j)
		{
			if(data[jump[j] * side + act].first == 0 && jump[j] * side + act != maks)
			{
				data[jump[j] * side + act].first = data[act].first + 1;
				data[jump[j] * side + act].second = act;
				if(jump[j] * side + act == maks + 1)
					return;
				que.push(jump[j] * side + act);
			}
		}
	}
}

