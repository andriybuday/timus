//1295
#include <stdio.h>

int arr[20] = {1, 1, 2, 0, 2, 1, 2, 0, 1, 1, 2, 0, 1, 1, 2, 0, 1, 1, 2, 0};

int main(){
			
	int n, m = 20;

	scanf("%d", &n);
	
	n %= m;

	printf("%d\n", arr[n-1]);

	return 0;
}
