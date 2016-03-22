/* 2010
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
//#define DEBUG(args...) fprintf(stderr, args)
#define DEBUG(args...)

unsigned int length,
			 inversions,
			 inv[2][250005];

int main(void)
{
	scanf("%u %u", &length, &inversions);
	inv[0][0] = inv[1][0] = 1;

	for(unsigned int i = 0; i <= inversions; ++ i)
		inv[0][i] = 1;

	for(unsigned int l = 1, *t = inv[(l - 1) & 1], *t2 = inv[l & 1]; l <= length; t = inv[l ++ & 1], t2 = inv[l & 1])
		for(unsigned int i = 1; i <= inversions; ++ i)
		{
			t2[i] = t2[i - 1] + t[i] - (i >= l?t[i - l]:0);
			if(t2[i] >= 30011)
				t2[i] = (30011 + t2[i]) % 30011;
		}


	printf("%u\n", (30011 + inv[length & 1][inversions] - (inversions?inv[length & 1][inversions - 1]:0)) % 30011);
	return 0;
}
