#include <stdio.h>
#define HALF 0.0499999999999
#define COND ((double(full_sum+curr)/double(n+curr)))

int main()
{
	double f = HALF;
	double x, y;
	int n,old_N;
	scanf("%lf%lf%d", &x, &y, &n);
	old_N = n;
	if(x == y)
	{
		printf("0");
		return 0;
	}

	if(x == 10.0)
	{}
	else
	{
		x += HALF;
	}
	
	if(y == 10.0)
	{}
	else
	{
		y += HALF;
	}


	int full_sum = int (x*(double(n)));

	if(n == 10.0)
	{
		while (full_sum/n >= x) full_sum--;
	}
	else while (full_sum/n >= x + HALF) full_sum--;

	int ans = 0;

	//while (((double(full_sum++)/double(n++))) >= y)ans++;

	int adder = 1000000000;
///
	
	int floor = 0, roof = 1000000000, curr = 500000000;
	while(true)
	{
		if(COND > y)
		{
			floor = curr;
			curr += (roof-curr)/2;
		}
		else
		{
			roof = curr;
			curr -= (curr-floor)/2;
		}
		if((roof-floor) <= 2)break;
	}
	ans = floor;
	full_sum += ans;
	n += ans;

	while (((double(full_sum++)/double(n++))) >= y)ans++;

	printf("%d\n", ans);
	

	return 0;
}