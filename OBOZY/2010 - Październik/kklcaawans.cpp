/* 2010
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
#include<vector>
//#define DEBUG(args...) fprintf(stderr, args)
#define DEBUG(args...)

int workers,
			 master,
			 padawan,
			 first,
			 second,
			 questions,
			 actions,
			 repr[500005],
			 root;
char action[8];
bool visited[500005];
int answered[500005],
	father[500005];
std::vector<int> tree[500005];
std::vector<std::pair<int, int> > asked[500005];

inline static void answerQuestions(int v = 0);
inline static void changeTree(int from, int to);
inline static bool unionUnion(int &a, int &b);
inline static int unionFind(int &a);
inline static std::vector<int>::iterator find(std::vector<int> &where, int what);

int main(void)
{
	scanf("%d", &workers);
	for(int e = 1; e < workers; ++ e)
	{
		scanf("%d %d", &master, &padawan);
		-- master;
		-- padawan;
		tree[master].push_back(padawan);
		father[padawan] = master;
	}
	father[0] = -1;

	scanf("%d", &actions);
	for(int a = 0; a < actions; ++ a)
	{
		scanf("%s %d %d", action, &first, &second);
		-- first;
		-- second;
		if(action[0] == 'b')
		{
			asked[first].push_back(std::make_pair(questions, second));
			asked[second].push_back(std::make_pair(questions, first));
			questions ++;
		}

		else
		{
			if(questions)
			{
				for(int w = 0; w < workers; ++ w)
				{
					repr[w] = w;
					visited[w] = false;
					//printf("%u: ", w + 1);
					//for(int n = 0; n < tree[w].size(); ++ n)
					//printf("%u ", tree[w][n] + 1);
					//
					//puts("");
				}

				//printf("----------\n");
				answerQuestions(root);
				for(int q = 0; q < questions; ++ q)
					printf("%d\n", answered[q]);

				questions = 0;
			}

			if(second == root)
				root = first;

			changeTree(second, first);
		}
	}

	if(questions)
	{
		for(int w = 0; w < workers; ++ w)
			repr[w] = w;

		answerQuestions(root);
		for(int q = 0; q < questions; ++ q)
			printf("%d\n", answered[q]);

		questions = 0;
	}

	return 0;
}

inline static void answerQuestions(int v)
{
	visited[v] = true;
	//printf("==> %d\n", v + 1);
	for(unsigned int q = 0; q < asked[v].size(); ++ q)
	{
		if(!visited[asked[v][q].second])
			continue;

		answered[asked[v][q].first] = unionFind(asked[v][q].second) + 1;
		//printf("%u => %u\n", asked[v][q].second + 1, unionFind(asked[v][q].second) + 1);
	}

	asked[v].clear();
	for(unsigned int n = 0; n < tree[v].size(); ++ n)
		answerQuestions(tree[v][n]);

	unionUnion(father[v], v);
	return;
}

inline static void changeTree(int from, int to)
{
	if(father[from] != -1)
		*find(tree[father[from]], from) = to;

	tree[from].erase(find(tree[from], to));
	tree[to].push_back(from);
	father[to] = father[from];
	father[from] = to;
	return;
}

inline static bool unionUnion(int &a, int &b)
{
	/* Zakładam że a jest ojcem b */
	int fA = unionFind(a),
				 fB = unionFind(b);

	if(fA == fB)
		return false;

	repr[fB] = fA;
	return true;
}

inline static int unionFind(int &a)
{
	if(repr[a] != a)
		repr[a] = unionFind(repr[a]);

	return repr[a];
}

inline static std::vector<int>::iterator find(std::vector<int> &where, int what)
{
	for(std::vector<int>::iterator it = where.begin();  it != where.end(); ++ it)
		if(*it == what)
			return it;

	return where.end();
}
