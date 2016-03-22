/* 2010
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
//#define DEBUG(args...) fprintf(stderr, args)
#define DEBUG(args...)
#define ABS(a) ((a) > 0?(a):-(a))

int numbers,
	number,
	res = 1000;
int floor[2][2002];

int main(void)
{
	scanf("%d", &numbers);
	floor[0][1000] = 1;
	for(int n = 0; n < numbers; ++ n)
	{
		scanf("%d", &number);
		for(int s = 0; s <= 2000; ++ s)
			if(floor[n % 2][s] == n + 1)
			{
				if(s - number >= 0)
					floor[(n + 1) % 2][s - number] = n +2;

				if(s + number <= 2000)
					floor[(n + 1) % 2][s + number] = n + 2;
			}
	}

	for(int s = 0; s <= 2000; ++ s)
		if(floor[numbers % 2][s] == numbers + 1 && ABS(s - 1000) < res)
			res = ABS(s - 1000);

	printf("%d\n", res);
	return 0;
}

