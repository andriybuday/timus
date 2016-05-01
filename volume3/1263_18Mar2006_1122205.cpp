#include <stdio.h>
#include <iostream>

using namespace std;

int main(){
	int i, j;
	double N, M;
	cin>>N>>M;
//	N=10000;M=10000; 

	int candit[10002];// to double ?????
	for(i = 0; i < N; i++)candit[i] = 0;

	int arr[10002];
	for(i = 0; i < M; i++){
		scanf("%d", &arr[i]);
//		arr[i] = i;
	}

	for(i=0; i<M; i++){
		for(j=0; j<N; j++){
			if(arr[i] == j+1)++candit[j];
		}
	}

	for(i=0; i<N; i++){
		printf("%.2f%%\n", (candit[i]/M)*100);
	}

	return 0;
}