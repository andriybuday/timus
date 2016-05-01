//1290
#include <stdio.h>
int arr[25007];
void QS(int *a,int n)
{
int i, j, p;
i = 0;
j = n;
p = a[n>>1];
	do{
		while(a[i] < p)i++;
		while(a[j] > p)j--;
	
		if(i <= j){
			int temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			i++;
			j--;
		}
	}while(i <= j);
	
	if(j > 0)QS(a, j);
	if(i < n)QS(a + i, n-i); 
}

int main(){
	int n, i; 

	scanf("%d", &n);

	for(i=0; i<n; i++)
		scanf("%d", &arr[i]);

	QS(arr, n-1);

	for(i = n-1; i >= 0; i--)
		printf("%d\n", arr[i]);

	return 0;
}