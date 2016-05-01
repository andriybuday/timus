//1131
#include <stdio.h>

int main(){
	int n, k;
	scanf("%d%d", &n, &k);
	if(n==1){
		printf("0");
		return 0;
	}
	if(k==1){
		printf("%d", n-1);
		return 0;
	}
	//if(k>=n){printf("%d", )}
	//if(n==4 && k==2){printf("2");return 0;}
	int num = 1, step = 1;
	int count = 0;
	while(num < n){
		if(step >= k){
			/*
			while(num < n){
				num += k;
				count++;
			}
			*/
			count += (n-num)/k;
			if((n-num)%k)count++;
			printf("%d", count);
			return 0;
		}
		
		num += step;
		step *= 2;
		count++;
	}


	printf("%d", count);


	return 0;
}