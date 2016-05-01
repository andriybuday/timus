#include <iostream>
#include <cmath>
using namespace std;

int main(){
unsigned long K; cin>>K;
if(!(K%3)){cout<<2; return 0;}
if(!(K%4)){cout<<3; return 0;}
if(!(K%2))K/=2;
long int elementic = -1;
for(unsigned long i=3; i< (unsigned long)(sqrt(double(K))+1);i++){
	if(!(K%i)){
		elementic = i;
		break;
	}
}
if (!(elementic+1)) cout<<(K-1);
else cout<<(elementic-1);
return 0;
}