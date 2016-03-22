/* 2009
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
/*
 * Porównywanie szybkości sorotwań :
 * 	- S - Selection Sort
 * 	- I - Insertion Sort
 * 	- M - Merge Sort
 * 	- Q - Quick Sort
 * 	- C - Counting Sort
 * 	- B - Bucket Sort
 *
 * A dokładniej :
 * 	1. S vs I
 *  2. M vs Q
 *  3. C vs B
 */
#include <cstdio>
#include <sys/time.h>
#include <algorithm>
#include <unistd.h>
#include <cstring>
#include <list>
#define MAX_ELEMS 2000002

using namespace std;

void SelectionSort ( void ); // Selection Sort
void InsertionSort ( void ); // Insertion Sort
void MergeSort ( void ); // Merge Sort
void QuickSort ( void ); // Quick Sort
void CountingSort ( void ); // Counting Sort
void BucketSort ( void ); // Bucket Sort
void compare ( const char * firstName, void ( * firstFunction ) ( void ), const char * secondName, void ( * secondFunction ) ( void ) ); // Porównywanie dwóch funkcji
double timeIt ( void ( * function ) ( void ) );// Timer - zwraca czas wykonywania funkcji

int original [ MAX_ELEMS ], // oryginalna tablica
	toSort [ MAX_ELEMS ], // do posortowania
	sorted [ MAX_ELEMS ], // posortowana sortem
	size; // ilość elementów

int main ( )
{
	scanf ( "%d", & size );
	for ( int s = 0; s < size; ++ s )
	{
		scanf ( "%d", & original [ s ] );
		sorted [ s ] = original [ s ];
	}
	std :: sort ( sorted, sorted + size ); // aby sprawdzać czy dobrze posortowało...

	/*
	 * M vs Q
	 */
	compare ( "Merge sort", MergeSort, "Quick sort", QuickSort );
	printf ( "\n" );

	/*
	 * C vs B
	 */
	compare ( "Counting sort", CountingSort, "Bucket sort", BucketSort );
	printf ( "\n" );

	/*
	 * S vs I
	 */
	compare ( "Selection sort", SelectionSort, "Insertion sort", InsertionSort );
	printf ( "\n" );


	return 0;
}

void compare ( const char * firstName, void ( * firstFunction ) ( void ), const char * secondName, void ( * secondFunction ) ( void ) )
{
	int times = 2, // ile testów
		t = 0;

	double first = 0.0, //czas pierwszej funkcji
		   second = 0.0, // czas drugiej
		   percentage = 0.0; //o ile procent szybsza jest jedna z nich

	bool good; // dobrze posortowane?

	good = true;
	first = 0.0;
	for ( t = 0; good && t < times; ++ t )
	{
		for ( int s = 0; s < size; ++ s )
			toSort [ s ] = original [ s ]; // tworzenie tablicy toSort - kopiowanie original

		first += timeIt ( firstFunction );
		for ( int s = 0; good && s < size; ++ s ) // sprawdzanie posortowania
			if ( sorted [ s ] != toSort [ s ] )
				good = false;
	}

	first /= t;
	printf ( "%s: %0.3lf ms [%s]\n", firstName, first, good ? "OK" : "FAIL" );

	good = true;
	second = 0.0;
	for ( t = 0; good && t < times; ++ t )
	{
		for ( int s = 0; s < size; ++ s )
			toSort [ s ] = original [ s ];

		second += timeIt ( secondFunction );
		for ( int s = 0; good && s < size; ++ s )
			if ( sorted [ s ] != toSort [ s ] )
				good = false;
	}

	second /= t;
	printf ( "%s: %0.3lf ms [%s]\n", secondName, second, good ? "OK" : "FAIL" );

	printf ( "Podsumowanie:\n" );
	if ( first > second )
		percentage = first / second;

	else
		percentage = second / first;

	percentage = percentage * 100 - 100.0;
	if ( first != second )
		printf ( "Wygrał %s z %0.2lf%% przewaga\n", ( first > second ) ? secondName : firstName, percentage );

	else
		printf ( "Remis!\n" );

	return;
}

double timeIt ( void ( * function ) ( void )  )
{
	struct timeval start, end;
	sleep ( 2 ); // żeby testy były bardziej "prawdziwe"
	gettimeofday ( & start, NULL );
	function ( );
	gettimeofday ( & end, NULL );

	return ( end . tv_sec - start . tv_sec ) * 1000 + ( end . tv_usec - start . tv_usec ) / 1000.0 + 0.5;
}

