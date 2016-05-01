#include <stdio.h>

int main()
{
int i,n;
unsigned long ans=0,num[46];
scanf("%d",&n);
num[1]=1;num[2]=1;
for(i=3;i<=n;i++)num[i]=num[i-1]+num[i-2];
ans=num[n]*2;
printf("%lu",ans);
return(0);
} 