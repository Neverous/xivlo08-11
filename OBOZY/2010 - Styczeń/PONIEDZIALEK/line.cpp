/* 2010
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
//#define DEBUG(args...) fprintf(stderr, args)
#define DEBUG(args...)

int fields,
	act,
	temp,
	res;

int main(void)
{
	scanf("%d", &fields);
	for(int f = 0; f < fields; ++ f)
	{
		scanf("%d", &act);
		if(act)
			++ temp;

		else
			temp = 0;

		res += temp;
	}

	printf("%d\n", res);

	return 0;
}

