/*
   Laboratorium Praktyki Programowania
*/

#include <iostream>
#include <cstring>

using namespace std;

#define T_SIZE 1001

char* replicate(char * zd, int x)
{
	int len = strlen(zd);
	char *result = new char[len*x+1];
	for(int i=0;i<len*x;i++)result[i]=0;
	for(int i=0,j=0;i<len*x;i++,j++)
	{
		result[i] = zd[j%len];
	}
	result[len*x] = 0;
	return result;
}

int main(){
  int t,n;
  char S1[T_SIZE], *S;

  cin >> t;
  cin.getline(S1,T_SIZE);
  while(t){
    cin >> n;
    ws (cin);
    cin.getline(S1,T_SIZE);
    S=replicate(S1,n);
    cout << S << endl;
    delete[] S;
    t--;
  }
  return 0;
}

