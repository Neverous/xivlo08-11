/* 2009
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
using namespace std;

bool solve(void);

int tests,
	numbers,
	number,
	maxSize,
	size,
	position;
bool stopped[1000001],
	 flag;

int main(void)
{
	scanf("%d", &tests);
	for(int t = 0; t < tests; ++ t)
	{
		scanf("%d %d", &numbers, &maxSize);
		printf("%s\n", solve()?"TAK":"NIE");
	}
}

bool solve(void)
{
	size = 0;
	position = 1;
	flag = true;
	for(int s = 0; s < 1000001; ++ s)
		stopped[s] = false;

	for(int n = 0; n < numbers; ++ n)
	{
		while(flag && stopped[position])
		{
			stopped[position ++] = false;
			-- size;
		}

		scanf("%d", &number);
		if(flag)
		{
			if(number == position)
				++ position;

			else
			{
				stopped[number] = true;
				++ size;
			}

			if(size > maxSize)
				flag = false;
		}
	}

	while(flag && stopped[position])
	{
		stopped[position ++] = false;
		-- size;
	}

	return !size && flag;
}

