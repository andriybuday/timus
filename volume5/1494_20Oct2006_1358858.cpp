//1494//the most best result
#include <stdio.h>
int arr[100001];
int main()
{
	int N, i, j, counter, index, last = 0,pointer = 0;
	scanf("%d", &N);

	for(i = 0; i < N; i++)
	{
		scanf("%d", &index);

		if(index < pointer)
		{
			printf("Cheater\n");

			return 0;
		}
		arr[index] = arr[index-1]+1;

		if(index > last)last = index;

		int save = j = last;

		counter = 0;

		while(arr[j])
		{
			counter += arr[j];
			j -= arr[j];
		}

		arr[save] = counter;

		pointer = j;
	
	}

	if(pointer == 0)
	{
		printf("Not a proof\n");
	}



return 0;
}
