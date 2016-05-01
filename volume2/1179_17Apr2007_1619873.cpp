//1179_Sb
#include <iostream>
using namespace std;
int a[38];
int result[38];
int get_val(char ch)
{
	if(ch == ' ' || ch == '\n')return 41;
	if(isdigit(ch))return (ch - '0');
	return (ch - 'A') + 10;
}
int main()
{
	char ch;
	string str;
	int i;
	while(cin.get(ch))
	{
		for(i = 2; i <= 36; ++i)
		{
			if(get_val(ch) < i)
			{
				if(!a[i])
				{
					result[i]++;
					a[i] = 1;
				}
			}
			else a[i] = 0;
		}
	}
	
	int max = -25;
	int max_i = 0;

	for(i = 2; i <= 36; ++i)
	{
		if(result[i] > max)max = result[i], max_i = i;
	}
	cout << max_i << " " << max << endl;

	return 0;
}