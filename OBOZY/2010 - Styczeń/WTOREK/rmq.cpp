/* 2010
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
//#define DEBUG(args...) fprintf(stderr, args)
#define DEBUG(args...)

struct iTree
{
	static const int SIZE = 131072;
	int data[SIZE * 2],
		element[SIZE],
		elements;

	iTree(void)
	{
		for(int d = 0; d < 2 * SIZE; ++ d)
			data[d] = SIZE - 1;

		element[SIZE - 1] = 1000000000;
	}

	void propagate(void)
	{
		for(int s = SIZE; s - SIZE < elements; ++ s)
			data[s] = s - SIZE;

		for(int s = SIZE - 1; s > 0; -- s)
			if(element[data[s * 2]] < element[data[s * 2 + 1]])
				data[s] = data[s * 2];

			else
				data[s] = data[s * 2 + 1];
	}

	int getMinimum(int start, int end, int position = 1, int rootStart = 0, int rootEnd = SIZE - 1)
	{
		if(start == rootStart && end == rootEnd)
			return data[position];

		int middle = (rootStart + rootEnd) / 2;
		if(end <= middle)
			return getMinimum(start, end, position * 2, rootStart, middle);

		if(start > middle)
			return getMinimum(start, end, position * 2 + 1, middle + 1, rootEnd);

		int a = getMinimum(start, middle, position * 2, rootStart, middle),
			b = getMinimum(middle + 1, end, position * 2 + 1, middle + 1, rootEnd);

		if(element[a] < element[b])
			return a;

		return b;
	}
};

int questions,
	start,
	end;
iTree tree;

int main(void)
{
	scanf("%d", &tree.elements);
	for(int e = 0; e < tree.elements; ++ e)
		scanf("%d", &tree.element[e]);

	tree.propagate();
	scanf("%d", &questions);
	for(int q = 0; q < questions; ++ q)
	{
		scanf("%d %d", &start, &end);
		printf("%d\n", tree.getMinimum(start, end));
	}
	return 0;
}

