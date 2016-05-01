#include <iostream>
using namespace std;

int main(){
	
	int A, B;
	cin>>A>>B;

	if(!(A%2) && !(B%2)){
		cout<<(B-A)/2;
	}else
		cout<<(B-A)/2 + 1;

	return 0;
}