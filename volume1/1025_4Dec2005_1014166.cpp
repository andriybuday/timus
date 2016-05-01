#include<iostream>
#include<cmath>
using namespace std;
int main(){
	unsigned k;
	cin>>k;
	unsigned a[101];
	unsigned i,j;
	for (i = 0; i < k; ++i)cin>>a[i];
	for (i = 0; i < k; i++){
		for (j = 0; j < k-1; j++){
			if (a[j]>a[j+1]){
				unsigned tmp = a[j];
				a[j]=a[j+1];
				a[j+1]=tmp;
			}
		}
	}
	unsigned n = 0;
	for (i = 0; i < (k / 2 + 1); i++) n += a[i]/2 + 1;
	cout<<n;
	return 0;
}