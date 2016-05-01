//1100
#include<stdio.h>
int arry[150000];
char brry[150000];
int main()
{
int n,i,j;
scanf("%d",&n);
for(i=0;i<n;++i)
scanf("%d%d",&arry[i],&brry[i]);
for(i=100;i>=0;--i)
for(j=0;j<n;++j)
if(brry[j]==i)
printf("%d %d\n",arry[j],brry[j]);
return 0;
}