/* 2009
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

struct BigNum
{
	long long unsigned int A,
						   B;

	BigNum(char *number)
	{
		int size = strlen(number) - 1,
			n = 0;
		A = B = 0;
		for(long long unsigned power = 1; n < 13 && n <= size; ++ n, power *= 10)
			B += (number[size - n] - '0') * power;

		for(long long unsigned power = 1; n <= size; ++ n, power *= 10)
			A += (number[size - n] - '0') * power;
	}

	BigNum(void)
	{
		A = B = 0;
	}

	const bool operator<(const BigNum &N) const // To jest na odwrót
	{
		if(A > N.A)
			return true;

		if(A < N.A)
			return false;

		return B > N.B;
	}

	BigNum operator*(const int number) const
	{
		BigNum N = *this;
		N.B *= number;
		N.A *= number;
		N.A += N.B / (long long unsigned int)10000000000000LLU;
		N.B %= (long long unsigned int)10000000000000LLU;

		return N;
	}

	BigNum operator+=(const BigNum &N)
	{
		B += N.B;
		A += B / (long long unsigned int)10000000000000LLU;
		B %= (long long unsigned int)10000000000000LLU;
		A += N.A;
		return *this;
	}

	void print(void)
	{
		if(A)
			printf("%llu", A);

		if(B)
		{
			if(A)
				printf("%13llu", B);

			else
				printf("%llu", B);
		}

		if(!A && !B)
			printf("0");

		puts("");
	}
};

int size,
	particles,
	quant;
BigNum result;
pair<BigNum, int> particle[100001];
char numberA[32];

int main(void)
{
	scanf("%d %d", &size, &particles);
	for(int p = 0; p < particles; ++ p)
	{
		scanf("%d %s", &quant, numberA);
		particle[p] = pair<BigNum, int>(BigNum(numberA), quant);
	}

	sort(particle, particle + particles);
	for(int p = 0; p < particles && size; ++ p)
	{
		if(size >= particle[p].second)
		{
			size -= particle[p].second;
			result += particle[p].first * particle[p].second;
		}

		else
		{
			result += particle[p].first * size;
			size = 0;
		}
	}

	result.print();
}
