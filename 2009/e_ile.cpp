/* kod pisany w okienku... */
#include<cstdio>
int number,
	result = 1,
	pow;

int main(void)
{
	scanf("%d", &number);
	for(int p = 2; p * p <= number; ++ p)
	{
		pow = 1;
		while(number % p == 0)
		{
			++ pow;
			number /= p;
		}

		result *= pow;
	}

	if(number > 1)
		result *= 2;

	printf("%d\n", result);
	return 0;
}
