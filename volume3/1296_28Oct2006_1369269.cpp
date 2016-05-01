//#include <iostream>
//using namespace std;
#include <stdio.h>

int main(){
	int n, max = 0, p = 0, q;
	//cin >> n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		//cin >> q;
		scanf("%d", &q);
		p += q;
		if (p < 0) p = 0;
		if (p > max) max = p;
	}
	//cout << max;
	printf("%d", max);
}