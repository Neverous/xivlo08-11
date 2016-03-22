/* 2010
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
#include<vector>

long long int tests,
			  size,
			  prime,
			  matrix[256][256];

long long int determinant(void);
long long int divMod(long long int a, long long int b, long long int p); // a / b (mod p)
std::pair<long long int, long long int> extEuclides(long long int a, long long int b);
inline long long int MOD(long long int a, long long int mod)
{
	return (a % mod >= 0)?a % mod:mod + (a % mod);
}

int main(void)
{
	scanf("%lld", &tests);
	for(long long int t = 0; t < tests; ++ t)
	{
		scanf("%lld %lld", &size, &prime);
		for(long long int h = 0; h < size; ++ h)
			for(long long int w = 0; w < size; ++ w)
			{
				scanf("%lld", &matrix[h][w]);
				matrix[h][w] = MOD(matrix[h][w], prime);
			}

		printf("%lld\n", determinant());
	}

	return 0;
}

long long int determinant(void)
{
	long long int ratio;
	for(long long int h = 0; h < size; ++ h)
	{
		if(!matrix[h][h])
			return 0;

		for(long long int c = h + 1; c < size; ++ c)
		{
			ratio = divMod(matrix[c][h], matrix[h][h], prime);
			for(long long int w = h; w < size; ++ w)
				matrix[c][w] = MOD(matrix[c][w] - matrix[h][w] * ratio, prime);
		}

	}

	ratio = matrix[0][0];
	for(long long int h = 1; h < size; ++ h)
		ratio = MOD(ratio * matrix[h][h], prime);

	return ratio;
}

long long int divMod(long long int a, long long int b, long long int p)
{
	return MOD(a * extEuclides(b, p).first, p);
}

std::pair<long long int, long long int> extEuclides(long long int a, long long int b)
{
	std::pair<long long int, long long int> res(1, 0);
	long long int temp;
	if(b == 0)
		return res;

	if(b > a)
	{
		res = extEuclides(b, a);
		return std::pair<long long int, long long int>(res.second, res.first);
	}

	res = extEuclides(b, MOD(a, b));
	temp = res.first;
	res.first = res.second;
	res.second = temp - res.second * (a / b);

	return res;
}
