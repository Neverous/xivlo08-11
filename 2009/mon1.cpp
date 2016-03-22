/* 2009
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
#include<algorithm>
//#define DEBUG(args...) fprintf(stderr, args)
#define DEBUG(args...) 

using namespace std;

short int coins,
	  coin[1001],
	  question;
bool answerT[10001];

bool answer(short int &quest);

int main(void)
{
	scanf("%hd", &coins);
	for(int c = 0; c < coins; ++ c)
		scanf("%hd", &coin[c]);

	scanf("%hd", &question);
	printf("%s\n", answer(question)?"TAK":"NIE");
	return 0;
}

bool answer(short int &quest)
{
	sort(coin, coin + coins);
	answerT[0] = true;
	for(int c = 0; c < coins; ++ c)
		for(int a = coin[c]; a <= quest; ++ a)
			if(!answerT[a] && answerT[a - coin[c]])
				answerT[a] = true;
	
	return answerT[quest];
}
