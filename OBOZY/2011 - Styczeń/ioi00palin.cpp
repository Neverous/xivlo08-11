/* 2011
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
#include<string>
#include<algorithm>
#include<vector>
//#define DEBUG(args...) fprintf(stderr, args)
#define DEBUG(args...)

int size;
char buffer[5005];
std::string orig,
			rev;

static inline int MAX(const int &A, const int &B){return A>B?A:B;}
static inline int lengthLCS(const std::string &A, const std::string &B);

int main(void)
{
	scanf("%d %s", &size, buffer);
	rev = orig = std::string(buffer);
	std::reverse(rev.begin(), rev.end());
	printf("%d\n", size - lengthLCS(orig, rev));
	return 0;
}

static inline int lengthLCS(const std::string &A, const std::string &B)
{
	if(A.size() < B.size())
		return lengthLCS(B, A);

	std::vector<short int> len[2];
	len[0].resize(B.size() + 1, 0);
	len[1].resize(B.size() + 1, 0);

	for(unsigned int a = 0, _a = 1; a < A.size(); ++ a, _a ^= 1)
		for(unsigned int b = 0; b < B.size(); ++ b)
			len[_a][b + 1] = A[a] == B[b]?len[_a^1][b] + 1:MAX(len[_a^1][b + 1], len[_a][b]);

	return len[A.size() & 1][B.size()];
}
