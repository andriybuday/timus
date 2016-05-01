//1161
#include <stdio.h>
#include <math.h>
int arr[107];
double res = 0;
void Sq(int* a, int n){
	int p  = a[n>>1];
	int i = 0 , j = n; 
	int temp;
	
		do{
			while(a[i] < p)i++;
			while(a[j] > p)j--;
	
			if(i <= j){
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
				i++;
				j--;
			}
		}while(i <= j);

	if(j > 0)Sq(a, j);
	if(i < n)Sq(a + i, n-i); 
}
int main(){
	int n;
	scanf("%d", &n);
	int i;

	for(i = 0;i < n; i++)
		scanf("%d", &arr[i]);

	Sq(arr, n-1);

	res = arr[n-1];

	for(i = n-2; i >= 0; i--)
	{
		res = 2*sqrt(arr[i]*res);
	}


	printf("%.2f", res);

	return 0;
}