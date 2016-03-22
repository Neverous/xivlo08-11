#include <cstdio>

int sum(int x) {
	return (x * (x + 1)) / 2;
}

int main() {
	int n, res;

	scanf("%d", &n);

	res = 0;
	for(int i = n; i >= 1; i--)
		res += sum(i);
	for(int i = n - 1; i >= 1; i -= 2)
		res += sum(i);

	printf("%d\n", res);

	return 0;
}

