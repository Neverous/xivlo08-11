/* 2009
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
#define min(a, b) ((a) > (b)?(b):(a))

int numbers,
	number,
	prime[1000010],
	up[1000010],
	down[1000010],
	*position;
char action[4];
bool first,
	 was;

void preprocess(void);

int main(void)
{
	preprocess();
	scanf("%d", &numbers);
	for(int n = 0; n < numbers; ++ n)
	{
		scanf("%d", &number);
		if(action[0] == '/')
			position = down;

		else
			position = up;

		if(n + 1 < numbers)
			scanf("%s", action);

		while(number > 1)
		{
			++ position[prime[number]];
			number /= prime[number];
		}
	}

	for(int u = 2; u <= 1000000; ++ u)
	{
		number = min(down[u], up[u]);
		down[u] -= number;
		up[u] -= number;
	}

	first = true;
	was = false;
	for(int u = 2; u <= 1000000; ++ u)
	{
		while(up[u] --)
		{
			was = true;
			printf("%s%d", first?"":"*", u);
			if(first)
				first = false;
		}
	}
	if(!was)
		printf("1");

	printf("/");
	first = true;
	was = false;
	for(int d = 2; d <= 1000000; ++ d)
	{
		while(down[d] --)
		{
			was = true;
			printf("%s%d", first?"":"*", d);
			if(first)
				first = false;
		}
	}
	if(!was)
		printf("1");

	return 0;
}

void preprocess(void)
{
	prime[1] = 1;
	for(long long unsigned int p = 2; p <= 1000000; ++ p)
	{
		if(prime[p])
			continue;

		prime[p] = p;
		for(long long unsigned int m = p*p; m <= 1000000; m += p)
			prime[m] = p;
	}

	return;
}
