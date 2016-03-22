#include<cstdio>

using namespace std;
unsigned int number;

unsigned int divMe(unsigned int divBy2,unsigned int number )
{
	if(number==0)
		return 0;
	if(number<=11)
		return number;
	unsigned int result = divMe(0,number/4);
	if(divBy2==0)
		result += divMe(result,number/2);
	else
		result += divBy2;
	result += divMe(0,number/3);
	return result;
}

int main(void)
{
	while(scanf("%u", &number)!=-1)
		printf("%u\n", divMe(0,number));
	return 0;
}

