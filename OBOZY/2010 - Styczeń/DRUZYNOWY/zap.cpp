#include<cstdio>

int tests,
	matches,
	temp;

int main(void)
{
	scanf("%d", &tests);
	for(int t = 0; t < tests; ++ t)
	{
		scanf("%d", &matches);
		if(matches == 2)
		{
			printf("1 1\n");
			continue;
		}

		if(matches == 3)
		{
			printf("7 7\n");
			continue;
		}

		if(matches == 4)
		{
			printf("4 11\n");
			continue;
		}

		if(matches == 5)
		{
			printf("2 71\n");
			continue;
		}

		if(matches == 6)
		{
			printf("6 111\n");
			continue;
		}
		temp = matches;
		switch(matches % 7)
		{
			case 0:
				matches /= 7;
				break;

			case 1:
				printf("10");
				matches = (matches - 8) / 7;
				break;

			case 2:
				printf("18");
				matches = (matches - 9) / 7;
				break;

			case 3:
				printf("22");
				matches = (matches - 10) / 7;
				break;

			case 4:
				printf("20");
				matches = (matches - 11) / 7;
				break;

			case 5:
				printf("28");
				matches = (matches - 12) / 7;
				break;

			case 6:
				printf("68");
				matches = (matches - 13) / 7;
				break;
		}

		for(int i = 0; i < matches; ++ i)
			printf("8");

		printf(" ");
		matches = temp;
		if(matches % 2 == 0)
			matches /= 2;

		else
		{
			printf("7");
			matches = (matches - 3) / 2;
		}

		for(int i = 0; i < matches; ++ i)
			printf("1");

		puts("");
	}
	return 0;
}

