#include <iostream>
using namespace std;

int main(){
	double fir, sec, thi;
	cin>>fir>>sec>>thi;
	double tmp = fir;
	int count =0;
	while (tmp > sec){
	
	
	
	
		count++;
		tmp = tmp - (tmp * (thi/100.0));
	}
	cout<<count;



	return 0;
}