/* 2009
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
#include<list>
#include<vector>

std::list<std::pair<int, int> > que,
								result[1000];

int tab[1001][1001],
	fieldSize,
	trapSize;

int main(void)
{
	scanf("%d %d", &fieldSize, &trapSize);
	for(int h = 0; h < fieldSize; ++ h)
	{
		que.clear();
		for(int w = 0; w < fieldSize; ++ w)
		{
			scanf("%d", &tab[h][w]);
			while(!que.empty() && tab[que.rbegin()->first][que.rbegin()->second] >= tab[h][w])
				que.pop_back(); // Kolejka danego wiersza

			que.push_back(std::pair<int, int>(h, w)); //...
			if(w >= trapSize - 1) // Jeśli pułapka mieści się na szerokość
			{
				while(!result[w - trapSize + 1].empty() && tab[result[w - trapSize + 1].rbegin()->first][result[w - trapSize + 1].rbegin()->second] >= tab[que.begin()->first][que.begin()->second])
					result[w - trapSize + 1].pop_back(); // Kolejka kolumny

				result[w - trapSize + 1].push_back(std::pair<int, int>(que.begin()->first, que.begin()->second)); // ...
				if(h >= trapSize - 1) // Tu możemy ustawić pułapkę
				{
					printf("%d ", tab[result[w - trapSize + 1].begin()->first][result[w - trapSize + 1].begin()->second]); // Minimum na tym "przedziale"
					if(h - trapSize + 1 == result[w - trapSize + 1].begin()->first) // Jeśli najmniejszy element jest na granicy zasięgu 
						result[w - trapSize + 1].pop_front(); // to go wyrzuć...
				}

				if(w - trapSize + 1 == que.begin()->second) // Jeśli najmniejszy element jest na granicy zasięgu
					que.pop_front(); // to go wyrzuć...
			}
		}

		if(h >= trapSize - 1)
			puts("");
	}
	return 0;
}
