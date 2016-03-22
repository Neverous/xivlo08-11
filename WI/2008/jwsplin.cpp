#include<cstdio>

int tests,
    Ax, Ay,
    Bx, By,
    Cx, Cy;

int main(void)
{
	scanf("%d", &tests);
	for(int i=0;i<tests;i++)
	{
		scanf("%d %d %d %d %d %d", &Ax, &Ay, &Bx, &By, &Cx, &Cy);
		printf("%s\n", (Ax*By+Bx*Cy+Cx*Ay-Cx*By-Bx*Ay-Ax*Cy==0)?"TAK":"NIE");
	}
	return 0;
}

