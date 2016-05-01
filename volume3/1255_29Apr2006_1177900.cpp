//1255
#include <stdio.h>
int karr[10000];

int main(){

	int i, j;
	int n, k, count_k = 1;
	int count_k_rows = 1;
	scanf("%d%d", &n, &k);
	if(n < k){
		printf("0");
		return 0;
	}

	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			karr[count_k]++;
			count_k++;
			//if(count_k > k)count_k = 1;
			count_k = (count_k > k) ? 1 : count_k;
		}
		count_k_rows++;
		count_k = count_k_rows % k + 1;
		
	}

	int res = karr[1];
	for(i = 2; i <= k; i++)
		if(karr[i] < res)res = karr[i];

	printf("%d", res);

	return 0;
}