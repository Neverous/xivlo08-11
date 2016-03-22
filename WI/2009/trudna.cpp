#include<cstdio>
int tests,
	number;

bool solve(int num)
{
	for(int p = 2, pow; p * p <= num; ++ p)
	{
		pow = 1;
		while(num % p == 0)
		{
			++ pow;
			num /= p;
		}

		if(pow % 2 == 0)
			return true;
	}

	return num > 1;
}

int main(void)
{
	scanf("%d", &tests);
	for(int t = 0; t < tests; ++ t)
	{
		scanf("%d", &number);
		printf("%s\n", solve(number)?"TAK":"NIE");
	}
	return 0;
}
