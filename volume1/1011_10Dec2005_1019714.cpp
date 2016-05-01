#include<iostream>
#include<cmath>
using namespace std;
int main(){
	double P, Q; cin>>P>>Q;
	unsigned N = 1; double Base = 100.0; double R = 0;
	while (true){
		while (Base/N < P) Base += 100.0f;
		R=Base/N;
		if ((R>P) && (R<Q)) break;
		N++;
	}
	cout<<N;
	return 0;
}