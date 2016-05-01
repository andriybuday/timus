#include <string>
#include <iostream>
using namespace std;
string strS[1000];
string strH[1000];
string strG[1000];
string strR[1000];
int main(){

	int n, i;
	int Scount = 0;
	int Hcount = 0;
	int Gcount = 0;
	int Rcount = 0;
	string str;
	string strd;
	cin>>n;
	getline(cin, str);
	for(i = 0; i < n; i++)
	{
		str = "";
		getline(cin, str);
		getline(cin, strd);
		//cin>>strd;
		if(strd[0] == 'S')
		{
			strS[Scount] = str;
			Scount++;
			continue;
		}
		if(strd[0] == 'H')
		{
			strH[Hcount] = str;
			Hcount++;
			continue;
		}
		if(strd[0] == 'G')
		{
			strG[Gcount] = str;
			Gcount++;
			continue;
		}
		if(strd[0] == 'R')
		{
			strR[Rcount] = str;
			Rcount++;
			continue;
		}		
	}

	cout<<"Slytherin:\n";
	for(i = 0; i < Scount; i++)
	{
		cout<<strS[i]<<endl;
	}
	cout<<"\nHufflepuff:\n";
	for(i = 0; i < Hcount; i++)
	{
		cout<<strH[i]<<endl;
	}
	cout<<"\nGryffindor:\n";
	for(i = 0; i < Gcount; i++)
	{
		cout<<strG[i]<<endl;
	}
	cout<<"\nRavenclaw:\n";
	for(i = 0; i < Rcount; i++)
	{
		cout<<strR[i]<<endl;
	}


	return 0;
}
