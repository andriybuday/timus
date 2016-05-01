//1204_AC
#include <stdio.h>
#define ERATO_SIZE 40000
#define PRIME_SIZE 5000
int erato[ERATO_SIZE+5];
int prime[PRIME_SIZE+5];
void Erato()
{
	int ii, jj, an;
	for(ii = 2; ii<ERATO_SIZE; ii++)
		if (!erato[ii])
			for (jj=2; jj <= ERATO_SIZE/ii; jj++)
				if (ii*jj<=ERATO_SIZE) erato[ii*jj]=1;

	an=0;
	for (ii=2; ii<ERATO_SIZE; ++ii)
		if(!erato[ii])
		{
			an++;
			prime[an]=ii;
		}
}
//This is implementation of Euclid algorithm. After Euclid(p,q,x,y) you get px-qy=1
void Euclid(int p, int q, int &x, int &y)
{
	int a, b;
	if(p==1)
	{
		x = 1;
		y = 0;
		return;
	}
	if(q == 1)
	{
		x = 1;
		y = p-1;
		return;
	}
	if(p > q)
	{
		Euclid((p%q), q, a, b);
		x = a;
		y = (b+a*(p/q));
	}
	if(q > p)
	{
		Euclid(p, q%p, a, b);
		y = b;
		x = (a+b*(q/p));
	}
}

int main()
{
	int curr, i, j, p, q, n, x, y;
	Erato();

	scanf("%d", &n);
	for(i = 0; i < n; ++i)
	{
		scanf("%d", &curr);
		printf("\n0 1 ");

		j = 1;
		while(curr%prime[j])++j;

		p = prime[j];
		q = curr/p;

		if(p != q)
		{
			Euclid(p, q, x, y);
			(x <= q/2)?(printf("%d %d", p*x ,p*q-p*x+1)):(printf("%d %d", p*q-p*x+1 ,p*x));
		}
	}
	return 0;
}