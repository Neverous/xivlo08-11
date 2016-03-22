/* 2009
 * Maciej Szeptuch
 * XIV LO Wrocław
 * ----------
 *  http://www.research.att.com/~njas/sequences/ - przydatna strona ^^
 */
#include<cstdio>
//#define DEBUG(args...) fprintf(stderr, args)
#define DEBUG(args...) 

int size,
	MODULO,
	temp,
	balance,
	result = 1,
	ndPowerT[1000001];
char buffer[1000001];

int main(void)
{
	scanf("%d %d ", &size, &MODULO);
	ndPowerT[0] = 1;
	for(int i = 1; i < size; ++ i)
		ndPowerT[i] = (ndPowerT[i - 1] * 2) % MODULO;

	scanf("%s", buffer);
	for(int s = 0; s < size; ++ s)
		if(buffer[s] == 'P')
		{
			temp = 2;
			if(balance == 1 && s != size - 1)
			{
				temp = 1;
				if(size - s - 3 > 0)
					result = result + 1 - ndPowerT[(size - s - 2) / 2];
			}

			if(balance != 2)
				result = (MODULO + result + ndPowerT[(size - s + temp - 2) / 2] + ndPowerT[(size - s + temp - 3) / 2] - 1) % MODULO;

			if(balance)
				-- balance;
		}
		else
			++ balance;

	printf("%d\n", result);
	return 0;
}
