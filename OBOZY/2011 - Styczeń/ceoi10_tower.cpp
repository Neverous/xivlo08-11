/* 2011
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
#include<vector>
#include<algorithm>
//#define DEBUG(args...) fprintf(stderr, args)
#define DEBUG(args...)

int numbers,
	tolerance;
std::vector<int> number;
long long int result = 1;

int main(void)
{
	scanf("%d %d", &numbers, &tolerance);
	number.resize(numbers);
	for(int n = 0; n < numbers; ++ n)
		scanf("%d", &number[n]);

	std::sort(number.begin(), number.end());
	for(int n = 0, n2 = 0; n < numbers; ++ n)
	{
		while(n2 < (int)number.size() && number[n2] <= number[n] + tolerance)
			++ n2;

		result = (result * (n2 - n)) % 1000000009;
	}

	printf("%d\n", (int)result);
	return 0;
}

