#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

const double pi = 3.141592654;

class complex {
public:
double r;
double i;
complex(double rnew = 0.0,double inew = 0.0) {
r=rnew;
i=inew;
}
~complex() {}
complex &operator = (const complex &c) {
r=c.r;
i=c.i;
return *this;
}
complex operator + (const complex &c) const {
return (complex(r+c.r,i+c.i));
}
complex operator - (const complex &c) const {
return (complex(r-c.r,i-c.i));
}
complex operator * (const complex &c) const {
return (complex(r*c.r-i*c.i,i*c.r+r*c.i));
}
complex operator / (const complex &c) const {
return (complex((r*c.r+i*c.i)/(c.r*c.r+c.i*c.i),
(i*c.r-r*c.i)/(c.r*c.r+c.i*c.i)));
}
};

int main(void) {
long n,i,j;
cin>>n;
complex temp,a,b;
complex* z=new complex[n+1];
complex* node=new complex[n+1];
complex* result=new complex[n+1];
double* degree=new double[n+1];
for(i=1;i<=n;i++){
cin>>z[i].r>>z[i].i;
}
for(i=1;i<=n;i++){
cin>>degree[i];
degree[i]=degree[i]*pi/180;
node[i].r=cos(degree[i]);
node[i].i=sin(degree[i]);
}
for(i=1;i<=n;i++){
temp=z[i]*(node[i]-complex(1,0));
for(j=i+1;j<=n;j++){
temp=temp*node[j];
}
a=a+temp;
}
b=node[1];
for(i=2;i<=n;i++){
b=b*node[i];
}
b=b-complex(1,0);
result[1]=a/b;
for(i=2;i<=n;i++){
result[i]=(result[i-1]-z[i-1])*node[i-1]+z[i-1];
}
for(i=1;i<=n;i++){
cout<<result[i].r<<" "<<result[i].i<<endl;

}
delete []z;
delete []node;
delete []result;
delete []degree;
return 0;
}