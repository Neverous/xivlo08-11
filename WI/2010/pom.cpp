/* 2010
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
#include<vector>
//#define DEBUG(args...) fprintf(stderr, args)
#define DEBUG(args...)

unsigned int tomatoes,
			 actions,
			 who,
			 where;
std::pair<unsigned int, unsigned int> repr[1048576];
char action[4];

inline static bool unionUnion(unsigned int f, unsigned int t);
inline static std::pair<unsigned int, unsigned int> unionFind(unsigned int t);

int main(void)
{
	scanf("%u %u", &tomatoes, &actions);
	for(unsigned int t = 0; t < tomatoes; ++ t)
		repr[t].first = t;

	for(unsigned int a = 0; a < actions; ++ a)
	{
		scanf("%s %u", action, &who);
		if(action[0] == 'D')
		{
			printf("%u\n", unionFind(who - 1).second + 1);
			continue;
		}

		scanf("%u", &where);
		unionUnion(who - 1, where - 1);
	}

	return 0;
}

inline static bool unionUnion(unsigned int f, unsigned int t)
{
	std::pair<unsigned int, unsigned int> rF = unionFind(f),
										  rT = unionFind(t);

	if(rF.first == rT.first)
		return false;

	repr[rF.first].first = t;
	repr[rF.first].second = 1;
	return true;
}

inline static std::pair<unsigned int, unsigned int> unionFind(unsigned int t)
{
	std::pair<unsigned int, unsigned int> res;
	if(repr[t].first != t)
	{
		res = unionFind(repr[t].first);
		repr[t].second += res.second;
		repr[t].first = res.first;
	}

	return repr[t];
}
