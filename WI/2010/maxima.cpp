/* 2010
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
#include<list>
//#define DEBUG(args...) fprintf(stderr, args)
#define DEBUG(args...)

unsigned int numbers,
			 wsize,
			 number[1048576];
std::list<unsigned int> window;

int main(void)
{
	scanf("%u %u", &numbers, &wsize);
	-- wsize;
	for(unsigned int n = 0; n < numbers; ++ n)
	{
		scanf("%u", &number[n]);
		while(!window.empty() && window.front() + wsize < n)
			window.pop_front();

		while(!window.empty() && number[window.back()] < number[n])
			window.pop_back();

		window.push_back(n);
		if(n >= wsize)
			printf("%u ", number[window.front()]);
	}

	puts("");
	return 0;
}

