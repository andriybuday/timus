//1278_AC
#include <stdio.h>
#include <math.h>

int first[50];
int main()
{
	int k, i=0;
	scanf("%d", &k);
	int save_K = k;

	int count = 0;

	while(k)
	{
		while(k >= pow(2.0, double(first[i])))first[i]++;
		first[i]--;
		k -= int(pow(2.0, double(first[i])));
		if(!first[i])break;
		i++;
	}
	int mean  = 0;
	i = 0;
	while(first[i])
	{
		mean += pow(2.0, double(first[i]));
		++i;
	}
	int amountpowers = 0;
	if(save_K - mean == 1)
	{
		amountpowers = i;
		for(i += 1; i < 50; i++)first[i] = -1;
	}
	else
	{
		amountpowers = i - 1;
		for(; i < 50; i++)first[i] = -1;
	}
	int n = amountpowers + first[0];
	for(i = 49; i > 0; i--)
	{
		if(first[i] == -1)continue;
		printf("CALL %d\n", n-first[i]);
	}
	for(i = first[0] - 1; i >= 0; i--)
	{
		printf("CALL %d\n", n - i);
	}
	printf("BELL&RET\n");
	return 0;
}