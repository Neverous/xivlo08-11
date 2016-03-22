/* 2009
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
#define abs(a) ((a) > 0?(a):-(a))

int parts,
	part[64],
	ob;

int main(void)
{
	scanf("%d", &parts);
	for(int p = 1; p <= parts; ++ p)
	{
		scanf("%d", &part[p]);
		ob += 2 + abs(part[p] - part[p - 1]);
	}

	ob += part[parts - 1];
	possible[0][0].first = 0;
	for(int p = 1; p <= parts; ++ p)
	{
		for(int o = 2 + abs(part[p] - part[p - 1]) + part[p]; o <= ob; ++ o)
			for(int n = 0; n < p; ++ n)
				if(
	}
			
	printf("%d\n", ob);

}
