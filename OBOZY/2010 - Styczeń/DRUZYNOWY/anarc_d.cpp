#include<cstdio>

int number,
	number1,
	number2,
	number3,
	number4;

int main(void)
{
	for(int t = 1; scanf("%d", &number) != -1 && number; ++ t)
	{
		number1 = number * 3;
		if(number1 % 2)
			number2 = (number1 + 1) / 2;

		else
			number2 = number1 / 2;

		number3 = number2 * 3;
		number4 = number3 / 9;
		printf("%d. %s %d\n", t, number == number4 * 2?"even":"odd", number4);
	}
	return 0;
}

