#include <stdio.h>
#include <math.h>
int main()
{
double max, val1, val2;
__int64 n, i, first;
scanf("%I64d%lf%lf", &n, &val1, &val2);
max = fabs(val1 - val2);
first = 1;

for(i = 3; i <= n; i++)
{
	val1 = val2;
	scanf("%lf", &val2);

	if(fabs(val1 - val2) > max)
	{
		max = fabs(val1 - val2);
		first = i-1;
	}

}

	printf("%I64d %I64d\n", first , first + 1);


return 0;
}
