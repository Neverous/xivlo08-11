#include<iostream>

using namespace std;

int n, s, r;

long long fib ( int k )
{
	if ( r == k ) ++ s;
	if  ( k < 2 )
		return 1;

	return fib ( k - 1 ) + fib ( k - 2 );
}

int main ( )
{
	cin >> n;
  	while ( n >= 0 )
  	{
  		cin >> r;
  		s = 0;
  		fib ( n );
  		cout << "Podczas liczenia " << n << "-tej liczby Fibonacciego, fib(" << r << ") wywolano " << s << " razy" << endl;
     	cin >> n;
  	}
}

