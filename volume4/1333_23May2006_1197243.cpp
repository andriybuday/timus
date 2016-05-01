//1333
#include <stdio.h>
#include <stdlib.h>
#define max 1000000

double aix[11];
double aiy[11];
double air[11];

inline bool is_in(double xx_random,double yy_random,double x_center,double y_center,double rad){
	if(((x_center - xx_random)*(x_center - xx_random) +
		(y_center - yy_random)*(y_center - yy_random)) < rad*rad)return true;
	return false;
}

int	main(){
	int n, i;
	scanf("%d", &n);

	int total_counter = 0;
	for(i = 0; i < n; i++)
	{
		scanf("%lf%lf%lf", &aix[i], &aiy[i], &air[i]);
	}

	double temp_x;
	double temp_y = 0.256;
	for(i = 0; i<max; i++)
	{
		temp_x = ((double) rand() / (double) RAND_MAX);

		for(int j = 0; j<n; j++)
		{
			if(is_in(temp_x,temp_y,aix[j],aiy[j],air[j]))
			{
				total_counter++;
				break;
			}
		}

		temp_y = ((double) rand() / (double) RAND_MAX);
	}

	printf("%f", double(total_counter) / 10000.0);

	return 0;
}