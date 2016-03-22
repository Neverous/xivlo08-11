/* 2010
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
#include<vector>
#include<queue>
#include<map>

using namespace std;

int tests,
	size,
	atOnce,
	power[10],
	//visited[40400],
	res;

vector<int> number(8);
map<vector<int>, int> visited;

int solve(vector<int> tab, int swapping);
//int countPermutations(vector<int> tab);
//int countPerms(vector<int> tab, unsigned int pos, int num, int mask);
vector<int> reversePermutation(vector<int> tab, int pos, int swap);

int main(void)
{
	power[0] = 1;
	for(int p = 1; p < 10; ++ p)
		power[p] = power[p - 1] * 2;

	scanf("%d", &tests);
	for(int t = 0; t < tests; ++ t)
	{
		for(int v = 0; v < 40400; ++ v)
			visited[v] = 40400;

		scanf("%d %d", &size, &atOnce);
		number.resize(size);
		for(int s = 0; s < size; ++ s)
			scanf("%d", &number[s]);

		res = solve(number, atOnce);
		if(res == 40400)
			printf("NIE\n");

		else
			printf("%d\n", res - 1);
	}

	return 0;
}
/*
int countPermutations(vector<int> tab)
{
	return countPerms(tab, 0, tab[0], power[tab.size() + 1] - 1);
}

int countPerms(vector<int> tab, unsigned int pos, int num, int mask)
{

	if(pos == tab.size() - 1)
		return 1;

	int count = 0;
	for(int i = num - 1; i > 0; -- i)
		if(mask & power[i])
			count += countPerms(tab, pos + 1, i, mask & (~power[i]));

	count += countPerms(tab, pos + 1, tab[pos + 1], mask & (~power[num]));
	return count;

}*/

vector<int> reversePermutation(vector<int> tab, int pos, int swap)
{
	vector<int> copy(tab.size());
	for(unsigned int i = 0; i < tab.size(); ++ i)
		copy[i] = tab[i];

	for(int i = 0; i < swap; ++ i)
		copy[pos + swap - i - 1] = tab[pos + i];

	return copy;
}

int solve(vector<int> tab, int swapping)
{
	//queue<pair<int, pair<int, vector<int> > > > que;
	queue<pair<int, vector<int> > > que;
	//pair<int, pair<int, vector<int> > > act;
	pair<int, vector<int> > act;
	vector<int> temp,
				sorted = tab;
	sor(sorted.begin(), sorted.end());
	//int tmp = countPermutations(tab);
	//que.push(make_pair(1, make_pair(tmp, tab)));
	que.push(make_pair(1, tab));
	visited[tab] = 1;

	while(!que.empty() && !visited[sorted])
	{
		act = que.front();
		que.pop();
		for(unsigned int p = 0; p <= act.second.size() - swapping; ++ p)
		{
			temp = reversePermutation(act.second, p, swapping);
			//tmp = countPermutations(temp);
			if(!visited[temp])
			{
				visited[temp] = visited[act.second] + 1;
				que.push(make_pair(visited[temp], temp));
			}
		}
	}

	return visited[sorted];
}

