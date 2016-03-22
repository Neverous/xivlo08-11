#include<algorithm>
#include<cstdio>

using namespace std;

int i,ilNamiotow, nicA, nicB, naprawie;
pair<int, int> namiocik[110];

int main(void)
{
	scanf("%d %d %d", &ilNamiotow, &nicA, &nicB);
	for(i = 0; i< ilNamiotow; i++)
		scanf("%d %d", &(namiocik[i].first), &(namiocik[i].second));

	sort(namiocik, namiocik+ilNamiotow);

	for(i = 0; i< ilNamiotow && (namiocik[i].first <= nicA || namiocik[i].second <= nicB); i++)
	{
		if (namiocik[i].first > nicA && namiocik[i].second > nicB) break;
		if (namiocik[i].first > nicA || namiocik[i].second > nicB) continue;
		naprawie++;
		nicA -= namiocik[i].first;
		nicB -= namiocik[i].second;
	}
	printf("%d",naprawie);
	return 0;
}

