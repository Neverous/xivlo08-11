#include<cstdio>
int num,search,nums,temp;
int main(void)
{
	while(scanf("%d %d", &search, &nums)!=-1)
	{
		num = 0;
		while(nums--)
		{
			scanf("%d", &temp);
			if(temp == search)
				num++;
		}
		printf("%d\n", num);
	}
	return 0;
}

