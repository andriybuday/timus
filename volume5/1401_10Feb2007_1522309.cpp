#include <stdio.h>
#include <iostream>
#include <math.h>
int static_counter;
using namespace std;
int a[1025][1025];
void creating_the_matrix(int first_x,int first_y,int n,int x,int y, int reverse_counter)
{
	__int64 i, j;

	if(n == 2)
	{

		for(i = first_x; i < first_x + 2; i++)
		{
			for(j = first_y; j < first_y + 2; j++)
			{
				if((i != first_x + x - 1) || (j != first_y + y -1))
				{
					a[i][j] = static_counter;
				}
				else
				{
					a[i][j] = reverse_counter;
				}
			}
		}
		//if(static_counter == reverse_counter){printf("-1"); exit(0);}
		static_counter++; 
		
		return;
	}
	
	if(x <= n/2 && y <= n/2)
	{
		creating_the_matrix(first_x,first_y,n/2, x, y, reverse_counter - 1);

	creating_the_matrix(first_x ,first_y + n/2 ,n/2, n/2, 1, reverse_counter);

	creating_the_matrix(first_x + n/2,first_y ,n/2, 1, n/2, reverse_counter);

	creating_the_matrix(first_x + n/2,first_y + n/2,n/2, 1, 1, reverse_counter);

	}
	if(x <= n/2 && y > n/2)
	{
	creating_the_matrix(first_x,first_y,n/2, n/2, n/2, reverse_counter);

		creating_the_matrix(first_x ,first_y + n/2 ,n/2, x, y - n/2, reverse_counter - 1);

	creating_the_matrix(first_x + n/2,first_y ,n/2, 1, n/2, reverse_counter);

	creating_the_matrix(first_x + n/2,first_y + n/2,n/2, 1, 1, reverse_counter);
	}
	if(x > n/2 && y <= n/2)
	{
	creating_the_matrix(first_x,first_y,n/2, n/2, n/2, reverse_counter);

	creating_the_matrix(first_x ,first_y + n/2 ,n/2, n/2, 1, reverse_counter);

		creating_the_matrix(first_x + n/2,first_y ,n/2, x - n/2, y, reverse_counter - 1);

	creating_the_matrix(first_x + n/2,first_y + n/2,n/2, 1, 1, reverse_counter);
	}
	if(x > n/2 && y > n/2)
	{
	creating_the_matrix(first_x,first_y,n/2, n/2, n/2, reverse_counter);

	creating_the_matrix(first_x ,first_y + n/2 ,n/2, n/2, 1, reverse_counter);

	creating_the_matrix(first_x + n/2,first_y ,n/2, 1, n/2, reverse_counter);

		creating_the_matrix(first_x + n/2,first_y + n/2,n/2, x-n/2, y-n/2, reverse_counter - 1);
	}

	return;

}
int main()
{
	int i, j;
	int reverse_counter;
	
	static_counter = 1;
	
	int n, needed_x, needed_y;
	scanf("%d", &n);
	scanf("%d%d", &needed_x, &needed_y);

	int matrix_size = int(pow(2.0, double(n)));
	reverse_counter = int((pow(2.0, double(2*n)) - 1)/3);
	int r_c = reverse_counter;

	creating_the_matrix(1,1,matrix_size ,needed_x, needed_y, reverse_counter);

	a[needed_x][needed_y] = 0;

	int st_c = static_counter;
	for(i = 1; i <= matrix_size; i++)
	{
		for(j = 1; j <= matrix_size; j++)
		{
			if (st_c <= a[i][j] && a[i][j] <= r_c)
			{
				if (a[i][j] == a[i][j+1])
				{
					//2
					if(a[i][j] == a[i+1][j])
					{
						a[i][j] = static_counter;
						a[i][j+1] = static_counter;
						//a[i+1][j-1] = static_counter;
						a[i+1][j] = static_counter;
						//a[i+1][j+1] = static_counter;
						static_counter++;
						j++;
					}
					//1
					if(a[i][j] == a[i+1][j+1])
					{
						a[i][j] = static_counter;
						a[i][j+1] = static_counter;
						//a[i+1][j-1] = static_counter;
						//a[i+1][j] = static_counter;
						a[i+1][j+1] = static_counter;
						static_counter++;
						j++;
					}
					
				}
				else
				{
					//4
					if(a[i][j] == a[i+1][j-1])
					{
						a[i][j] = static_counter;
						//a[i][j+1] = static_counter;
						a[i+1][j-1] = static_counter;
						a[i+1][j] = static_counter;
						//a[i+1][j+1] = static_counter;
						static_counter++;
					}
					//3
					if(a[i][j] == a[i+1][j+1])
					{
						a[i][j] = static_counter;
						//a[i][j+1] = static_counter;
						//a[i+1][j-1] = static_counter;
						a[i+1][j] = static_counter;
						a[i+1][j+1] = static_counter;
						static_counter++;
					}
				}
			}
			
		}
	}

	for(i = 1; i <= matrix_size; i++)
	{
		for(j = 1; j <= matrix_size; j++)
			printf("%d ", a[i][j]);
		printf("\n");
	}
	return 0;
}