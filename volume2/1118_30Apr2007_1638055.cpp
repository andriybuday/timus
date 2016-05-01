//1118_AC
#include <stdio.h>

int b[1000007];

void make()
{
	int i,j;
	for (i=2; i<1000000; i++)
		if (!b[i])
			for (j=2; j<=1000000/i; j++)
				if (i*j<=1000000) b[i*j]=1;
}

int main()
{
	make();//in b zeros where thee prime is....
	int i, I, J, n;
	scanf("%d %d", &I, &J);
	if(I == 1){printf("1\n"); return 0;}

	for(i = J; i >= I; --i)
	{
		if(!b[i]){printf("%d\n", i); return 0;}
	}

	double min_trivial = 1e12;
	int min_i = -1;
	for(i = J; i >= I; --i)
	{
		n = i;
		int sum_div = 0;
		int div = 1;
		while(div != n)
		{
			if(!(n%div))sum_div += div;
			++div;
		}
		double trivial = (double)sum_div/double(n);
		//printf("%d %lf\n", n, trivial);
		if(trivial < min_trivial)min_trivial = trivial, min_i = n;
		
	}
	
	printf("\n\n%d\n", min_i);

}