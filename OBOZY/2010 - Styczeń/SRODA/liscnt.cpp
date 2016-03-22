/* 2010
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
#include<vector>

using namespace std;

struct Lis
{
	vector<unsigned int> lTab[1000001];
	vector<unsigned int> cTab[1000001];
	unsigned int data[1000001];
	unsigned int dSize,
				 lSize;

	Lis(void)
	{
		clear(1000001);
	}

	void clear(int num)
	{
		for(int d = 0; d < num; ++ d)
		{
			lTab[d].clear();
			data[d] = 0;
		}

		dSize = lSize = 0;
	}

	void push(unsigned int number)
	{
		unsigned int start = 0,
					 end = lSize,
					 middle;

		data[dSize] = number;
		while(end != start)
		{
			middle = (start + end) / 2;
			if(data[*(lTab[middle].rbegin())] >= number)
				end = middle;

			else
				start = middle + 1;
		}

		lTab[start].push_back(dSize);
		if(start >= lSize)
			lSize = start + 1;

		++ dSize;
		return;
	}

	unsigned int count(void)
	{
		unsigned int limUp = 0,
					 limDown = 1;
		for(unsigned int s = 0; s < lSize; ++ s)
			cTab[s].resize(lTab[s].size(), 0);

		for(unsigned int i = 0; i < cTab[0].size(); ++ i)
			cTab[0][i] = i + 1;

		for(unsigned int s = 1; s < lSize; ++ s)
		{
			limUp = 0;
			limDown = 1;
			for(unsigned int h = 0; h < cTab[s].size(); ++ h)
			{
				while(limUp < lTab[s - 1].size() && data[lTab[s - 1][limUp]] >= data[lTab[s][h]])
					++ limUp;

				while(limDown < lTab[s - 1].size() && lTab[s - 1][limDown] < lTab[s][h])
					++ limDown;

				cTab[s][h] = (cTab[s - 1][limDown - 1] + 1000000007 - (limUp?cTab[s - 1][limUp - 1]:0) + (h?cTab[s][h - 1]:0)) % 1000000007;
			}
		}

		return *(cTab[lSize - 1].rbegin());
	}
};

int tests,
	numbers;
unsigned int number;
Lis lis;

int main(void)
{
	scanf("%d", &tests);
	for(int t = 0; t < tests; ++ t)
	{
		scanf("%d", &numbers);
		for(int n = 0; n < numbers; ++ n)
		{
			scanf("%u", &number);
			lis.push(number);
		}

		printf("%u %u\n", lis.lSize, lis.count());
		lis.clear(lis.lSize);
	}

	return 0;
}

