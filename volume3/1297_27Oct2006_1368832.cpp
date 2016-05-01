//1297-SB
#include <iostream>
using namespace std;
char x;
char a[1001];
int n ,i ,start ,len , maxlen;
void find(int p,int q){
	int p0, q0;
	p0=p;
	q0=q;
	while ((p0>=1)&&(q0<=n)&&(a[p0]==a[q0]))
	{
		len += 2;
		q0++;
		p0--;
	}
	if(len > maxlen)
	{
		maxlen = len;
		start = p0;
	}
}
int main()
{
	n = 0;
	while(cin >> x)
	{
		n++;
		a[n] = x;
	}

	maxlen = 0;
	for( i=1 ; i <= n; i++)
	{
		len=0;
		find(i,i+1);
		len = 1;
		find(i-1,i+1);
	}
	for( i=1; i <= maxlen;i++)
	{
		printf("%c", a[start+i]);
	}
return 0;
}