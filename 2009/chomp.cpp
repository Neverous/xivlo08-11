/* 2009
 * Maciej Szeptuch
 * XIV LO Wrocław
 * ----------------------
 *  Cienkie te testy ^^...
 */
#include<cstdio>
#include<map>
//#define DEBUG(args...) fprintf(stderr, args)
#define DEBUG(args...) 
using namespace std;

int tests;
short int column[16];
map<long int, int> remember;

bool brute(short int *);
inline long int GIMMEH(short int *table);

int main(void)
{
	scanf("%d", &tests);
	for(int t = 0; t < tests; ++ t)
	{
		for(int c = 0; c < 10; ++ c)
			scanf("%hd", &column[c]);

		printf("%s\n", brute(column)?"W":"L");
	}

	return 0;
}


bool brute(short int *table)
{
	long int tmp = GIMMEH(table);
	if(remember[tmp])
		return remember[tmp] - 1;

	short int temp[16];
	for(int t = 0; t < 16; ++ t)
		temp[t] = table[t];

	bool was = false;
	for(int r = 9; r >= 0; -- r) 
		for(int c = 9; c >= 0; -- c)
		{
			if(table[c] <= r)
				continue;

			for(int t = c; t < 10; ++ t)
				if(table[t] > r)
					temp[t] = r;

			if(!brute(temp))
			{
				remember[tmp] = 2;
				return true;
			}

			for(int t = c; t < 10; ++ t)
				temp[t] = table[t];

			was = true;
		}

	remember[tmp] = !was + 1;
	return !was;
}

inline long int GIMMEH(short int *table)
{
	long int result = 0;
	for(int t = 0; t < 10; ++ t)
	{
		result *= 10;
		result += table[t];
	}

	return result;
}

