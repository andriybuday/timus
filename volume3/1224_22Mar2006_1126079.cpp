#include <stdio.h>

__int64 min(__int64 nn, __int64 mm){
	if(nn<=mm)return 2*nn; 
	return 2*mm+1;
}

int main(){
	__int64 n, m;
	scanf("%I64d", &n);
	scanf("%I64d", &m);

	printf("%I64d", min(n,m) - 2);

	return 0;
}