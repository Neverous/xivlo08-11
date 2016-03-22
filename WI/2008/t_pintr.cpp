#include<cstdio>

int min(int a, int b)
{
	return (a>b)?b:a;
}

int max(int a, int b)
{
	return (a>b)?a:b;
}

int Xa,		//Współrzędna x punktu A
    Ya,		//Współrzędna y punktu A
    Xb,		//Współrzędna x punktu B
    Yb,		//Współrzędna y punktu B
    Xc,		//Współrzędna x punktu C
    Yc,		//Współrzędna y punktu C
    Xd,		//Współrzędna x punktu D
    Yd,
    x;

int side(int x, int y, int Xa, int Ya, int Xb, int Yb)
{
	return x*Ya + Xa*Yb + Xb*y - Xb*Ya - x*Yb - Xa*y;
}
int solve()
{
	int sideAB = side(Xd,Yd,Xa,Ya,Xb,Yb),
	    sideBC = side(Xd,Yd,Xb,Yb,Xc,Yc),
	    sideCA = side(Xd,Yd,Xc,Yc,Xa,Ya);

	if(sideAB==0 && min(Xa,Xb)<=Xd && Xd<=max(Xa,Xb) && min(Ya,Yb)<=Yd && Yd<=max(Ya,Yb))
		return 2;
	if(sideBC==0 && min(Xc,Xb)<=Xd && Xd<=max(Xc,Xb) && min(Yc,Yb)<=Yd && Yd<=max(Yc,Yb))
		return 2;
	if(sideCA==0 && min(Xa,Xc)<=Xd && Xd<=max(Xa,Xc) && min(Ya,Yc)<=Yd && Yd<=max(Ya,Yc))
		return 2;

	return (sideAB<0)==(sideBC<0) && (sideAB<0)==(sideCA<0) && (sideCA<0)==(sideBC<0);
}

int main(void)
{
	while(true)
	{
		scanf("%d%d%d%d%d%d%d%d", &Xa, &Ya, &Xb, &Yb, &Xc, &Yc, &Xd, &Yd);
		if(Xa==0 && Ya==0 && Xb==0 && Yb==0 && Xc==0 && Yc==0 && Xd==0 && Yd==0)
			break;
		x = solve();
		printf("%c\n", ((x==1)?'I':(x==0)?'O':'E'));

	}
	return 0;
}

