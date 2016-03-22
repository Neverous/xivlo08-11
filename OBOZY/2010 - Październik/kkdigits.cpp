/* 2010
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
//#define DEBUG(args...) fprintf(stderr, args)
#define DEBUG(args...)

int number;
char numbers[10][5][3] = {
	{
		{'x', 'x', 'x'},
		{'x', ' ', 'x'},
		{'x', ' ', 'x'},
		{'x', ' ', 'x'},
		{'x', 'x', 'x'},
	}, // 0
	{
		{' ', ' ', 'x'},
		{' ', ' ', 'x'},
		{' ', ' ', 'x'},
		{' ', ' ', 'x'},
		{' ', ' ', 'x'},
	}, // 1
	{
		{'x', 'x', 'x'},
		{' ', ' ', 'x'},
		{'x', 'x', 'x'},
		{'x', ' ', ' '},
		{'x', 'x', 'x'},
	}, // 2
	{
		{'x', 'x', 'x'},
		{' ', ' ', 'x'},
		{'x', 'x', 'x'},
		{' ', ' ', 'x'},
		{'x', 'x', 'x'},
	}, // 3
	{
		{'x', ' ', 'x'},
		{'x', ' ', 'x'},
		{'x', 'x', 'x'},
		{' ', ' ', 'x'},
		{' ', ' ', 'x'},
	}, // 4
	{
		{'x', 'x', 'x'},
		{'x', ' ', ' '},
		{'x', 'x', 'x'},
		{' ', ' ', 'x'},
		{'x', 'x', 'x'},
	}, // 5
	{
		{'x', 'x', 'x'},
		{'x', ' ', ' '},
		{'x', 'x', 'x'},
		{'x', ' ', 'x'},
		{'x', 'x', 'x'},
	}, // 6
	{
		{'x', 'x', 'x'},
		{' ', ' ', 'x'},
		{' ', ' ', 'x'},
		{' ', ' ', 'x'},
		{' ', ' ', 'x'},
	}, // 7
	{
		{'x', 'x', 'x'},
		{'x', ' ', 'x'},
		{'x', 'x', 'x'},
		{'x', ' ', 'x'},
		{'x', 'x', 'x'},
	}, // 8
	{
		{'x', 'x', 'x'},
		{'x', ' ', 'x'},
		{'x', 'x', 'x'},
		{' ', ' ', 'x'},
		{'x', 'x', 'x'},
	}, // 9
};

inline static void printXNumber(int num);

int main(void)
{
	while(scanf("%d", &number) != -1 && number != -1)
		printXNumber(number);

	return 0;
}

inline static void printXNumber(int num)
{
	for(int i = 0; i < 5; ++ i)
	{
		for(int n = 0; n < 3; ++ n)
			putchar(numbers[num / 10][i][n]);

		putchar(' ');
		for(int n = 0; n < 3; ++ n)
			putchar(numbers[num % 10][i][n]);

		putchar('\n');
	}

	return;
}
