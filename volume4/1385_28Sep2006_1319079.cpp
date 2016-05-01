#include <stdio.h>

int main()
{
int N;
scanf("%d", &N);
if(N==1)
{
printf("14");
return 0;
}
if(N==2)
{
printf("155");
return 0;
}
if(N==3)
{
printf("1575");
return 0;
}
if(N==4)
{
printf("15750");
return 0;
}
if(N==5)
{
printf("157500");
return 0;
}
printf("1575");
int i;
for(i = 0; i < N-3; i++)printf("0");



return 0;
}