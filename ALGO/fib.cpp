/* 2010
 * Maciej Szeptuch
 * XIV LO Wrocław
 * --------------------------
 *  Fibonacci porządnie! - Klasy i tepmlaty to zło!!! strasznie psują wydajność!
 */
#include<cstdio>
#include<vector>

int tests;
long long unsigned int number,
					   modulo;

struct Matrix
{
	long long unsigned int A,B,C,D;
	Matrix(long long unsigned int a = 1, long long unsigned int b = 0, long long unsigned int c = 0, long long unsigned int d = 1)
	{
		A = a;
		B = b;
		C = c;
		D = d;
	}
};

inline long long unsigned int fibonacci(long long unsigned int which, long long unsigned int MOD);
Matrix fastPower(Matrix base, long long unsigned int power, long long unsigned int MOD);

int main(void)
{
	scanf("%d", &tests);
	for(int t = 0; t < tests; ++ t)
	{
		scanf("%llu %llu", &number, &modulo);
		printf("%llu\n", fibonacci(number - 1, modulo));
	}

	return 0;
}

inline long long unsigned int fibonacci(long long unsigned int which, long long unsigned int MOD)
{
	return fastPower(Matrix(1,1,1,0), which, MOD).A;
}

Matrix fastPower(Matrix base, long long unsigned int power, long long unsigned int MOD)
{
	if(power == 0)
		return Matrix();

	Matrix R = fastPower(base, power / 2, MOD);
	Matrix Temp;
	Temp.A = (R.A * R.A + R.B * R.C) % MOD;
	Temp.B = (R.A * R.B + R.B * R.D) % MOD;
	Temp.C = (R.C * R.A + R.D * R.C) % MOD;
	Temp.D = (R.C * R.B + R.D * R.D) % MOD;
	R = Temp;
	if(power % 2)
	{
		Temp = Matrix();
		Temp.A = (R.A * base.A + R.B * base.C) % MOD;
		Temp.B = (R.A * base.B + R.B * base.D) % MOD;
		Temp.C = (R.C * base.A + R.D * base.C) % MOD;
		Temp.D = (R.C * base.B + R.D * base.D) % MOD;
		R = Temp;
	}

	return R;
}
