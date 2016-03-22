/* 2011
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
#include<algorithm>
#include<queue>
//#define DEBUG(args...) fprintf(stderr, args)
#define DEBUG(args...)

int tests,
	width,
	Sx, Sy, Sz,
	Ex, Ey, Ez,
	cost[1048576],
	ways[1048576],
	data[3];
std::priority_queue<std::pair<int, int> > que;
std::pair<int, int> act;

typedef int (*function)(int);

inline static int STATE(int x, int y, int z);
inline static int FIRST(int state);
inline static int SECOND(int state);
inline static int THIRD(int state);
inline static void dijkstra(int start, int end, int max);
function a[3] = {FIRST, SECOND, THIRD};

int main(void)
{
	scanf("%d", &tests);
	for(int t = 0; t < tests; ++ t)
	{
		scanf("%d %d %d %d %d %d %d", &width, &Sx, &Sy, &Sz, &Ex, &Ey, &Ez);
		-- Sx; -- Sy; -- Sz;
		-- Ex; -- Ey; -- Ez;
		dijkstra(STATE(Sx, Sy, Sz), STATE(Ex, Ey, Ez), width);
		if(cost[STATE(Ex, Ey, Ez)] != (1 << 30))
			printf("%d %d\n", cost[STATE(Ex, Ey, Ez)], ways[STATE(Ex, Ey, Ez)]);

		else
			puts("-1 0");
	}

	return 0;
}

inline static void dijkstra(int start, int end, int max)
{
	que = std::priority_queue<std::pair<int, int> >();
	for(int m = 0; m < 1048576; ++ m)
	{
		cost[m] = (1 << 30);
		ways[m] = 0;
	}

	cost[start] = 0;
	ways[start] = 1;
	que.push(std::make_pair(0, start));
	while(!que.empty())
	{
		act = que.top();
		act.first = -act.first;
		que.pop();

		DEBUG("JESTEM W %d %d %d\n", a[0](act.second), a[1](act.second), a[2](act.second));
		if(act.second == end)
			break;

		if(act.first > cost[act.second])
			continue;

		/* KEEP ON MOVIN' */
		for(int c = 3; c < 8; c += 2)
		{
			/* ONE PAWN AT THE TIME */
			for(int i = 0, st = STATE(a[0](act.second) + c, a[1](act.second), a[2](act.second)); i < 3; ++ i, st = STATE(a[i](act.second) + c, a[(i + 1) % 3](act.second), a[(i + 2) % 3](act.second)))
			{
				DEBUG("Czy z %d %d %d -> %d %d %d?\n", a[0](act.second), a[1](act.second), a[2](act.second), a[0](st), a[1](st), a[2](st));
				if(a[0](st) < max && cost[st] >= cost[act.second] + 2 * c)
				{
					DEBUG("TAK\n");
					if(cost[st] > cost[act.second] + 2 * c)
					{
						cost[st] = cost[act.second] + 2 * c;
						ways[st] = 0;
						que.push(std::make_pair(-cost[st], st));
					}

					ways[st] += ways[act.second];
					ways[st] %= 1000000007;
				}
			}

			/* ONE PAWN AT THE TIME BACKWARDS */
			for(int i = 0, st; i < 3; ++ i)
			{
				if(a[i](act.second) < c)
					continue;

				st = STATE(a[i](act.second) - c, a[(i + 1) % 3](act.second), a[(i + 2) % 3](act.second));
				DEBUG("Czy z %d %d %d -> %d %d %d?\n", a[0](act.second), a[1](act.second), a[2](act.second), a[0](st), a[1](st), a[2](st));
				if(cost[st] >= cost[act.second] + 2 * c)
				{
					DEBUG("TAK\n");
					if(cost[st] > cost[act.second] + 2 * c)
					{
						cost[st] = cost[act.second] + 2 * c;
						ways[st] = 0;
						que.push(std::make_pair(-cost[st], st));
					}

					ways[st] += ways[act.second];
					ways[st] %= 1000000007;
				}
			}

			/* ALL PAWNS */
			int st = STATE(a[0](act.second) + c, a[1](act.second) + c, a[2](act.second) + c);
			DEBUG("Czy z %d %d %d -> %d %d %d?\n", a[0](act.second), a[1](act.second), a[2](act.second), a[0](st), a[1](st), a[2](st));
			if(a[0](st) < max && cost[st] >= cost[act.second] + 5 * c)
			{
				DEBUG("TAK\n");
				if(cost[st] > cost[act.second] + 5 * c)
				{
					cost[st] = cost[act.second] + 5 * c;
					ways[st] = 0;
					que.push(std::make_pair(-cost[st], st));
				}

				ways[st] += ways[act.second];
				ways[st] %= 1000000007;
			}

			/* ALL PAWNS BACKWARDS */
			if(a[2](act.second) < c)
				continue;

			st = STATE(a[0](act.second) - c, a[1](act.second) - c, a[2](act.second) - c);
			DEBUG("Czy z %d %d %d -> %d %d %d?\n", a[0](act.second), a[1](act.second), a[2](act.second), a[0](st), a[1](st), a[2](st));
			if(cost[st] >= cost[act.second] + 5 * c)
			{
				DEBUG("TAK\n");
				if(cost[st] > cost[act.second] + 5 * c)
				{
					cost[st] = cost[act.second] + 5 * c;
					ways[st] = 0;
					que.push(std::make_pair(-cost[st], st));
				}

				ways[st] += ways[act.second];
				ways[st] %= 1000000007;
			}
		}
	}

	return;
}

inline static int STATE(int x, int y, int z)
{
	data[0] = x; data[1] = y; data[2] = z;
	std::sort(data, data + 3);
	if(data[0] < 0)
		throw "O Kurwa!";

	return 10000 * data[2] + 100 * data[1] + data[0];
}

inline static int FIRST(int state)
{
	return state / 10000;
}

inline static int SECOND(int state)
{
	return (state / 100) % 100;
}

inline static int THIRD(int state)
{
	return state % 100;
}
