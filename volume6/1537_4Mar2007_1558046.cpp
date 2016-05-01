#include <cstdio>
//#include <cmath>
//#include <iostream>
//using namespace std;

#define MAXV 10000007

int arr[10000015];

int main(){
	int k, p;
	scanf("%d %d", &k, &p);
	if (p == 1){
		printf("0\n");
		return 0;
	}
	int i, j;

	arr[2] = 1;
	for (i = 2; i <= k + 1; ++i){
		if (i + 1 < MAXV){
			arr[i + 1] += arr[i];
			arr[i + 1] %= p;
		}
		if (i + i < MAXV){
			arr[i + i] += arr[i];
			arr[i + i] %= p;
		}
	}

	printf("%d\n", arr[k]);

	return 0;
}
