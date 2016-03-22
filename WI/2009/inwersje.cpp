/* 2009
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>

long long unsigned mergecount(int start, int end);

int numbers,
	data[1000001],
	i,j,
	place;

int main(void)
{
	scanf("%d", &numbers);
	for(int n = 0; n < numbers; ++ n)
		scanf("%d", &data[n]);

	printf("%llu\n", mergecount(0, numbers - 1));
	return 0;
}

long long unsigned mergecount(int start, int end)
{
	if(start == end)
		return 0;

	int middle = (start + end) / 2,
		helper[end - start + 1];
	long long unsigned result = 0;

	result += mergecount(start, middle);
	result += mergecount(middle + 1, end);

	for(i = start, j = middle + 1, place = 0; i <= middle || j <= end;)
	{
		if(j > end || (i <= middle && data[i] < data[j]))
			helper[place ++] = data[i ++];

		else if(i > middle || (j <= end && data[i] >= data[j]))
		{
			result += middle - i + 1;
			helper[place ++] = data[j ++];
		}
	}

	for(i = start; i <= end; ++ i)
		data[i] = helper[i - start];

	return result;
}
