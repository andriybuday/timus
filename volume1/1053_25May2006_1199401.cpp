//1053
#include <iostream>

using namespace std;

short n;
unsigned long a[1000];

void Input()
{cin>>n;
for (short i=0; i<n; i++)
cin>>a[i];
}

unsigned long gcd(unsigned long a, unsigned long b)
{unsigned long x;
while (b>0)
{x=b;
b=a%b;
a=x;
}
return a;
}

void Solve()
{for (short i=1; i<n; i++)
a[i]=gcd(a[i-1],a[i]);
}

void Output()
{cout<<a[n-1]<<"\n";
}

int main()
{Input();
Solve();
Output();
return 0;
}
 
