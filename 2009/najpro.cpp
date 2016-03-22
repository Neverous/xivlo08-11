/* 2009
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
#define max(a, b) ((a) > (b)?(a):(b))

int size,
	s,
	number[1000010],
	stack[1000010],
	left[1000010],
	right[1000010],
	numbers;

long long unsigned int result;

int main(void)
{
	scanf("%d", &numbers);
	for(int n = 1; n <= numbers; ++ n)
	{
		scanf("%d", &number[n]);
		left[n] = 0;
		right[n] = numbers + 1;
	}

	s = 0;
	for(int n = 0; n <= numbers; ++ n)
	{
		stack[s] = n;
		while(s && number[stack[s - 1]] > number[stack[s]])
		{
			right[stack[s - 1]] = stack[s];
			stack[s - 1] = stack[s];
			-- s;
		}

		++ s;
	}

	s = 0;
	for(int n = numbers; n > 0; -- n)
	{
		stack[s] = n;
		while(s && number[stack[s - 1]] > number[stack[s]])
		{
			left[stack[s - 1]] = stack[s];
			stack[s - 1] = stack[s];
			-- s;
		}

		++ s;
	}

	for(int n = 1; n <= numbers; ++ n)
		result = max(result, (long long unsigned int)(right[n] - left[n] - 1) * number[n]);

	printf("%llu\n", result);
	return 0;
}
