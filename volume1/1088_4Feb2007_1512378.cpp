#include <iostream.h>;
#include <math.h>;

void main()
{
int d,e,f,h;
int ans;
int a[31],
b[31];
int i,j,p;
long ep,dp;

cin>>d>>e>>f>>dp>>ep>>h;

dp--;ep--;

d=f-d;
e=f-e;

p=d>e?e:d;

for(i=f;i>=1;i--)
{a[i]=dp%2;dp/=2;
b[i]=ep%2;ep/=2;
};

for(i=1;(a[i]==b[i])&&(i<=p);i++);

i--;

ans=d+e-2*i;

if(ans<=h)cout<<"YES"<<endl;
else cout<<"NO"<<endl;
};