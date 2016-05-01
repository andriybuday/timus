//1031_Sb
#include <stdio.h>

long cost[10002], lung[10002], l1, l2, l3, c1, c2, c3;
int n, s1, s2, man;

int main ()
{
	int i, j;

	scanf("%ld %ld %ld %ld %ld %ld %d %d %d",&l1,&l2,&l3,&c1,&c2,&c3,&n,&s1,&s2);

	if(s1>s2)
	{
		man=s1;
		s1=s2;
		s2=man;
	}

	for(i=2; i<=n; i++)scanf("%ld",&lung[i]);

	for(i=s1; i<n; i++)
	{
		for(j=i+1; j<=n; j++)
		{
	///////////////////
	if(lung[j]-lung[i]<=l1 && lung[j]-lung[i]>0 && (cost[j]>cost[i]+c1 || !cost[j]))
			cost[j]=cost[i]+c1;
	if(lung[j]-lung[i]<=l2 && lung[j]-lung[i]>l1 && (cost[j]>cost[i]+c2 || !cost[j]))
			cost[j]=cost[i]+c2;
	if(lung[j]-lung[i]<=l3 && lung[j]-lung[i]>l2 && (cost[j]>cost[i]+c3 || !cost[j]))
			cost[j]=cost[i]+c3;
	//////////////////
		}
	}

	printf("%ld\n",cost[s2]);

return 0;
}