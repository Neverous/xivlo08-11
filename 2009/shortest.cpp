/* 2009
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<cmath>

using namespace std;

struct sorcik
{
	bool operator() (const pair<int, int> &A, const pair<int, int> &B) const
	{
		if(A.second < B.second)
			return true;

		if(A.second == B.second)
			return A.first < B.first;

		return false;
	}
};

int points,
	r;
long long unsigned int length = 1000000000000000000LLU;
pair<int, int> point[100001];
set<pair<int, int>, sorcik > secik;
set<pair<int, int> >::iterator toRemove[100001];

inline long long unsigned int distance(int x1, int y1, int x2, int y2);

int main(void)
{
	scanf("%d", &points);
	for(int p = 0; p < points; ++ p)
		scanf("%d %d", &point[p].first, &point[p].second);
	
	sort(point, point + points);
	for(int p = 0; p < points; ++ p)
	{
		r = 0;
		for(set<pair<int, int> >::iterator s = secik.lower_bound(pair<int, int>(0, point[p].second - (int)sqrt(length))),
				k = secik.upper_bound(pair<int, int>(0, point[p].second + (int)sqrt(length)));
				s != k; ++ s)
		{
			if(s->first <= point[p].first - (int)sqrt(length))
			{
				toRemove[r++] = s;
				continue;
			}

			if(distance(s->first, s->second, point[p].first, point[p].second) < length)
				length = distance(s->first, s->second, point[p].first, point[p].second);
		}

		for(int t = 0; t < r; ++ t)
			secik.erase(toRemove[t]);

		secik.insert(point[p]);
	}

	printf("%.5lf\n", sqrt(length));
	return 0;
}

inline long long unsigned int distance(int x1, int y1, int x2, int y2)
{
	return (long long unsigned int)(x1 - x2) * (x1 - x2) + (long long unsigned int)(y1 - y2) * (y1 - y2);
}