void SelectionSort ( void )
{
	for ( int place = 0, min = 0, act = 0; place < size; min = ++ place )
	{
		for ( act = place + 1; act < size; ++ act )
			if ( toSort [ act ] < toSort [ min ] )
				min = act;

		if ( place == min )
			continue;

		toSort [ size + 1 ] = toSort [ min ];
		toSort [ min ] = toSort [ place ];
		toSort [ place ] = toSort [ size + 1 ];
	}

	return;
}

void InsertionSort ( void )
{
	for ( int place = 1, act = 1, value = toSort [ act ]; place < size; act = ++ place, value = toSort [ act ] )
	{
		while ( act > 0 && toSort [ act - 1 ] > value )
		{
			toSort [ act ] = toSort [ act - 1 ];
			-- act;
		}

		toSort [ act ] = value;
	}

	return;
}

void CountingSort ( void )
{
	int max = 0;
	for ( int s = 0; s < size; ++ s )
		if ( toSort [ s ] > max )
			max = toSort [ s ];

	int helper [ max + 1 ];

	memset ( helper, 0, sizeof ( int ) * ( max + 1 ) );
	for ( int s = 0; s < size; ++ s )
		++ helper [ toSort [ s ] ];

	for ( int h = 0, place = 0; h < max + 1 && place < size; ++ h )
		while ( helper [ h ] -- )
			toSort [ place ++ ] = h;

	return;
}

void BucketSort ( void )
{
	int min = 0,
		max = 0,
		length = 0,
		buckets = 0,
		delta = 1;

	if ( size % 2 )
		toSort [ size ] = toSort [ size - 1 ];

	for ( int s = 0; s < size; s += 2 )
	{
		if ( toSort [ s ] < toSort [ s + 1 ] )
		{
			if ( toSort [ s ] < toSort [ min ] )
				min = s;

			if ( toSort [ s + 1 ] > toSort [ max ] )
				max = s + 1;
		}
		else
		{
			if ( toSort [ s + 1 ] < toSort [ min ] )
				min = s + 1;

			if ( toSort [ s ] > toSort [ max ] )
				max = s;
		}
	}

	length = toSort [ max ] - toSort [ min ] + 1;
	if ( length < size )
	{
		buckets = length + 1;
		delta = 1;
	}
	else
	{
		buckets = size + 1;
		delta = ( size - 1 + length ) / size;
	}

	list < int > * bucket = new list < int > [ buckets ]; //list < int > bucket [ buckets ] nie pozwalało stworzyć tablicy o wielkości > 100000...
	for ( int s = 0, place = 0; s < size; ++ s )
	{
		place = ( toSort [ s ] - toSort [ min ] ) / delta;
		bucket [ place ] . push_back ( toSort [ s ] );
	}

	for ( int b = 0, place = 0; b < buckets; ++ b )
	{
		bucket [ b ] . sort ( );
		for ( list < int > :: iterator it = bucket [ b ] . begin ( ); it != bucket [ b ] . end ( ); ++ it )
			toSort [ place ++ ] = * it;
	}

	return;
}

void mergesort ( int start, int end )
{
	if ( start == end )
		return;

	int middle = ( start + end ) / 2,
		helper [ end - start + 1 ],
		i = 0,
		j = 0,
		place = 0;

	mergesort ( start, middle );
	mergesort ( middle + 1, end );

	for ( i = start, j = middle + 1, place = 0; i <= middle || j <= end; )
	{
		if ( j > end || ( i <= middle && toSort [ i ] < toSort [ j ] ) )
			helper [ place ++ ] = toSort [ i ++ ];

		else if ( i > middle || ( j <= end && toSort [ i ] >= toSort [ j ] ) )
			helper [ place ++ ] = toSort [ j ++ ];
	}

	for ( int i = start; i <= end; ++ i )
		toSort [ i ] = helper[ i - start ];

	return;
}

void MergeSort ( void )
{
	mergesort ( 0, size - 1 );
}

void quicksort ( int start, int end )
{
	int middle = ( start + end ) / 2,
		elem = toSort [ middle ],
		i = start,
		j = end;

	do
	{
		while ( toSort [ i ] < elem )
			++ i;

		while ( toSort [ j ] > elem )
			-- j;

		if ( i <= j )
		{
			toSort [ size ] = toSort [ i ];
			toSort [ i ] = toSort [ j ];
			toSort [ j ] = toSort [ size ];
			++ i;
			-- j;
		}

	} while ( i <= j );
	if ( start < j )
		quicksort ( start, j );

	if ( end > i )
		quicksort ( i, end );
}

void QuickSort ( void )
{
	quicksort ( 0, size - 1 );
}
