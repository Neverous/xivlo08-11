/* 2010
 * Maciej Szeptuch
 * XIV LO Wrocław
 * ----------
 *  Brute v2
 */
#include<cstdio>
#include<string>
#include<queue>

unsigned int words,
			 maxLength,
			 result = 0;
char word[16];
std::string sWord[50],
	act;

class myCompare
{
	public:
		bool operator()(const std::string &A, const std::string &B) const;
};

std::priority_queue<std::string, std::vector<std::string>, myCompare> que;

bool isPalindrome(std::string &check);

int main(void)
{
	scanf("%u %u", &words, &maxLength);
	for(unsigned int w = 0; w < words; ++ w)
	{
		scanf("%s", word);
		sWord[w] = std::string(word);
		que.push(sWord[w]);
	}

	while(!que.empty())
	{
		act = que.top();
		que.pop();
		if(isPalindrome(act))
		{
			++ result;
			if(result == 835454957)
				result = 0;
		}

		for(unsigned int w = 0; w < words; ++ w)
			if((act + " " + sWord[w]).length() <= maxLength)
				que.push(act + " " + sWord[w]);
	}

	printf("%u\n", result);


	return 0;
}

bool isPalindrome(std::string &check)
{
	int s = 0,
		e = check.length() - 1;

	for(;s <= e; ++ s, -- e)
	{
		if(check[s] == ' ')
			++ s;

		if(check[e] == ' ')
			-- e;

		if(check[s] != check[e])
			return false;
	}

	return true;
}

bool myCompare::operator()(const std::string &A, const std::string &B) const
{
	return A.length() < B.length();
}
