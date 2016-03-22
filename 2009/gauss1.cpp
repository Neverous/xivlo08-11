/* 2010
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
#include<cstdlib>
#include<algorithm>
//#define DEBUG(args...) fprintf(stderr, args)
#define DEBUG(args...)

inline void readCase(void);
inline void solveCase(void);
inline void writeCase(void);
inline void makeBest(int col);
inline long double abs(long double a);

int tests,
	size;
bool unable;
long double matrix[110][110];

int main(void)
{
	scanf("%d", &tests);
	for(int t = 0; t < tests; ++ t)
	{
		unable = false;
		readCase();
		solveCase();
		writeCase();
	}

	return 0;
}

inline long double abs(long double a)
{
	return a > 0?a:-a;
}

inline void readCase(void)
{
	scanf("%d", &size);
	for(int h = 0; h < size; ++ h)
		for(int w = 0; w <= size; ++ w)
			scanf("%Lf", &matrix[h][w]);

	return;
}

inline void solveCase(void)
{
	long double ratio = 0;
	for(int c = 0; c < size; ++ c)
	{
		makeBest(c);
		if(!matrix[c][c])
		{
			unable = true;
			return;
		}

		for(int h = c + 1; h < size; ++ h)
		{
			if(!matrix[h][c])
				continue;

			ratio = - matrix[c][c] / matrix[h][c];
			for(int w = c; w <= size; ++ w)
				matrix[h][w] = matrix[h][w] * ratio + matrix[c][w];
		}
	}

	for(int c = size - 1; c >= 0; -- c)
	{
		matrix[c][size] /= matrix[c][c];
		matrix[c][c] = 1;
		for(int h = 0; h < c; ++ h)
		{
			matrix[h][size] -= matrix[h][c] * matrix[c][size];
			matrix[h][c] = 0;
		}
	}
	return;
}

inline void makeBest(int col)
{
	int best = col;
	for(int h = col; h < size; ++ h)
		if(abs(matrix[h][col]) > abs(matrix[best][col]))
			best = h;

	for(int w = col; w <= size; ++ w)
		std::swap(matrix[col][w], matrix[best][w]);

	return;
}

inline void writeCase(void)
{
	//for(int h = 0; h < size; ++ h)
	//for(int w = 0; w <= size; ++ w)
	//printf("%lf%c", matrix[h][w], w == size?'\n':' ');
	//
	//puts("");
	//return;

	if(unable)
	{
		printf("ZA TRUDNE\n");
		return;
	}

	for(int h = 0; h < size; ++ h)
		printf("%0.6Lf%c", matrix[h][size], h == size - 1?'\n':' ');

	return;
}
