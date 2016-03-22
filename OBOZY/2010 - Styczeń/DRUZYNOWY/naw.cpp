#include<cstdio>

char buffer[1048576],
	 stack[1048576];
int s,
	result,
	pos;

int main(void)
{
	for(int t = 1; scanf("%s", buffer) != -1 && buffer[0] != '-'; ++ t)
	{
		s = result = 0;
		for(int b = 0; buffer[b]; ++ b)
		{
			if(s && buffer[b] == '}' && stack[s - 1] == '{')
			{
				-- s;
				continue;
			}

			stack[s ++] = buffer[b];
		}

		for(s = s - 1; s > 0 && stack[s] == '{' && stack[s - 1] == '{'; s -= 2)
				result += 1;

		++ s;
		for(pos = 0; pos < s - 1 && stack[pos] == '}' && stack[pos + 1] == '}'; pos += 2)
				result += 1;

		if(s - pos)
			result += 2;

		printf("%d. %d\n", t, result);
	}

	return 0;
}
