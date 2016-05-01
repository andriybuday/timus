#include <iostream>
using namespace std;

int main(){
	int N, i, j;
	cin>>N;
	int arr[102][102];
int ght = 1;
	int sum = 0;
	do{
		sum++;
		j=0;
		for(i=sum-1; i>=0; i--){
				arr[i][j] = ght;
			j++;
			ght++;
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
		arr[k][j] = ght;
			j++;
			k--;
			ght++;
		}	
	count++;
	}while(sum != 0);

	for(j=0; j<N; j++){
		for(i=N-1; i>=0; i--){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}


	return 0;
}