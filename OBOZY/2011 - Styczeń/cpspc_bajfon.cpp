/* 2011
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>
//#define DEBUG(args...) fprintf(stderr, args)
#define DEBUG(args...)

char buffer[131072];
std::string first,
			second;

static inline int MAX(const int &A, const int &B){return A>B?A:B;}
static inline int lengthLCS(const std::string &A, const std::string &B);
static inline void printLCS(const std::string &A, const std::string &B);

int main(void)
{
	scanf("%*u %*u %s", buffer);
	first = buffer;
	scanf("%s", buffer);
	second = buffer;
	printf("%d\n", lengthLCS(first, second));
	printLCS(first, second);
	return 0;
}

static inline int lengthLCS(const std::string &A, const std::string &B)
{
	if(A.size() < B.size())
		return lengthLCS(B, A);

	std::vector<short int> len[2];
	len[0].resize(B.size() + 1, 0);
	len[1].resize(B.size() + 1, 0);

	for(unsigned int a = 0, _a = 0; a < A.size(); ++ a, _a ^= 1)
		for(unsigned int b = 0; b < B.size(); ++ b)
			len[_a][b + 1] = A[a] == B[b]?len[_a^1][b] + 1:MAX(len[_a^1][b + 1], len[_a][b]);

	return len[A.size() & 1][B.size()];
}

static inline void printLCS(const std::string &A, const std::string &B)
{
	if(A.size() > B.size())
		return lengthLCS(B, A);

	if(!A.size())
		return;

	if(A.size() == 1)
	{
		if(B.find(A[0]) != std::string::npos)
			putchar(A[0]);

		return;
	}

	unsigned int len = A.size() / 2;
	std::string fA = A.substr(0, len),
				sA = A.substr(len),
				rB = B,
				rS = sA;
	std::reverse(rB.begin(), rB.end());
	std::reverse(rS.begin(), rS.end());
	unsigned int lenA = lengthLCS(fA, B),
				 lenB = lengthLCS(rS, rB),
				 best = 0,
				 k = 0;
	for(
	return;
}
