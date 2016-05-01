//1209
#include <stdio.h>
#include <math.h>
int main(){
	int n, k = 1, i;
	scanf("%d", &n);

	for(i = 0; i<n;i++)
	{	
		scanf("%d", &k);
		
		double x = sqrt(1.0 + 8.0 * double(k-1));
		//double x = (sqrt(1.0 + 8.0 * double(k-1)) - 1.0) / (2.0);

		if(x - long(x) < 0.00001)
			printf("1 ");
		else 
			printf("0 ");
	}
	return 0;
}

