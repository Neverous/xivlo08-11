#include<cstdio>
#include<vector>

using namespace std;

struct iTree
{
	static const int SIZE = 1048576;
	pair<int, int> data[SIZE * 2]; //(mniejsze, wieksze)

	void propagate(int two)
	{
		for(int s = two - 1; s > 0; -- s)
		{
			data[s].first = data[s * 2].first < data[s * 2 + 1].first?data[s * 2].first:data[s * 2 + 1].first;
			data[s].second = data[s * 2].second > data[s * 2 + 1].second?data[s * 2].second:data[s * 2 + 1].second;
		}
		return;
	}

	pair<int, int> find(int start, int end, int act = 1, int rootStart = 1, int rootEnd = SIZE)
	{
		pair<int, int> result(1000000000,0), temp;
		int half = (rootStart + rootEnd) / 2;
		if(start == rootStart && end == rootEnd)
			return data[act];

		if(start <= half && end <= half)
			return find(start, end, act * 2, rootStart, half);

		if(start > half && end > half)
			return find(start, end, act * 2 + 1, half + 1, rootEnd);

		result = find(start, half, act * 2, rootStart, half);
		temp = find(half + 1, end, act * 2 + 1, half + 1, rootEnd);

		if(temp.first < result.first)
			result.first = temp.first;

		if(temp.second > result.second)
			result.second = temp.second;

		return result;
	}
};

/* -------- */
int tests,
	numbers,
	questions,
	start,
	end,
	two;
pair<int, int> result;
iTree tree;

int main(void)
{
	scanf("%d", &tests);
	for(int t = 0; t < tests; ++ t)
	{

		scanf("%d", &numbers);
		for(two = 1; two < numbers; two *= 2);

		for(int n = 0; n < two * 2; ++ n)
		{
			tree.data[n].first = 1000000000;
			tree.data[n].second = 0;
		}

		for(int n = 0; n < numbers; ++ n)
		{
			scanf("%d", &tree.data[two + n].second);
			tree.data[two + n].first = tree.data[two + n].second;
		}

		tree.propagate(two);

		scanf("%d", &questions);
		for(int q = 0; q < questions; ++ q)
		{
			scanf("%d %d", &start, &end);
			result = tree.find(start, end, 1, 1, two);
			printf("%d %d\n", result.first, result.second); 
		}
	}
	return 0;
}

