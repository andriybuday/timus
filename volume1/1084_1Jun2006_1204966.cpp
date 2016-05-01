//1084
#include <stdio.h>
#include <math.h>
#define P 3.1415926535897932
//double P = 3.1415926535897;
int main(){
	double n, r, p;
	scanf("%lf%lf", &n, &r);
	p = n / 2.0;
	if( r < p){
		printf("%.3lf", P*r*r);
		return 0;
	}

	if(r >= n / sqrt(2.0)){
		printf("%.3lf", n*n);
		return 0;
	}

//	double m = sqrt(r*r - p*p);

//	double q = acos(p/r);

//	double ssec = q * r*r;

//	double del = 4.0*((acos(p/r) * r*r) - (sqrt(r*r - p*p))*p);
//	double res = ((P*r*r) - (4.0*((acos(p/r) * r*r) - (sqrt(r*r - p*p))*p)));

	printf("%.3lf", ((P*r*r) - (4.0*((acos(p/r) * r*r) - (sqrt(r*r - p*p))*p))));






	return 0;
}