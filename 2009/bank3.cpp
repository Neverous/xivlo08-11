/* 2009
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
#include<deque>
#include<cstring>

short int numbers,
		  number[202],
		  count[202],
		  result[20002],
		  old[20002],
		  wanted;
std::deque<short int> que;

inline short int solve(short int &max);

int main(void)
{
	scanf("%hd", &numbers);
	for(int n = 0; n < numbers; ++ n)
		scanf("%hd", &number[n]);

	for(int n = 0; n < numbers; ++ n)
		scanf("%hd", &count[n]);

	scanf("%hd", &wanted);
	printf("%hd\n", solve(wanted));
	return 0;
}

inline short int solve(short int &max)
{
	result[0] = 0;
	for(int m = 1; m <= max; ++ m)
		result[m] = 20002;

	for(short int n = 0; n < numbers; ++ n) // dla każdego nominału
		for(short int num = 0; num < number[n]; ++ num) // dla każdej liczby mniejszej od jego wartości
		{
			que.clear();
			for(short int q = 0; num + q * number[n] <= max; ++ q) // sprawdzaj wszystkie wartości n * B[i] + r <= max - i to rozpatrywany nominał, r to ta liczba mniejsza od B[i], n jest N, B[] to tablica nominałów
			{
				old[q] = result[num + q * number[n]] - q; // wynik zanim zacząłem badać dany "num"
				while(!que.empty() && old[que.back()] >= old[q]) // chcemy mieć jak najlepsze możliwości rozbudowy - najmniejsza ilość banknotów
					que.pop_back();

				que.push_back(q);
				result[num + q * number[n]] = old[que.front()] + q;
				while(!que.empty() && q - que.front() >= count[n]) // jeśli musiałbym użyć za dużo banknotów to trzeba wyrzucić z okienka początkowe wartości
					que.pop_front();
			}
		}

	return result[max] == 20002?-1:result[max];
}
