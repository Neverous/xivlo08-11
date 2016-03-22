#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

typedef long long unsigned int llu;

struct BigNum
{
	llu a,b;
	bool operator< (const BigNum &X) const
	{
		return (a<X.a || (a==X.a && b<X.b));
	}

	bool operator== (const BigNum &X) const
	{
		return (a==X.a && b==X.b);
	}

};

vector<BigNum> allNums;
BigNum AX;
int numbers,numbers2;
llu powerOf10[16];
char number[31];

BigNum make_BigNum(char * x)
{
	BigNum A;
	A.a = A.b = 0;
	int i,j,size = strlen(x)-1;
	for(i=size,j=0;j<15 && i>=0;i--,j++)
		A.b +=  (x[i]-'0')*powerOf10[j];
	for(j=0;i>=0;i--,j++)
		A.a +=  (x[i]-'0')*powerOf10[j];

	return A;
}
int myBsearch(BigNum &X, int start, int end)
{
	int position = (start+end)/2;
	if(allNums[position]==X)
	{
		while(position>0 && allNums[position-1]==X)position --;
		return position;
	}
	if(start == end || start>end)
		return position+((allNums[position]<X)?1:0);

	if(allNums[position] < X)
		return myBsearch(X,position+1,end);
	else
		return myBsearch(X,start,position-1);
}

int main(void)
{
	powerOf10[0] = (llu)1;powerOf10[1] = (llu)10;powerOf10[2] = (llu)100;powerOf10[3] = (llu)1000;powerOf10[4] = (llu)10000;powerOf10[5] = (llu)100000;powerOf10[6] = (llu)1000000;powerOf10[7] = (llu)10000000;powerOf10[8] = (llu)100000000;powerOf10[9] = (llu)1000000000;powerOf10[10] = (llu)powerOf10[5]*powerOf10[5];powerOf10[11] = (llu)powerOf10[5]*powerOf10[6];powerOf10[12] = (llu)powerOf10[6]*powerOf10[6];powerOf10[13] = (llu)powerOf10[6]*powerOf10[7];powerOf10[14] = (llu)powerOf10[7]*powerOf10[7];powerOf10[15] = (llu)powerOf10[7]*powerOf10[8];
	scanf("%d ", &numbers);
	for(int i=0;i<numbers;i++)
	{
		scanf("%s", number);
		allNums.push_back(make_BigNum(number));
	}
	sort(allNums.begin(),allNums.end());
	scanf("%d ", &numbers2);
	for(int i=0;i<numbers2;i++)
	{
		scanf("%s", number);
		AX = make_BigNum(number);
		printf("%d\n", myBsearch(AX,0,numbers-1));
	}
	return 0;
}

