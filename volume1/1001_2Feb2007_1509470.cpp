//AC
//#include <stdio.h>
#include <iostream>
#include <math.h>
double a[1000000];
int main()
{
	double temp;
	int i = 0;
	while(std::cin >> temp)
	{
		a[i] = sqrt(temp);
		i++;
	}

	for(int j = i-1; j>=0; j--)printf("%.4lf\n", a[j]);

	return 0;
}