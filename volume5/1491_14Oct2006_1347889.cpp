#include <stdio.h>

int arr[100007];

int main(){
	int n;
	int a, b, c, i;

	scanf("%d", &n);
	for (i = 0; i <= n; i++){
		scanf("%d %d %d", &a, &b, &c);
		arr[a] += c;
		arr[b + 1] -= c;
	}

	int res = 0;
	for (i = 1; i <= n; i++){
		res += arr[i];
		printf("%d ", res);
	}

	return 0;
}
