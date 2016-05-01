//1149
#include <stdio.h>

void An(int n)
{
	int count = 1;
	for(int i=1; i<=n; i++)
	{
		printf("sin(%d", i);
		if(i == n)
		{
			for(int j = 0; j < n; j++)printf(")");
			break;
		}
		if(i%2)
		{
			printf("-");
		}else 
			printf("+");
		
	}

}

void Sn(int n){
	
	int cnt = 1;
	
	int postcnt = n;
	
	for(int i=0; i<n-1; i++)printf("(");
	
	for(int j=0; j<n; j++)
	{
		An(cnt);
		if(j == n-1)
		{
			printf("+%d", postcnt);
			break;
		}
		printf("+%d)", postcnt);
		postcnt--;
		cnt++;
	}
}

int main(){
	
	int n;
	
	scanf("%d", &n);
	
	if(n <= 0)return 0;//or maybe it is '1' when n==0 ?//or even '0' 

	Sn(n);

	return 0;
}