#include <cstdio>
typedef long long unsigned int bigInt;

bigInt n,
	   k,
	   mod;
bigInt modulo( bigInt x, bigInt mod )
{
	return (x%mod<mod)?mod+x%mod:x;
}
bigInt newtonExtended ( bigInt n, bigInt k, bigInt mod )
{
	bigInt a=1,b=1;
	for ( bigInt i = ( ( k > n - k ) ? k : n - k) + 1; i <= n; i++ )
		a = modulo((a * i),(1<<30));
	for ( bigInt i = 1, end = ( ( k < n - k ) ? k : n - k); i <= end; i++ )
		b = modulo((b * i),(1<<30));
	return ( a / modulo((b*b),(1<<30)))%mod;
}

int main ( void )
{
	scanf ( "%llu %llu %llu", &n, &k, &mod );
	printf ( "%llu\n", newtonExtended ( n, k, mod ) );
	return 0;
}

