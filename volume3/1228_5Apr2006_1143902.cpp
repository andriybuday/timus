#include <stdio.h>
int main(){
int n;int k, k1;
scanf("%d%d", &n, &k);
while(n--){
	scanf("%d", &k1);
printf("%d\n", k/k1-1);

k = k1;
}


return 0;
}
