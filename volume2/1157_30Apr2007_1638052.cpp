//1157_AC
#include <stdio.h>
#include <math.h>
inline int num(int number)
{
	int counter = 0;
	for (int i = 1; i <= (int)sqrt(double(number)); ++i)
	{
		if (number%i==0) ++counter;
	}
	return counter;
}
int main()
{
	int m,n,k;
	scanf("%d%d%d",&m,&n,&k); 

	for (int i = k; i < 10000; ++i)
	{
		if ((num(i)==n)&&(num(i-k)==m))
		{	
			printf("%d\n",i);
			return 0;
		} 
	}
	printf("0\n");
	return 0;
}