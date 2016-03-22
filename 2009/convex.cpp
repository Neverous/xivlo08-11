/* 2009
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cmath>
#define sgn(a) ((a) == 0?0:((a) > 0?1:-1))

using namespace std;

pair<pair<int, int>, int> point[200002],
						  bestpoint;
int tests,
	points,
	border[200002],
	borderSize;

void findBorder(int &points); // Znajdź otoczkę
int angle(const pair<pair<int, int>, int> &A, const pair<pair<int, int>, int> &B, const pair<pair<int, int>, int> &C); // Iloczyn skalarny
bool specialSort(const pair<pair<int, int>, int> &A, const pair<pair<int, int>, int> &B); // sortowanie wg. "kąta"
double dist(const pair<pair<int, int>, int> &A, const pair<pair<int, int>, int> &B); // odległość między punktami

int main(void)
{
	scanf("%d", &tests);
	for(int t = 0; t < tests; ++ t)
	{
		scanf("%d", &points);
		for(int p = 0; p < points; ++ p)
		{
			scanf("%d %d", &point[p].first.first, &point[p].first.second);
			point[p].second = p + 1;
			point[p + 1].second = point[p + 1].first.first = point[p + 1].first.second = 0;
		}
		
		findBorder(points);
	}

	return 0;
}

void findBorder(int &points)
{
	double result = 0;
	bestpoint = point[0];
	for(int p = 0; p < points; ++ p)
		if(point[p] < bestpoint)
			bestpoint = point[p];

	sort(point, point + points, specialSort);

	border[0] = 0;
	border[1] = 1;
	borderSize = 2 < points?2:points;
	for(int p = 2; p < points; ++ p)
	{
		if(point[p].first == point[p-1].first)
			continue;

		while(borderSize > 1 && angle(point[border[borderSize - 1]], point[border[borderSize - 2]], point[p]) < 0)
			-- borderSize;

		border[borderSize ++] = p;
	}

	for(int b = 0; b < borderSize; ++ b)
		result += dist(point[border[b]], point[border[(b + 1) % borderSize]]) / 150;
	
	printf("%d", (int)(result + 1));
	for(int b = 0; b < borderSize; ++ b)
		printf(" %d", point[border[b]].second);

	puts("");
	return;
}

bool specialSort(const pair<pair<int, int>, int> &A, const pair<pair<int, int>, int> &B)
{
	if(A == bestpoint)
		return true;

	if(B == bestpoint)
		return false;

	int side = angle(A, bestpoint, B);

	if(side > 0)
		return true;

	if(side == 0)
		return A.first.second > B.first.second || (A.first.second == B.first.second && A < B);

	return false;
}

int angle(const pair<pair<int, int>, int> &A, const pair<pair<int, int>, int> &B, const pair<pair<int, int>, int> &C)
{
	return sgn((long long int)(A.first.first - B.first.first) * (C.first.second - B.first.second) - (long long int)(C.first.first - B.first.first) * (A.first.second - B.first.second));
}

double dist(const pair<pair<int, int>, int> &A, const pair<pair<int, int>, int> &B)
{
	return sqrt((long long int)(A.first.first - B.first.first) * (A.first.first - B.first.first) + (long long int)(A.first.second - B.first.second) * (A.first.second - B.first.second));
}
