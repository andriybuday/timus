//1413
#include <stdio.h>
int arr[10];
#define c 0.70710678118654752440084436210485
int main(){
	char a = 'r';

	long double x = 0.0000000000, y = 0.0000000000;

	while(scanf("%c", &a) != -1){
		if(a == '\n')break;
		if(a == '0')break;
		if(a == '1'){arr[1]++;continue;}
		if(a == '2'){arr[2]++;continue;}
		if(a == '3'){arr[3]++;continue;}
		if(a == '4'){arr[4]++;continue;}
		if(a == '6'){arr[6]++;continue;}
		if(a == '7'){arr[7]++;continue;}
		if(a == '8'){arr[8]++;continue;}
		if(a == '9')arr[9]++;
	}
	
	x = double(double(arr[6]-arr[4]) + c*(double(arr[9] - arr[7]) + double(arr[3] - arr[1])));
	y = double(double(arr[8]-arr[2]) + c*(double(arr[9] - arr[3]) + double(arr[7] - arr[1])));
	
	printf("%.10lf %.10lf", x, y);

	return 0;
}