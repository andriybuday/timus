//1048

#include <stdio.h>

#define sum (dig_1 + dig_2)



int main(){

	int n, i, j;

	scanf("%d", &n);

	int dig_1, dig_2;
	int count = 0;

	scanf("%d%d", &dig_1, &dig_2);
	int save = sum;

	for(i = 1; i < n; i++)
	{
		count = 0;
		scanf("%d%d", &dig_1, &dig_2);
		
		while(sum == 9)
		{
			scanf("%d%d", &dig_1, &dig_2);
			
			count++;

			i++;

			if(i == n-1)
			{		

				if(sum < 9)
				{
					printf("%d", save);
					for(j = 0; j <= count; j++)
					{
						printf("9");
					}
					return 0;
				}
				if(sum > 9)
				{
					printf("%d", save + 1);
					for(j = 0; j <= count; j++)
					{
						printf("0");
					}
					return 0;
				}
				if(sum == 9)
				{
					printf("%d", save);
					for(j = 0; j <= count; j++)
					{
						printf("9");
					}
					return 0;
				}
			}
		}
		//if sum is less then 9 print the number and count of nines
		if(sum < 9)
		{
			printf("%d", save);
			for(j = 0; j < count; j++)
			{
				printf("9");
			}
			save = sum;
		}
		if(sum > 9)
		{
			printf("%d", save + 1);
			for(j = 0; j < count; j++)
			{
				printf("0");
			}
			save = sum%10;
		}

	}
	printf("%d", save);


	return 0;
}
