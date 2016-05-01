#include <iostream>
#include <cmath>
using namespace std;

int main(){

unsigned i, a, n, x, k;

cin>>n;

int* masa = new int[n];

double s=0;

for(i=0; i<n; i++)cin>>masa[i];

for(i=0; i<n; i++)s+=masa[i];

double wanted = s/2;

a = 1<<n;		

double riznmin = 1E+20;


for(i=0; i<=a; i++){
	s=0; x=i; k=0;
	while(x){
		s+=masa[k]*(x%2);
		x=x>>1;
		k++;
	}	
if(fabs(s-wanted)<riznmin)riznmin=fabs(s-wanted);
}
cout<<(unsigned(riznmin*2));
return 0;
}