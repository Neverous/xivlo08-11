#include <vector>
#include <algorithm>
#include <functional>
#include <cstdlib>
#include <iostream>

using namespace std;
long long unsigned int tab [ 60 ],
	numberOfMoney,
	toGet;
long long unsigned int check ( long long unsigned int n, long long unsigned int k )
{
	if (n == 0 || tab[k]==0)
		return 0;
 	long long unsigned int A = n / tab [ k ] + check ( n % tab [ k ], k + 1 ),
 						   B = check ( n, k + 1 );

	return B > 0 ? B < A ? B : A : A;
}

int main ( void )
{
	scanf ( "%llu", & numberOfMoney );
	for ( int i = 0; i < numberOfMoney; i++ )
		scanf ( "%llu", & tab [ i ] );
	scanf ( "%llu", & toGet );

	sort ( tab, tab + numberOfMoney, greater<int>( ) );

	printf ( "%llu", check ( toGet, 0 ) );
	return 0;
}

