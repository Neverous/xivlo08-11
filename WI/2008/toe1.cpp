#include<cstdio>
#include<cstdlib>

char tictoe[3][3];
int tests,
    numOfX,
    numOfO;
bool Xwon,
     Owon;
bool solve(void)
{
	for(int i=0;i<3;i++)
		if(tictoe[i][0]==tictoe[i][1] && tictoe[i][1]==tictoe[i][2])
			if(tictoe[i][0]=='X' && !Xwon)
				Xwon = true;
			else if(tictoe[i][0]=='O' && !Owon)
				Owon = true;
	for(int i=0;i<3;i++)
		if(tictoe[0][i]==tictoe[1][i] && tictoe[1][i]==tictoe[2][i])
			if(tictoe[0][i]=='X' && !Xwon)
				Xwon = true;
			else if(tictoe[0][i]=='O' && !Owon)
				Owon = true;
	if((!Owon || !Xwon) && tictoe[0][0]==tictoe[1][1] && tictoe[1][1]==tictoe[2][2])
		if(tictoe[0][0]=='X' && !Xwon)
			Xwon = true;
		else if(tictoe[0][0]=='O' && !Owon)
			Owon = true;
	if((!Owon || !Xwon) && tictoe[0][2]==tictoe[1][1] && tictoe[1][1]==tictoe[2][0])
		if(tictoe[0][2]=='X' && !Xwon)
			Xwon = true;
		else if(tictoe[0][2]=='O' && !Owon)
			Owon = true;
	if((Xwon && Owon) ||
		(Xwon && numOfX!=numOfO+1)  ||
		(Owon && numOfX!=numOfO) ||
		(numOfO!=numOfX && numOfX!=numOfO+1))
		return 0;
	return 1;
}
int main(void)
{
	scanf("%d ", &tests);
	while(tests--)
	{
		numOfO = numOfX = Xwon = Owon = 0;
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				scanf("%c", &tictoe[i][j]);
				//if(tictoe[i][j]=='\n')
				//	scanf("%c", &tictoe[i][j]);
				if(tictoe[i][j]=='X')
					numOfX++;
				else if(tictoe[i][j]=='O')
					numOfO++;
			}
			scanf(" ");
		}
		printf("%s\n", (solve())?"yes":"no");
	}
	return 0;
}

