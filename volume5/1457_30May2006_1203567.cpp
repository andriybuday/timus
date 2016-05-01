#include <stdio.h>
#include <cmath>
int arr[1007];
int main(){
int n;
scanf("%d", &n);
int i;
for(i = 0; i< n; i++)scanf("%d", &arr[i]);

int sum = 0;
for(i = 0; i< n; i++)sum += arr[i];



printf("%f", double(sum)/double(n));
return 0;
}