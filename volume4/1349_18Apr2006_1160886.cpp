#include <stdio.h>

int main(){
	int n;
	scanf("%d", &n);
	
	if(n==1)printf("1 2 3");
	if(n==2)printf("3 4 5");
	if((n!=1)&&(n!=2))printf("-1");

	return 0;
}