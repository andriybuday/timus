//1370
#include <stdio.h>
int arr[1004];

int main(){
	
	int n, m;
	scanf("%d%d", &n, &m);
	
	int i;

	m = m%n;
	for(i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	
	int count = 0;
	for(i = m; i < n; i++)
	{
		if(count >= 10)break;
		printf("%d", arr[i]);
		count++;
	}
	if(count < 10)
	{
		for(i = 0; i < 10-count; i++)
			printf("%d", arr[i]);
	}



	return 0;
}
