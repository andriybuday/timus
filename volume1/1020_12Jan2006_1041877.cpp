#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main(){

unsigned short N; cin>>N;
float R; cin>>R;
float x[101], y[101];

for(unsigned short i=0; i<N; i++){
	cin>>x[i]>>y[i];
}
unsigned short i=N;

x[i]=x[0]; y[i]=y[0];

float p = 0.0;

for(i=0; i<N; i++)
{
p+=sqrt((x[i]-x[i+1])*(x[i]-x[i+1])+(y[i]-y[i+1])*(y[i]-y[i+1]));
}
p+=2.0*3.1415926*R;

printf("%#.2f", p);

return 0;
}