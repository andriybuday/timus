//1213
#include <iostream>
#include <string>
using namespace std;
string starr[32];

int main()
{	
	int flag = 1;
	int i;
	for(i = 0; i < 32; i++)starr[i] = "";

	cin>>starr[0];//gateway
	int counter = 1;
	if((starr[0] == "")||(starr[0] == "#")){printf("0"); return 0;}
	string str = "";	
	string str1 = "";
	string str2 = "";
	while(true)
	{
		cin>>str;
		if(str == "#")break;
		int pos = str.find("-");	
		str1.append(str, 0, pos);
		str2.append(str, pos + 1, str.length() - pos - 1);
		for(i = 0; i <= counter+1; i++)
		{
			if(starr[i] == str1)
			{
				flag = 0;
				break;
			}
		}
		if(flag)
		{
			starr[counter++] = str1;

		}else flag = 1;
		for(i = 0; i <= counter+1; i++)
		{
			if(starr[i] == str2)
			{
				flag = 0;
				break;
			}
		}
		if(flag)
		{
			starr[counter++] = str2;
		}else flag = 1;
		str = "";
		str1 = "";
		str2 = "";
		
	}
	cout<<counter - 1;

	return 0;
}