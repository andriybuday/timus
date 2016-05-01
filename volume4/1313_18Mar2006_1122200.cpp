#include <iostream>
using namespace std;

int main(){
	int N, i, j;
	cin>>N;
	int arr[102][102];
	for(i=0; i<N; i++){
		for(j=0; j<N; j++){
			cin>>arr[i][j];
		}
	}

	int sum = 0;
	do{
		sum++;
		j=0;
		for(i=sum-1; i>=0; i--){
				cout<<arr[i][j]<<" ";
			j++;
		}
	}while(sum != N);
	/////////
	int k;
	sum = N;
	int count = 1;
	do{
		sum--;
		k = N-1;
		j = count;
		for(i=sum; i>0; i--){
			cout<<arr[k][j]<<" ";
			j++;
			k--;
		}	
	count++;
	}while(sum != 0);

	return 0;
}