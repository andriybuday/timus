#include <iostream>
#include <string>
using namespace std;

int main()
{
	string st;
	cin>>st;

	string res = st;


	int MAS[100];
	unsigned i=0;

	while(st[i])
	{
		MAS[i] = st[i] - 97;
		i++;
	}

	int MAS1[100];

	if(MAS[0]<=5)
	{
		MAS1[0] = MAS[0] + 21;
	}
	else MAS1[0] = MAS[0] - 5;


	i=1;
	while(st[i])
	{
		int P = MAS[i] - MAS[i-1]; 
		if(P>=0&&P<26)MAS1[i] = P;else MAS1[i] = P+26;
		i++;
	}


	i=0;
	while(st[i])
	{	
		res[i] = MAS1[i]+97;
		i++;
	}
	
	cout<<res;

	return 0;
}