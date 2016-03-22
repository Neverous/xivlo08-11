/* 2011
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
#include<string>
#include<vector>
//#define DEBUG(args...) fprintf(stderr, args)
#define DEBUG(args...)

unsigned int tests;
char buffer[128];
std::string first,
			second,
			third;

inline static unsigned int MAX(const unsigned int &A, const unsigned int &B){return A>B?A:B;}
inline static unsigned int tripleLCS(const std::string &A, const std::string &B, const std::string &C);

int main(void)
{
	scanf("%u", &tests);
	for(unsigned int t = 0; t < tests; ++ t)
	{
		scanf("%s", buffer); first = std::string(buffer);
		scanf("%s", buffer); second = std::string(buffer);
		scanf("%s", buffer); third = std::string(buffer);
		printf("%u\n", tripleLCS(first, second, third));
	}

	return 0;
}

inline static unsigned int tripleLCS(const std::string &A, const std::string &B, const std::string &C)
{
	if(A.size() < B.size())
		return tripleLCS(B, A, C);

	if(B.size() < C.size())
		return tripleLCS(A, C, B);

	std::vector<std::vector<short int> > len[2];
	len[0].resize(B.size() + 1, std::vector<short int>(C.size() + 1));
	len[1].resize(B.size() + 1, std::vector<short int>(C.size() + 1));
	for(unsigned int a = 0, _a = 1; a < A.size(); ++ a, _a ^= 1)
		for(unsigned int b = 0; b < B.size(); ++ b)
			for(unsigned int c = 0; c < C.size(); ++ c)
			{
				if(A[a] == B[b] && A[a] == C[c])
					len[_a][b + 1][c + 1] = len[_a^1][b][c] + 1;

				else
					len[_a][b + 1][c + 1] = MAX(
						MAX(len[_a][b][c + 1], len[_a][b + 1][c]),
						len[_a^1][b + 1][c + 1]);
			}

	return len[A.size() & 1][B.size()][C.size()];
}
