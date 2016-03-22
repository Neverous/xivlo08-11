/* 2011
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
#include<algorithm>
#include<functional>
#include<vector>
//#define DEBUG(args...) fprintf(stderr, args)
#define DEBUG(args...)

class Matrix
{
	private:
		std::vector<long long int> data;

	public:
		Matrix(void);
		inline bool append(long long int num);
};

int tests,
	numbers;
long long int number[64],
	 result;
Matrix matrix;

int main(void)
{
	scanf("%d", &tests);
	for(int t = 0; t < tests; ++ t)
	{
		result = 0;
		matrix = Matrix();
		scanf("%d", &numbers);
		for(int n = 0; n < numbers; ++ n)
			scanf("%lld", &number[n]);

		std::sort(number, number + numbers, std::greater<long long int>());
		for(int n = 0; n < numbers; ++ n)
			if(!matrix.append(number[n]))
				result += number[n];

		printf("%lld\n", result);
	}

	return 0;
}

Matrix::Matrix(void)
{
	this->data.clear();
	return;
}

inline bool Matrix::append(long long int num)
{
	if(this->data.empty())
	{
		this->data.push_back(num);
		return true;
	}

	std::vector<long long int> copy = this->data;
	copy.push_back(num);
	for(int b = 55, p = 0, found = 0; b >= 0; -- b, found = 0)
	{
		for(unsigned int c = p; c < copy.size(); ++ c)
			if(copy[c] & (1LL << b))
			{
				std::swap(copy[c], copy[p]);
				found = true;
				break;
			}

		if(!found)
			continue;

		for(unsigned int c = p + 1; c < copy.size(); ++ c)
			if(copy[c] & (1LL << b))
				copy[c] ^= copy[p];

		++ p;
	}

	for(unsigned int c = 0; c < copy.size(); ++ c)
		if(!copy[c])
			return false;

	this->data = copy;
	return true;
}
