#include <iostream>
using namespace std;

int main()
{
	int f;
	cin>>f;
	const int con = 1;
	int s = 0;
	if(f<con)
	{
		for(int i = f; i<=con; i++)
		s+=i;
		
		cout<<s;
	}else
		{
			for(int i = con; i<=f; i++)
			s+=i;
			cout<<s;			
		}

	return 0;
}