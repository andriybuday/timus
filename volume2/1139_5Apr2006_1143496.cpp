#include <stdio.h>

int main(){
	int N, M;
	scanf("%d%d", &N, &M);
	int min, max, curr;
	int n = N-1;
	int m = M-1;
	if(n <= m)
	{
		min = n;
		max = m;
	}else{
		min = m;
		max = n;
	}
	curr = min;

	while(true){
		if((max%curr == 0)&&(min%curr == 0))break;
		curr--;
		if(curr == 1)break;
	}


	printf("%d", n + m - curr);

	return 0;
}