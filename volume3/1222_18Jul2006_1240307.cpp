//1222
#include <stdio.h>

int N,LRes;
long int Res[200];

void Umn3(void)
{
int i;
long int T,P=0;
for (i=0;i<LRes;i++)
{
T=Res[i];
Res[i]=(P+Res[i]*3)%10000;
P=(P+T*3)/10000;
}
if (P>0)
{
LRes++;
Res[i]=P;
}
}

int main(void)
{
int i;
scanf("%d",&N);
if (N==1)
{
printf("1");
return 0;
}
LRes=1;


switch (N%3)
{
case 0: Res[0]=1;
N=N/3;
break;
case 1: Res[0]=4;
N=(N-4)/3;
break;
case 2: Res[0]=2;
N=(N-2)/3;
break;
}
for (i=0;i<N;i++)
Umn3();


printf("%ld",Res[LRes-1]);
for (i=LRes-2;i>=0;i--)
{
if (Res[i]/1000==0)
printf("0");
if (Res[i]/100==0)
printf("0");
if (Res[i]/10==0)
printf("0");
printf("%ld",Res[i]);
}
return 0;
}