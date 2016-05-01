//1036_SB
//1044_good_ac
#include <iostream>
using namespace std;
__int64 a[52][455];
int main()
{

	///init of matrix
	for (int i = 0; i < 10; i++)a[1][i] = 1;
	for (int i = 0; i < 52; i++)a[i][0] = 1;

	for (int i = 2; i <= 50; i++)
	{
		for(int j = 1; j < 10; j++)
		{
			a[i][j] = a[i][j-1] + a[i-1][j];
		}
		int middle = 0;
		if (i%2)//
		{
			middle = (i*9 - 1)/2;//  
			for (int j = 10; j <= middle; j++)
			{
				a[i][j] = a[i][j-1] + a[i-1][j] - a[i-1][j-10];
			}
			// 
			for (int j = 1; j <= middle + 1; j++)
			{
				a[i][j + middle] = a[i][middle - j + 1];
			}
		
		}
		else//
		{
			middle = i*9 / 2; //     
			for (int j = 10; j <= middle; j++)
			{
				a[i][j] = a[i][j-1] + a[i-1][j] - a[i-1][j-10];
			}
			// 
			for (int j = 1; j <= middle; j++)
			{
				a[i][j + middle] = a[i][middle - j];
			}
		}
	
	}

	int n;
	__int64 sum = 0;
	cin >> n; // >> sum;
	n /= 2;
	//sum /= 2;

	for(int i = 0; i < n*9 + 2; i++)
	{
		sum += a[n][i]*a[n][i];
	}
	cout << sum << endl;
	//cout << a[n][sum]*a[n][sum] << endl;

	return 0;
}