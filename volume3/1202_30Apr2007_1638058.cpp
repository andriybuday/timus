//1202_AC
#include <stdio.h>
int main()
{
	int x1,x2,y1,y2,ymin,ymax,n,i,posy,disttt = 0;
	scanf("%d",&n);
	scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
	posy = 1;
	ymin = y1;
	ymax = y2;
for(i = 1; i < n; i++)
{
	scanf("%ld%ld%ld%ld",&x1,&y1,&x2,&y2);
	if(y1 >= ymax-1 || y2 <= ymin+1)
	{
		printf("-1\n");
		return 0;
	}
	if (posy <= y1) 
	{
		disttt += (y1+1-posy);
		posy = y1+1;
	}
	else if (posy >= y2)
	{
		disttt += posy-y2+1;
		posy = y2-1;
	}
	ymin = y1;
	ymax = y2;
}
	disttt += x2-2;

	if (posy > y2-1)disttt += posy+1-y2;
	else
		disttt+=y2-1-posy;

	printf("%ld\n",disttt);

	return 0;
}
