#include <stdio.h>
int main()
{
	int n;
	scanf("%d", &n);
	int num;

	
	bool in_num = 0;
	int curr_num = -41;
	int counter = 0;
	for(int i = 0; i < n; ++i)
	{
		scanf("%d", &num);

		if(in_num)
		{
			if(num != curr_num)
			{
				in_num = 0;
			}else 
			counter++;
		}
		if(!in_num)
		{
			if(curr_num != -41)printf("%d %d ", counter, curr_num);
			in_num = 1;
			curr_num = num;
			counter = 1;
		}		
	}
	printf("%d %d ", counter, curr_num);

	return 0;
}