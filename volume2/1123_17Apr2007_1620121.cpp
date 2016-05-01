//1123_SB
#include <iostream>
#include <string>
using namespace std;

int main()
{
	
	string str;
	cin >> str;
	int len = str.length();
	int rev;
	for(int i = 0; i < len/2; ++i)
	{
		rev = len-1-i;
		if(str[i] >= str[rev])str[rev] = str[i];
		else
		{
			int nin = rev - 1;
			/*
			while(str[nin] == '9')
			{
				str[nin] = '0';
				--nin;
			}
			*/
			for(; str[nin] == '9'; --nin)str[nin] = '0';
			str[nin] = str[nin] + 1;
			str[rev] = str[i];
		}
	}

	cout << str;

	return 0;
}