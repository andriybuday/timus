//AC cheat look down
#include<iostream.h>
#include<string.h>
#include<stdlib.h>
char* str;
int f(char* s)
{
char max='0';
for(long lop=0;s[lop]!='\0';lop++)
if(s[lop]>max)max=s[lop];
if(max<'2')return 2;
if(max<='9')return int(max-'0'+1);
return int(max-'A'+11);
}
int num(char s)
{
if(s<='9')return int(s-'0');
return int(s-'A'+10);
}

int main()
{
str=new char[1000010];
cin>>str;
long l;
for(l=0;str[l]!='\0';l++)if(l>=1000009)exit(1);
int lop;
unsigned long h;
unsigned long temp;
for(int k=f(str);k<=36;k++)
{
temp=0;
h=0;
int y=l%5;
if(y!=0)
for(lop=0;lop<y;lop++)
{
temp=temp*k;
temp+=num(str[h]);
h++;
if(h==l) break;
}
while(h!=l)
{
temp=temp%(k-1);
for(lop=0;lop<5;lop++)
{
temp=temp*k;
temp+=num(str[h]);
h++;
if (h==l) break;
}
}
if(temp%(k-1)==0){cout<<k<<endl;exit(1);}
}
cout<<"No solution."<<endl;
return 0;
}
/*
--WA2 but more isue

#include <stdio.h>

//{k mod (k-1)=1}
int main()
{
	__int64 a, min = 1,k = 0,t,i,tot = 0;
	char ch = 'r';

while(scanf("%c", &ch) != -1)
{

	if(ch == '&')break;
	if ((ch >= '0')&&(ch <= '9'))
	{
		a = (ch - 48);
	}
	if ((ch >= 'A')&&(ch <= 'Z'))
	{
		a = ch - 55;
	}

	tot += a;

	if (a > min)min=a;
}


if (min == 0)
{
	printf("2\n");
	return 0;
}
for (k = min+1;k <= 36; k++)
{
	if(tot % (k-1) == 0)
	{
		printf("%I64d\n", k);
		return 0;
	}
}
	printf("No solution.\n");

return 0;
}
*/