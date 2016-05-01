//1120
#include <stdio.h>
#include <math.h>

int main(){
double N;
scanf("%lf", &N);
double A = 0.0;
int P;
double under = 2.0*N;
//printf("%lf\n", under);
P = sqrt(under);
while(P){
	A = (double(2*N + P - P*P))/double(2*P);
	if(A < 0){P--; continue;}
	if(A - long(A) < 0.00001)break;
	P--;
}
printf("%d %d", int(A), P);
      //    int t;
        //  scanf("%d", &t);
return 0;
}