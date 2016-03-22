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
short int answerT[10001];

bool answer(short int &quest);

int main(void)
{
	scanf("%hd", &coins);
	for(int c = 0; c < coins; ++ c)
		scanf("%hd", &coin[c]);

	scanf("%hd", &question);
	if(answer(question))
		printf("%d\n", answerT[question]);

	else
		printf("NIE\n");

	return 0;
}

bool answer(short int &quest)
{
	sort(coin, coin + coins);
	for(int a = 1; a <= quest; ++ a)
		answerT[a] = 10001;

	answerT[0] = 0;
	for(int c = coins - 1; c >= 0; -- c)
		for(int a = coin[c]; a <= quest; ++ a)
			if(answerT[a] > answerT[a - coin[c]] + 1)
				answerT[a] = answerT[a - coin[c]] + 1;
	
	return answerT[quest] != 10001;
}
