#include <stdio.h>
#include <iostream>
using namespace std;
int a[106];
int main()
{
	int n, columns, i, j;

	scanf("%d%d", &n, &columns);

	int rows =((n-1)/columns) + 1;

	for(i = 0; i <= 103; i++)a[i] = -256;

	for(i = 0; i < n; i++)scanf("%d", &a[i]);

	for(i = 0; i < rows; i++)
	{
		for(j = 0; j < columns; j++)
		{
			cout.width(4);
			if(a[i + j*rows] >= 0)cout << a[i + j*rows];
		}
		cout << endl;
	
	}

	return 0;
}