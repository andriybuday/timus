//1535_AC
#include <stdio.h>
int main()
 {
	int n, rev_counter, counter, half_counter, rev_half_counter;
	scanf("%d", &n);
//	freopen("out.txt", "w", stdout);

	if(n%2)
	{
		//min	
		rev_counter = n-1;
		counter = 1;
		while(counter != n)
		{
			fprintf(stdout,"%d %d ", counter, rev_counter);
			rev_counter-=2;
			counter+=2;
		}
		fprintf(stdout,"%d\n", n);
		//max
		rev_counter = n-1;
		counter = 1;
		while(counter != n)
		{
			fprintf(stdout,"%d ", counter);
			counter+=2;
		}
		fprintf(stdout,"%d ", n);
		while(rev_counter != 0)
		{
			fprintf(stdout,"%d ", rev_counter);
			rev_counter-=2;
		}
	}
	else
	{
		if(n%4)
		{
			//min
			half_counter = 1;
			rev_half_counter = n-1;
			while(half_counter != (n/2))
			{
				fprintf(stdout,"%d %d ", half_counter, rev_half_counter);
				rev_half_counter-=2;
				half_counter+=2;
			}
			fprintf(stdout,"%d ", half_counter);
			half_counter = (n/2) + 1;
			rev_half_counter = (n/2) - 1;
			while(half_counter != n)
			{
				fprintf(stdout,"%d %d ", half_counter, rev_half_counter);
				half_counter+=2;
				rev_half_counter-=2;
			}
			fprintf(stdout,"%d\n", half_counter);
			//max
			rev_counter = n;
			counter = 1;
			while(counter != n-1)
			{
				fprintf(stdout,"%d ", counter);
				counter+=2;
			}
			fprintf(stdout,"%d ", n-1);
			while(rev_counter != 0)
			{
				fprintf(stdout,"%d ", rev_counter);
				rev_counter-=2;
			}
		}
		else //four
		{
			//min
			half_counter = 1;
			rev_half_counter = n-1;
			while(half_counter <= (n/2))
			{
				fprintf(stdout,"%d %d ", half_counter, rev_half_counter);
				rev_half_counter-=2;
				half_counter+=2;
			}
			rev_half_counter = (n/2);
			half_counter = (n/2) + 2;
			while(rev_half_counter != 0)
			{
				fprintf(stdout,"%d %d ", rev_half_counter, half_counter);
				half_counter+=2;
				rev_half_counter-=2;
			}		
			fprintf(stdout,"\n");
			//max
			rev_counter = n;
			counter = 1;
			while(counter != n-1)
			{
				fprintf(stdout,"%d ", counter);
				counter+=2;
			}
			fprintf(stdout,"%d ", n-1);
			while(rev_counter != 0)
			{
				fprintf(stdout,"%d ", rev_counter);
				rev_counter-=2;
			}
		}
	}
	return 0;
}