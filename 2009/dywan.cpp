/* 2010
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
#include<vector>
#include<algorithm>

long long int spots,
	questions,
	MOD,
	sRow,
	sCol,
	sCost,
	factorialModulo[1000010],
	factorialCount[1000010],
	difference[1010];
std::pair<std::pair<long long int, long long int>, long long int> position[1010];

void preprocess(void);
long long int newton(long long int n, long long int k);
long long int getDifference(long long int n, long long int k);
long long int divMod(long long int a, long long int b, long long int Modulo);
std::pair<long long int, long long int> extEuclides(long long int first, long long int second);

int main(void)
{
	scanf("%lld %lld %lld", &spots, &questions, &MOD);
	preprocess();
	for(long long int s = 0 ; s < spots; ++ s)
	{
		scanf("%lld %lld %lld", &sRow, &sCol, &sCost);
		position[s] = std::make_pair(std::make_pair(sRow, sCol), sCost);
	}

	std::sort(position, position + spots);
	for(long long int s = 0 ; s < spots; ++ s)
		difference[s] = (position[s].second - newton(position[s].first.first, position[s].first.second) - getDifference(position[s].first.first, position[s].first.second)) % MOD;

	for(long long int q = 0; q < questions; ++ q)
	{
		scanf("%lld %lld", &sRow, &sCol);
		printf("%lld\n", (newton(sRow, sCol) + getDifference(sRow, sCol)) % MOD);
	}

	return 0;
}

void preprocess(void)
{
	factorialModulo[0] = 1;
	factorialCount[0] = 0;

	for(long long int n = 1; n < 1000001; ++ n)
	{
		factorialModulo[n] = n;
		while(factorialModulo[n] && factorialModulo[n] % MOD == 0)
		{
			++ factorialCount[n];
			factorialModulo[n] /= MOD;
		}

		factorialModulo[n] = (factorialModulo[n - 1] * factorialModulo[n]) % MOD;
		factorialCount[n] += factorialCount[n - 1];
	}

	return;
}

long long int newton(long long int n, long long int k)
{
	if(n < 0 || k < 0 || k > n)
		return 0;

	if(factorialCount[n] > factorialCount[k] + factorialCount[n - k])
		return 0;

	return divMod(divMod(factorialModulo[n], factorialModulo[k], MOD), factorialModulo[n - k], MOD);
}

long long int divMod(long long int a, long long int b, long long int Modulo)
{
	b = extEuclides(Modulo, b).second;
	b = ((long long int)a * b) % Modulo;
	if(b < 0)
		b += (b - Modulo + 1) / Modulo * (- Modulo);

	return b;
}

std::pair<long long int, long long int> extEuclides(long long int first, long long int second)
{
	std::pair<long long int, long long int> result(0,1);
	long long int temp;
	if(!second || first % second == 0)
		return result;

	result = extEuclides(second, first % second);
	temp = result.first;
	result.first = result.second;
	result.second = temp - result.second * (first / second);

	return result;
}

long long int getDifference(long long int n, long long int k)
{
	long long int result = 0;
	for(long long int s = 0; s < spots; ++ s)
		result += (newton(n - position[s].first.first, k - position[s].first.second) * difference[s]) % MOD;

	if(result < 0)
		result += (result - MOD + 1) / MOD * (- MOD);

	return result % MOD;
}
