#include <cstdio>

using namespace std;

int t,
	n,
	i,
	mini,
	maxi;

void xxx(int);

int main()
{
   scanf("%d", &t);
   while(t--)
   {
	mini = 0; maxi = 0;
    scanf("%d", &n);
    if(n < 7)
    {
        if(n == 2) mini = 1;
        else if(n == 3) mini = 7;
        else if(n == 4) mini = 4;
        else if(n == 5) mini = 2;
        else if(n == 6) mini = 6;
		printf("%d ", mini);
    }
    else
    {
        if(n%7==0) xxx(0);
        else if(n%7==1) xxx(10);
        else if(n%7==2) xxx(1);
        else if(n%7==3) xxx(20);
        else if(n%7==4) xxx(20);
        else if(n%7==5) xxx(2);
        else if(n%7==6) xxx(68);
    }
    if(n%2)
    {
         i = 3;
         printf("7");
    }
    else i = 0;
    for(; i < n ; i += 2)
    {
        printf("1");
    }
	printf("\n");
    //printf("%d %d\n", mini, maxi);
   }
}

void xxx(int k)
{
	if(k != 0)
		printf("%d", k);
    int doo;
    if(k > 9) doo = n/7-1;
    else doo = n/7;
    mini = k;
    for(int i = 0 ; i < doo ; ++i)
    {
        printf("8");
    }
	printf(" ");
}
