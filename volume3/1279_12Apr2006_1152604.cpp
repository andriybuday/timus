#include <stdio.h>

int M, N, K;
int arr[10007];

void qs(int* a, int n){
	int i = 0, j = n, tmp;
	int p = a[n>>1];
	do{
		while (a[i] < p) i++;
		while (a[j] > p) j--;
		if(i <= j){
			tmp = a[j];
			a[j] = a[i];
			a[i] = tmp;
			i++; j--;
		}
	}while (i <= j);
	if (j > 0) qs(a, j);
	if (i < n) qs(a+i, n-i);
}

int main(){
	scanf("%d%d%d", &M, &N, &K);
	int i;
	for(i=0; i<N*M; i++){
		scanf("%d", &arr[i]);
	}

	qs(arr, N*M-1);

	int diff;

	for	(i = 1; i<N*M; i++){
		diff = arr[i] - arr[i-1];
		K -= diff*i;
		//if(K<=0)break;
		
	if(K==0){ 
			printf("%d", arr[i]);
			return 0;
	}
		
	if(K<0){
			K += diff*(i-1);
			int cnt = 0;
			while(K>0){
				K -= (i-1);
				cnt++;
			}
			printf("%d", arr[i-1] + cnt -((K==0)?0:1));
			return 0;
		}
	}
	if(K>0){
			double re = double(K) / double(M*N);
			printf("%d", arr[M*N - 1]+long (re));
			return 0;
		}
	
	return 0;
}
/*
	for (i = 1; i < size; i++){
		k -= (arr[i] - arr[i-1]) * i;
		if (k <= 0)break;
	}

	if (k < 0) printf("%d", arr[i] + (k - i + 1) / i);
	if (k == 0) printf("%d", arr[i]);
	if (k > 0) printf("%d", arr[size - 1] + k / size );
}
*/