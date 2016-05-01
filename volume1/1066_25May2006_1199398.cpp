//1066
#include <stdio.h>
#define eps 0.00000001

double A, B=((1<<31)-1), DMin=((1<<31)-1);
int N;

void bs()
{
double p1 = A, p2 = 0, mij, a1, a2, a3, min;
int i;

while ((p1-p2)>eps)
{
min = A;
mij = (p1+p2)/2;
a1 = A; a2 = mij;
for (i = 2; i < N; i++)
{
a3 = 2*(a2+1)-a1;
a1 = a2;
a2 = a3;
if (a3 < 0)
{
p2 = mij+eps;
break;
}
else
if (min > a3) min = a3;
}
if (i == N)
{
if ((B-a3)<eps) p2=2*p1;
if ((DMin-min) > eps) DMin = min, B = a3;
p1 = mij-eps;
}
}
}

int main()
{
scanf("%d %lf", &N, &A);
bs();
printf("%.2lf\n", B);

return 0;

}
 
