//1125_AC_cheat
#include <stdio.h>

int n,m;
long y[60][60];
char in[60][60],x[60][60],sel[300000];

void read_data()
{
int i,j;
FILE *f=stdin;
fscanf(f,"%d%d",&m,&n);
fscanf(f,"%c",&in[0][0]);
for(i=0;i<m;i++)
fgets(in[i],100,f);
for(i=0;i<m;i++)
for(j=0;j<n;j++)
fscanf(f,"%ld",&y[i][j]);
}

void init()
{
int i;
for(i=0;i<=500;i++)
sel[i*i]=1; //sel[i]== 1 if i==(X*X)
// 0 else
}

void expand(int a,int b,int nr)
{
int i,j;
for(i=0;i<m;i++)
for(j=0;j<n;j++)
if(j==b || i==a || sel[((i-a)*(i-a)+(j-b)*(j-b))])
x[i][j]=x[i][j] ^ nr;
}

void solve()
{
int i,j;
init();
for(i=0;i<m;i++)
for(j=0;j<n;j++)
if(y[i][j])expand(i,j,y[i][j]%2);
}

void print()
{
int i,j;
FILE *f=stdout;
for(i=0;i<m;i++)
{
for(j=0;j<n;j++)
if(x[i][j])
if(in[i][j]=='B')fprintf(f,"W");
else fprintf(f,"B");
else fprintf(f,"%c",in[i][j]);
fprintf(f,"\n");
}
}

void main()
{
read_data();
solve();
print();
}